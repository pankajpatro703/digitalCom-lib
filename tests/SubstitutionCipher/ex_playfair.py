import sys, os
sys.path.append(os.path.abspath('../../src/SubstitutionCipher'))
from playfair import *

secretkey = input('Enter the Secret Key: ')
msg = input('Enter the message to be protected: ')
new_square = getSquare(secretkey)
print('Square map:')
for row in new_square:
    print(row)
enc = encrypt(msg, new_square)
print('Encrypted message:')
print(enc)
dec = decrypt(enc, new_square)
print('Decrypted message:')
print(dec)
