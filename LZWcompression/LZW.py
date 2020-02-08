#LZW Compression and Decompression algorithm
###########################
# @Author: pankajpatro703 #
#  Licensed under GPL v3  #
###########################

def compress(uncompressed_string):
    '''
    This method calculates the compressed data and creates the initial table.
    :param uncompressed_string: original string to be compressed
    :return tuple[0] compressed_string: list with final compressed data
    :return tuple[1] initial_list: initial alphabetic list from original string
    :return tuple[2] dictionary: encoding dictionary obtained
    '''
    dictionary = {}
    l = []
    for i in uncompressed_string:
        l.append(i)
    l = list(dict.fromkeys(l))
    l.sort()
    for i in range(len(l)):
        dictionary[l[i]] = i + 1
    initial_list = l
    dict_size = len(initial_list) + 1
    w = ""
    compressed_list = []
    for c in uncompressed_string:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            compressed_list.append(dictionary[w])
            dictionary[wc] = dict_size
            dict_size += 1
            w = c
    if (w!=""):
        compressed_list.append(dictionary[w])
    return compressed_list, initial_list, dictionary

def uncompress(compressed_list,initial_list):
    '''
    This method decompresses the compressed data.
    :param compressed_list: list of integers of compressed data
    :param initial_list: list of characters from original data
    :return data_string: string obtained after decompression 
    '''
    dictionary = {}
    data_string = ""
    for i in range(len(initial_list)):
        dictionary[initial_list[i]] = i + 1
    i, j, flag = 0, 0, 0
    while(i < len(compressed_list)):
        if(compressed_list[i] in dictionary.values()):
            if(flag != 0):
                data_string = data_string[:len(data_string) - flag]
                flag = 0
            data_string += list(dictionary.keys())[list(dictionary.values()).index(compressed_list[i])]
            i += 1
        elif(compressed_list[i] > len(dictionary)):
            newdata = data_string[j:]
            w = ""
            dict_size = len(dictionary)
            for c in newdata:        
                wc = w + c
                if(wc in dictionary):
                    w = wc
                    j += 1
                else:
                    dictionary[wc] = dict_size + 1
                    dict_size += 1
                    w = c
                    break
                if(j == len(data_string)):
                    data_string += wc
                    j -= len(wc)
                    flag = len(wc)
    return data_string

if (__name__ == '__main__'):
    data = 'This is the data to be compressed'
    compressed, initial, dictionary = compress(data)
    print("Compressed data is: ")
    print(compressed)
    print("Dictionary used for encoding: ")
    print(dictionary)
    print("Initial characters in the dictionary: ")
    print(initial)
    decoded=uncompress(compressed,initial)
    print("Decompressed data is: ")
    print(decoded)