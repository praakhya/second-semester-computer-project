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
/*
void toHex(char* num, int b){
    long convertedToDec;
    printf("In toHex\n");
    convertedToDec=toDec(num, b);
    long res=convertedToDec;
    int rem,i=0,dn;
    char* hexNum;
    while (res>0){   
        printf("in while\n"); 
        rem=res%16;
        res=(res/16);
        dn+=rem*pow(10,i);
        printf(">>> res=%ld\n   rem=%d\n   dn=%d\n",res,rem,dn);
        ++i;
    }
    hexNum = (char*) malloc(i * sizeof(char));
    for (int i=0; i<strlen(hexNum); ++i){
        
    }
}
*/
/*
void convertor(int base){
    if (base==2){
        long n;
        //scanf("%ld",&n);
        n=111000;
        printf("\n%ld (Binary) ---> %ld (Decimal)\n",n,binOctToDec(n,2));
    }
    else if (base==8){
        long n;
        //scanf("%ld",&n);
        n=78;
        printf("\n%ld (Octal) ---> %ld (Decimal)\n",n,binOctToDec(n,8));
    }
    else if (base==16){
        char n[100]="FFF222";
        //scanf("%s",n);
        printf("\n%s (Hex) ---> %ld (Decimal)\n",n,hexToDec(n));
    }
}
*/
int main(){
    //toBin("FFF",16);
    printf("7 to binary %ld\n",toBin("7",10));
    printf("FFF to binary %ld\n",toBin("FFF",16));
    printf("10 to binary %ld\n",toBin("10",8));
    
}