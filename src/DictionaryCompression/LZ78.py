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

#LZ78 Compression and Decompression algorithm
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def compress(uncompressed_string):
    '''
    This method calculates the compressed data.
    :param uncompressed_string: original string to be compressed
    :return compressed_string: list with final compressed data as tuple pair
    '''
    dictionary = []                 #string list
    w = ""
    compressed_list = []            #tuple list
    for c in uncompressed_string:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            compressed_list.append((dictionary.index(w)+1 if w in dictionary else 0, wc[-1]))
            dictionary.append(wc)
            w = ""
    if (w!=""):
        compressed_list.append((dictionary.index(w)+1, ""))
    return compressed_list

def uncompress(compressed_list):
    '''
    This method decompresses the compressed data.
    :param compressed_list: list of tuple pairs of compressed data
    :return data_string: string obtained after decompression
    '''
    dictionary =[]                  #string list
    for t in compressed_list:
        if(t[0] == 0):
            w = t[1]
        else:
            w = dictionary[t[0]-1] + t[1]
        dictionary.append(w)
    data_string = "".join(dictionary)
    return data_string

if (__name__ == '__main__'):
    data = 'This is the data to be compressed'
    compressed = compress(data)
    print("Compressed data is: ")
    print(compressed)
    decoded=uncompress(compressed)
    print("Decompressed data is: ")
    print(decoded)
