#include<stdio.h>
#include<string.h>
int i,cnt=0;
void display(char a[],int n)
{
	for(i=0; i<n; i++)
  	printf("%d ",a[i]); 
}
void permutation(char P[], char a[], char rtn[],int n)
{
	for(i=0; i<n; i++)
    {
        cnt = P[i];
   	    rtn[i] = a[cnt-1];
    }
  rtn[i]='\0';
}
void lshift(char m[])
{
	char a;
	a=m[0];
	for(i=0; i<4; i++)
		m[i]=m[i+1];
    m[4]=a;
    a=m[5];
    for(i=5; i<9; i++)
        m[i]=m[i+1];
    m[9]=a;
}
void sw(char m[])
{
	char t;
	for(i=0;i<4;i++)
	{
		t=m[i];
		m[i]=m[i+4];
		m[i+4]=t;
	}
}
char F(char m[],char k[])
{
	char x[8],z[4];
	int r1,c1,r2,c2;
	char EP[8]={4,1,2,3,2,3,4,1};
	char p4[4]={2,4,3,1};
	int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
	int s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
	permutation(EP,m,x,8);	
	for(i=0; i<8; i++)
        x[i]=(char)((int)x[i]^(int)k[i]);
    r1=2*(int)(x[0])+(int)(x[3]);
    c1=2*(int)(x[1])+(int)(x[2]);
    r2=2*(int)(x[4])+(int)(x[7]);
	c2=2*(int)(x[5])+(int)(x[6]);
	z[0]=(char)s0[r1][c1]/2;
    z[1]=(char)s0[r1][c1]%2;
    z[2]=(char)s1[r2][c2]/2;
    z[3]=(char)s1[r2][c2]%2;
    permutation(p4,z,m,4);		
}
void fk(char m[],char k[])
{
	char x[4];
	for(i=0;i<4;i++)
		x[i]=m[i+4];
	F(x,k);
	for(i=0;i<4;i++)
	{
		x[i]=(char)((int)x[i]^(int)m[i]);
		m[i]=x[i];
	}
}
void keygen(char p10[],char p8[],char k1[],char k2[])
{ 
	char key[11], temp[11];
	char LS1[5], LS2[5];
	printf("Enter 10 bits key  :");
    scanf("%s",key); 
    key[10]='\0';
	printf("Permutation p10    :");
    display(p10,10);
    printf("\nPermutation p8     :");
    display(p8,8);
	permutation(p10,key,temp,10);		  
    printf("\nBits after p10     :");
    puts(temp);
    lshift(temp);
    printf("Output after LS-1  :");
    puts(temp);
	permutation(p8,temp,k1,8);		
    printf("Your key k1 is     :");
    puts(k1); 
    lshift(temp);
    lshift(temp);
    printf("Output after LS-2  :");
    puts(temp);
    permutation(p8,temp,k2,8);		
    printf("Your key k2 is     :");
    puts(k2);
}
