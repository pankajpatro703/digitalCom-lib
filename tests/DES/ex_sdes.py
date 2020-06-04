import sys, os
sys.path.append(os.path.abspath('../../src/DES'))
from sdes import *

secretkey = int(input('Enter the Secret Key(0-1023): '))
msg = input('Enter the message to be protected: ')
enc = ''
for i in msg:
    enc += chr(encrypt(ord(i), secretkey))
print('Encrypted message:')
print(enc)
dec =''
for i in enc:
    dec += chr(decrypt(ord(i), secretkey))
print('Decrypted message:')
print(dec)