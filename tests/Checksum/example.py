import sys, os
sys.path.append(os.path.abspath('../../src/Checksum'))
from intadd import *

message = input('Enter the message: ')

#message = [0x63,0x68,0x65,0x63,0x6b,0x73]        #for hex values
#message = [chr(i) for i in message]

lrc = getChecksum(message)
print('Checksum is',format(lrc, '02x'))
