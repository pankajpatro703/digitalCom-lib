/**
 * @file         crc.cpp
 * @brief        Cyclic Redundancy Check - CRC calculator
 * @author       pankajpatro703
 * @date         27.07.2020      //created
 * @date         10.08.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 * crc.cpp - Description file to calculate 8,16,32,64-bit CRC Hash value.
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

#include "crc.hpp"

crc<uint8_t> CRC8_AUTOSAR         = {.poly=0x2F, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
crc<uint8_t> CRC8_BLUETOOTH       = {.poly=0xA7, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crc<uint8_t> CRC8_CDMA2000        = {.poly=0x9B, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_DARC            = {.poly=0x39, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crc<uint8_t> CRC8_DVB_S2          = {.poly=0xD5, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_EBU             = {.poly=0x1D, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
crc<uint8_t> CRC8_GSM_A           = {.poly=0x1D, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_GSM_B           = {.poly=0x49, .init=0x00, .refIn=false, .refOut=false, .xorOut=0xFF};
crc<uint8_t> CRC8_ITU             = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x55};
crc<uint8_t> CRC8_I_CODE          = {.poly=0x1D, .init=0xFD, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_LTE             = {.poly=0x9B, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_MAXIM           = {.poly=0x31, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crc<uint8_t> CRC8_MIFARE_MAD      = {.poly=0x1D, .init=0xC7, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_NRSC_5          = {.poly=0x31, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_OPENSAFETY      = {.poly=0x2F, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_ROHC            = {.poly=0x07, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
crc<uint8_t> CRC8_SAE_J1850       = {.poly=0x1D, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
crc<uint8_t> CRC8_SMBUS           = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crc<uint8_t> CRC8_WCDMA           = {.poly=0x9B, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};

crc<uint16_t> CRC16_A             = {.poly=0x1021, .init=0xC6C6, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_ARC           = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_AUG_CCITT     = {.poly=0x1021, .init=0x1D0F, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_B             = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crc<uint16_t> CRC16_CCITT_FALSE   = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_CDMA2000      = {.poly=0xC867, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_CMS           = {.poly=0x8005, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_DDS_110       = {.poly=0x8005, .init=0x800D, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_DECT_R        = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0001};
crc<uint16_t> CRC16_DECT_X        = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_DNP           = {.poly=0x3D65, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crc<uint16_t> CRC16_EN_13757      = {.poly=0x3D65, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crc<uint16_t> CRC16_GENIBUS       = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crc<uint16_t> CRC16_GSM           = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crc<uint16_t> CRC16_KERMIT        = {.poly=0x1021, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_LJ1200        = {.poly=0x6F63, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_MAXIM         = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crc<uint16_t> CRC16_MCRF4XX       = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_MODBUS        = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_NRSC_5        = {.poly=0x080B, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_OPENSAFETY_A  = {.poly=0x5935, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_OPENSAFETY_B  = {.poly=0x755B, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_PROFIBUS      = {.poly=0x1DCF, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crc<uint16_t> CRC16_RIELLO        = {.poly=0x1021, .init=0xB2AA, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_T10_DIF       = {.poly=0x8BB7, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_TELEDISK      = {.poly=0xA097, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_TMS37157      = {.poly=0x1021, .init=0x89EC, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crc<uint16_t> CRC16_UMTS          = {.poly=0x8005, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crc<uint16_t> CRC16_USB           = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crc<uint16_t> CRC16_XMODEM        = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};

crc<uint32_t> CRC32_ADCCP         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crc<uint32_t> CRC32_AUTOSAR       = {.poly=0xF4ACFB13, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crc<uint32_t> CRC32_BZIP2         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
crc<uint32_t> CRC32_C             = {.poly=0x1EDC6F41, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crc<uint32_t> CRC32_CD_ROM_EDC    = {.poly=0x8001801B, .init=0x00000000, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
crc<uint32_t> CRC32_D             = {.poly=0xA833982B, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crc<uint32_t> CRC32_JAMCRC        = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
crc<uint32_t> CRC32_MPEG2         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0x00000000};
crc<uint32_t> CRC32_POSIX         = {.poly=0x04C11DB7, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
crc<uint32_t> CRC32_Q             = {.poly=0x814141AB, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};
crc<uint32_t> CRC32_XFER          = {.poly=0x000000AF, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};

crc<uint64_t> CRC64_ECMA_182      = {.poly=0x42F0E1EBA9EA3693, .init=0x0000000000000000, .refIn=false, .refOut=false, .xorOut=0x0000000000000000};
crc<uint64_t> CRC64_GO_ISO        = {.poly=0x000000000000001B, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};
crc<uint64_t> CRC64_WE            = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFFFFFFFFFF};
crc<uint64_t> CRC64_XZ            = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};

//template class SimpleCRC<uint8_t>;
//template class SimpleCRC<uint16_t>;
//template class SimpleCRC<uint32_t>;
//template class SimpleCRC<uint64_t>;
//template class FastCRC<uint8_t>;
//template class FastCRC<uint16_t>;
//template class FastCRC<uint32_t>;
//template class FastCRC<uint64_t>;
