/**
 * @file         crc8.h
 * @brief        Cyclic Redundancy Check - 8-bit CRC calculator
 * @author       pankajpatro703
 * @date         08.03.2020      //created
 * @date         17.06.2020      //modified
 * @version      1.0
 * @copyright    GNU Lesser GPL v3.0+
 *    
 *    crc8.h - Header file to calculate 8-bit CRC Hash value.
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

#ifndef CRC8_H
#define CRC8_H

#include <stdbool.h>
#include <stdint.h>

/**
 * Example:
 * @code
 *  #include "crc8.h"
 *  algorithm8 CRC_rand = {.poly=0x37, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
 * @endcode
 */

/// This structure type defines the parameters required for algorithms used for different applications.
typedef struct {
    uint8_t poly, init, xorOut;
    bool refIn, refOut;
} algorithm8;

//  Different pre-defined algorithms
algorithm8 CRC8, CRC8_CDMA2000, CRC8_DARC, CRC8_DVB_S2, CRC8_EBU, CRC8_I_CODE, CRC8_ITU, CRC8_MAXIM, CRC8_ROHC, CRC8_WCDMA;

/**
 *  Calculates the 8-bit number obtained by reversing the bit sequence of input number.
 *  @param num original 8-bit integer to be reversed
 *  @return reversed 8-bit integer value
 */
uint8_t reverseBits8(uint8_t num);

/**
 *  Calculates the 8-bit CRC Hash for a given string.
 *  @param s data(byte array) on which the CRC is to be calculated
 *  @param algo_struct struct defining the algorithm parameters
 *  @param length length of the message
 *  @return calculated 8-bit CRC value
 */
uint8_t getCRC8(uint8_t *s, algorithm8 *algo_struct, int length);

#endif
