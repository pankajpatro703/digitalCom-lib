from LZW import *

data = input("Enter a string: ")
compressed, initial, dictionary = compress(data)
print("Compressed data is: ")
print(compressed)
print(dictionary)
print(initial)
decoded=uncompress(compressed,initial)
print(decoded)
