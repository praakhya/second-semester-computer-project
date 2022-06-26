#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "functionHeaders.h"

int validNumByBase(char* num, int base)
{
    for (int i=0; i<strlen(num); ++i)
    {
        if (alphaToNum(num[i])>=base)
        {
            return 0;
        }
    }
    return 1;
}
int alphaToNum(char a){
    int digA=10, res;
    if ((a>='A')&&(a<='Z')){
        res=digA+(a-'A'); //converting a given letter to its hexadecimal value
    }
    else if((a>='0')&&(a<='9')) {
        res=a-'0'; //converting the character of number to its integer
    }
    return res;
}
char numToAlpha(int a){
    int digA=10;
    char res;
    if (a>=10){
        res=a-digA+'A'; //converting a given letter to its hexadecimal value
    }
    else{
        res=a+'0'; //converting the character of number to its integer
    }
    return res;
}
/*
long long convertToNum(char* num){
    long n=0;
    int len=strlen(num);
    for (int i=0; i<len; ++i){
        n+=(num[i]-'0')*pow(10,len-i-1);
    }
    return n;
}
*/

long long toDec(char* num, int b){
    long dn=0; //the resultant decimal number
    int n=0, len=strlen(num); 
    while (n<len){
        int dig=alphaToNum(num[len-n-1]); //digA contains hexadecimal value of A
        if (dig<b){
            dn+=pow(b, n)*dig; //(base^n)*(number's digit)
            ++n;
        }
        else{
            dn=-1;
            break;
        }  
    }
    return dn;
}

long long toBin(char* num, int b){ 
    
    long long dn=toDec(num,b), res=dn, bn=0;
    int rem,i=0,lastChk=0;
    while ((res>0)){
        rem=res%2;
        res=res/2;
        bn+=rem*pow(10,i);
        ++i;
    }
    return bn;
}
void reverse(char* num){
    char temp;
    int len=strlen(num);
    for (int i=0; i<len/2; ++i){
        temp=num[i];
        num[i]=num[len-i-1];
        num[len-i-1]=temp;
    }
}
int getLen(long num){
    int len=0, val=1;
    while (val<num){
        val*=10;
        ++len;
    }
    return len;

}

char* toHex(char* num, int b){
    long long res=toDec(num, b);
    char sres[32];
    sprintf(sres,"%lld",res);
    int rem,len=strlen(sres);
    char* hn= (char*) calloc(len, sizeof(char));
    int i = 0;
    while(res>0) {
        rem=res%16;
        res=(res/16);
        hn[i]=numToAlpha(rem);
        hn[i+1] = 0;
        ++i;
    }
    reverse(hn);
    return hn;
}
long long toOct(char* num, int b){ 
    long long dn=toDec(num,b), res=dn, bn=0;
    int rem,i=0,lastChk=0;
    while ((res>0)){
        rem=res%8;
        res=res/8;
        bn+=rem*pow(10,i);
        ++i;
        
    }
    return bn;
}
void prettyPrint_ops(char* num1, char* type1, char* num2, char* type2){
    printf("%s (%s) --> %s (%s)\n",num1, type1, num2, type2);
}
void prettyPrint_opi(char* num1, char* type1, int num2, char* type2){
    printf("%s (%s) --> %lld (%s)\n",num1, type1, num2, type2);
}
struct type{
    char name[20];
    int base;
}typedef type;
void printOpt(type types[4]){
    int len=4;
    for (int i=0; i<len; ++i){
        printf("%d. %s\n",i+1,types[i].name);
    }
}
void printHead(){
    system("clear");
    printf("         __________________\n");
    printf("--------|Converting Numbers|--------\n");
    printf("         ------------------\n");
}
int valid(int opt){
    if ((opt<1)||(opt>4)){
        printf("Invalid option\n");
        return 0;
    }
    return 1;
}
int baseOfChosen(type* types)
{
    int opt;
    scanf("%d",&opt);
    while(!valid(opt))
    {
        printf("Invalid option. Try again\n");
        scanf("%d",&opt);
    }
    return types[opt-1].base;
}
char* getTypeName(int b,type* types)
{
    for (int i=0; i<4; ++i)
    {
        if (types[i].base==b)
        {
            return types[i].name;
        }
    }
    return NULL;
}
void convertMain()
{
    type types[4]={{"Decimal",10},{"Hexadecimal",16},{"Binary",2},{"Octal",8}};
    char value[256];
    printHead();
    char ch='y';
    int initBase;
    int finBase;
    while(tolower(ch)=='y')
    {   
        printf("\nAvailable Bases:-\n");
        printOpt(types);
        printf("Initial Base: ");
        initBase = baseOfChosen(types);
        printf("\n");
        printf("Enter value to be converted: ");
        scanf("%s",value);
        printf("\n");
        if (!validNumByBase(value,initBase))
        {
            printf("Incorrect number as per base! Try again\n");
            continue;
        }
        printf("Final Base: ");
        finBase = baseOfChosen(types);
        printf("\n");
        switch (finBase)
        {
            case 2:
                prettyPrint_opi(value, getTypeName(initBase,types), toBin(value,initBase),getTypeName(finBase,types));
                break;
            case 8:
                prettyPrint_opi(value, getTypeName(initBase,types), toOct(value,initBase),getTypeName(finBase,types));
                break;
            case 10:
                prettyPrint_opi(value, getTypeName(initBase,types), toDec(value,initBase),getTypeName(finBase,types));
                break;
            case 16:
            {
                char* hn=toHex(value,initBase);
                prettyPrint_ops(value, getTypeName(initBase,types), hn,getTypeName(finBase,types));
                free(hn);
                break;
            }
        }
        fflush(stdin);
        printf("Continue conversions?: ");
        scanf("%c",&ch);
        
    }
/*
void prettyPrint_ops(char* num1, char* type1, char* num2, char* type2){
    printf("%s (%s) --> %s (%s)\n",num1, type1, num2, type2);
}
void prettyPrint_opi(char* num1, char* type1, int num2, char* type2){
    printf("%s (%s) --> %d (%s)\n",num1, type1, num2, type2);
}
*/

}
