/**
 * @file         crc16.h
 * @brief        Cyclic Redundancy Check - 16-bit CRC calculator
 * @author       pankajpatro703
 * @date         08.03.2020      //created
 * @date         19.07.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    crc16.h - Header file to calculate 16-bit CRC Hash value.
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

#ifndef CRC16_H
#define CRC16_H

#include <stdbool.h>
#include <stdint.h>

/**
 *  This structure type defines the parameters required for algorithms used in different applications.
 *
 *  Example:
 *  @code
 *  #include "crc16.h"
 *  algorithm16 CRC_new = {.poly=0x3712, .init=0x0011, .refIn=false, .refOut=false, .xorOut=0x0000};
 *  @endcode
 */
typedef struct {
    uint16_t poly, init;
    bool refIn, refOut;
    uint16_t  xorOut;
} algorithm16;

//  Different pre-defined algorithms
extern algorithm16  CRC16_A,                ///< ISO-IEC-14443-3-A
                    CRC16_ARC,              ///< LHA
                    CRC16_AUG_CCITT,        ///< SPI Fujitsu Semiconductors
                    CRC16_B,                ///< ISO-HDLC IEC-14443-3-B X-25
                    CRC16_CCITT_FALSE,      ///< AUTOSAR, IBM-3740
                    CRC16_CDMA2000,         ///< 3GPP2
                    CRC16_CMS,              ///< RPM packages
                    CRC16_DDS_110,          ///< ELV function generator
                    CRC16_DECT_R,           ///< ETSI EN 300 175-3
                    CRC16_DECT_X,           ///< ETSI EN 300 175-3
                    CRC16_DNP,              ///< Distributed Network Protocol
                    CRC16_EN_13757,         ///< Wireless M-Bus protocol
                    CRC16_GENIBUS,          ///< DARC, EPC-C1G2, I-CODE
                    CRC16_GSM,              ///< GSM
                    CRC16_KERMIT,           ///< V-41-LSB
                    CRC16_LJ1200,           ///< SDRTrunk
                    CRC16_MAXIM,            ///< MAXIM-DOW
                    CRC16_MCRF4XX,          ///< MCRF45X device
                    CRC16_MODBUS,           ///< MODBUS
                    CRC16_NRSC_5,           ///< HD Radio PHY standard
                    CRC16_OPENSAFETY_A,     ///< OpenSAFETY standard A
                    CRC16_OPENSAFETY_B,     ///< OpenSAFETY standard B
                    CRC16_PROFIBUS,         ///< IEC-61158-2
                    CRC16_RIELLO,           ///< Riello Dialog UPS
                    CRC16_T10_DIF,          ///< SCSI Data Integrity Field
                    CRC16_TELEDISK,         ///< Teledisk disc archive format
                    CRC16_TMS37157,         ///< Texas Instruments TMS37157
                    CRC16_UMTS,             ///< BUYPASS VERIFONE
                    CRC16_USB,              ///< USB
                    CRC16_XMODEM;           ///< ACORN, LTE, V-41-MSB, ZMODEM

/**
 *  Calculates the 16-bit number obtained by reversing the bit sequence of input number.
 *  @param num original 16-bit integer to be reversed
 *  @return reversed 16-bit integer value
 *
 *  Example:
 *  @code
 *  #include "crc16.h"
 *  void main() {
 *      uint16_t revnum = reverseBits16(0x0482);
 *  }
 *  @endcode
 */
uint16_t reverseBits16(uint16_t num);

/**
 *  Calculates the 16-bit CRC Hash for a given string of data.
 *  @param s data(byte array) on which the CRC is to be calculated
 *  @param algo_struct struct defining the algorithm parameters
 *  @param length length of the message data
 *  @return calculated 16-bit CRC value
 *
 *  Example:
 *  @code
 *  #include "crc16.h"
 *  void main() {
 *      char message1[] = "Enter data here";
 *      unsigned int length1 = sizeof(message1)-1;
 *      char message2[] = {0x3A,0x2B,0x11};
 *      unsigned int length2 = sizeof(message2);
 *      uint16_t crc1 = getCRC16(message1, &CRC16_CCITT_FALSE, length1);
 *      uint16_t crc2 = getCRC16(message2, &CRC16_CCITT_FALSE, length2);
 *  }
 *  @endcode
 */
uint16_t getCRC16(uint8_t* s, algorithm16* algo_struct, unsigned int length);

#endif
