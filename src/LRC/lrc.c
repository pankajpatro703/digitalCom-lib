/**
 * @file         lrc.c
 * @brief        Longitutdinal Redundancy Check
 * @author       pankajpatro703
 * @date         10.06.2020      //created
 * @date         07.07.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 *    sdes.c - Description file to calculate LRC.
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

#include "lrc.h"

uint8_t getLRC(uint8_t *s, int length) {
    uint8_t lrc = 0;
    for(unsigned int i=0; i<length; i++) {
        lrc = (lrc ^ *(s + i)) & 0xFF;
    }
    return lrc;
}
