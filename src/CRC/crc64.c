/**
 * @file         crc64.c
 * @brief        Cyclic Redundancy Check - 64-bit CRC calculator
 * @author       pankajpatro703
 * @date         20.06.2020      //created
 * @date         20.06.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    crc64.c - Description file to calculate 64-bit CRC Hash value.
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

#include "crc64.h"

algorithm64 CRC64_ECMA_182  = {.poly=0x42F0E1EBA9EA3693, .init=0x0000000000000000, .refIn=false, .refOut=false, .xorOut=0x0000000000000000};
algorithm64 CRC64_GO_ISO    = {.poly=0x000000000000001B, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};
algorithm64 CRC64_WE        = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFFFFFFFFFF};
algorithm64 CRC64_XZ        = {.poly=0x42F0E1EBA9EA3693, .init=0xFFFFFFFFFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFFFFFFFFFF};

uint64_t reverseBits64(uint64_t num) {
    uint64_t  NoOfBits = sizeof(num) * 8;
    uint64_t revnum = 0, i, temp;
    for (i = 0; i < NoOfBits; i++) {
        temp = (num & (1 << i));
        if(temp)
            revnum |= (1 << ((NoOfBits - 1) - i));
    }
    return revnum;
}

uint64_t getCRC64(uint8_t *s, algorithm64 *algo_struct, unsigned int length) {
    uint64_t d, test, crc = algo_struct -> init;
    unsigned int i, j;
    for(i=0; i<length; i++) {
        d = algo_struct -> refIn ? reverseBits64(*(s + i)) : *(s + i) << 56;
        crc ^= d;
        for(j=0; j<8; j++) {
            test = (crc & 0x8000000000000000) != 0;
            crc = (crc<<1) & 0xffffffffffffffff;
            if(test)
                crc ^= algo_struct -> poly;
        }
    }
    if(algo_struct -> refOut)
        crc = reverseBits64(crc);
    crc ^= algo_struct -> xorOut;
    return crc;
}
