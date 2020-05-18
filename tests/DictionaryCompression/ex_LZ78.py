import sys, os
sys.path.append(os.path.abspath('../../src/DictionaryCompression'))
from LZ78 import *

data = input("Enter a string: ")
compressed = compress(data)
print("Compressed data is: ")
print(compressed)
decoded = uncompress(compressed)
print("Decompressed data is: ")
print(decoded)
