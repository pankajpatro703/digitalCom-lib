import sys, os
sys.path.append(os.path.abspath('../../src/DictionaryCompression'))
from LZW import *

data = input("Enter a string: ")
compressed, initial, dictionary = compress(data)
print("Compressed data is: ")
print(compressed)
print("Dictionary used for encoding: ")
print(dictionary)
print("Initial characters in the dictionary: ")
print(initial)
decoded = uncompress(compressed,initial)
print("Decompressed data is: ")
print(decoded)
