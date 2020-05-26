import sys, os
sys.path.append(os.path.abspath('../../src/DictionaryCompression'))
from LZ77 import *

LAB = 6
SB = 7
data = input("Enter a string: ")
compressed = compress(data, LAB, SB)
print("Compressed data is: ")
print(compressed)
decoded = uncompress(compressed, SB)
print("Decompressed data is: ")
print(decoded)
