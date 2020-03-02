/*
*    This file is part of DigiCom-algorithms.
*    
*    DigiCom-algorithms is free software: you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*    
*    DigiCom-algorithms is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with DigiCom-algorithms.  If not, see <https://www.gnu.org/licenses/>.
*/

//8-bit CRC Hash algorithm 
//////////////////////////////////
//   @Author: pankajpatro703    //
// Licensed under Lesser GPL v3 //
//////////////////////////////////

#include<string.h>
#include<stdbool.h>
#include<stdint.h>

struct algorithm {
	/*
	This structure defines the parameters required for algorithms used for different applications.
	*/
    uint8_t poly, init, xorOut;
    bool refIn, refOut;
};

//Different application types and their parameters
struct algorithm CRC8           = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00}; 
struct algorithm CRC8_CDMA2000  = {.poly=0x9B, .init=0xFF, .refIn=false, .refOut=false, .xorOut=0x00}; 
struct algorithm CRC8_DARC      = {.poly=0x39, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00}; 
struct algorithm CRC8_DVB_S2    = {.poly=0xD5, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x00}; 
struct algorithm CRC8_EBU       = {.poly=0x1D, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00}; 
struct algorithm CRC8_I_CODE    = {.poly=0x1D, .init=0xFD, .refIn=false, .refOut=false, .xorOut=0x00}; 
struct algorithm CRC8_ITU       = {.poly=0x07, .init=0x00, .refIn=false, .refOut=false, .xorOut=0x55}; 
struct algorithm CRC8_MAXIM     = {.poly=0x31, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00}; 
struct algorithm CRC8_ROHC      = {.poly=0x07, .init=0xFF, .refIn=true,  .refOut=true,  .xorOut=0x00}; 
struct algorithm CRC8_WCDMA     = {.poly=0x9B, .init=0x00, .refIn=true,  .refOut=true,  .xorOut=0x00}; 

uint8_t reverseBits(uint8_t num) {
	/*
	This function returns the 8-bit number obtained by reversing the bit sequence of input number.
	:param uint8_t num: original 8-bit integer to be reversed
	:return uint8_t revnum: reversed 8-bit number 
	*/ 
    uint8_t  NoOfBits = sizeof(num) * 8;
    uint8_t revnum = 0, i, temp; 
    for (i = 0; i < NoOfBits; i++) { 
        temp = (num & (1 << i)); 
        if(temp) 
            revnum |= (1 << ((NoOfBits - 1) - i)); 
    }
    return revnum; 
} 

uint8_t getCRC(char *s, struct algorithm algo_struct) {
	/*
	This function calculates the 8-bit CRC for a given string.
	:param char *s: string(char array) on which the CRC is to be calculated
	:param struct algorithm algo_struct: struct defining the algorithm parameters
	:return uint8_t crc: calculated 8-bit CRC
	*/
    uint8_t d, test, crc = algo_struct.init;
    unsigned int i, j;
    for(i=0; i<strlen(s); i++) {
        d = algo_struct.refIn ? reverseBits(s[i]) : s[i];
        crc ^= d;
        for(j=0;j<8;j++) {
            test = (crc & 0x80) != 0;
            crc = (crc<<1) & 0xff;
            if(test)
                crc ^= algo_struct.poly;
        }
    }
    if(algo_struct.refOut)
        crc = reverseBits(crc);
    crc ^= algo_struct.xorOut;
    return crc;
}
