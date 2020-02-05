#Encryption and Decryption using playfair cipher

SIZE=9

#orglist = [chr(i) for i in range(32,127)]
orglist = [chr(i) for i in range(32+33,32+59)] + \
        [chr(i) for i in range(32+65,32+91)] + \
        [chr(i) for i in range(32+16,32+26)] + \
        [chr(i) for i in range(32+0,32+16)] + \
        [chr(i) for i in range(32+91,32+95)]
#A-Z,a-z,0-9,symbols
# ~ may be required specially

def removeDuplicate(str, n):       
    index = 0
    for i in range(0, n): 
        for j in range(0, i + 1): 
            if (str[i] == str[j]): 
                break 
        if (j == i): 
            str[index] = str[i] 
            index += 1
    return("".join(str[:index])) 

def getSquare(secretkey):
    square = []
    key = removeDuplicate(list(secretkey), len(secretkey))
    keylist = [char for char in key]
    for i in orglist:
        if(i not in keylist):
            keylist.append(i)    
    for i in range(SIZE):
        row=[]
        for j in range(SIZE):
            row.append(keylist[0])
            keylist.pop(0)
        square.append(row)
    return square

def getcode(l, r, square, operation):
    for i in range(len(square)):
        if l in square[i]:
            j = square[i].index(l)
            l_loc = (i, j)
        if r in square[i]:
            j = square[i].index(r)
            r_loc = (i, j)
    if(l_loc[0]==r_loc[0] and l_loc[1]==r_loc[1]):
        #dont change    
    elif(l_loc[0]==r_loc[0]):
        #same row
    elif(l_loc[1]==r_loc[1]):
        #same column
    else:
        #check block

    return code


def playfairEncrypt(plaintext, square):
    pairs = []
    newpairs = []
    for i in range(len(plaintext), 2):
        pairs.append(plaintext[i:i+2])
    for i in pairs:
        newpairs.append(getcode(i[0], i[1], square, 'encrypt'))
    ciphertext = "".join(newpairs)
    return ciphertext

def playfairDecrypt(ciphertext, square):
    pairs = []
    newpairs = []
    for i in range(len(ciphertext), 2):
        pairs.append(ciphertext[i:i+2])
    for i in pairs:
        newpairs.append(getcode(i[0], i[1], square, 'decrypt'))
    deciphertext = "".join(newpairs)
    return deciphertext

if (__name__ == '__main__'):
    secretkey = 'ThisIsASecretKey'
    msg = "ThisIsTheMessageToBeProtected"
    new_square = getSquare(secretkey)
    enc = playfairEncrypt(msg, new_square)
    print(enc)
    dec = playfairDecrypt(enc, new_square)
    print(dec)
