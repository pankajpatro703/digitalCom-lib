/**
 * @file         crc32.h
 * @brief        Cyclic Redundancy Check - 32-bit CRC calculator
 * @author       pankajpatro703
 * @date         08.03.2020      //created
 * @date         19.07.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    crc32.h - Header file to calculate 32-bit CRC Hash value.
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

#ifndef CRC32_H
#define CRC32_H

#include <stdbool.h>
#include <stdint.h>

/**
 *  This structure type defines the parameters required for algorithms used in different applications.
 *
 *  Example:
 *  @code
 *  #include "crc32.h"
 *  algorithm32 CRC_new = {.poly=0x3712AA00, .init=0x0011CA01, .refIn=false, .refOut=false, .xorOut=0x000011AA};
 *  @endcode
 */
typedef struct {
    uint32_t poly, init;
    bool refIn, refOut;
    uint32_t  xorOut;
} algorithm32;

//  Different pre-defined algorithms
extern algorithm32  CRC32_ADCCP,        ///< ISO-HDLC, V-42, XZ, PKZIP
                    CRC32_AUTOSAR,      ///< AUTOSAR
                    CRC32_BZIP2,        ///< AAL5, DECT-B
                    CRC32_C,            ///< ISCSI, BASE91-C, CASTAGNOLI, INTERLAKEN
                    CRC32_CD_ROM_EDC,   ///< CD-ROM-EDC
                    CRC32_D,            ///< BASE91-D
                    CRC32_JAMCRC,       ///< Altera Megacore
                    CRC32_MPEG2,        ///< Video LAN
                    CRC32_POSIX,        ///< CKSUM
                    CRC32_Q,            ///< Aeronautical Information Exchange Model
                    CRC32_XFER;         ///< XFER

/**
 *  Calculates the 32-bit number obtained by reversing the bit sequence of input number.
 *  @param num original 32-bit integer to be reversed
 *  @return reversed 32-bit integer value
 *
 *  Example:
 *  @code
 *  #include "crc32.h"
 *  void main() {
 *      uint32_t revnum = reverseBits32(0x04820100);
 *  }
 *  @endcode
 */
uint32_t reverseBits32(uint32_t num);

/**
 *  Calculates the 32-bit CRC Hash for a given string of data.
 *  @param s data(byte array) on which the CRC is to be calculated
 *  @param algo_struct struct defining the algorithm parameters
 *  @param length length of the message data
 *  @return calculated 32-bit CRC value
 *
 *  Example:
 *  @code
 *  #include "crc32.h"
 *  void main() {
 *      char message1[] = "Enter data here";
 *      unsigned int length1 = sizeof(message1)-1;
 *      char message2[] = {0x3A,0x2B,0x11};
 *      unsigned int length2 = sizeof(message2);
 *      uint32_t crc1 = getCRC32(message1, &CRC32_ADCCP, length1);
 *      uint32_t crc2 = getCRC32(message2, &CRC32_ADCCP, length2);
 *  }
 *  @endcode
 */
uint32_t getCRC32(uint8_t* s, algorithm32* algo_struct, unsigned int length);

#endif
