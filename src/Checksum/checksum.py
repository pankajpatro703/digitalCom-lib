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

#n-bit integer addition checksum algorithm
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def getChecksum(data):
    '''
    This method obtains the integer addition checksum value of the data.
    :param data: original string data
    :return lrc: calculated integer value of integer addition checksum
    '''
    sum = 0
    for c in data:
        sum = (sum + ord(c)) & 0xFF
    return sum

if(__name__=='__main__'):
    message = 'Hello. This is the message.'

    #message = [0x4E,0x61,0x70]         #for hex values
    #message = [chr(i) for i in message]
    
    csum = getChecksum(message)
    print('Checksum is',format(csum, '02x'))
