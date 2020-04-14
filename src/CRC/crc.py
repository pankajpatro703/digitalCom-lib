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

#n-bit CRC Hash algorithm 
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

#Different application types and their parameters
CRC8          = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_CDMA2000 = {'poly':0x9B, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_DARC     = {'poly':0x39, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_DVB_S2   = {'poly':0xD5, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_EBU      = {'poly':0x1D, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_I_CODE   = {'poly':0x1D, 'init':0xFD, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_ITU      = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55, 'size':8}
CRC8_MAXIM    = {'poly':0x31, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_ROHC     = {'poly':0x07, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_WCDMA    = {'poly':0x9B, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}

CRC16_CCITT_False    = {'poly':0x1021, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_ARC            = {'poly':0x8005, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_AUG_CCITT      = {'poly':0x1021, 'init':0x1D0F, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DVB_S2BUYPASS  = {'poly':0x8005, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_CDMA2000       = {'poly':0xC867, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DDS110         = {'poly':0x8005, 'init':0x800D, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DECT_R         = {'poly':0x0589, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0001, 'size':16}
CRC16_DECT_X         = {'poly':0x0589, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DNP            = {'poly':0x3D65, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_EN13757        = {'poly':0x3D65, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}
CRC16_GENIBUS        = {'poly':0x1021, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}
CRC16_MAXIM          = {'poly':0x8005, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_MCRF4XX        = {'poly':0x1021, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_RIELLO         = {'poly':0x1021, 'init':0xB2AA, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_T10_DIF        = {'poly':0x8BB7, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_TELEDISK       = {'poly':0xA097, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_TMS37157       = {'poly':0x1021, 'init':0x89EC, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_USB            = {'poly':0x8005, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_A              = {'poly':0x1021, 'init':0xC6C6, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_KERMIT         = {'poly':0x1021, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_MODBUS         = {'poly':0x8005, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_X25            = {'poly':0x1021, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_XMODEM         = {'poly':0x1021, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}

CRC32        = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_BZIP2  = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFF, 'size':32}
CRC32_C      = {'poly':0x1EDC6F41, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_D      = {'poly':0xA833982B, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_MPEG2  = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}
CRC32_POSIX  = {'poly':0x04C11DB7, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFF, 'size':32}
CRC32_Q      = {'poly':0x814141AB, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}
CRC32_JAMCRC = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x00000000, 'size':32}
CRC32_XFER   = {'poly':0x000000AF, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}

def getBinary(byte, size):
    '''
    This method returns the n-bit binary representation of a byte integer along with its reversed version.
    :param byte: original byte integer
    :param size: number of bits(n) required in output
    :return tuple 1: integer corresponding n-bit binary value of byte integer shifted to most significant byte 
    :return tuple 2: integer corresponding n-bit reversed binary value of byte integer shifted to most significant byte
    '''
    res = ''.join(format(byte,'b'))
    res2 = res[: : -1]
    res2 += '0' * (size - len(res2))
    return (int(res, 2) << (size - 8), int(res2, 2))

def getCRC(data, algo_list):
    '''
    This method obtains the CRC value of the data based on application.
    :param data: original string data
    :param algo_list: name of application algorithm
    :return crc: calculated integer value of crc
    '''
    size = algo_list['size']
    crc = algo_list['init']
    for byte in data:
        d = getBinary(ord(byte), size)[1] if algo_list['refIn'] else getBinary(ord(byte), size)[0]
        crc ^= d
        for i in range(8):
            test = (crc & (0x01 << (size - 1))) != 0
            crc = (crc << 1) & ((0x01 << (size)) - 1)
            if(test):
                crc ^= algo_list['poly']
    if(algo_list['refOut']):
        crc = getBinary(crc, size)[1]
    crc ^= algo_list['xorOut']
    return crc

if(__name__=='__main__'):
    message = 'Hello. This is the message.'
    
    #message = [0x23,0x11,0x43]         #for hex values
    #for i in range(len(message)):
        #message[i]=chr(message[i])
    
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
    
    print('16-bit CCITT-False CRC of the message is', format(getCRC(message, CRC16_CCITT_False),'04x'))
    print('16-bit ARC CRC of the message is', format(getCRC(message, CRC16_ARC),'04x'))
    print('16-bit AUG-CCITT CRC of the message is', format(getCRC(message, CRC16_AUG_CCITT),'04x'))
    print('16-bit DVB-S2BUYPASS CRC of the message is', format(getCRC(message, CRC16_DVB_S2BUYPASS),'04x'))
    print('16-bit CDMA2000 CRC of the message is', format(getCRC(message, CRC16_CDMA2000),'04x'))
    print('16-bit DDS110 CRC of the message is', format(getCRC(message, CRC16_DDS110),'04x'))
    print('16-bit DECT-R CRC of the message is', format(getCRC(message, CRC16_DECT_R),'04x'))
    print('16-bit DECT-X CRC of the message is', format(getCRC(message, CRC16_DECT_X),'04x'))
    print('16-bit DNP CRC of the message is', format(getCRC(message, CRC16_DNP),'04x'))
    print('16-bit EN13757 CRC of the message is', format(getCRC(message, CRC16_EN13757),'04x'))
    print('16-bit GENIBUS CRC of the message is', format(getCRC(message, CRC16_GENIBUS),'04x'))
    print('16-bit MAXIM CRC of the message is', format(getCRC(message, CRC16_MAXIM),'04x'))
    print('16-bit MCRF4XX CRC of the message is', format(getCRC(message, CRC16_MCRF4XX),'04x'))
    print('16-bit RIELLO CRC of the message is', format(getCRC(message, CRC16_RIELLO),'04x'))
    print('16-bit T10-DIF CRC of the message is', format(getCRC(message, CRC16_T10_DIF),'04x'))
    print('16-bit TELEDISK CRC of the message is', format(getCRC(message, CRC16_TELEDISK),'04x'))
    print('16-bit TMS37157 CRC of the message is', format(getCRC(message, CRC16_TMS37157),'04x'))
    print('16-bit USB CRC of the message is', format(getCRC(message, CRC16_USB),'04x'))
    print('16-bit A CRC of the message is', format(getCRC(message, CRC16_A),'04x'))
    print('16-bit KERMIT CRC of the message is', format(getCRC(message, CRC16_KERMIT),'04x'))
    print('16-bit MODBUS CRC of the message is', format(getCRC(message, CRC16_MODBUS),'04x'))
    print('16-bit X25 CRC of the message is', format(getCRC(message, CRC16_X25),'04x'))
    print('16-bit XMODEM CRC of the message is', format(getCRC(message, CRC16_XMODEM),'04x'))

    print('32-bit CRC of the message is', format(getCRC(message, CRC32),'08x'))
    print('32-bit BZIP2 CRC of the message is', format(getCRC(message, CRC32_BZIP2),'08x'))
    print('32-bit C CRC of the message is', format(getCRC(message, CRC32_C),'08x'))
    print('32-bit D CRC of the message is', format(getCRC(message, CRC32_D),'08x'))
    print('32-bit MPEG2 CRC of the message is', format(getCRC(message, CRC32_MPEG2),'08x'))
    print('32-bit POSIX CRC of the message is', format(getCRC(message, CRC32_POSIX),'08x'))
    print('32-bit Q CRC of the message is', format(getCRC(message, CRC32_Q),'08x'))
    print('32-bit JAMCRC CRC of the message is', format(getCRC(message, CRC32_JAMCRC),'08x'))
    print('32-bit XFER CRC of the message is', format(getCRC(message, CRC32_XFER),'08x'))
