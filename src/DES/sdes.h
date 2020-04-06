/*
*    Copyright 2020 Pankajkumar Patro
*
*    This file is part of digitalCom-lib.
*
*    digitalCom-lib is free software: you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    digitalCom-lib is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public License
*    along with digitalCom-lib.  If not, see <https://www.gnu.org/licenses/>.
*/

//Simplified Data Encryption Standard algorithm for encryption and decryption
//////////////////////////////////
//   @Author: pankajpatro703    //
// Licensed under Lesser GPL v3 //
//////////////////////////////////

#include<stdint.h>
#include<math.h>
#include<stdlib.h>

//Sequences defined by SDES algorithm
uint8_t p10[10] = {3,5,2,7,4,10,1,9,8,6};
uint8_t p8[8] = {6,3,7,4,8,5,10,9};
uint8_t iP[8] = {2,6,3,1,4,8,5,7};
uint8_t invIP[8] = {4,1,3,5,7,2,8,6};

uint8_t s0[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
uint8_t s1[4][4] = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
uint8_t eP[8] = {4,1,2,3,2,3,4,1};
uint8_t p4[4] = {2,4,3,1};

uint16_t permutation(uint8_t seq[], uint8_t size, uint16_t data, uint8_t datasize) {
    /*
    This function changes the sequence of occurence of bits in the data.
    :param uint8_t *seq: required order/sequence array
    :param uint8_t size: size of array
    :param uint16_t data: original data whose bit sequence is to be changed
    :param uint8_t datasize: number of bits in original data
    :return uint16_t result: data with specified sequence, size is same as seq
    */
    uint16_t result = 0;
    for(int i=0; i<size; i++)
        result += pow(2,size-i-1) * (data & (0b1<<(datasize-seq[i])) ? 1 : 0);
    return result;
}

uint16_t sw(uint16_t data, uint8_t size, uint8_t partsize) {
    /*
    This function divides a block of bits into two and exchanges their positions.
    :param uint16_t data: original data
    :param uint8_t size: number of bits in original data
    :param uint8_t partsize: integer position for slicing
    :return uint16_t exchangedData: data after exchanging
    */
    uint16_t exchangedData = (data << (partsize) | data >> (size-partsize)) & (int)(pow(2,size)-1);
    return exchangedData;
}

uint8_t fk(uint8_t base, uint8_t key) {
    /*
    This function applies a key on given data.
    :param uint8_t base: original 8-bit data on which key is to be applied
    :param uint8_t key: 8-bit generated key
    :return uint8_t ept: 8-bit data obtained after applying key function
    */
    uint8_t pos = permutation(eP, 8, (base & 0b1111), 4) ^ key;
    uint8_t value = s0[(((pos&0x80)?1:0)<<1) | ((pos&0x10)?1:0)][(((pos&0x40)?1:0)<<1) | ((pos&0x20)?1:0)] <<2 |
        s1[(((pos&0x08)?1:0)<<1) | ((pos&0x01)?1:0)][(((pos&0x04)?1:0)<<1) | ((pos&0x02)?1:0)];
    uint8_t lpt = permutation(p4, 4, value, 4) ^ ((base >> 4) & 0b1111);
    uint8_t ept = (lpt << 4) | (base & 0b1111);
    return ept;
}

uint16_t lshift(uint16_t data, uint8_t size, uint8_t partsize, uint8_t shifts) {
    /*
    This function circular left shifts two bit sequences after dividing them.
    :param uint16_t data: original data
    :param uint8_t size: number of bits in original data
    :param uint8_t partsize: integer position for slicing
    :param uint8_t shifts: number of left shifts required
    :return uint16_t shiftData: shifted and combined data
    */
    uint16_t shiftData = 0;
    uint16_t lpart = data >> (size-partsize);
    uint16_t rpart = data & ((int)pow(2,size-partsize)-1);
    lpart = (lpart << shifts | lpart >> (partsize-shifts)) & (int)(pow(2,partsize)-1);
    rpart = (rpart << shifts | rpart >> (size-partsize-shifts)) & (int)(pow(2,size-partsize)-1);
    shiftData = (lpart << (size-partsize) | rpart);
    return shiftData;
}

uint8_t* keygen(uint16_t key) {
    /*
    This function generates two keys from user defined key.
    :param uint16_t key: original 10-bit key
    :return uint8_t *k: generated array of two 8-bit keys
    */
    uint16_t base = lshift(permutation(p10, 10, key, 10), 10, 5, 1);
    uint8_t *k;
    k = malloc(2*sizeof(*k));
    if(k == NULL)
        return NULL;
    k[0] = permutation(p8, 8, base, 10);
    k[1] = permutation(p8, 8, lshift(base, 10, 5, 2), 10);
    return k;
}

uint8_t sdesEncrypt(uint8_t plaintext, uint16_t key) {
    /*
    This function encrypts the plaintext using S-DES.
    :param uint8_t plaintext: original 8-bit data
    :param uint16_t key: secret 10-bit key
    :return uint8_t ciphertext: 8-bit cipher text after encryption
    */
    uint8_t *k;
    k = keygen(key);
    uint8_t ciphertext = permutation(invIP, 8, fk(sw(fk(permutation(iP, 8, plaintext, 8), k[0]), 8, 4), k[1]), 8);
    free(k);
    return ciphertext;
}

uint8_t sdesDecrypt(uint8_t ciphertext, uint16_t key) {
    /*
    This function decrypts the ciphertext using S-DES.
    :param uint8_t ciphertext: ciphered 8-bit data
    :param uint16_t key: secret 10-bit key
    :return uint8_t decipheredtext: 8-bit deciphered text after decryption
    */
    uint8_t *k;
    k = keygen(key);
    uint8_t decipheredtext = permutation(invIP, 8, fk(sw(fk(permutation(iP, 8, ciphertext, 8), k[1]), 8, 4), k[0]), 8);
    free(k);
    return decipheredtext;
}
