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

#Encryption and Decryption using Rail Fence cipher
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def encrypt(plaintext, rows):
    '''
    This method encrypts the plaintext using Rail Fence cipher.
    :param plaintext: original string
    :param rows: secret key integer
    :return ciphertext: cipher text after encryption 
    '''
    fence = [[] for i in range(rows)]
    ciphertext = ''
    for i in range(len(plaintext)):
        fence[i % rows].append(plaintext[i])
    for r in fence:
        ciphertext += ''.join(r)
    return(ciphertext)

def decrypt(ciphertext, rows):
    '''
    This method decrypts the ciphertext using Rail Fence cipher.
    :param ciphertext: ciphered string
    :param rows: secret key integer
    :return decipheredtext: deciphered text after decryption
    '''
    columns = -(-len(ciphertext) // rows)
    fence = [[] for i in range(columns)]
    count = len(ciphertext) % rows
    if(count == 0):
        count = rows
    decipheredtext = ''
    c = 0
    for i in range(rows * columns):
        if((count <= 0) and (i % columns == columns - 1)):
            fence[i % columns].append('')
        else:
            fence[i % columns].append(ciphertext[c])
            if(i % columns == columns - 1):
                count -= 1
            c += 1
    for c in fence:
        decipheredtext += ''.join(c)
    return(decipheredtext)

if(__name__=='__main__'):
    rows = 5    #This is the secret key
    msg = 'This is the message to be protected'
    enc = encrypt(msg, rows)
    print('Encrypted message:')
    print(enc)
    dec = decrypt(enc, rows)
    print('Decrypted message:')
    print(dec)
