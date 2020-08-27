/**
 * @file        crcLite.c
 * @brief       Cyclic Redundancy Check - CRC calculator
 * @author      pankajpatro703
 * @date        08.03.2020      //created
 * @date        27.08.2020      //modified
 * @version     1.0.0
 * @copyright   Copyright (C) 2020 Pankajkumar Patro
 * @license     GNU Lesser GPL v3.0+
 * @see         https://github.com/pankajpatro703/digitalCom-lib
 *
 * crcLite.c - Description file to calculate low memory 8,16,32,64-bit CRC Hash value.
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

#include "crc.h"

crcparam8 CRC8_AUTOSAR          = {.poly=0x2F, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
crcparam8 CRC8_BLUETOOTH        = {.poly=0xA7, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_CDMA2000         = {.poly=0x9B, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_DARC             = {.poly=0x39, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_DVB_S2           = {.poly=0xD5, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_EBU              = {.poly=0x1D, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_GSM_A            = {.poly=0x1D, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_GSM_B            = {.poly=0x49, .init=0x00, .refIn=false, .refOut=false, .xorOut=0xFF};
crcparam8 CRC8_ITU              = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x55};
crcparam8 CRC8_I_CODE           = {.poly=0x1D, .init=0xFD, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_LTE              = {.poly=0x9B, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_MAXIM            = {.poly=0x31, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_MIFARE_MAD       = {.poly=0x1D, .init=0xC7, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_NRSC_5           = {.poly=0x31, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_OPENSAFETY       = {.poly=0x2F, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_ROHC             = {.poly=0x07, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
crcparam8 CRC8_SAE_J1850        = {.poly=0x1D, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
crcparam8 CRC8_SMBUS            = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
crcparam8 CRC8_WCDMA            = {.poly=0x9B, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};

crcparam16 CRC16_A              = {.poly=0x1021, .init=0xC6C6, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_ARC            = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_AUG_CCITT      = {.poly=0x1021, .init=0x1D0F, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_B              = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_CCITT_FALSE    = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_CDMA2000       = {.poly=0xC867, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_CMS            = {.poly=0x8005, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_DDS_110        = {.poly=0x8005, .init=0x800D, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_DECT_R         = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0001};
crcparam16 CRC16_DECT_X         = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_DNP            = {.poly=0x3D65, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_EN_13757       = {.poly=0x3D65, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_GENIBUS        = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_GSM            = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_KERMIT         = {.poly=0x1021, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_LJ1200         = {.poly=0x6F63, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_MAXIM          = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_MCRF4XX        = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_MODBUS         = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_NRSC_5         = {.poly=0x080B, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_OPENSAFETY_A   = {.poly=0x5935, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_OPENSAFETY_B   = {.poly=0x755B, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_PROFIBUS       = {.poly=0x1DCF, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF};
crcparam16 CRC16_RIELLO         = {.poly=0x1021, .init=0xB2AA, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_T10_DIF        = {.poly=0x8BB7, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_TELEDISK       = {.poly=0xA097, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_TMS37157       = {.poly=0x1021, .init=0x89EC, .refIn=true,  .refOut=true,  .xorOut=0x0000};
crcparam16 CRC16_UMTS           = {.poly=0x8005, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};
crcparam16 CRC16_USB            = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF};
crcparam16 CRC16_XMODEM         = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};

crcparam32 CRC32_ADCCP          = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_AUTOSAR        = {.poly=0xF4ACFB13, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_BZIP2          = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
crcparam32 CRC32_C              = {.poly=0x1EDC6F41, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_CD_ROM_EDC     = {.poly=0x8001801B, .init=0x00000000, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
crcparam32 CRC32_D              = {.poly=0xA833982B, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
crcparam32 CRC32_JAMCRC         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
crcparam32 CRC32_MPEG2          = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0x00000000};
crcparam32 CRC32_POSIX          = {.poly=0x04C11DB7, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
crcparam32 CRC32_Q              = {.poly=0x814141AB, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};
crcparam32 CRC32_XFER           = {.poly=0x000000AF, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};

crcparam64 CRC64_ECMA_182       = {.poly=0x42F0E1EBA9EA3693, .init=0x0000000000000000, .refIn=false, .refOut=false, .xorOut=0x0000000000000000};
crcparam64 CRC64_GO_ISO         = {.poly=0x000000000000001B, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};
crcparam64 CRC64_WE             = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFFFFFFFFFF};
crcparam64 CRC64_XZ             = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};

uint8_t reverseBits8(uint8_t num) {
    uint8_t revnum = 0;
    for (uint8_t i = 0; i < 8; ++i) {
        if(num & ((uint8_t)1 << i))
            revnum |= ((uint8_t)1 << (7 - i));
    }
    return revnum;
}
uint16_t reverseBits16(uint16_t num) {
    uint16_t revnum = 0;
    for (uint8_t i = 0; i < 16; ++i) {
        if(num & ((uint16_t)1 << i))
            revnum |= ((uint16_t)1 << (15 - i));
    }
    return revnum;
}
uint32_t reverseBits32(uint32_t num) {
    uint32_t revnum = 0;
    for (uint8_t i = 0; i < 32; ++i) {
        if(num & ((uint32_t)1 << i))
            revnum |= ((uint32_t)1 << (31 - i));
    }
    return revnum;
}
uint64_t reverseBits64(uint64_t num) {
    uint64_t revnum = 0;
    for (uint8_t i = 0; i < 64; ++i) {
        if(num & ((uint64_t)1 << i))
            revnum |= ((uint64_t)1 << (63 - i));
    }
    return revnum;
}

uint8_t initCRC8(crcparam8* paramlist) {
    return paramlist -> init;
}
uint16_t initCRC16(crcparam16* paramlist) {
    return paramlist -> init;
}
uint32_t initCRC32(crcparam32* paramlist) {
    return paramlist -> init;
}
uint64_t initCRC64(crcparam64* paramlist) {
    return paramlist -> init;
}

uint8_t updateCRC8(uint8_t* s, uint8_t crc_val, crcparam8* paramlist) {
    crc_val ^= (paramlist -> refIn ? reverseBits8(*s) : *s);
    for(uint8_t i = 0; i < 8; ++i) {
        bool test = (crc_val & ((uint8_t)1 << 7)) != 0;
        crc_val <<= 1;
        if(test)
            crc_val ^= paramlist -> poly;
    }
    return crc_val;
}
uint16_t updateCRC16(uint8_t* s, uint16_t crc_val, crcparam16* paramlist) {
    crc_val ^= (paramlist -> refIn ? reverseBits16(*s) : (uint16_t)*s << 8);
    for(uint8_t i = 0; i < 8; ++i) {
        bool test = (crc_val & ((uint16_t)1 << 15)) != 0;
        crc_val <<= 1;
        if(test)
            crc_val ^= paramlist -> poly;
    }
    return crc_val;
}
uint32_t updateCRC32(uint8_t* s, uint32_t crc_val, crcparam32* paramlist) {
    crc_val ^= (paramlist -> refIn ? reverseBits32(*s) : (uint32_t)*s << 24);
    for(uint8_t i = 0; i < 8; ++i) {
        bool test = (crc_val & ((uint32_t)1 << 31)) != 0;
        crc_val <<= 1;
        if(test)
            crc_val ^= paramlist -> poly;
    }
    return crc_val;
}
uint64_t updateCRC64(uint8_t* s, uint64_t crc_val, crcparam64* paramlist) {
    crc_val ^= (paramlist -> refIn ? reverseBits64(*s) : (uint64_t)*s << 56);
    for(uint8_t i = 0; i < 8; ++i) {
        bool test = (crc_val & ((uint64_t)1 << 63)) != 0;
        crc_val <<= 1;
        if(test)
            crc_val ^= paramlist -> poly;
    }
    return crc_val;
}

uint8_t fetchCRC8(uint8_t crc_val, crcparam8* paramlist) {
    if(paramlist -> refOut)
        crc_val = reverseBits8(crc_val);
    return crc_val ^ paramlist -> xorOut;
}
uint16_t fetchCRC16(uint16_t crc_val, crcparam16* paramlist) {
    if(paramlist -> refOut)
        crc_val = reverseBits16(crc_val);
    return crc_val ^ paramlist -> xorOut;
}
uint32_t fetchCRC32(uint32_t crc_val, crcparam32* paramlist) {
    if(paramlist -> refOut)
        crc_val = reverseBits32(crc_val);
    return crc_val ^ paramlist -> xorOut;
}
uint64_t fetchCRC64(uint64_t crc_val, crcparam64* paramlist) {
    if(paramlist -> refOut)
        crc_val = reverseBits64(crc_val);
    return crc_val ^ paramlist -> xorOut;
}

uint8_t getCRC8(uint8_t* s, crcparam8* paramlist, size_t length) {
    uint8_t crc_val = initCRC8(paramlist);
    for(size_t i =0 ; i < length; ++i)
        crc_val = updateCRC8(s+i, crc_val, paramlist);
    return fetchCRC8(crc_val, paramlist);
}
uint16_t getCRC16(uint8_t* s, crcparam16* paramlist, size_t length) {
    uint16_t crc_val = initCRC16(paramlist);
    for(size_t i =0 ; i < length; ++i)
        crc_val = updateCRC16(s+i, crc_val, paramlist);
    return fetchCRC16(crc_val, paramlist);
}
uint32_t getCRC32(uint8_t* s, crcparam32* paramlist, size_t length) {
    uint32_t crc_val = initCRC32(paramlist);
    for(size_t i =0 ; i < length; ++i)
        crc_val = updateCRC32(s+i, crc_val, paramlist);
    return fetchCRC32(crc_val, paramlist);
}
uint64_t getCRC64(uint8_t* s, crcparam64* paramlist, size_t length) {
    uint64_t crc_val = initCRC64(paramlist);
    for(size_t i =0 ; i < length; ++i)
        crc_val = updateCRC64(s+i, crc_val, paramlist);
    return fetchCRC64(crc_val, paramlist);
}
