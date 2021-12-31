##
 # @file        crc.py
 # @brief       Cyclic Redundancy Check - CRC calculator
 # @author      pankajpatro703
 # @date        14.04.2020      //created
 # @date        31.12.2021      //modified
 # @version     1.0.2
 # @copyright   Copyright (C) 2020, 2021 Pankajkumar Patro
 # @license     GNU Lesser GPL v3.0+
 # @see         https://github.com/pankajpatro703/digitalCom-lib
 #
 # crc.py - File to calculate 8,16,32,64-bit CRC Hash value.
 #
 # Copyright (C) 2020 Pankajkumar Patro
 #
 # This file is part of digitalCom-lib.
 #
 # digitalCom-lib is free software: you can redistribute it and/or modify
 # it under the terms of the GNU Lesser General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
 # (at your option) any later version.
 #
 # digitalCom-lib is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public License
 # along with digitalCom-lib.  If not, see <https://www.gnu.org/licenses/>.
 #

CRC8_AUTOSAR        = {'poly':0x2F, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0xFF, 'size':8}                                                ###! AUTOSAR standard
CRC8_BLUETOOTH      = {'poly':0xA7, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}                                                ###! Bluetooth HEC
CRC8_CDMA2000       = {'poly':0x9B, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! CDMA2000 PHY standard
CRC8_DARC           = {'poly':0x39, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}                                                ###! Data Radio Channel
CRC8_DVB_S2         = {'poly':0xD5, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! Digital Video Broadcasting - Satellite - 2nd Gen
CRC8_EBU            = {'poly':0x1D, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}                                                ###! AES/EBU TECH-3250
CRC8_GSM_A          = {'poly':0x1D, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! GSM - A
CRC8_GSM_B          = {'poly':0x49, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0xFF, 'size':8}                                                ###! GSM - B
CRC8_ITU            = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55, 'size':8}                                                ###! ATM HEC I-432-1
CRC8_I_CODE         = {'poly':0x1D, 'init':0xFD, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! Philips Semiconductors SL2 ICS11
CRC8_LTE            = {'poly':0x9B, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! 3GPP
CRC8_MAXIM          = {'poly':0x31, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}                                                ###! MAXIM-DOW
CRC8_MIFARE_MAD     = {'poly':0x1D, 'init':0xC7, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! MIFARE application directory
CRC8_NRSC_5         = {'poly':0x31, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! HD Radio PHY standard
CRC8_OPENSAFETY     = {'poly':0x2F, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! OpenSAFETY standard
CRC8_ROHC           = {'poly':0x07, 'init':0xFF, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}                                                ###! Robust Header Compression
CRC8_SAE_J1850      = {'poly':0x1D, 'init':0xFF, 'refIn':False, 'refOut':False, 'xorOut':0xFF, 'size':8}                                                ###! SAE standard
CRC8_SMBUS          = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x00, 'size':8}                                                ###! System Management BUS
CRC8_WCDMA          = {'poly':0x9B, 'init':0x00, 'refIn':True,  'refOut':True,  'xorOut':0x00, 'size':8}                                                ###! WCDMA embedded networks standard

CRC16_A             = {'poly':0x1021, 'init':0xC6C6, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! ISO-IEC-14443-3-A
CRC16_ARC           = {'poly':0x8005, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! LHA
CRC16_AUG_CCITT     = {'poly':0x1021, 'init':0x1D0F, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! SPI Fujitsu Semiconductors
CRC16_B             = {'poly':0x1021, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}                                         ###! ISO-HDLC IEC-14443-3-B X-25
CRC16_CCITT_FALSE   = {'poly':0x1021, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! AUTOSAR, IBM-3740
CRC16_CDMA2000      = {'poly':0xC867, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! 3GPP2
CRC16_CMS           = {'poly':0x8005, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! RPM packages
CRC16_DDS_110       = {'poly':0x8005, 'init':0x800D, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! ELV function generator
CRC16_DECT_R        = {'poly':0x0589, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0001, 'size':16}                                         ###! ETSI EN 300 175-3
CRC16_DECT_X        = {'poly':0x0589, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! ETSI EN 300 175-3
CRC16_DNP           = {'poly':0x3D65, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}                                         ###! Distributed Network Protocol
CRC16_EN_13757      = {'poly':0x3D65, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}                                         ###! Wireless M-Bus protocol
CRC16_GENIBUS       = {'poly':0x1021, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}                                         ###! DARC, EPC-C1G2, I-CODE
CRC16_GSM           = {'poly':0x1021, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}                                         ###! GSM
CRC16_KERMIT        = {'poly':0x1021, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! V-41-LSB
CRC16_LJ1200        = {'poly':0x6F63, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! SDRTrunk
CRC16_MAXIM         = {'poly':0x8005, 'init':0x0000, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}                                         ###! MAXIM-DOW
CRC16_MCRF4XX       = {'poly':0x1021, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! MCRF45X device
CRC16_MODBUS        = {'poly':0x8005, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! MODBUS
CRC16_NRSC_5        = {'poly':0x080B, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! HD Radio PHY standard
CRC16_OPENSAFETY_A  = {'poly':0x5935, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! OpenSAFETY standard A
CRC16_OPENSAFETY_B  = {'poly':0x755B, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! OpenSAFETY standard B
CRC16_PROFIBUS      = {'poly':0x1DCF, 'init':0xFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFF, 'size':16}                                         ###! IEC-61158-2
CRC16_RIELLO        = {'poly':0x1021, 'init':0xB2AA, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! Riello Dialog UPS
CRC16_T10_DIF       = {'poly':0x8BB7, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! SCSI Data Integrity Field
CRC16_TELEDISK      = {'poly':0xA097, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! Teledisk disc archive format
CRC16_TMS37157      = {'poly':0x1021, 'init':0x89EC, 'refIn':True,  'refOut':True,  'xorOut':0x0000, 'size':16}                                         ###! TI TMS37157
CRC16_UMTS          = {'poly':0x8005, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! BUYPASS VERIFONE
CRC16_USB           = {'poly':0x8005, 'init':0xFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFF, 'size':16}                                         ###! USB
CRC16_XMODEM        = {'poly':0x1021, 'init':0x0000, 'refIn':False, 'refOut':False, 'xorOut':0x0000, 'size':16}                                         ###! ACORN, LTE, V-41-MSB, ZMODEM

CRC32_ADCCP         = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}                             ###! ISO-HDLC, V-42, XZ, PKZIP
CRC32_AUTOSAR       = {'poly':0xF4ACFB13, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}                             ###! AUTOSAR
CRC32_BZIP2         = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFF, 'size':32}                             ###! AAL5, DECT-B
CRC32_C             = {'poly':0x1EDC6F41, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}                             ###! ISCSI, BASE91-C, CASTAGNOLI, INTERLAKEN
CRC32_CD_ROM_EDC    = {'poly':0x8001801B, 'init':0x00000000, 'refIn':True,  'refOut':True,  'xorOut':0x00000000, 'size':32}                             ###! CD-ROM-EDC
CRC32_D             = {'poly':0xA833982B, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFF, 'size':32}                             ###! BASE91-D
CRC32_JAMCRC        = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0x00000000, 'size':32}                             ###! Altera Megacore
CRC32_MPEG2         = {'poly':0x04C11DB7, 'init':0xFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}                             ###! Video LAN
CRC32_POSIX         = {'poly':0x04C11DB7, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFF, 'size':32}                             ###! CKSUM
CRC32_Q             = {'poly':0x814141AB, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}                             ###! Aeronautical Information Exchange Model
CRC32_XFER          = {'poly':0x000000AF, 'init':0x00000000, 'refIn':False, 'refOut':False, 'xorOut':0x00000000, 'size':32}                             ###! XFER

CRC64_ECMA_182      = {'poly':0x42F0E1EBA9EA3693, 'init':0x0000000000000000, 'refIn':False, 'refOut':False, 'xorOut':0x0000000000000000, 'size':64}     ###! DLT-1 cartridges
CRC64_GO_ISO        = {'poly':0x000000000000001B, 'init':0xFFFFFFFFFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFFFFFFFFFF, 'size':64}     ###! Go-lang
CRC64_WE            = {'poly':0x42F0E1EBA9EA3693, 'init':0xFFFFFFFFFFFFFFFF, 'refIn':False, 'refOut':False, 'xorOut':0xFFFFFFFFFFFFFFFF, 'size':64}     ###! Wolfgang Ehrhardt plugin
CRC64_XZ            = {'poly':0x42F0E1EBA9EA3693, 'init':0xFFFFFFFFFFFFFFFF, 'refIn':True,  'refOut':True,  'xorOut':0xFFFFFFFFFFFFFFFF, 'size':64}     ###! GO-ECMA

class CRCbase(object):
    '''!
     @brief Base class for CRC calculation algorithms
    '''
    def __init__(self, paramlist):
        '''!
         @brief Initializes algorithm reference.
         @param paramlist crc parameter dict

         Example:
         @code
         import crc
         CRC8_new = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55, 'size':8}
         new_crc = crc.CRCbase(CRC8_new)
         @endcode
        '''
        self.__algo_dict = paramlist
        self.__nbits = self.__algo_dict['size']

    def __reverseBits(self, num):
        '''!
         @brief Calculates the number obtained by reversing the bit sequence of input number.
         @param num original n-bit integer to be reversed
         @return reversed n-bit integer value
        '''
        revs = ''.join(format(num, 'b'))[: : -1]
        revs += '0' * (self.__nbits - len(revs))
        return int(revs, 2)

class LiteCRC(CRCbase):
    '''!
     @brief Class for low memory CRC calculation algorithms.
    '''
    def __init__(self, paramlist):
        '''!
         @brief Initializes algorithm reference.
         @param paramlist crc parameter dict

         Example:
         @code
         import crc
         CRC8_new = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55, 'size':8}
         new_crc = crc.LiteCRC(CRC8_new)
         @endcode
        '''
        super(LiteCRC, self).__init__(paramlist)

    def initCRC(self):
        '''!
         @brief Initializes the crc value as per the algorithm parameter.

         Example:
         @code
         import crc
         new_crc.initCRC()
         @endcode
        '''
        self.__crc_val = self._CRCbase__algo_dict['init']

    def updateCRC(self, byte):
        '''!
         @brief Updates the crc value for each new byte of input.
         @param byte data byte

         Example:
         @code
         import crc
         data = 0x12
         new_crc.updateCRC(data)
         @endcode
        '''
        self.__crc_val ^= self._CRCbase__reverseBits(byte) if self._CRCbase__algo_dict['refIn'] else byte << (self._CRCbase__nbits - 8)
        for i in range(8):
            test = (self.__crc_val & (0x01 << (self._CRCbase__nbits - 1))) != 0
            self.__crc_val = (self.__crc_val << 1) & ((0x01 << (self._CRCbase__nbits)) - 1)
            if(test):
                self.__crc_val ^= self._CRCbase__algo_dict['poly']

    def fetchCRC(self):
        '''!
         @brief Obtains the final crc value after post-processing.
         @return calculated crc value

         Example:
         @code
         import crc
         crcval = new_crc.fetchCRC()
         @endcode
        '''
        if(self._CRCbase__algo_dict['refOut']):
            self.__crc_val = self._CRCbase__reverseBits(self.__crc_val)
        self.__crc_val ^= self._CRCbase__algo_dict['xorOut']
        return self.__crc_val

    def getCRC(self, data):
        '''!
         @brief Calculates the crc value for given input data.
         @param data byte array on which the CRC is to be calculated
         @return calculated CRC value

         Example:
         @code
         import crc
         data = "Enter data here"
         crcval = new_crc.getCRC(data)
         @endcode
        '''
        self.initCRC()
        for byte in data:
            self.updateCRC(ord(byte))
        return self.fetchCRC()

class FastCRC(CRCbase):
    '''!
     @brief Class for fast CRC calculation algorithms.
    '''
    def __init__(self, paramlist):
        '''!
         @brief Initializes algorithm reference.
         @param paramlist crc parameter dict

         Example:
         @code
         import crc
         CRC8_new = {'poly':0x07, 'init':0x00, 'refIn':False, 'refOut':False, 'xorOut':0x55, 'size':8}
         new_crc = crc.FastCRC(CRC8_new)
         @endcode
        '''
        super(FastCRC, self).__init__(paramlist)
        self.__hbits = self._CRCbase__nbits - 8
        self.__M1 = (0x01 << self.__hbits) - 1
        self.__M2 = ((0x01 << self._CRCbase__nbits) - 1) - 0xff
        self.__table = []
        if(self._CRCbase__algo_dict['refIn']):
            newpoly = self._CRCbase__reverseBits(self._CRCbase__algo_dict['poly'])
            for i in range(256):
                self.__table.append(i)
                for j in range(8):
                    if(self.__table[i] & 1):
                        self.__table[i] = (self.__table[i] >> 1) ^ newpoly
                    else:
                        self.__table[i] >>= 1
        else:
            newpoly = self._CRCbase__algo_dict['poly']
            for i in range(256):
                self.__table.append(i << self.__hbits)
                for j in range(8):
                    if(self.__table[i] & (0x01 << (self._CRCbase__nbits - 1))):
                        self.__table[i] = ((self.__table[i] << 1) & ((0x01 << (self._CRCbase__nbits)) - 1)) ^ newpoly
                    else:
                        self.__table[i] = (self.__table[i] << 1) & ((0x01 << (self._CRCbase__nbits)) - 1)

    def initCRC(self):
        '''!
         @brief Initializes the crc value as per the algorithm parameter.

         Example:
         @code
         import crc
         new_crc.initCRC()
         @endcode
        '''
        self.__crc_val = self._CRCbase__reverseBits(self._CRCbase__algo_dict['init']) if self._CRCbase__algo_dict['refIn'] else self._CRCbase__algo_dict['init']

    def updateCRC(self, byte):
        '''!
         @brief Updates the crc value for each new byte of input.
         @param byte data byte

         Example:
         @code
         import crc
         data = 0x12
         new_crc.updateCRC(data)
         @endcode
        '''
        if(self._CRCbase__algo_dict['refOut']):
            self.__crc_val = ((self.__crc_val >> 8) & self.__M1) ^ self.__table[(self.__crc_val & 0xff) ^ byte]
        else:
            self.__crc_val = ((self.__crc_val << 8) & self.__M2) ^ self.__table[((self.__crc_val >> self.__hbits) & 0xff) ^ byte]

    def fetchCRC(self):
        '''!
         @brief Obtains the final crc value after post-processing.
         @return calculated crc value

         Example:
         @code
         import crc
         crcval = new_crc.fetchCRC()
         @endcode
        '''
        self.__crc_val ^= self._CRCbase__algo_dict['xorOut']
        return self.__crc_val

    def getCRC(self, data):
        '''!
         @brief Calculates the crc value for given input data.
         @param data byte array on which the CRC is to be calculated
         @return calculated CRC value

         Example:
         @code
         import crc
         data = "Enter data here"
         crcval = new_crc.getCRC(data)
         @endcode
        '''
        self.initCRC()
        for byte in data:
            self.updateCRC(ord(byte))
        return self.fetchCRC()
