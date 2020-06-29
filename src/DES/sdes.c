/**
 * @file         sdes.c
 * @brief        Simplified Data Encryption Standard - 8-bit DES implementation
 * @author       pankajpatro703
 * @date         27.02.2019      //created
 * @date         28.06.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    sdes.c - Description file to encrypt and decrypt data using simplified-DES.
 *
 *    Copyright (C) 2020 Pankajkumar Patro
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

#include "sdes.h"

uint8_t p10[10]     = {3,5,2,7,4,10,1,9,8,6};
uint8_t p8[8]       = {6,3,7,4,8,5,10,9};
uint8_t iP[8]       = {2,6,3,1,4,8,5,7};
uint8_t invIP[8]    = {4,1,3,5,7,2,8,6};
uint8_t s0[4][4]    = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
uint8_t s1[4][4]    = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
uint8_t eP[8]       = {4,1,2,3,2,3,4,1};
uint8_t p4[4]       = {2,4,3,1};

uint16_t* permutation16(uint8_t* seq, uint8_t size, uint16_t* data, uint8_t datasize) {
    uint16_t* result = malloc(sizeof(uint16_t));
    if(result == NULL)
        return NULL;
    for(int i=0; i<size; i++)
        *result += pow(2, size - i - 1) * (*data & (0b1 << (datasize - *(seq + i))) ? 1 : 0);
    return result;
}

uint8_t* permutation8(uint8_t* seq, uint8_t size, uint8_t* data, uint8_t datasize) {
    uint8_t* result = malloc(sizeof(uint8_t));
    if(result == NULL)
        return NULL;
    for(int i=0; i<size; i++)
        *result += pow(2, size - i - 1) * (*data & (0b1 << (datasize - *(seq + i))) ? 1 : 0);
    return result;
}

uint8_t* sw(uint8_t* data, uint8_t size, uint8_t partsize) {
    uint8_t* exchangedData = malloc(sizeof(uint8_t));
    if(exchangedData == NULL)
        return NULL;
    *exchangedData = (*data << (partsize) | *data >> (size - partsize)) & (uint8_t)(pow(2, size) - 1);
    return exchangedData;
}

uint8_t* fk(uint8_t* base, uint8_t* key) {
    uint8_t* ept = malloc(sizeof(uint8_t));
    if(ept == NULL)
        return NULL;
    uint8_t rpt = *base & 0b1111;
    uint8_t pos = *permutation8(eP, 8, &rpt, 4) ^ *key;
    uint8_t value = *(*(s0 + ((((pos & 0x80) ? 1 : 0) << 1) | ((pos & 0x10) ? 1 : 0))) + ((((pos & 0x40) ? 1 : 0) <<1) | ((pos & 0x20) ? 1 : 0))) <<2 | 
        *(*(s1 + ((((pos & 0x08) ? 1 : 0) << 1) | ((pos & 0x01) ? 1 : 0))) + ((((pos & 0x04) ? 1 : 0) << 1) | ((pos & 0x02) ? 1 : 0)));
    uint8_t lpt = *permutation8(p4, 4, &value, 4) ^ ((*base >> 4) & 0b1111);
    *ept = (lpt << 4) | (*base & 0b1111);
    return ept;
}

uint16_t* lshift(uint16_t* data, uint8_t size, uint8_t partsize, uint8_t shifts) {
    uint16_t* shiftData = malloc(sizeof(uint16_t));
    if(shiftData == NULL)
        return NULL;
    uint16_t lpart = *data >> (size - partsize);
    uint16_t rpart = *data & ((uint8_t)pow(2, size - partsize) - 1);
    lpart = (lpart << shifts | lpart >> (partsize - shifts)) & (uint8_t)(pow(2, partsize) - 1);
    rpart = (rpart << shifts | rpart >> (size - partsize - shifts)) & (uint8_t)(pow(2 , size - partsize) - 1);
    *shiftData = (lpart << (size - partsize) | rpart);
    return shiftData;
}

uint8_t* keygen(uint16_t* key) {
    uint8_t* k = malloc(2 * sizeof(*k));
    if(k == NULL)
        return NULL;
    uint16_t* base = lshift(permutation16(p10, 10, key, 10), 10, 5, 1);
    *k = *permutation16(p8, 8, base, 10);
    *(k+1) = *permutation16(p8, 8, lshift(base, 10, 5, 2), 10);
    return k;
}

uint8_t encrypt(uint8_t* plaintext, uint16_t* key) {
    uint8_t* k = keygen(key);
    uint8_t ciphertext = *permutation8(invIP, 8, fk(sw(fk(permutation8(iP, 8, plaintext, 8), k), 8, 4), (k+1)), 8);
    free(k);
    return ciphertext;
}

uint8_t decrypt(uint8_t* ciphertext, uint16_t* key) {
    uint8_t* k = keygen(key);
    uint8_t decipheredtext = *permutation8(invIP, 8, fk(sw(fk(permutation8(iP, 8, ciphertext, 8), (k+1)), 8, 4), k), 8);
    free(k);
    return decipheredtext;
}
