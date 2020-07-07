/**
 * @file         lrc.h
 * @brief        Longitutdinal Redundancy Check
 * @author       pankajpatro703
 * @date         10.06.2020      //created
 * @date         07.07.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    lrc.h - Header file to calculate LRC.
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

#ifndef LRC_H
#define LRC_H

#include<stdbool.h>
#include<stdint.h>

/**
 *  Calculates the LRC for a given string.
 *  @param s data(byte array) on which the LRC is to be calculated
 *  @param length length of the message
 *  @return calculated 8-bit LRC
 *
 *  Example:
 *  @code
 *  #include "lrc.h"
 *  void main() {
 *      char message1[] = "Enter data here";
 *      unsigned int length1 = sizeof(message1)-1;
 *      char message2[] = {0x3A,0x2B,0x11};
 *      unsigned int length2 = sizeof(message2);
 *      printf("LRC of message1 is %02x\n",getLRC(message1, length1));
 *      printf("LRC of message2 is %02x\n",getLRC(message2, length2));
 *  }
 *  @endcode
 */
uint8_t getLRC(uint8_t *s, int length);

#endif
