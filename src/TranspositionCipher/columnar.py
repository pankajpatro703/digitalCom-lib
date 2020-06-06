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

#Encryption and Decryption using Columnar cipher
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def encrypt(plaintext, key):
    '''
    This method encrypts the plaintext using Columnar cipher.
    :param plaintext: original string
    :param key: secret key list for column arrangement
    :return ciphertext: cipher text after encryption
    '''
    columns = len(key)
    table = [[] for i in range(columns)]
    ciphertext = ''
    for i in range(len(plaintext)):
        table[i % columns].append(plaintext[i])
    print("Change")
    table = [table[i-1] for i in key]
    for c in table:
        ciphertext += ''.join(c)
    return(ciphertext)

def decrypt(ciphertext, key):
    '''
    This method decrypts the ciphertext using Columnar cipher.
    :param ciphertext: ciphered string
    :param key: secret key list for column arrangement
    :return decipheredtext: deciphered text after decryption
    '''
    columns = len(key)
    rows = -(-len(ciphertext) // columns)
    table = [[] for i in range(columns)]
    count = len(ciphertext) % columns
    if(count == 0):
        count = columns
    decipheredtext = ''
    c = 0
    k = 0
    for i in range(rows * columns):
        if((key[k] > count) and (i % rows == rows - 1)):
            table[key[k]-1].append('')
            k += 1
        else:
            table[key[k]-1].append(ciphertext[c])
            if(i % rows == rows - 1):
                k += 1
            c += 1
    for i in range(rows):
        for c in table:
            decipheredtext += c[i]
    return(decipheredtext)

if(__name__=='__main__'):
    key = [1,5,2,4,6,3]    #This is the secret key
    msg = 'This is the message to be protected'
    enc = encrypt(msg, key)
    print('Encrypted message:')
    print(enc)
    dec = decrypt(enc, key)
    print('Decrypted message:')
    print(dec)
