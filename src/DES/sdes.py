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

#Encryption and Decryption using Simplified-DES algorithm
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

#Sequences defined by SDES algorithm
p10 = [3,5,2,7,4,10,1,9,8,6]
p8 = [6,3,7,4,8,5,10,9]
iP = [2,6,3,1,4,8,5,7]
invIP = [4,1,3,5,7,2,8,6]

s0 = [[1,0,3,2],[3,2,1,0],[0,2,1,3],[3,1,3,2]]
s1 = [[0,1,2,3],[2,0,1,3],[3,0,1,0],[2,1,0,3]]
eP = [4,1,2,3,2,3,4,1]
p4 = [2,4,3,1]

def permutation(seq, data, datasize):
    '''
    This method changes the sequence of occurence of bits in the data.
    :param seq: required order/sequence list 
    :param data: original data whose bit sequence is to be changed
    :param datasize: number of bits in original data
    :return: data with specified sequence, size is same as seq
    '''
    newdata = ''
    for i in range(len(seq)):
        newdata += format(data, '0{}b'.format(datasize))[seq[i]-1]
    return(int(newdata, 2))

def sw(data, partsize):
    '''
    This method divides a block of bits into two and exchanges their positions.
    :param data: original data
    :param partsize: integer position for slicing
    :return: data after exchanging
    '''
    stringData = format(data, '0{}b'.format(2*partsize))
    stringData = stringData[partsize :] + stringData[: partsize] 
    return(int(stringData, 2)) 

def fk(base, k):
    '''
    This method applies a key on given data.
    :param base: original 8-bit data on which key is to be applied
    :param k: 8-bit generated key 
    :return: 8-bit data obtained after applying key function
    '''
    pos = format(permutation(eP, base & 0b1111, 4) ^ k, '08b')
    value = format(s0[int(pos[0]+pos[3], 2)][int(pos[1]+pos[2], 2)], '02b') + \
        format(s1[int(pos[4]+pos[7], 2)][int(pos[5]+pos[6], 2)], '02b')
    lpt = permutation(p4, int(value, 2), 4) ^ ((base>>4) & 0b1111)
    return((lpt << 4) + (base & 0x0F))

def lshift(data, partsize, shifts):
    '''
    This method circular left shifts two bit sequences after dividing them.
    :param data: original data
    :param partsize: integer position for slicing
    :param shifts: number of left shifts required
    :return stringData: shifted and combined data
    '''
    stringData = format(data, '0{}b'.format(2*partsize))
    stringData = stringData[shifts : partsize] + stringData[: shifts] + \
        stringData[partsize + shifts :] + stringData[partsize : partsize + shifts]
    return(int(stringData, 2)) 

def keygen(key):
    '''
    This method generates two keys from user defined key.
    :param key: original 10-bit key
    :return k1, k2: generated tuple of 8-bit keys
    '''
    base = lshift(permutation(p10, key, 10), 5, 1)
    k1 = permutation(p8, base, 10)
    k2 = permutation(p8, lshift(base, 5, 2), 10)
    return(k1, k2)

def encrypt(plaintext, key):
    '''
    This method encrypts the plaintext using S-DES.
    :param plaintext: original 8-bit data
    :param key: secret 10-bit key
    :return ciphertext: 8-bit cipher text after encryption 
    '''
    (k1, k2) = keygen(key)
    ciphertext = permutation(invIP, fk(sw(fk(permutation(iP, plaintext, 8), k1), 4), k2), 8)
    return(ciphertext)

def decrypt(ciphertext, key):
    '''
    This method decrypts the ciphertext using S-DES.
    :param ciphertext: ciphered 8-bit data
    :param key: secret 10-bit key
    :return decipheredtext: 8-bit deciphered text after decryption
    '''
    (k1, k2) = keygen(key)
    decipheredtext = permutation(invIP, fk(sw(fk(permutation(iP, ciphertext, 8), k2), 4), k1), 8)
    return decipheredtext

if(__name__=='__main__'):
    secretkey = 0b1010000010    #This is the secret key
    msg = 0b01110010            #This is the message to be protected
    enc = encrypt(msg, secretkey)
    print('Encrypted message:')
    print(format(enc,'08b'))
    dec = decrypt(enc, secretkey)
    print('Decrypted message:')    
    print(format(dec,'08b'))