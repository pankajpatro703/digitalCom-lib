import sys, os
sys.path.append(os.path.abspath('../../src/TranspositionCipher'))
from railfence import *

secretkey = int(input('Enter the Secret Key(integer): '))
msg = input('Enter the message to be protected: ')
enc = encrypt(msg, secretkey)
print('Encrypted message:')
print(enc)
dec = decrypt(enc, secretkey)
print('Decrypted message:')
print(dec)