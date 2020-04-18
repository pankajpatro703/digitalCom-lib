/*
*    Copyright 2020 Pankajkumar Patro
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

//32-bit CRC Hash algorithm 
//////////////////////////////////
//   @Author: pankajpatro703    //
// Licensed under Lesser GPL v3 //
//////////////////////////////////

#ifndef CRC32_H
#define CRC32_H

#include<stdbool.h>
#include<stdint.h>

struct algorithm32 {
    /*
    This structure defines the parameters required for algorithms used for different applications.
    */
    uint32_t poly, init, xorOut;
    bool refIn, refOut;
};

//Different application types and their parameters
struct algorithm32 CRC32        = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF}; 
struct algorithm32 CRC32_BZIP2  = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF}; 
struct algorithm32 CRC32_C      = {.poly=0x1EDC6F41, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF}; 
struct algorithm32 CRC32_D      = {.poly=0xA833982B, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFFFFFF}; 
struct algorithm32 CRC32_MPEG2  = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=false, .refOut=false, .xorOut=0x00000000}; 
struct algorithm32 CRC32_POSIX  = {.poly=0x04C11DB7, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0xFFFFFFFF}; 
struct algorithm32 CRC32_Q      = {.poly=0x814141AB, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000}; 
struct algorithm32 CRC32_JAMCRC = {.poly=0x04C11DB7, .init=0xFFFFFFFF, .refIn=true,  .refOut=true,  .xorOut=0x00000000}; 
struct algorithm32 CRC32_XFER   = {.poly=0x000000AF, .init=0x00000000, .refIn=false, .refOut=false, .xorOut=0x00000000}; 

uint32_t reverseBits32(uint32_t num) {
    /*
    This function returns the 32-bit number obtained by reversing the bit sequence of input number.
    :param uint32_t num: original 32-bit integer to be reversed
    :return uint32_t revnum: reversed 32-bit number 
    */ 
    uint32_t  NoOfBits = sizeof(num) * 8;
    uint32_t revnum = 0, i, temp; 
    for (i = 0; i < NoOfBits; i++) { 
        temp = (num & (1 << i)); 
        if(temp) 
            revnum |= (1 << ((NoOfBits - 1) - i)); 
    }
    return revnum; 
} 

uint32_t getCRC32(uint8_t *s, struct algorithm32 algo_struct, int length) {
    /*
    This function calculates the 32-bit CRC for a given string.
    :param uint8_t *s: data(byte array) on which the CRC is to be calculated
    :param struct algorithm16 algo_struct: struct defining the algorithm parameters
    :param int length: length of the message
    :return uint32_t crc: calculated 32-bit CRC
    */
    uint32_t d, test, crc = algo_struct.init;
    unsigned int i, j;
    for(i=0; i<length; i++) {
        d = algo_struct.refIn ? reverseBits32(s[i]) : s[i] << 24;
        crc ^= d;
        for(j=0; j<8; j++) {
            test = (crc & 0x80000000) != 0;
            crc = (crc<<1) & 0xffffffff;
            if(test)
                crc ^= algo_struct.poly;
        }
    }
    if(algo_struct.refOut)
        crc = reverseBits32(crc);
    crc ^= algo_struct.xorOut;
    return crc;
}

#endif

