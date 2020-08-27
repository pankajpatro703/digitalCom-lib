/**
 * @file        crc.h
 * @brief       Cyclic Redundancy Check - CRC calculator
 * @author      pankajpatro703
 * @date        08.03.2020      //created
 * @date        27.08.2020      //modified
 * @version     1.0.0
 * @copyright   Copyright (C) 2020 Pankajkumar Patro
 * @license     GNU Lesser GPL v3.0+
 * @see         https://github.com/pankajpatro703/digitalCom-lib
 *
 * crc.h - Header file to calculate 8,16,32,64-bit CRC Hash value.
 *
 * Copyright (C) 2020 Pankajkumar Patro
 *
 * This file is part of digitalCom-lib.
 *
 * digitalCom-lib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * digitalCom-lib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with digitalCom-lib.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CRC_H
#define CRC_H

#include "stdbool.h"
#include "stdlib.h"
#include "stdint.h"

/**
 * @struct crcparam8
 * @brief Defines the parameters required for 8-bit algorithms.
 *
 * Example:
 * @code
 * #include "crc.h"
 * crcparam8 CRC_new = {.poly=0x37, .init=0x23, .refIn=false, .refOut=false, .xorOut=0x11};
 * @endcode
 */
typedef struct {
    uint8_t poly, init;
    bool refIn, refOut;
    uint8_t xorOut;
} crcparam8;
/**
 * @struct crcparam16
 * @brief Defines the parameters required for 16-bit algorithms.
 *
 * Example:
 * @code
 * #include "crc.h"
 * crcparam16 CRC_new = {.poly=0x3712, .init=0x2318, .refIn=false, .refOut=false, .xorOut=0x1134};
 * @endcode
 */
typedef struct {
    uint16_t poly, init;
    bool refIn, refOut;
    uint16_t xorOut;
} crcparam16;
/**
 * @struct crcparam32
 * @brief Defines the parameters required for 32-bit algorithms.
 *
 * Example:
 * @code
 * #include "crc.h"
 * crcparam32 CRC_new = {.poly=0x37123455, .init=0x23182214, .refIn=false, .refOut=false, .xorOut=0x11345523};
 * @endcode
 */
typedef struct {
    uint32_t poly, init;
    bool refIn, refOut;
    uint32_t xorOut;
} crcparam32;
/**
 * @struct crcparam64
 * @brief Defines the parameters required for 64-bit algorithms.
 *
 * Example:
 * @code
 * #include "crc.h"
 * crcparam64 CRC_new = {.poly=0x3712345525342137, .init=0x2318221487230098, .refIn=false, .refOut=false, .xorOut=0x1134552399823102};
 * @endcode
 */
typedef struct {
    uint64_t poly, init;
    bool refIn, refOut;
    uint64_t xorOut;
} crcparam64;

extern crcparam8    CRC8_AUTOSAR,           ///< AUTOSAR standard
                    CRC8_BLUETOOTH,         ///< Bluetooth HEC
                    CRC8_CDMA2000,          ///< CDMA2000 PHY standard
                    CRC8_DARC,              ///< Data Radio Channel
                    CRC8_DVB_S2,            ///< Digital Video Broadcasting - Satellite - 2nd Gen
                    CRC8_EBU,               ///< AES/EBU TECH-3250
                    CRC8_GSM_A,             ///< GSM - A
                    CRC8_GSM_B,             ///< GSM - B
                    CRC8_ITU,               ///< ATM HEC I-432-1
                    CRC8_I_CODE,            ///< Philips Semiconductors SL2 ICS11
                    CRC8_LTE,               ///< 3GPP
                    CRC8_MAXIM,             ///< MAXIM-DOW
                    CRC8_MIFARE_MAD,        ///< MIFARE application directory
                    CRC8_NRSC_5,            ///< HD Radio PHY standard
                    CRC8_OPENSAFETY,        ///< OpenSAFETY standard
                    CRC8_ROHC,              ///< Robust Header Compression
                    CRC8_SAE_J1850,         ///< SAE standard
                    CRC8_SMBUS,             ///< System Management BUS
                    CRC8_WCDMA;             ///< WCDMA embedded networks standard

