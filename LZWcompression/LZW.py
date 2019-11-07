def compress(uncompressed):
    dictionary = {}
    l = []
    for i in uncompressed:
        l.append(i)
    l = list(dict.fromkeys(l))
    l.sort()
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
    if (w!=""):
        result.append(dictionary[w])
    return result, initial, dictionary

def uncompress(compressed,initial):
    dictionary = {}
    data=""
    for i in range(len(initial)):
        dictionary[initial[i]] = i + 1
    i,j,flag=0,0,0
    while(i<len(compressed)):
        if(compressed[i] in dictionary.values()):
            if(flag!=0):
                data=data[:len(data)-flag]
                flag=0
            data=data+list(dictionary.keys())[list(dictionary.values()).index(compressed[i])]
            i=i+1
        elif(compressed[i]>len(dictionary)):
            newdata=data[j:]
            w=""
            dict_size=len(dictionary)
            for c in newdata:        
                wc=w+c
                if(wc in dictionary):
                    w=wc
                    j+=1
                else:
                    dictionary[wc] = dict_size+1
                    dict_size += 1
                    w = c
                    break
                if(j==len(data)):
                    data+=wc
                    j-=len(wc)
                    flag=len(wc)
    return data

#data = input("Enter a string: ")
#compressed, initial, dictionary = compress(data)
#print("Compressed data is: ")
#print(compressed)
#print(dictionary)
#print(initial)
#decoded=uncompress(compressed,initial)
#print(decoded)
