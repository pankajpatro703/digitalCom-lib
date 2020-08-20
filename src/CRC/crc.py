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
CRC8_AUTOSAR        = {'poly':0x2F, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0xFF, 'size':8}
CRC8_BLUETOOTH      = {'poly':0xA7, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_CDMA2000       = {'poly':0x9B, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_DARC           = {'poly':0x39, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_DVB_S2         = {'poly':0xD5, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_EBU            = {'poly':0x1D, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_GSM_A          = {'poly':0x1D, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_GSM_B          = {'poly':0x49, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0xFF, 'size':8}
CRC8_ITU            = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55, 'size':8}
CRC8_I_CODE         = {'poly':0x1D, 'init':0xFD, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_LTE            = {'poly':0x9B, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_MAXIM          = {'poly':0x31, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_MIFARE_MAD     = {'poly':0x1D, 'init':0xC7, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_NRSC_5         = {'poly':0x31, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_OPENSAFETY     = {'poly':0x2F, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_ROHC           = {'poly':0x07, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}
CRC8_SAE_J1850      = {'poly':0x1D, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0xFF, 'size':8}
CRC8_SMBUS          = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}
CRC8_WCDMA          = {'poly':0x9B, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}

CRC16_A             = {'poly':0x1021, 'init':0xC6C6, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_ARC           = {'poly':0x8005, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_AUG_CCITT     = {'poly':0x1021, 'init':0x1D0F, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_B             = {'poly':0x1021, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_CCITT_FALSE   = {'poly':0x1021, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_CDMA2000      = {'poly':0xC867, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_CMS           = {'poly':0x8005, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DDS_110       = {'poly':0x8005, 'init':0x800D, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DECT_R        = {'poly':0x0589, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0001, 'size':16}
CRC16_DECT_X        = {'poly':0x0589, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_DNP           = {'poly':0x3D65, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_EN_13757      = {'poly':0x3D65, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}
CRC16_GENIBUS       = {'poly':0x1021, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}
CRC16_GSM           = {'poly':0x1021, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}
CRC16_KERMIT        = {'poly':0x1021, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_LJ1200        = {'poly':0x6F63, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_MAXIM         = {'poly':0x8005, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_MCRF4XX       = {'poly':0x1021, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_MODBUS        = {'poly':0x8005, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_NRSC_5        = {'poly':0x080B, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_OPENSAFETY_A  = {'poly':0x5935, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_OPENSAFETY_B  = {'poly':0x755B, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_PROFIBUS      = {'poly':0x1DCF, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}
CRC16_RIELLO        = {'poly':0x1021, 'init':0xB2AA, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_T10_DIF       = {'poly':0x8BB7, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_TELEDISK      = {'poly':0xA097, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_TMS37157      = {'poly':0x1021, 'init':0x89EC, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}
CRC16_UMTS          = {'poly':0x8005, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}
CRC16_USB           = {'poly':0x8005, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}
CRC16_XMODEM        = {'poly':0x1021, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}

CRC32_ADCCP         = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_AUTOSAR       = {'poly':0xF4ACFB13, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_BZIP2         = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFF, 'size':32}
CRC32_C             = {'poly':0x1EDC6F41, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_CD_ROM_EDC    = {'poly':0x8001801B, 'init':0x00000000, 'refIn':True,  'refOut':True,  'xorOut':0x00000000, 'size':32}
CRC32_D             = {'poly':0xA833982B, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}
CRC32_JAMCRC        = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x00000000, 'size':32}
CRC32_MPEG2         = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}
CRC32_POSIX         = {'poly':0x04C11DB7, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFF, 'size':32}
CRC32_Q             = {'poly':0x814141AB, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}
CRC32_XFER          = {'poly':0x000000AF, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}

CRC64_ECMA_182      = {'poly':0x42F0E1EBA9EA3693, 'init':0x0000000000000000, 'refIn':False, 'refOut':False, 'xorOut':0x0000000000000000, 'size':64};
CRC64_GO_ISO        = {'poly':0x000000000000001B, 'init':0xFFFFFFFFFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFFFFFFFFFF, 'size':64};
CRC64_WE            = {'poly':0x42F0E1EBA9EA3693, 'init':0xFFFFFFFFFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFFFFFFFFFF, 'size':64};
CRC64_XZ            = {'poly':0x42F0E1EBA9EA3693, 'init':0xFFFFFFFFFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFFFFFFFFFF, 'size':64};

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
