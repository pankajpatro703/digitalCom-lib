#include <stdio.h>
#include "sdes.h"
void main()
{
    char p10[10]={3,5,2,7,4,10,1,9,8,6};
    char p8[8]={6,3,7,4,8,5,10,9};
    char k1[9],k2[9],temp[11];
    char IP[8]={2,6,3,1,4,8,5,7};
    char invIP[8]={4,1,3,5,7,2,8,6};
    char cipher[9],plain[9];
    keygen(p10,p8,k1,k2);
    printf("Enter cipher-text  :");
    scanf("%s",cipher); 
    cipher[8]='\0';
    printf("Permutation IP     :");
    display(IP,10);
    permutation(IP,cipher,temp,8);   
    printf("\nBits after IP      :");
    puts(temp);
    fk(temp,k2);
    printf("Bits after round1  :");
    puts(temp);
    sw(temp);
    printf("Bits after swap    :");
    puts(temp);
    fk(temp,k1);
    printf("Bits after round2  :");
    puts(temp);
    permutation(invIP,temp,plain,8); 
    printf("Permutation IP(-1) :");
    display(invIP,8);
    printf("\nPlain Text         :");
    puts(plain);
}
