#include <stdio.h>
#include "../../src/CRC/crc8.h"
#include "../../src/CRC/crc16.h"
#include "../../src/CRC/crc32.h"
#include "../../src/CRC/crc64.h"

void main() {
    char message[] = "Hello. This is the message.";
    unsigned int length = sizeof(message)-1;

    //char message[] = {0x3A,0x2B,0x11};
    //unsigned int length = sizeof(message);

    //8-bit CRC applications
    printf("8-bit AUTOSAR CRC of the message is %02x\n",getCRC8(message, &CRC8_AUTOSAR, length));
    printf("8-bit BLUETOOTH CRC of the message is %02x\n",getCRC8(message, &CRC8_BLUETOOTH, length));
    printf("8-bit CDMA2000 CRC of the message is %02x\n",getCRC8(message, &CRC8_CDMA2000, length));
    printf("8-bit DARC CRC of the message is %02x\n",getCRC8(message, &CRC8_DARC, length));
    printf("8-bit DVB-S2 CRC of the message is %02x\n",getCRC8(message, &CRC8_DVB_S2, length));
    printf("8-bit EBU CRC of the message is %02x\n",getCRC8(message, &CRC8_EBU, length));
    printf("8-bit GSM-A CRC of the message is %02x\n",getCRC8(message, &CRC8_GSM_A, length));
    printf("8-bit GSM-B CRC of the message is %02x\n",getCRC8(message, &CRC8_GSM_B, length));
    printf("8-bit ITU CRC of the message is %02x\n",getCRC8(message, &CRC8_ITU, length));
    printf("8-bit I-CODE CRC of the message is %02x\n",getCRC8(message, &CRC8_I_CODE, length));
    printf("8-bit LTE CRC of the message is %02x\n",getCRC8(message, &CRC8_LTE, length));
    printf("8-bit MAXIM CRC of the message is %02x\n",getCRC8(message, &CRC8_MAXIM, length));
    printf("8-bit MIFARE-MAD CRC of the message is %02x\n",getCRC8(message, &CRC8_MIFARE_MAD, length));
    printf("8-bit NRSC-5 CRC of the message is %02x\n",getCRC8(message, &CRC8_NRSC_5, length));
    printf("8-bit OPENSAFETY CRC of the message is %02x\n",getCRC8(message, &CRC8_OPENSAFETY, length));
    printf("8-bit ROHC CRC of the message is %02x\n",getCRC8(message, &CRC8_ROHC, length));
    printf("8-bit SAE-J1850 CRC of the message is %02x\n",getCRC8(message, &CRC8_SAE_J1850, length));
    printf("8-bit SMBUS CRC of the message is %02x\n",getCRC8(message, &CRC8_SMBUS, length));
    printf("8-bit WCDMA CRC of the message is %02x\n",getCRC8(message, &CRC8_WCDMA, length));

    //16-bit CRC applications
    printf("16-bit A CRC of the message is %04x\n",getCRC16(message, &CRC16_A, length));
    printf("16-bit ARC CRC of the message is %04x\n",getCRC16(message, &CRC16_ARC, length));
    printf("16-bit AUG-CCITT CRC of the message is %04x\n",getCRC16(message, &CRC16_AUG_CCITT, length));
    printf("16-bit B CRC of the message is %04x\n",getCRC16(message, &CRC16_B, length));
    printf("16-bit CCITT-FALSE CRC of the message is %04x\n",getCRC16(message, &CRC16_CCITT_FALSE, length));
    printf("16-bit CDMA2000 CRC of the message is %04x\n",getCRC16(message, &CRC16_CDMA2000, length));
    printf("16-bit CMS CRC of the message is %04x\n",getCRC16(message, &CRC16_CMS, length));
    printf("16-bit DDS-110 CRC of the message is %04x\n",getCRC16(message, &CRC16_DDS_110, length));
    printf("16-bit DECT-R CRC of the message is %04x\n",getCRC16(message, &CRC16_DECT_R, length));
    printf("16-bit DECT-X CRC of the message is %04x\n",getCRC16(message, &CRC16_DECT_X, length));
    printf("16-bit DNP CRC of the message is %04x\n",getCRC16(message, &CRC16_DNP, length));
    printf("16-bit EN-13757 CRC of the message is %04x\n",getCRC16(message, &CRC16_EN_13757, length));
    printf("16-bit GENIBUS CRC of the message is %04x\n",getCRC16(message, &CRC16_GENIBUS, length));
    printf("16-bit GSM CRC of the message is %04x\n",getCRC16(message, &CRC16_GSM, length));
    printf("16-bit KERMIT CRC of the message is %04x\n",getCRC16(message, &CRC16_KERMIT, length));
    printf("16-bit LJ1200 CRC of the message is %04x\n",getCRC16(message, &CRC16_LJ1200, length));
    printf("16-bit MAXIM CRC of the message is %04x\n",getCRC16(message, &CRC16_MAXIM, length));
    printf("16-bit MCRF4XX CRC of the message is %04x\n",getCRC16(message, &CRC16_MCRF4XX, length));
    printf("16-bit MODBUS CRC of the message is %04x\n",getCRC16(message, &CRC16_MODBUS, length));
    printf("16-bit NRSC-5 CRC of the message is %04x\n",getCRC16(message, &CRC16_NRSC_5, length));
    printf("16-bit OPENSAFETY-A CRC of the message is %04x\n",getCRC16(message, &CRC16_OPENSAFETY_A, length));
    printf("16-bit OPENSAFETY-B CRC of the message is %04x\n",getCRC16(message, &CRC16_OPENSAFETY_B, length));
    printf("16-bit PROFIBUS CRC of the message is %04x\n",getCRC16(message, &CRC16_PROFIBUS, length));
    printf("16-bit RIELLO CRC of the message is %04x\n",getCRC16(message, &CRC16_RIELLO, length));
    printf("16-bit T10-DIF CRC of the message is %04x\n",getCRC16(message, &CRC16_T10_DIF, length));
    printf("16-bit TELEDISK CRC of the message is %04x\n",getCRC16(message, &CRC16_TELEDISK, length));
    printf("16-bit TMS37157 CRC of the message is %04x\n",getCRC16(message, &CRC16_TMS37157, length));
    printf("16-bit UMTS CRC of the message is %04x\n",getCRC16(message, &CRC16_UMTS, length));
    printf("16-bit USB CRC of the message is %04x\n",getCRC16(message, &CRC16_USB, length));
    printf("16-bit XMODEM CRC of the message is %04x\n",getCRC16(message, &CRC16_XMODEM, length));

    //32-bit CRC applications
    printf("32-bit ADCCP CRC of the message is %08x\n",getCRC32(message, &CRC32_ADCCP, length));
    printf("32-bit AUTOSAR CRC of the message is %08x\n",getCRC32(message, &CRC32_AUTOSAR, length));
    printf("32-bit BZIP2 CRC of the message is %08x\n",getCRC32(message, &CRC32_BZIP2, length));
    printf("32-bit C CRC of the message is %08x\n",getCRC32(message, &CRC32_C, length));
    printf("32-bit CD-ROM-EDC CRC of the message is %08x\n",getCRC32(message, &CRC32_CD_ROM_EDC, length));
    printf("32-bit D CRC of the message is %08x\n",getCRC32(message, &CRC32_D, length));
    printf("32-bit JAMCRC CRC of the message is %08x\n",getCRC32(message, &CRC32_JAMCRC, length));
    printf("32-bit MPEG2 CRC of the message is %08x\n",getCRC32(message, &CRC32_MPEG2, length));
    printf("32-bit POSIX CRC of the message is %08x\n",getCRC32(message, &CRC32_POSIX, length));
    printf("32-bit Q CRC of the message is %08x\n",getCRC32(message, &CRC32_Q, length));
    printf("32-bit XFER CRC of the message is %08x\n",getCRC32(message, &CRC32_XFER, length));

    //64-bit CRC applications
    printf("64-bit ECMA-182 CRC of the message is %016lx\n",getCRC64(message, &CRC64_ECMA_182, length));
    printf("64-bit GO-ISO CRC of the message is %016lx\n",getCRC64(message, &CRC64_GO_ISO, length));
    printf("64-bit WE CRC of the message is %016lx\n",getCRC64(message, &CRC64_WE, length));
    printf("64-bit XZ CRC of the message is %016lx\n",getCRC64(message, &CRC64_XZ, length));
}
