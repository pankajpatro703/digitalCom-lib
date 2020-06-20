/**
 * @file         crc8.h
 * @brief        Cyclic Redundancy Check - 8-bit CRC calculator
 * @author       pankajpatro703
 * @date         08.03.2020      //created
 * @date         20.06.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
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
 *  algorithm8 CRC_new = {.poly=0x37, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
 * @endcode
 */

/// This structure type defines the parameters required for algorithms used in different applications.
typedef struct {
    uint8_t poly, init, xorOut;
    bool refIn, refOut;
} algorithm8;

//  Different pre-defined algorithms
algorithm8  CRC8_AUTOSAR,       ///< AUTOSAR standard
            CRC8_BLUETOOTH,     ///< Bluetooth HEC
            CRC8_CDMA2000,      ///< CDMA2000 PHY standard
            CRC8_DARC,          ///< Data Radio Channel
            CRC8_DVB_S2,        ///< Digital Video Broadcasting - Satellite - 2nd Gen
            CRC8_EBU,           ///< AES/EBU TECH-3250
            CRC8_GSM_A,         ///< GSM - A
            CRC8_GSM_B,         ///< GSM - B
            CRC8_ITU,           ///< ATM HEC I-432-1
            CRC8_I_CODE,        ///< Philips Semiconductors SL2 ICS11
            CRC8_LTE,           ///< 3GPP
            CRC8_MAXIM,         ///< MAXIM-DOW
            CRC8_MIFARE_MAD,    ///< MIFARE application directory
            CRC8_NRSC_5,        ///< HD Radio PHY standard
            CRC8_OPENSAFETY,    ///< OpenSAFETY standard
            CRC8_ROHC,          ///< Robust Header Compression
            CRC8_SAE_J1850,     ///< SAE standard
            CRC8_SMBUS,         ///< System Management BUS
            CRC8_WCDMA;         ///< WCDMA embedded networks standard

/**
 * Example:
 * @code
 *  #include "crc8.h"
 *  void main() {
 *      uint8_t revnum = reverseBits8(0x48);
 *  }
 * @endcode
 */

/**
 *  Calculates the 8-bit number obtained by reversing the bit sequence of input number.
 *  @param num original 8-bit integer to be reversed
 *  @return reversed 8-bit integer value
 */
uint8_t reverseBits8(uint8_t num);

/**
 * Example:
 * @code
 *  #include "crc8.h"
 *  void main() {
 *      char message1[] = "Enter data here";
 *      unsigned int length1 = sizeof(message1)-1;
 *      char message2[] = {0x3A,0x2B,0x11};
 *      unsigned int length2 = sizeof(message2);
 *      printf("8-bit CRC of message1 is %02x\n",getCRC8(message1, &CRC8_SMBUS, length1));
 *      printf("8-bit CRC of message2 is %02x\n",getCRC8(message2, &CRC8_SMBUS, length2));
 *  }
 * @endcode
 */

/**
 *  Calculates the 8-bit CRC Hash for a given string of data.
 *  @param s data(byte array) on which the CRC is to be calculated
 *  @param algo_struct struct defining the algorithm parameters
 *  @param length length of the message data
 *  @return calculated 8-bit CRC value
 */
uint8_t getCRC8(uint8_t *s, algorithm8 *algo_struct, unsigned int length);

#endif
