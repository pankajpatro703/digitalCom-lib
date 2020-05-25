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

#LZ77 Compression and Decompression algorithm
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def compress(uncompressed_string, LAB, SB):
    '''
    This method calculates the compressed data.
    :param uncompressed_string: original string to be compressed
    :param LAB: size of look-ahead buffer
    :param SB: size of search buffer
    :return compressed_string: list with final compressed data as tuple triplet
    '''
    wl = list(uncompressed_string[: LAB])      #look ahead buffer list
    LAB = len(wl)
    ws = []                                    #search buffer list
    compressed_list = []                       #tuple list
    length = 0
    buffer_size = len(uncompressed_string)
    for c in uncompressed_string[LAB:] + '*' * LAB:
        if(length > 0):
            #adjusting matched length shifts
            length -= 1
        else:
            #searching and matching after adjusting matched length shifts
            offset = 0
            for i in range(len(wl)):
                if(''.join(wl[: len(wl)-i]) in ''.join(ws)):
                    length = len(wl) - i
                    offset =  length + ''.join(ws)[: : -1].find(''.join(wl)[: length][: : -1])
                    break
            character = wl[length] if (buffer_size != 1 or length == 0) else ''
            compressed_list.append((offset, length, character))
            #print(ws,'    ',wl)               #testing shift steps
        #sequential shifting of one character at a time
        wl.append(c)
        if(len(wl) > LAB):
            ws.append(''.join(wl[: 1]))
            wl = wl[1 :]
        if(len(ws) > SB):
            ws = ws[1 :]
        buffer_size -= 1
    compressed_list.append((0, 0, 0))
    #print(ws,'    ',wl)                       #testing final shift step
    return compressed_list

def uncompress(compressed_list, SB):
    '''
    This method decompresses the compressed data.
    :param compressed_list: list of tuple triplet of compressed data
    :param SB: size of search buffer
    :return data_string: string obtained after decompression
    '''
    ws = [' ' for i in range(SB)]              #search buffer list
    data_string = ""
    #print(ws)                                 #testing initial shift step
    for t in compressed_list:
        if(t[2] == 0):
            break
        else:
            pos = SB - t[0]
            entry = ''.join(ws)[pos : pos + t[1]] + t[2]
            data_string += entry
            for i in entry:
                ws.append(i)
        if(len(ws) > SB):
            ws = ws[len(ws) - SB :]
        #print(ws)                             #testing shift steps
    return data_string

if (__name__ == '__main__'):
    LAB = 6
    SB = 7
    data = "This is the data to be compressed"
    compressed = compress(data, LAB, SB)
    print("Compressed data is: ")
    print(compressed)
    decoded=uncompress(compressed, SB)
    print("Decompressed data is: ")
    print(decoded)

