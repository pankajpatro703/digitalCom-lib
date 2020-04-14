import sys, os
sys.path.append(os.path.abspath('../../src/CRC'))
from crc import *

message = input('Enter the message: ')

#message = [0x3A,0x2B,0x11]         #for hex values
#for i in range(len(message)):
    #message[i]=chr(message[i])

#8-bit CRC applications
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

#16-bit CRC applications
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

#32-bit CRC applications
print('32-bit CRC of the message is', format(getCRC(message, CRC32),'08x'))
print('32-bit BZIP2 CRC of the message is', format(getCRC(message, CRC32_BZIP2),'08x'))
print('32-bit C CRC of the message is', format(getCRC(message, CRC32_C),'08x'))
print('32-bit D CRC of the message is', format(getCRC(message, CRC32_D),'08x'))
print('32-bit MPEG2 CRC of the message is', format(getCRC(message, CRC32_MPEG2),'08x'))
print('32-bit POSIX CRC of the message is', format(getCRC(message, CRC32_POSIX),'08x'))
print('32-bit Q CRC of the message is', format(getCRC(message, CRC32_Q),'08x'))
print('32-bit JAMCRC CRC of the message is', format(getCRC(message, CRC32_JAMCRC),'08x'))
print('32-bit XFER CRC of the message is', format(getCRC(message, CRC32_XFER),'08x'))