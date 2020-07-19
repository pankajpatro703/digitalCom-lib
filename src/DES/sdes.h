/**
 * @file         sdes.h
 * @brief        Simplified Data Encryption Standard - 8-bit DES implementation
 * @author       pankajpatro703
 * @date         27.02.2019      //created
 * @date         19.07.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    sdes.h - Header file to encrypt and decrypt data using simplified-DES.
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

#ifndef SDES_H
#define SDES_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

//  Sequences defined by SDES algorithm
extern uint8_t  p10[10],    ///< 10 position permutation for key generation
                p8[8],      ///< 8 position permutation for key generation
                iP[8],      ///< 8 position initial permutation
                invIP[8],   ///< 8 position final permutation
                s0[4][4],   ///< s-box 1
                s1[4][4],   ///< s-box 2
                eP[8],      ///< 8 position permutation for applying a key
                p4[4];      ///< 4 position permutation for dividing the bit sequence

/**
 *  Changes the sequence of occurence of bits in the data(upto 16 bits).
 *  @param seq required order/sequence array
 *  @param size size of array
 *  @param data original data whose bit sequence is to be changed
 *  @param datasize number of bits in original data
 *  @return data with specified sequence, size is same as seq
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint16_t data = 0b1100101011;
 *       uint16_t newdata = *permutation16(p10, 10, &data, 10);
 *  }
 *  @endcode
 */
uint16_t* permutation16(uint8_t* seq, uint8_t size, uint16_t* data, uint8_t datasize);

/**
 *  Changes the sequence of occurence of bits in the data(upto 8 bits).
 *  @param seq required order/sequence array
 *  @param size size of array
 *  @param data original data whose bit sequence is to be changed
 *  @param datasize number of bits in original data
 *  @return data with specified sequence, size is same as seq
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t data = 0b11001010;
 *       uint8_t newdata = *permutation8(p8, 8, &data, 8);
 *  }
 *  @endcode
 */
uint8_t* permutation8(uint8_t* seq, uint8_t size, uint8_t* data, uint8_t datasize);

/**
 *  Divides a block of bits into two and exchanges their positions.
 *  @param data original data
 *  @param size number of bits in original data
 *  @param partsize integer position for slicing
 *  @return data after exchanging
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t data = 0b11001010;
 *       uint8_t newdata = *sw(&data, 8, 4);
 *  }
 *  @endcode
 */
uint8_t* sw(uint8_t* data, uint8_t size, uint8_t partsize);

/**
 *  Applies a key on given data.
 *  @param base original 8-bit data on which key is to be applied
 *  @param key 8-bit generated key
 *  @return 8-bit data obtained after applying key function
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t data = 0b11001010;
 *       uint8_t key = 0b00111100;
 *       uint8_t newdata = *fk(&data, &key);
 *  }
 *  @endcode
 */
uint8_t* fk(uint8_t* base, uint8_t* key);

/**
 *  Circular left shifts two bit sequences after dividing them.
 *  @param data original data
 *  @param size number of bits in original data
 *  @param partsize integer position for slicing
 *  @param shifts number of left shifts required
 *  @return shifted and combined data
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t data = 0b1100101011;
 *       uint16_t newdata = *lshift(&data, 10, 5, 1);
 *  }
 *  @endcode
 */
uint16_t* lshift(uint16_t* data, uint8_t size, uint8_t partsize, uint8_t shifts);

/**
 *  Generates two keys from user defined key.
 *  @param key original 10-bit key
 *  @return generated array of two 8-bit keys
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t key = 0b1100101011;
 *       uint8_t* k = keygen(&key);   //generates k[0] and k[1]
 *       free(k);
 *  }
 *  @endcode
 */
uint8_t* keygen(uint16_t* key);

/**
 *  Encrypts the plaintext using S-DES.
 *  @param plaintext original 8-bit data
 *  @param key secret 10-bit key
 *  @return 8-bit cipher text after encryption
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t data = 0b11001010;
 *       uint16_t key = 0b1100101011;
 *       uint8_t newdata = encrypt(&data, &key);
 *  }
 *  @endcode
 */
uint8_t encrypt(uint8_t* plaintext, uint16_t* key);

/**
 *  Decrypts the ciphertext using S-DES.
 *  @param ciphertext ciphered 8-bit data
 *  @param key secret 10-bit key
 *  @return 8-bit deciphered text after decryption
 *
 *  Example:
 *  @code
 *  #include "sdes.h"
 *  void main() {
 *       uint8_t data = 0b11001010;
 *       uint16_t key = 0b1100101011;
 *       uint8_t newdata = decrypt(&data, &key);
 *  }
 *  @endcode
 */
uint8_t decrypt(uint8_t* ciphertext, uint16_t* key);

#endif
