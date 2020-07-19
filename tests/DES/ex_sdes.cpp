#include <iostream>
#include <cmath>
#include "../../src/DES/sdes.h"
using namespace std;

//  Function to display the binary format of a number
void printBin(int number, int exsize) {
    for(int i=1; i<=exsize; i++) {
        cout << (char)(number & (int)pow(2,exsize-i)?'1':'0');
    }
    cout << endl;
}

int main() {
    unsigned short int secretkey = 0b1010000010;
    uint8_t msg = 0b01110010;
    cout << "Original message:" << endl;
    printBin(msg,8);
    cout << "Secret key:" << endl;
    printBin(secretkey,10);
    uint8_t enc = encrypt(&msg, &secretkey);
    cout << "Encrypted message:" << endl;
    printBin(enc,8);
    uint8_t dec = decrypt(&enc, &secretkey);
    cout << "Decrypted message:" << endl;
    printBin(dec,8);
    return 0;
}
