#    Copyright 2020 Pankajkumar Patro

#    This file is part of digitalCom-lib.

#    digitalCom-lib is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    digitalCom-lib is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.

#    You should have received a copy of the GNU Lesser General Public License
#    along with digitalCom-lib.  If not, see <https://www.gnu.org/licenses/>.

#8-bit CRC Hash algorithm 
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

#Different application types and their parameters
CRC8          = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00}
CRC8_CDMA2000 = {'poly':0x9B, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0x00}
CRC8_DARC     = {'poly':0x39, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00}
CRC8_DVB_S2   = {'poly':0xD5, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00}
CRC8_EBU      = {'poly':0x1D, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00}
CRC8_I_CODE   = {'poly':0x1D, 'init':0xFD, 'refIn':False, 'refOut':False, 'xorOut':0x00}
CRC8_ITU      = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55}
CRC8_MAXIM    = {'poly':0x31, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00}
CRC8_ROHC     = {'poly':0x07, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00}
CRC8_WCDMA    = {'poly':0x9B, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00}

def getBinary(string):
    '''
    This method returns the binary(ASCII) representation of a string along with its reversed version.
    :param string: original string or character
    :return tuple 1: binary(ASCII) value of string
    :return tuple 2: reversed binary(ASCII) value of string
    '''
    res = ''.join(format(ord(i),'b') for i in string)
    res2 = res[::-1]
    res2 += '0' * (8 - len(res2))
    return (int(res,2), int(res2,2))

def getCRC(data, algo_list):
    '''
    This method obtains the 8-bit CRC value of the data based on application.
    :param data: original string data
    :param algo_list: name of application algorithm
    :return crc: calculated integer value of 8-bit crc
    '''
    crc = algo_list['init']
    for byte in data:
        d = getBinary(byte)[1] if algo_list['refIn'] else getBinary(byte)[0]
        crc ^= d
        for i in range(8):
            test = (crc & 0x80) != 0
            crc = (crc<<1) & 0xff
            if(test):
                crc ^= algo_list['poly']
    if(algo_list['refOut']):
        crc = getBinary(chr(crc))[1]
    crc ^= algo_list['xorOut']
    return crc

if(__name__=='__main__'):
    message = 'Hello. This is the message.'
    print('8-bit CRC of the message is', format(getCRC(message, CRC8),'02x'))
    print('8-bit CDMA2000 CRC of the message is', format(getCRC(message, CRC8_CDMA2000),'02x'))
    print('8-bit DARC CRC of the message is', format(getCRC(message, CRC8_DARC),'02x'))
    print('8-bit DVB-S2 CRC of the message is', format(getCRC(message, CRC8_DVB_S2),'02x'))
    print('8-bit EBU CRC of the message is', format(getCRC(message, CRC8_EBU),'02x'))
    print('8-bit I-code CRC of the message is', format(getCRC(message, CRC8_I_CODE),'02x'))
    print('8-bit ITU CRC of the message is', format(getCRC(message, CRC8_ITU),'02x'))
    print('8-bit MAXIM CRC of the message is', format(getCRC(message, CRC8_MAXIM),'02x'))
    print('8-bit ROHC CRC of the message is', format(getCRC(message, CRC8_ROHC),'02x'))
    print('8-bit WCDMA CRC of the message is', format(getCRC(message, CRC8_WCDMA),'02x'))
