/**
 * @file         crc32.c
 * @brief        Cyclic Redundancy Check - 32-bit CRC calculator
 * @author       pankajpatro703
 * @date         08.03.2020      //created
 * @date         20.06.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    crc32.c - Description file to calculate 32-bit CRC Hash value.
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

#include "crc32.h"

algorithm32 CRC32_ADCCP         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
algorithm32 CRC32_AUTOSAR       = {.poly=0xF4ACFB13, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
algorithm32 CRC32_BZIP2         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
algorithm32 CRC32_C             = {.poly=0x1EDC6F41, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
algorithm32 CRC32_CD_ROM_EDC    = {.poly=0x8001801B, .init=0x00000000, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
algorithm32 CRC32_D             = {.poly=0xA833982B, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF};
algorithm32 CRC32_JAMCRC        = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0x00000000};
algorithm32 CRC32_MPEG2         = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0x00000000};
algorithm32 CRC32_POSIX         = {.poly=0x04C11DB7, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF};
algorithm32 CRC32_Q             = {.poly=0x814141AB, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};
algorithm32 CRC32_XFER          = {.poly=0x000000AF, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000};

uint32_t reverseBits32(uint32_t num) {
    uint32_t  NoOfBits = sizeof(num) * 8;
    uint32_t revnum = 0, i, temp;
    for (i = 0; i < NoOfBits; i++) {
        temp = (num & (1 << i));
        if(temp)
            revnum |= (1 << ((NoOfBits - 1) - i));
    }
    return revnum;
}

uint32_t getCRC32(uint8_t *s, algorithm32 *algo_struct, unsigned int length) {
    uint32_t d, test, crc = algo_struct -> init;
    unsigned int i, j;
    for(i=0; i<length; i++) {
        d = algo_struct -> refIn ? reverseBits32(*(s + i)) : *(s + i) << 24;
        crc ^= d;
        for(j=0; j<8; j++) {
            test = (crc & 0x80000000) != 0;
            crc = (crc<<1) & 0xffffffff;
            if(test)
                crc ^= algo_struct -> poly;
        }
    }
    if(algo_struct -> refOut)
        crc = reverseBits32(crc);
    crc ^= algo_struct -> xorOut;
    return crc;
}
