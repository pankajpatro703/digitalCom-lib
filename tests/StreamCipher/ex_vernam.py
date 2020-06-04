import sys, os
sys.path.append(os.path.abspath('../../src/StreamCipher'))
from vernam import *

secretkey = input('Enter the Secret Key: ')
msg = input('Enter the message to be protected: ')
enc = encrypt(msg, secretkey)
print('Encrypted message:')
print(enc)
dec = decrypt(enc, secretkey)
print('Decrypted message:')
print(dec)
