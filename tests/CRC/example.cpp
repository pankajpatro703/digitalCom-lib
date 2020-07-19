#include <iostream>
#include <iomanip>
#include "../../src/CRC/crc8.h"
#include "../../src/CRC/crc16.h"
#include "../../src/CRC/crc32.h"
#include "../../src/CRC/crc64.h"
using namespace std;

int main() {
    uint8_t message[] = "Hello. This is the message.";
    unsigned int length = sizeof(message)-1;

    //uint8_t message[] = {0x3A,0x2B,0x11};
    //unsigned int length = sizeof(message);

    //8-bit CRC applications
    cout << "8-bit AUTOSAR CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_AUTOSAR, length)) << endl;
    cout << "8-bit BLUETOOTH CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_BLUETOOTH, length)) << endl;
    cout << "8-bit CDMA2000 CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_CDMA2000, length)) << endl;
    cout << "8-bit DARC CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_DARC, length)) << endl;
    cout << "8-bit DVB-S2 CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_DVB_S2, length)) << endl;
    cout << "8-bit EBU CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_EBU, length)) << endl;
    cout << "8-bit GSM-A CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_GSM_A, length)) << endl;
    cout << "8-bit GSM-B CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_GSM_B, length)) << endl;
    cout << "8-bit ITU CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_ITU, length)) << endl;
    cout << "8-bit I-CODE CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_I_CODE, length)) << endl;
    cout << "8-bit LTE CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_LTE, length)) << endl;
    cout << "8-bit MAXIM CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_MAXIM, length)) << endl;
    cout << "8-bit MIFARE-MAD CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_MIFARE_MAD, length)) << endl;
    cout << "8-bit NRSC-5 CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_NRSC_5, length)) << endl;
    cout << "8-bit OPENSAFETY CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_OPENSAFETY, length)) << endl;
    cout << "8-bit ROHC CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_ROHC, length)) << endl;
    cout << "8-bit SAE-J1850 CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_SAE_J1850, length)) << endl;
    cout << "8-bit SMBUS CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_SMBUS, length)) << endl;
    cout << "8-bit WCDMA CRC of the message is " << hex << setfill('0') << setw(2) << int(getCRC8(message, &CRC8_WCDMA, length)) << endl;

    //16-bit CRC applications
    cout << "16-bit A CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_A, length)) << endl;
    cout << "16-bit ARC CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_ARC, length)) << endl;
    cout << "16-bit AUG-CCITT CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_AUG_CCITT, length)) << endl;
    cout << "16-bit B CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_B, length)) << endl;
    cout << "16-bit CCITT-FALSE CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_CCITT_FALSE, length)) << endl;
    cout << "16-bit CDMA2000 CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_CDMA2000, length)) << endl;
    cout << "16-bit CMS CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_CMS, length)) << endl;
    cout << "16-bit DDS-110 CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_DDS_110, length)) << endl;
    cout << "16-bit DECT-R CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_DECT_R, length)) << endl;
    cout << "16-bit DECT-X CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_DECT_X, length)) << endl;
    cout << "16-bit DNP CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_DNP, length)) << endl;
    cout << "16-bit EN-13757 CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_EN_13757, length)) << endl;
    cout << "16-bit GENIBUS CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_GENIBUS, length)) << endl;
    cout << "16-bit GSM CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_GSM, length)) << endl;
    cout << "16-bit KERMIT CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_KERMIT, length)) << endl;
    cout << "16-bit LJ1200 CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_LJ1200, length)) << endl;
    cout << "16-bit MAXIM CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_MAXIM, length)) << endl;
    cout << "16-bit MCRF4XX CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_MCRF4XX, length)) << endl;
    cout << "16-bit MODBUS CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_MODBUS, length)) << endl;
    cout << "16-bit NRSC-5 CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_NRSC_5, length)) << endl;
    cout << "16-bit OPENSAFETY-A CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_OPENSAFETY_A, length)) << endl;
    cout << "16-bit OPENSAFETY-B CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_OPENSAFETY_B, length)) << endl;
    cout << "16-bit PROFIBUS CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_PROFIBUS, length)) << endl;
    cout << "16-bit RIELLO CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_RIELLO, length)) << endl;
    cout << "16-bit T10-DIF CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_T10_DIF, length)) << endl;
    cout << "16-bit TELEDISK CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_TELEDISK, length)) << endl;
    cout << "16-bit TMS37157 CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_TMS37157, length)) << endl;
    cout << "16-bit UMTS CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_UMTS, length)) << endl;
    cout << "16-bit USB CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_USB, length)) << endl;
    cout << "16-bit XMODEM CRC of the message is " << hex << setfill('0') << setw(4) << uint16_t(getCRC16(message, &CRC16_XMODEM, length)) << endl;

    //32-bit CRC applications
    cout << "32-bit ADCCP CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_ADCCP, length)) << endl;
    cout << "32-bit AUTOSAR CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_AUTOSAR, length)) << endl;
    cout << "32-bit BZIP2 CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_BZIP2, length)) << endl;
    cout << "32-bit C CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_C, length)) << endl;
    cout << "32-bit CD-ROM-EDC CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_CD_ROM_EDC, length)) << endl;
    cout << "32-bit D CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_D, length)) << endl;
    cout << "32-bit JAMCRC CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_JAMCRC, length)) << endl;
    cout << "32-bit MPEG2 CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_MPEG2, length)) << endl;
    cout << "32-bit POSIX CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_POSIX, length)) << endl;
    cout << "32-bit Q CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_Q, length)) << endl;
    cout << "32-bit XFER CRC of the message is " << hex << setfill('0') << setw(8) << uint32_t(getCRC32(message, &CRC32_XFER, length)) << endl;

    //64-bit CRC applications
    cout << "64-bit ECMA-182 CRC of the message is " << hex << setfill('0') << setw(16) << uint64_t(getCRC64(message, &CRC64_ECMA_182, length)) << endl;
    cout << "64-bit GO-ISO CRC of the message is " << hex << setfill('0') << setw(16) << uint64_t(getCRC64(message, &CRC64_GO_ISO, length)) << endl;
    cout << "64-bit WE CRC of the message is " << hex << setfill('0') << setw(16) << uint64_t(getCRC64(message, &CRC64_WE, length)) << endl;
    cout << "64-bit XZ CRC of the message is " << hex << setfill('0') << setw(16) << uint64_t(getCRC64(message, &CRC64_XZ, length)) << endl;

    return 0;
}
