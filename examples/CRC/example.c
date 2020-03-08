#include<stdio.h>
#include"../../src/CRC/crc8.h"
#include"../../src/CRC/crc16.h"

void main() {
    char message[] ="Hello. This is the message.";
    //char message[] = {0x3A,0x2B};  //for hex data
    
    //8-bit CRC applications
    printf("8-bit CRC of the message is %02x\n",getCRC8(message,CRC8));
    printf("8-bit CDMA2000 CRC of the message is %02x\n",getCRC8(message,CRC8_CDMA2000));
    printf("8-bit DARC CRC of the message is %02x\n",getCRC8(message,CRC8_DARC));
    printf("8-bit DVB-S2 CRC of the message is %02x\n",getCRC8(message,CRC8_DVB_S2));
    printf("8-bit EBU CRC of the message is %02x\n",getCRC8(message,CRC8_EBU));
    printf("8-bit I-CODE CRC of the message is %02x\n",getCRC8(message,CRC8_I_CODE));
    printf("8-bit ITU CRC of the message is %02x\n",getCRC8(message,CRC8_ITU));
    printf("8-bit MAXIM CRC of the message is %02x\n",getCRC8(message,CRC8_MAXIM));
    printf("8-bit ROHC CRC of the message is %02x\n",getCRC8(message,CRC8_ROHC));
    printf("8-bit WCDMA CRC of the message is %02x\n",getCRC8(message,CRC8_WCDMA));
    
    //16-bit CRC applications
    printf("16-bit CCITT-FALSE CRC of the message is %04x\n",getCRC16(message,CRC16_CCITT_FALSE));
    printf("16-bit ARC CRC of the message is %04x\n",getCRC16(message,CRC16_ARC));
    printf("16-bit AUG-CCITT CRC of the message is %04x\n",getCRC16(message,CRC16_AUG_CCITT));
    printf("16-bit DVB-S2BUYPASS CRC of the message is %04x\n",getCRC16(message,CRC16_DVB_S2BUYPASS));
    printf("16-bit CDMA2000 CRC of the message is %04x\n",getCRC16(message,CRC16_CDMA2000));
    printf("16-bit DDS-110 CRC of the message is %04x\n",getCRC16(message,CRC16_DDS_110));
    printf("16-bit DECT-R CRC of the message is %04x\n",getCRC16(message,CRC16_DECT_R));
    printf("16-bit DECT-X CRC of the message is %04x\n",getCRC16(message,CRC16_DECT_X));
    printf("16-bit DNP CRC of the message is %04x\n",getCRC16(message,CRC16_DNP));
    printf("16-bit EN-13757 CRC of the message is %04x\n",getCRC16(message,CRC16_EN_13757));
    printf("16-bit GENIBUS CRC of the message is %04x\n",getCRC16(message,CRC16_GENIBUS));
    printf("16-bit MAXIM CRC of the message is %04x\n",getCRC16(message,CRC16_MAXIM));
    printf("16-bit MCRF4XX CRC of the message is %04x\n",getCRC16(message,CRC16_MCRF4XX));
    printf("16-bit RIELLO CRC of the message is %04x\n",getCRC16(message,CRC16_RIELLO));
    printf("16-bit T10-DIF CRC of the message is %04x\n",getCRC16(message,CRC16_T10_DIF));
    printf("16-bit TELEDISK CRC of the message is %04x\n",getCRC16(message,CRC16_TELEDISK));
    printf("16-bit TMS37157 CRC of the message is %04x\n",getCRC16(message,CRC16_TMS37157));
    printf("16-bit USB CRC of the message is %04x\n",getCRC16(message,CRC16_USB));
    printf("16-bit A CRC of the message is %04x\n",getCRC16(message,CRC16_A));
    printf("16-bit KERMIT CRC of the message is %04x\n",getCRC16(message,CRC16_KERMIT));
    printf("16-bit MODBUS CRC of the message is %04x\n",getCRC16(message,CRC16_MODBUS));
    printf("16-bit X-25 CRC of the message is %04x\n",getCRC16(message,CRC16_X_25));
    printf("16-bit XMODEM CRC of the message is %04x\n",getCRC16(message,CRC16_XMODEM));
}

