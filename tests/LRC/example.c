#include<stdio.h>
#include"../../src/LRC/lrc8.h"

void main() {
    char message[] ="Hello. This is the message.";
    int length = sizeof(message)-1;
    
    //char message[] = {0x4E,0x61,0x70,0x69,0x65,0x72};  
    //int length = sizeof(message);

    printf("8-bit LRC of the message is %02x\n",getLRC8(message, length));
}
