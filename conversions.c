#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
    if (a>10){
        res=a-digA+'A'; //converting a given letter to its hexadecimal value
    }
    else{
        res=a+'0'; //converting the character of number to its integer
    }
    return res;
}
long convertToNum(char* num){
    long n=0;
    int len=strlen(num);
    for (int i=0; i<len; ++i){
        n+=(num[i]-'0')*pow(10,len-i-1);
    }
    return n;
}

long toDec(char* num, int b){
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

long toBin(char* num, int b){ 
    long dn=toDec(num,b), res=dn, bn=0;
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
    long res=toDec(num, b);
    int rem,len=getLen(res);
    char * hn= (char*) calloc(len, sizeof(char));
    int i;
    for (i=0; i<len; ++i){   
            rem=res%16;
        res=(res/16);
        hn[i]=numToAlpha(rem);
    }
    reverse(hn);
    hn[len]='\0';
    return hn;
}
long toOct(char* num, int b){ 
    long dn=toDec(num,b), res=dn, bn=0;
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
    printf("%s (%s) --> %d (%s)\n",num1, type1, num2, type2);
}