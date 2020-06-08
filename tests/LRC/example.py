import sys, os
sys.path.append(os.path.abspath('../../src/LRC'))
from lrc import *

message = input('Enter the message: ')

#message = [0x4E,0x61,0x70,0x69,0x65,0x72]         #for hex values
#message = [chr(i) for i in message]

lrc = getLRC(message)
print('LRC is',format(lrc, '02x'))
