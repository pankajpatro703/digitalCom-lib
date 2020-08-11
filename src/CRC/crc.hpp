/**
 * @file         crc.hpp
 * @brief        Cyclic Redundancy Check - CRC calculator
 * @author       pankajpatro703
 * @date         27.07.2020      //created
 * @date         11.08.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 * crc.hpp - Header file to calculate 8,16,32,64-bit CRC Hash value.
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

#include "stdlib.h"
#include "stdint.h"

/**
 * @struct crc
 * @brief Defines the parameters required for algorithms.
 *
 * Example:
 * @code
 * #include "crc.hpp"
 * crcparam<uint8_t> CRC8_new = {.poly=0x37, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
 * @endcode
 */
template<typename T>
struct crcparam {
    T poly, init;
    bool refIn, refOut;
    T xorOut;
};

extern crcparam<uint8_t>    CRC8_AUTOSAR,           ///< AUTOSAR standard
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

extern crcparam<uint16_t>   CRC16_A,                ///< ISO-IEC-14443-3-A
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

extern crcparam<uint32_t>   CRC32_ADCCP,            ///< ISO-HDLC, V-42, XZ, PKZIP
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

extern crcparam<uint64_t>   CRC64_ECMA_182,         ///< DLT-1 cartridges
                            CRC64_GO_ISO,           ///< Go-lang
                            CRC64_WE,               ///< Wolfgang Ehrhardt plugin
                            CRC64_XZ;               ///< GO-ECMA

/**
 * @class CRCbase
 * @brief Abstract base class for CRC calculation algorithms.
 *
 * Example:
 * @code
 * #include "crc.hpp"
 * void main() {
 *      CRCbase<uint8_t>* ptr = new CRC<uint8_t>(CRC8_new);
 * }
 * @endcode
 */
template<typename T>
class CRCbase {
    protected:
        uint8_t nbits;                  ///< Number of bits in CRC value
        const crcparam<T>* algo_struct; ///< Pointer to algorithm struct
        T crc_val;                      ///< Calculated CRC value

        /**
         * @brief Calculates the number obtained by reversing the bit sequence of input number.
         * @param num original n-bit integer to be reversed
         * @return reversed n-bit integer value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data[] = "Enter data here";
         *      uint8_t crc = ptr -> getCRC(data, sizeof(data)-1);
         * }
         * @endcode
         */
        T reverseBits(T num) const;
    public:
        /**
         * @brief Initializes algorithm reference.
         * @param paramlist crc parameter struct
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      CRCbase base(CRC8_new);
         * }
         * @endcode
         */
        CRCbase(crcparam<T> &paramlist);

        /**
         * @brief Handles memory leaks.
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      delete ptr;
         * }
         * @endcode
         */
        virtual ~CRCbase() {};

        /**
         * @brief Initializes the crc value as per the algorithm parameter.
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      ptr -> initCRC();
         * }
         * @endcode
         */
        virtual inline void initCRC(void) = 0;

        /**
         * @brief Updates the crc value for each new byte of input.
         * @param s address of data byte
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data = 0x12;
         *      ptr -> updateCRC(&data);
         * }
         * @endcode
         */
        virtual inline void updateCRC(uint8_t* s) = 0;

        /**
         * @brief Obtains the final crc value after post-processing.
         * @return calculated crc value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t crc = ptr -> fetchCRC();
         * }
         * @endcode
         */
        virtual inline T fetchCRC(void) = 0;

        /**
         * @brief Calculates the crc value for given input data.
         * @param s data(byte array) on which the CRC is to be calculated
         * @param length length of the message data
         * @return calculated CRC value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data[] = "Enter data here";
         *      uint8_t crc = ptr -> getCRC(data, sizeof(data)-1);
         * }
         * @endcode
         */
        virtual T getCRC(uint8_t* s, size_t length) = 0;
};

/**
 * @class LiteCRC
 * @brief Class for low memory CRC calculation algorithms.
 *
 * Example:
 * @code
 * #include "crc.hpp"
 * void main() {
 *      LiteCRC<uint8_t> new_crc = new LiteCRC<uint8_t>(CRC8_new);
 * }
 * @endcode
 */
template<typename T>
class LiteCRC : public CRCbase<T> {
    public:
        /**
         * @brief Initializes algorithm reference.
         * @param paramlist crc parameter struct
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      LiteCRC new_crc(CRC8_new);
         * }
         * @endcode
         */
        LiteCRC(crcparam<T> &paramlist);

        /**
         * @brief Initializes the crc value as per the algorithm parameter.
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      new_crc.initCRC();
         * }
         * @endcode
         */
        inline void initCRC(void);

        /**
         * @brief Updates the crc value for each new byte of input.
         * @param s address of data byte
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data = 0x12;
         *      new_crc.updateCRC(&data);
         * }
         * @endcode
         */
        inline void updateCRC(uint8_t* s);

        /**
         * @brief Obtains the final crc value after post-processing.
         * @return calculated crc value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t crc = new_crc.fetchCRC();
         * }
         * @endcode
         */
        inline T fetchCRC(void);

        /**
         * @brief Calculates the crc value for given input data.
         * @param s data(byte array) on which the CRC is to be calculated
         * @param length length of the message data
         * @return calculated CRC value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data[] = "Enter data here";
         *      uint8_t crc = new_crc.getCRC(data, sizeof(data)-1);
         * }
         * @endcode
         */
        T getCRC(uint8_t* s, size_t length);
};

/**
 * @class FastCRC
 * @brief Class for fast CRC calculation algorithms.
 *
 * Example:
 * @code
 * #include "crc.hpp"
 * void main() {
 *      FastCRC<uint8_t> new_crc = new FastCRC<uint8_t>(CRC8_new);
 * }
 * @endcode
 */
template<typename T>
class FastCRC : public CRCbase<T> {
    protected:
        T   table[256],     ///< CRC table for all possible bytes
            newpoly,        ///< Corrected polynomial of algorithm
            M1,             ///< MS byte reject window
            M2,             ///< LS byte reject window
            hbits;          ///< Number of upper bytes
    public:
        /**
         * @brief Initializes algorithm reference.
         * @param paramlist crc parameter struct
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      FastCRC new_crc(CRC8_new);
         * }
         * @endcode
         */
        FastCRC(crcparam<T> &paramlist);

        /**
         * @brief Initializes the crc value as per the algorithm parameter.
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      new_crc.initCRC();
         * }
         * @endcode
         */
        inline void initCRC(void);

        /**
         * @brief Updates the crc value for each new byte of input.
         * @param s address of data byte
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data = 0x12;
         *      new_crc.updateCRC(&data);
         * }
         * @endcode
         */
        inline void updateCRC(uint8_t* s);

        /**
         * @brief Obtains the final crc value after post-processing.
         * @return calculated crc value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t crc = new_crc.fetchCRC();
         * }
         * @endcode
         */
        inline T fetchCRC(void);

        /**
         * @brief Calculates the crc value for given input data.
         * @param s data(byte array) on which the CRC is to be calculated
         * @param length length of the message data
         * @return calculated CRC value
         *
         * Example:
         * @code
         * #include "crc.hpp"
         * void main() {
         *      uint8_t data[] = "Enter data here";
         *      uint8_t crc = new_crc.getCRC(data, sizeof(data)-1);
         * }
         * @endcode
         */
        T getCRC(uint8_t* s, size_t length);
};

#include "crc.inl"      //including inline and template function definitions

#endif
