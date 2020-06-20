/**
 * @file         crc64.h
 * @brief        Cyclic Redundancy Check - 64-bit CRC calculator
 * @author       pankajpatro703
 * @date         20.06.2020      //created
 * @date         20.06.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    crc64.h - Header file to calculate 64-bit CRC Hash value.
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

#ifndef CRC64_H
#define CRC64_H

#include<stdbool.h>
#include<stdint.h>

/**
 * Example:
 * @code
 *  #include "crc64.h"
 *  algorithm64 CRC_new = {.poly=0x3712AA003712AA00, .init=0x0011CA010011CA01, .refIn=false, .refOut=false, .xorOut=0x000011AA000011AA};
 * @endcode
 */

/// This structure type defines the parameters required for algorithms used in different applications.
typedef struct {
    uint64_t poly, init, xorOut;
    bool refIn, refOut;
} algorithm64;

//  Different pre-defined algorithms
algorithm64 CRC64_ECMA_182,     ///< DLT-1 cartridges
            CRC64_GO_ISO,       ///< Go-lang
            CRC64_WE,           ///< Wolfgang Ehrhardt plugin
            CRC64_XZ;           ///< GO-ECMA

/**
 * Example:
 * @code
 *  #include "crc64.h"
 *  void main() {
 *      uint64_t revnum = reverseBits64(0x0482010004820100);
 *  }
 * @endcode
 */

/**
 *  Calculates the 64-bit number obtained by reversing the bit sequence of input number.
 *  @param num original 64-bit integer to be reversed
 *  @return reversed 64-bit integer value
 */
uint64_t reverseBits64(uint64_t num);

/**
 * Example:
 * @code
 *  #include "crc64.h"
 *  void main() {
 *      char message1[] = "Enter data here";
 *      unsigned int length1 = sizeof(message1)-1;
 *      char message2[] = {0x3A,0x2B,0x11};
 *      unsigned int length2 = sizeof(message2);
 *      printf("64-bit CRC of message1 is %016lx\n",getCRC64(message1, &CRC64_ECMA_182, length1));
 *      printf("64-bit CRC of message2 is %016lx\n",getCRC64(message2, &CRC64_ECMA_182, length2));
 *  }
 * @endcode
 */

/**
 *  Calculates the 64-bit CRC Hash for a given string of data.
 *  @param s data(byte array) on which the CRC is to be calculated
 *  @param algo_struct struct defining the algorithm parameters
 *  @param length length of the message data
 *  @return calculated 64-bit CRC value
 */
uint64_t getCRC64(uint8_t *s, algorithm64 *algo_struct, unsigned int length);

#endif
