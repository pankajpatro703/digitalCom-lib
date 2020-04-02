#include<stdio.h>
#include<math.h>
#include"../../src/DES/sdes.h"

void printBin(int number, int exsize) {
    for(int i=1; i<=exsize; i++) {
        printf("%c",number & (int)pow(2,exsize-i)?'1':'0');
    }
    printf("\n");
}

void main() {
    unsigned short int secretkey = 0b1010000010;
    unsigned short int msg = 0b01110010;
    printf("Original message:\n");
    printBin(msg,8);
    printf("Secret key:\n");
    printBin(secretkey,10);
    unsigned short int enc = sdesEncrypt(msg, secretkey);
    printf("Encrypted message:\n");
    printBin(enc,8);
    unsigned short int dec = sdesDecrypt(enc, secretkey);
    printf("Decrypted message:\n");
    printBin(dec,8);
}
