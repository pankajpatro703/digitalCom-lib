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

#Encryption and Decryption using Vernam cipher
################################
#   @Author: pankajpatro703    #
# Licensed under Lesser GPL v3 #
################################

def getlenkey(text, key):
    '''
    This method creates a one-time pad key by converting the length of the secret key
    to that of the message to be encrypted or decrypted.
    :param text: string type text(plain / cipher)
    :param key: string type key
    :return: string representating one-time pad
    '''
    lenkey = ''
    for i in range(len(text)):
        lenkey += key
    return (lenkey[:len(text)])

def vernamEncrypt(plaintext, key):
    '''
    This method encrypts the plaintext using Vernam cipher.
    :param plaintext: original string
    :param key: secret key string
    :return ciphertext: cipher text after encryption 
    '''
    lenkey = getlenkey(plaintext, key)
    ciphertext = ''
    for i in range(len(plaintext)):
        n = chr((ord(plaintext[i]) + ord(lenkey[i])) % 128)
        ciphertext += n
    return(ciphertext)

def vernamDecrypt(ciphertext, key):
    '''
    This method decrypts the ciphertext using Vernam cipher.
    :param ciphertext: ciphered string
    :param key: secret key string
    :return decipheredtext: deciphered text after decryption
    '''
    lenkey = getlenkey(ciphertext, key)
    decipheredtext = ''
    for i in range(len(ciphertext)):
        n = chr((ord(ciphertext[i]) + 128 - ord(lenkey[i])) % 128)
        decipheredtext +=n
    return(decipheredtext)

if(__name__=='__main__'):
    secretkey = 'This is the Secret Key'
    msg = 'This is the message to be protected'
    enc = vernamEncrypt(msg, secretkey)
    print('Encrypted message:')
    print(enc)
    dec = vernamDecrypt(enc, secretkey)
    print('Decrypted message:')
    print(dec)
