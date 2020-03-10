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

#Encryption and Decryption using playfair cipher
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

SIZE = 9      #for a 9x9 sized playfair square

#orglist = [chr(i) for i in range(32,127)] #useful ASCII codes
orglist = [chr(i) for i in range(32+33,32+59)] + \
        [chr(i) for i in range(32+65,32+91)] + \
        [chr(i) for i in range(32+16,32+26)] + \
        [chr(i) for i in range(32+0,32+16)] + \
        [chr(i) for i in range(32+91,32+95)]
#A-Z,a-z,0-9,symbols
# '|' is required for padding and should not be used in the message

def removeDuplicate(lst):
    '''
    This method removes duplicate characters in a list without 
    losing the order in which the characters appaer in the original list.
    :param lst: original list of characters
    :return: string with repeated charcaters removed 
    '''       
    index = 0
    n = len(lst)
    for i in range(0, n): 
        for j in range(0, i+1): 
            if (lst[i] == lst[j]): 
                break 
        if (j == i): 
            lst[index] = lst[i] 
            index += 1
    return("".join(lst[:index])) 

def getSquare(secretkey):
    '''
    This method generates a SIZE*SIZE square list containing all characters that can be used in a message
    :param secretkey: string type secret key to generate the Square.
    :return square: square list of ASCII characters 
    '''
    square = []
    key = removeDuplicate(list(secretkey))
    keylist = [char for char in key]
    for i in orglist:
        if(i not in keylist):
            keylist.append(i)    
    for i in range(SIZE):
        row=[]
        for j in range(SIZE):
            row.append(keylist[0])
            keylist.pop(0)
        square.append(row)
    return(square)

def getLocation(x, square):
    '''
    This method finds the location of an element on a square list.
    :param x: element whose location is to be found 
    :param square: square with list of elements
    :return x_loc: (row, column) location of x in square
    '''
    x_loc = 0
    for i in range(len(square)):
        if x in square[i]:
            j = square[i].index(x)
            x_loc = (i, j)
    return(x_loc)    

def getcode(l, r, square, operation):
    '''
    This method obtains the encrypted form of character pair.
    :param l: first character in the pair
    :param r: second character in the pair
    :param square: square list of character map
    :param operation: defines the opertaion - 'encrypt' or 'decrypt'
    :return code: encrypted character pair 
    '''
    l_loc = getLocation(l, square)
    r_loc = getLocation(r, square)
    if(l_loc[0] != r_loc[0] and l_loc[1] != r_loc[1]):
        #check block, same row different column
        code = square[l_loc[0]][r_loc[1]] + square[r_loc[0]][l_loc[1]]
    elif(l_loc[0] == r_loc[0] and l_loc[1] == r_loc[1]):
        #repeated character, no change
        code = square[l_loc[0]][l_loc[1]] + square[r_loc[0]][r_loc[1]]
    else:
        n = 0
        if(operation == 'encrypt'):
            n = 1
        elif(operation == 'decrypt'):
            n = -1
        if(l_loc[1]==r_loc[1]):
            #same column
            code = square[(l_loc[0]+n) % SIZE][l_loc[1]] + square[(r_loc[0]+n) % SIZE][r_loc[1]]
        elif(l_loc[0]==r_loc[0]):
            #same row
            code = square[l_loc[0]][(l_loc[1]+n) % SIZE] + square[r_loc[0]][(r_loc[1]+n) % SIZE]
    return code


def playfairEncrypt(plaintext, square):
    '''
    This method encrypts the plaintext using playfair cipher.
    :param plaintext: original string
    :param square: square list of characters obtained from key
    :return ciphertext: cipher text after encryption
    '''
    if(len(plaintext)%2==1):
        plaintext = plaintext[:] + '|'
    pairs = []
    newpairs = []
    for i in range(0, len(plaintext), 2):
        pairs.append(plaintext[i: i+2])
    for i in pairs:
        newpairs.append(getcode(i[0], i[1], square, 'encrypt'))
    ciphertext = "".join(newpairs)
    return ciphertext

def playfairDecrypt(ciphertext, square):
    '''
    This method decrypts the ciphertext using playfair cipher.
    :param ciphertext: ciphered string
    :param square: square list of characters obtained from key
    :return deciphertext: deciphered text after decryption
    '''
    pairs = []
    newpairs = []
    for i in range(0, len(ciphertext), 2):
        pairs.append(ciphertext[i: i+2])
    for i in pairs:
        newpairs.append(getcode(i[0], i[1], square, 'decrypt'))
    deciphertext = "".join(newpairs)
    if(deciphertext[-1] == '|'):
        deciphertext = deciphertext[: -1]
    return deciphertext

if (__name__ == '__main__'):
    secretkey = 'This Is A Secret Key That Is Required To Encrypt & Decrypt'
    msg = 'This is the message to be protected'
    new_square = getSquare(secretkey)
    print('Square map:')
    for row in new_square:
        print(row)
    enc = playfairEncrypt(msg, new_square)
    print('Encrypted message:')
    print(enc)
    dec = playfairDecrypt(enc, new_square)
    print('Decrypted message:')
    print(dec)
