/**
 * @file         crc8.c
 * @brief        Cyclic Redundancy Check - 8-bit CRC calculator
 * @author       pankajpatro703
 * @date         08.03.2020      //created
 * @date         20.06.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    crc8.c - Description file to calculate 8-bit CRC Hash value.
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

#include "crc8.h"

algorithm8 CRC8_AUTOSAR     = {.poly=0x2F, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
algorithm8 CRC8_BLUETOOTH   = {.poly=0xA7, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
algorithm8 CRC8_CDMA2000    = {.poly=0x9B, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_DARC        = {.poly=0x39, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
algorithm8 CRC8_DVB_S2      = {.poly=0xD5, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_EBU         = {.poly=0x1D, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
algorithm8 CRC8_GSM_A       = {.poly=0x1D, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_GSM_B       = {.poly=0x49, .init=0x00, .refIn=false, .refOut=false, .xorOut=0xFF};
algorithm8 CRC8_ITU         = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x55};
algorithm8 CRC8_I_CODE      = {.poly=0x1D, .init=0xFD, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_LTE         = {.poly=0x9B, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_MAXIM       = {.poly=0x31, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};
algorithm8 CRC8_MIFARE_MAD  = {.poly=0x1D, .init=0xC7, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_NRSC_5      = {.poly=0x31, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_OPENSAFETY  = {.poly=0x2F, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_ROHC        = {.poly=0x07, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00};
algorithm8 CRC8_SAE_J1850   = {.poly=0x1D, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0xFF};
algorithm8 CRC8_SMBUS       = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00};
algorithm8 CRC8_WCDMA       = {.poly=0x9B, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00};

uint8_t reverseBits8(uint8_t num) {
    uint8_t  NoOfBits = sizeof(num) * 8;
    uint8_t revnum = 0, i, temp;
    for (i = 0; i < NoOfBits; i++) {
        temp = (num & (1 << i));
        if(temp)
            revnum |= (1 << ((NoOfBits - 1) - i));
    }
    return revnum;
}

uint8_t getCRC8(uint8_t *s, algorithm8 *algo_struct, unsigned int length) {
    uint8_t d, test, crc = algo_struct -> init;
    unsigned int i, j;
    for(i=0; i<length; i++) {
        d = algo_struct -> refIn ? reverseBits8(*(s + i)) : *(s + i);
        crc ^= d;
        for(j=0; j<8; j++) {
            test = (crc & 0x80) != 0;
            crc = (crc << 1) & 0xff;
            if(test)
                crc ^= algo_struct -> poly;
        }
    }
    if(algo_struct -> refOut)
        crc = reverseBits8(crc);
    crc ^= algo_struct -> xorOut;
    return crc;
}