extern crcparam16   CRC16_A,                ///< ISO-IEC-14443-3-A
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
                    CRC16_TMS37157,         ///< TI TMS37157
                    CRC16_UMTS,             ///< BUYPASS VERIFONE
                    CRC16_USB,              ///< USB
                    CRC16_XMODEM;           ///< ACORN, LTE, V-41-MSB, ZMODEM

extern crcparam32   CRC32_ADCCP,            ///< ISO-HDLC, V-42, XZ, PKZIP
                    CRC32_AUTOSAR,          ///< AUTOSAR
                    CRC32_BZIP2,            ///< AAL5, DECT-B
                    CRC32_C,                ///< ISCSI, BASE91-C, CASTAGNOLI, INTERLAKEN
                    CRC32_CD_ROM_EDC,       ///< CD-ROM-EDC
                    CRC32_D,                ///< BASE91-D
                    CRC32_JAMCRC,           ///< Altera Megacore
                    CRC32_MPEG2,            ///< Video LAN
                    CRC32_POSIX,            ///< CKSUM
                    CRC32_Q,                ///< Aeronautical Information Exchange Model
                    CRC32_XFER;             ///< XFER

extern crcparam64   CRC64_ECMA_182,         ///< DLT-1 cartridges
                    CRC64_GO_ISO,           ///< Go-lang
                    CRC64_WE,               ///< Wolfgang Ehrhardt plugin
                    CRC64_XZ;               ///< GO-ECMA

extern uint8_t table8[];        ///< 8-bit CRC table
extern uint16_t table16[];      ///< 16-bit CRC table
extern uint32_t table32[];      ///< 32-bit CRC table
extern uint64_t table64[];      ///< 64-bit CRC table

uint8_t reverseBits8(uint8_t num);                                          ///< 8-bit - returns reversed bits number
void gentable8(crcparam8* paramlist);                                       ///< 8-bit - generates crc table
uint8_t initCRC8(crcparam8* paramlist);                                     ///< 8-bit - returns initial value for crc
uint8_t updateCRC8(uint8_t* s, uint8_t crc_val, crcparam8* paramlist);      ///< 8-bit - returns updated value of crc
uint8_t fetchCRC8(uint8_t crc_val, crcparam8* paramlist);                   ///< 8-bit - returns final value of crc
uint8_t getCRC8(uint8_t* s, crcparam8* paramlist, size_t length);           ///< 8-bit - returns crc value for given data

uint16_t reverseBits16(uint16_t num);                                       ///< 16-bit - returns reversed bits number
void gentable16(crcparam16* paramlist);                                     ///< 16-bit - generates crc table
uint16_t initCRC16(crcparam16* paramlist);                                  ///< 16-bit - returns initial value for crc
uint16_t updateCRC16(uint8_t* s, uint16_t crc_val, crcparam16* paramlist);  ///< 16-bit - returns updated value of crc
uint16_t fetchCRC16(uint16_t crc_val, crcparam16* paramlist);               ///< 16-bit - returns final value of crc
uint16_t getCRC16(uint8_t* s, crcparam16* paramlist, size_t length);        ///< 16-bit - returns crc value for given data

uint32_t reverseBits32(uint32_t num);                                       ///< 32-bit - returns reversed bits number
void gentable32(crcparam32* paramlist);                                     ///< 32-bit - generates crc table
uint32_t initCRC32(crcparam32* paramlist);                                  ///< 32-bit - returns initial value for crc
uint32_t updateCRC32(uint8_t* s, uint32_t crc_val, crcparam32* paramlist);  ///< 32-bit - returns updated value of crc
uint32_t fetchCRC32(uint32_t crc_val, crcparam32* paramlist);               ///< 32-bit - returns final value of crc
uint32_t getCRC32(uint8_t* s, crcparam32* paramlist, size_t length);        ///< 32-bit - returns crc value for given data

uint64_t reverseBits64(uint64_t num);                                       ///< 64-bit - returns reversed bits number
void gentable64(crcparam64* paramlist);                                     ///< 64-bit - generates crc table
uint64_t initCRC64(crcparam64* paramlist);                                  ///< 64-bit - returns initial value for crc
uint64_t updateCRC64(uint8_t* s, uint64_t crc_val, crcparam64* paramlist);  ///< 64-bit - returns updated value of crc
uint64_t fetchCRC64(uint64_t crc_val, crcparam64* paramlist);               ///< 64-bit - returns final value of crc
uint64_t getCRC64(uint8_t* s, crcparam64* paramlist, size_t length);        ///< 64-bit - returns crc value for given data

