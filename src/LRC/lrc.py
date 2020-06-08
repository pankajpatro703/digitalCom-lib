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

#n-bit LRC Hash algorithm
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def getLRC(data):
    '''
    This method obtains the LRC value of the data.
    :param data: original string data
    :return lrc: calculated integer value of lrc
    '''
    lrc = 0
    for c in data:
        lrc = (lrc ^ ord(c)) & 0xFF
    return lrc

if(__name__=='__main__'):
    message = 'Hello. This is the message.'

    #message = [0x4E,0x61,0x70,0x69,0x65,0x72]         #for hex values
    #message = [chr(i) for i in message]
    
    lrc = getLRC(message)
    print('LRC is',format(lrc, '02x'))
