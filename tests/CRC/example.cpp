#include <iostream>
#include <iomanip>
#include "../../src/CRC/crc.hpp"
using namespace std;

int main() {
    uint8_t message[] = "Hello. This is the message.";
    unsigned int length = sizeof(message)-1;

    //uint8_t message[] = {0x48,0x65,0x6c,0x6c,0x6f};
    //unsigned int length = sizeof(message);

    CRCbase<uint8_t>* ptr8;
    ptr8 = new LiteCRC<uint8_t>(CRC8_AUTOSAR);          cout << "8-bit AUTOSAR CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_BLUETOOTH);        cout << "8-bit BLUETOOTH CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_CDMA2000);         cout << "8-bit CDMA2000 CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_DARC);             cout << "8-bit DARC CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_DVB_S2);           cout << "8-bit DVB-S2 CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_EBU);              cout << "8-bit EBU CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_GSM_A);            cout << "8-bit GSM-A CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_GSM_B);            cout << "8-bit GSM-B CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_ITU);              cout << "8-bit ITU CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_I_CODE);           cout << "8-bit I-CODE CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_LTE);              cout << "8-bit LTE CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_MAXIM);            cout << "8-bit MAXIM CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_MIFARE_MAD);       cout << "8-bit MIFARE-MAD CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_NRSC_5 );          cout << "8-bit NRSC-5 CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_OPENSAFETY);       cout << "8-bit OPENSAFETY CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_ROHC);             cout << "8-bit ROHC CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_SAE_J1850);        cout << "8-bit SAE-J1850 CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_SMBUS);            cout << "8-bit SMBUS CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    ptr8 = new LiteCRC<uint8_t>(CRC8_WCDMA);            cout << "8-bit WCDMA CRC of the message is " << hex << setfill('0') << setw(2) << (int)ptr8->getCRC(message, length) << endl;
    delete ptr8;

    CRCbase<uint16_t>* ptr16;
    ptr16 = new LiteCRC<uint16_t>(CRC16_A);             cout << "16-bit A CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_ARC);           cout << "16-bit ARC CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_AUG_CCITT);     cout << "16-bit AUG-CCITT CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_B);             cout << "16-bit B CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_CCITT_FALSE);   cout << "16-bit CCITT-FALSE CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_CDMA2000);      cout << "16-bit CDMA2000 CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_CMS);           cout << "16-bit CMS CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_DDS_110);       cout << "16-bit DDS-110 CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_DECT_R);        cout << "16-bit DECT-R CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_DECT_X);        cout << "16-bit DECT-X CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_DNP);           cout << "16-bit DNP CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_EN_13757);      cout << "16-bit EN-13757 CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;    
    ptr16 = new LiteCRC<uint16_t>(CRC16_GENIBUS);       cout << "16-bit GENIBUS CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_GSM);           cout << "16-bit GSM CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_KERMIT);        cout << "16-bit KERMIT CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_LJ1200);        cout << "16-bit LJ1200 CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_MAXIM);         cout << "16-bit MAXIM CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_MCRF4XX);       cout << "16-bit MCRF4XX CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_MODBUS);        cout << "16-bit MODBUS CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_NRSC_5);        cout << "16-bit NRSC-5 CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_OPENSAFETY_A);  cout << "16-bit OPENSAFETY-A CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_OPENSAFETY_B);  cout << "16-bit OPENSAFETY-B CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_PROFIBUS);      cout << "16-bit PROFIBUS CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_RIELLO);        cout << "16-bit RIELLO CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_T10_DIF);       cout << "16-bit T10-DIF CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_TELEDISK);      cout << "16-bit TELEDISK CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_TMS37157);      cout << "16-bit TMS37157 CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_UMTS);          cout << "16-bit UMTS CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_USB);           cout << "16-bit USB CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    ptr16 = new LiteCRC<uint16_t>(CRC16_XMODEM);        cout << "16-bit XMODEM CRC of the message is " << hex << setfill('0') << setw(4) << (uint16_t)ptr16->getCRC(message, length) << endl;
    delete ptr16;

    CRCbase<uint32_t>* ptr32;
    ptr32 = new LiteCRC<uint32_t>(CRC32_ADCCP);         cout << "32-bit ADCCP CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_AUTOSAR);       cout << "32-bit AUTOSAR CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_BZIP2);         cout << "32-bit BZIP2 CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_C);             cout << "32-bit C CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_CD_ROM_EDC);    cout << "32-bit CD-ROM-EDC CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_D);             cout << "32-bit D CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_JAMCRC);        cout << "32-bit JAMCRC CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_MPEG2);         cout << "32-bit MPEG2 CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_POSIX);         cout << "32-bit POSIX CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_Q);             cout << "32-bit Q CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    ptr32 = new LiteCRC<uint32_t>(CRC32_XFER);          cout << "32-bit XFER CRC of the message is " << hex << setfill('0') << setw(8) << (uint32_t)ptr32->getCRC(message, length) << endl;
    delete ptr32;

    CRCbase<uint64_t>* ptr64;
    ptr64 = new LiteCRC<uint64_t>(CRC64_ECMA_182);      cout << "64-bit ECMA-182 CRC of the message is " << hex << setfill('0') << setw(16) << (uint64_t)ptr64->getCRC(message, length) << endl;
    ptr64 = new LiteCRC<uint64_t>(CRC64_GO_ISO);        cout << "64-bit GO-ISO CRC of the message is " << hex << setfill('0') << setw(16) << (uint64_t)ptr64->getCRC(message, length) << endl;
    ptr64 = new LiteCRC<uint64_t>(CRC64_WE);            cout << "64-bit WE CRC of the message is " << hex << setfill('0') << setw(16) << (uint64_t)ptr64->getCRC(message, length) << endl;
    ptr64 = new LiteCRC<uint64_t>(CRC64_XZ);            cout << "64-bit XZ CRC of the message is " << hex << setfill('0') << setw(16) << (uint64_t)ptr64->getCRC(message, length) << endl;
    delete ptr64;

    return 0;
}
