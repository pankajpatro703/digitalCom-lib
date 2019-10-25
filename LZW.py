def compress(uncompressed):
    dictionary = {}
    l = []
    for i in uncompressed:
        l.append(i)
    l = list(dict.fromkeys(l))
    for i in range(len(l)):
        dictionary[l[i]] = i + 1
    initial = l
    dict_size=len(initial)+1
    w = ""
    result = []
    for c in uncompressed:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            result.append(dictionary[w])
            dictionary[wc] = dict_size
            dict_size += 1
            w = c
    if w:
        result.append(dictionary[w])
    return result, initial, dictionary

def uncompress(compressed,initial):
    dictionary = {}
    data=""
    for i in range(len(initial)):
        dictionary[initial[i]] = i + 1
    count=len(dictionary)
    for i in compressed:
        if(i in dictionary.values()):
            data=data+list(dictionary.keys())[list(dictionary.values()).index(i)]
        else:

            
    return data


data = input("Enter a string: ")
compressed, initial, dictionary = compress(data)
print("Compressed data is: ")
print(compressed)
print(dictionary)
print(initial)
decoded=uncompress(compressed,initial)
print(decoded)
