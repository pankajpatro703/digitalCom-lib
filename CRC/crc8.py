#    This file is part of DigiCom-algorithms.

#    DigiCom-algorithms is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    DigiCom-algorithms is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.

#    You should have received a copy of the GNU Lesser General Public License
#    along with DigiCom-algorithms.  If not, see <https://www.gnu.org/licenses/>.

#8-bit CRC Hash algorithm 
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

#Different application types and their parameters
#[poly, init, refIn, refOut, xorOut, check, name]
CRC8          = [0x07, 0x00, False, False, 0x00, 0xF4]
CRC8_CDMA2000 = [0x9B, 0xFF, False, False, 0x00, 0xDA]
CRC8_DARC     = [0x39, 0x00, True, True, 0x00, 0x15]
CRC8_DVB_S2   = [0xD5, 0x00, False, False, 0x00, 0xBC]
CRC8_EBU      = [0x1D, 0xFF, True, True, 0x00, 0x97]
CRC8_I_CODE   = [0x1D, 0xFD, False, False, 0x00, 0x7E]
CRC8_ITU      = [0x07, 0x00, False, False, 0x55, 0xA1]
CRC8_MAXIM    = [0x31, 0x00, True, True, 0x00, 0xA1]
CRC8_ROHC     = [0x07, 0xFF, True, True, 0x00, 0xD0]
CRC8_WCDMA    = [0x9B, 0x00, True, True, 0x00, 0x25]

def getBinary(string):
    '''
    This method returns the binary(ASCII) representation of a string along with its reversed version.
    :param string: original string or character
    :return tuple 1: binary(ASCII) value of string
    :return tuple 2: reversed binary(ASCII) value of string
    '''
    res = ''.join(format(ord(i),'b') for i in string)
    res2 = res[::-1]
    while(len(res2)<8):
        res2 = res2 + '0'
    return (int(res,2), int(res2,2))

def getCRC(data, algo_list):
    '''
    This method obtains the 8-bit CRC value of the data based on application.
    :param data: original string data
    :param algo_list: name of application algorithm
    :return crc: calculated integer value of 8-bit crc
    '''
    crc = algo_list[1]
    for byte in data:
        d = getBinary(byte)[0]
        if(algo_list[2]):
            d = getBinary(byte)[1]
        crc = crc ^ d
        for i in range(8):
            test = crc & 0x80 != 0
            crc = (crc<<1) & 0xff
            if(test):
                crc ^= algo_list[0]
    if(algo_list[3]):
        crc = getBinary(chr(crc))[1]
    crc = crc ^ algo_list[4]
    return crc

if(__name__=='__main__'):
    print(format(getCRC('Hello. This is the message.', CRC8),'x'))
    print(getCRC('Hello. This is the message.', CRC8))