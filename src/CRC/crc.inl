/**
 * @file         crc.inl
 * @brief        Cyclic Redundancy Check - CRC calculator
 * @author       pankajpatro703
 * @date         27.07.2020      //created
 * @date         11.08.2020      //modified
 * @version      1.0
 * @copyright    Copyright (C) 2020 Pankajkumar Patro
 * @license      GNU Lesser GPL v3.0+
 *
 * crc.inl - Inline file to calculate 8,16,32,64-bit CRC Hash value.
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

#include "crc.hpp"

template<typename T>
CRCbase<T> :: CRCbase(crcparam<T> &paramlist) {
    algo_struct = &paramlist;
    nbits = sizeof(crc_val) * 8;
}

template<typename T>
T CRCbase<T> :: reverseBits(T num) const {
    T revnum = 0;
    for (uint8_t i = 0; i < nbits; ++i) {
        if(num & (1 << i))
            revnum |= (1 << ((nbits - 1) - i));
    }
    return revnum;
}

template<typename T>
LiteCRC<T> :: LiteCRC(crcparam<T> &paramlist) : CRCbase<T>::CRCbase(paramlist) {
}

template<typename T>
inline void LiteCRC<T> :: initCRC() {
    CRCbase<T>::crc_val = CRCbase<T>::algo_struct -> init;
}

template<typename T>
inline void LiteCRC<T> :: updateCRC(uint8_t* s) {
    CRCbase<T>::crc_val ^= (CRCbase<T>::algo_struct -> refIn ? CRCbase<T>::reverseBits(*s) : *s << (CRCbase<T>::nbits - 8));
    for(uint8_t i = 0; i < 8; ++i) {
        bool test = (CRCbase<T>::crc_val & (1 << (CRCbase<T>::nbits - 1))) != 0;
        CRCbase<T>::crc_val <<= 1;
        if(test)
            CRCbase<T>::crc_val ^= CRCbase<T>::algo_struct -> poly;
    }
}

template<typename T>
inline T LiteCRC<T> :: fetchCRC() {
    if(CRCbase<T>::algo_struct -> refOut)
        CRCbase<T>::crc_val = CRCbase<T>::reverseBits(CRCbase<T>::crc_val);
    CRCbase<T>::crc_val ^= CRCbase<T>::algo_struct -> xorOut;
    return CRCbase<T>::crc_val;
}

template<typename T>
T LiteCRC<T> :: getCRC(uint8_t* s, size_t length) {
    initCRC();
    for(size_t i = 0; i < length; ++i)
        updateCRC(s+i);
    return fetchCRC();
}

template<typename T>
FastCRC<T> :: FastCRC(crcparam<T> &paramlist) : CRCbase<T>::CRCbase(paramlist) {
    hbits = CRCbase<T>::nbits - 8;
    M1 = (1 << hbits) - 1;
    M2 = ((1 << CRCbase<T>::nbits) - 1) - 0xff;
    if(CRCbase<T>::algo_struct -> refIn) {
        newpoly = CRCbase<T>::reverseBits(CRCbase<T>::algo_struct -> poly);
        for(uint16_t i = 0; i < 256; ++i) {
            table[i] = i;
            for(uint8_t j = 0; j < 8; ++j) {
                if(table[i] & 1)
                    table[i] = (table[i] >> 1) ^ newpoly;
                else
                    table[i] >>= 1;
            }
        }
    }
    else {
        newpoly = CRCbase<T>::algo_struct -> poly;
        for(uint16_t i = 0; i < 256; ++i) {
            table[i] = i << hbits;
            for(uint8_t j = 0; j < 8; j++) {
                if(table[i] & (1 << (CRCbase<T>::nbits - 1)))
                    table[i] = (table[i] << 1) ^ newpoly;
                else
                    table[i] <<= 1;
            }
        }
    }
}

template<typename T>
inline void FastCRC<T> :: initCRC() {
    CRCbase<T>::crc_val = CRCbase<T>::algo_struct -> refIn ? CRCbase<T>::reverseBits(CRCbase<T>::algo_struct -> init) : CRCbase<T>::algo_struct -> init;
}

template<typename T>
inline void FastCRC<T> :: updateCRC(uint8_t* s) {
    if(CRCbase<T>::algo_struct -> refOut)
        CRCbase<T>::crc_val = ((CRCbase<T>::crc_val >> 8) & M1) ^ table[(CRCbase<T>::crc_val & 0xff) ^ *s];
    else
        CRCbase<T>::crc_val = ((CRCbase<T>::crc_val << 8) & M2) ^ table[((CRCbase<T>::crc_val >> hbits) & 0xff) ^ *s];
}

template<typename T>
inline T FastCRC<T> :: fetchCRC() {
    CRCbase<T>::crc_val ^= CRCbase<T>::algo_struct -> xorOut;
    return CRCbase<T>::crc_val;
}

template<typename T>
T FastCRC<T> :: getCRC(uint8_t* s, size_t length) {
    initCRC();
    for(size_t i = 0; i < length; ++i)
        updateCRC(s+i);
    return fetchCRC();
}
