#include<stdio.h>
#include"crc8.h"

void main() {
    char message[] ="Hello. This is the message.";
    printf("8-bit CRC of the message is %02x\n",getCRC(message,CRC8));
    printf("8-bit CDMA2000 CRC of the message is %02x\n",getCRC(message,CRC8_CDMA2000));
    printf("8-bit DARC CRC of the message is %02x\n",getCRC(message,CRC8_DARC));
    printf("8-bit DVB-S2 CRC of the message is %02x\n",getCRC(message,CRC8_DVB_S2));
    printf("8-bit EBU CRC of the message is %02x\n",getCRC(message,CRC8_EBU));
    printf("8-bit I-CODE CRC of the message is %02x\n",getCRC(message,CRC8_I_CODE));
    printf("8-bit ITU CRC of the message is %02x\n",getCRC(message,CRC8_ITU));
    printf("8-bit MAXIM CRC of the message is %02x\n",getCRC(message,CRC8_MAXIM));
    printf("8-bit ROHC CRC of the message is %02x\n",getCRC(message,CRC8_ROHC));
    printf("8-bit WCDMA CRC of the message is %02x\n",getCRC(message,CRC8_WCDMA));
}

