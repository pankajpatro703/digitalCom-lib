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

//16-bit CRC Hash algorithm 
//////////////////////////////////
//   @Author: pankajpatro703    //
// Licensed under Lesser GPL v3 //
//////////////////////////////////

#include<stdbool.h>
#include<stdint.h>

struct algorithm16 {
    /*
    This structure defines the parameters required for algorithms used for different applications.
    */
    uint16_t poly, init, xorOut;
    bool refIn, refOut;
};

//Different application types and their parameters
struct algorithm16 CRC16_CCITT_FALSE    = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_ARC            = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_AUG_CCITT      = {.poly=0x1021, .init=0x1D0F, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_DVB_S2BUYPASS  = {.poly=0x8005, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_CDMA2000       = {.poly=0xC867, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_DDS110         = {.poly=0x8005, .init=0x800D, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_DECT_R         = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0001}; 
struct algorithm16 CRC16_DECT_X         = {.poly=0x0589, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_DNP            = {.poly=0x3D65, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF}; 
struct algorithm16 CRC16_EN13757        = {.poly=0x3D65, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0xFFFF}; 
struct algorithm16 CRC16_GENIBUS        = {.poly=0x1021, .init=0xFFFF, .refIn=false, .refOut=false, .xorOut=0xFFFF}; 
struct algorithm16 CRC16_MAXIM          = {.poly=0x8005, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0xFFFF}; 
struct algorithm16 CRC16_MCRF4XX        = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_RIELLO         = {.poly=0x1021, .init=0xB2AA, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_T10_DIF        = {.poly=0x8BB7, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_TELEDISK       = {.poly=0xA097, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000}; 
struct algorithm16 CRC16_TMS37157       = {.poly=0x1021, .init=0x89EC, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_USB            = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF}; 
struct algorithm16 CRC16_A              = {.poly=0x1021, .init=0xC6C6, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_KERMIT         = {.poly=0x1021, .init=0x0000, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_MODBUS         = {.poly=0x8005, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0x0000}; 
struct algorithm16 CRC16_X25            = {.poly=0x1021, .init=0xFFFF, .refIn=true,  .refOut=true,  .xorOut=0xFFFF}; 
struct algorithm16 CRC16_XMODEM         = {.poly=0x1021, .init=0x0000, .refIn=false, .refOut=false, .xorOut=0x0000};

uint16_t reverseBits16(uint16_t num) {
    /*
    This function returns the 16-bit number obtained by reversing the bit sequence of input number.
    :param uint16_t num: original 16-bit integer to be reversed
    :return uint16_t revnum: reversed 16-bit number 
    */ 
    uint16_t  NoOfBits = sizeof(num) * 8;
    uint16_t revnum = 0, i, temp; 
    for (i = 0; i < NoOfBits; i++) { 
        temp = (num & (1 << i)); 
        if(temp) 
            revnum |= (1 << ((NoOfBits - 1) - i)); 
    }
    return revnum; 
} 

uint16_t getCRC16(uint8_t *s, struct algorithm16 algo_struct, int length) {
    /*
    This function calculates the 16-bit CRC for a given string.
    :param uint8_t *s: data(byte array) on which the CRC is to be calculated
    :param struct algorithm16 algo_struct: struct defining the algorithm parameters
    :param int length: length of the message
    :return uint16_t crc: calculated 16-bit CRC
    */
    uint16_t d, test, crc = algo_struct.init;
    unsigned int i, j;
    for(i=0; i<length; i++) {
        d = algo_struct.refIn ? reverseBits16(s[i]) : s[i] << 8;
        crc ^= d;
        for(j=0; j<8; j++) {
            test = (crc & 0x8000) != 0;
            crc = (crc<<1) & 0xffff;
            if(test)
                crc ^= algo_struct.poly;
        }
    }
    if(algo_struct.refOut)
        crc = reverseBits16(crc);
    crc ^= algo_struct.xorOut;
    return crc;
}