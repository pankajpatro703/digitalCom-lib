import sys, os
sys.path.append(os.path.abspath('../../src/CRC'))
from crc8 import *

message = input('Enter the message: ')
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
