import sys, os
sys.path.append(os.path.abspath('../../src/TranspositionCipher'))
from columnar import *

secretkey = input('Enter the Secret Key(sequence of columns separated by space): ')
secretkey = list(map(int,secretkey.split(' ')))
msg = input('Enter the message to be protected: ')
enc = encrypt(msg, secretkey)
print('Encrypted message:')
print(enc)
dec = decrypt(enc, secretkey)
print('Decrypted message:')
print(dec)