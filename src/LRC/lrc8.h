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

//8-bit LRC Hash algorithm 
//////////////////////////////////
//   @Author: pankajpatro703    //
// Licensed under Lesser GPL v3 //
//////////////////////////////////

#ifndef LRC_H
#define LRC_H

#include<stdbool.h>
#include<stdint.h>

uint8_t getLRC8(uint8_t *s, int length) {
    /*
    This function calculates the 8-bit LRC for a given string.
    :param uint8_t *s: data(byte array) on which the LRC is to be calculated
    :param int length: length of the message
    :return uint8_t lrc: calculated 8-bit LRC
    */
    uint8_t lrc = 0;
    unsigned int i, j;
    for(i=0; i<length; i++) {
        lrc = (lrc ^ s[i]) & 0xFF;
    }
    return lrc;
}

#endif