/**
 * @brief Calculates the number obtained by reversing the bit sequence of input number.
 * @details Support limited to C11 and above
 * @param num original n-bit integer to be reversed
 * @return reversed n-bit integer value
 *
 * Example:
 * @code
 * #include "crc.h"
 * void main() {
 *      uint8_t data = 0x12;
 *      uint8_t revdata = reverseBits(data);
 * }
 * @endcode
 */
#define reverseBits(num) _Generic((num), uint8_t:reverseBits8, uint16_t:reverseBits16, uint32_t:reverseBits32, uint64_t:reverseBits64)(num)

/**
 * @brief Generates the CRC table based on the algorithm.
 * @details Support limited to C11 and above
 * @param paramlist reference to crc parameter struct
 *
 * Example:
 * @code
 * #include "crc.h"
 * void main() {
 *      gentable(&CRC_new);
 * }
 * @endcode
 */
#define gentable(paramlist) _Generic((paramlist), crcparam8*:gentable8, crcparam16*:gentable16, crcparam32*:gentable32, crcparam64*:gentable64)(paramlist)

/**
 * @brief Initializes the crc value as per the algorithm parameter.
 * @details Support limited to C11 and above
 * @param paramlist reference to crc parameter struct
 * @return initialized crc value
 *
 * Example:
 * @code
 * #include "crc.h"
 * void main() {
 *      uint8_t crc = initCRC(&CRC_new);
 * }
 * @endcode
 */
#define initCRC(paramlist) _Generic((paramlist), crcparam8*:initCRC8, crcparam16*:initCRC16, crcparam32*:initCRC32, crcparam64*:initCRC64)(paramlist)

/**
 * @brief Updates the crc value for each new byte of input.
 * @details Support limited to C11 and above
 * @param s address of data byte
 * @param crc_val previously calculated CRC value
 * @param paramlist reference to crc parameter struct
 * @return updated value for crc
 *
 * Example:
 * @code
 * #include "crc.h"
 * void main() {
 *      uint8_t message[] = "Enter data here";
 *      for(size_t i =0 ; i < length; ++i)
 *          uint8_t crc = updateCRC(message + i, crc, &CRC_new);
 * }
 * @endcode
 */
#define updateCRC(s, crc_val, paramlist) _Generic((paramlist), crcparam8*:updateCRC8, crcparam16*:updateCRC16, crcparam32*:updateCRC32, crcparam64*:updateCRC64)(s, crc_val, paramlist)

/**
 * @brief Obtains the final crc value after post-processing.
 * @details Support limited to C11 and above
 * @param crc_val previously calculated CRC value
 * @param paramlist reference to crc parameter struct
 * @return calculated crc value
 *
 * Example:
 * @code
 * #include "crc.h"
 * void main() {
 *      uint8_t crc = fetchCRC(crc, &CRC_new);
 * }
 * @endcode
 */
#define fetchCRC(crc_val, paramlist) _Generic((paramlist), crcparam8*:fetchCRC8, crcparam16*:fetchCRC16, crcparam32*:fetchCRC32, crcparam64*:fetchCRC64)(crc_val, paramlist)

/**
 * @brief Calculates the crc value for given input data.
 * @details Support limited to C11 and above
 * @param s data(byte array) on which the CRC is to be calculated
 * @param paramlist reference to crc parameter struct
 * @param length length of the message data
 * @return calculated CRC value
 *
 * Example:
 * @code
 * #include "crc.h"
 * void main() {
 *      uint8_t data[] = "Enter data here";
 *      uint8_t crc = new_crc.getCRC(data, &CRC_new, sizeof(data)-1);
 * }
 * @endcode
 */
#define getCRC(s, paramlist, length) _Generic((paramlist), crcparam8*:getCRC8, crcparam16*:getCRC16, crcparam32*:getCRC32, crcparam64*:getCRC64)(s, paramlist, length)

#endif
