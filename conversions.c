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
    printf("in convertToNum\n");
    long n=0;
    printf("---- %s\n",num);
    int len=strlen(num);
    for (int i=0; i<len; ++i){
        n+=(num[i]-'0')*pow(10,len-i-1);
        printf(">>%ld\n",n);
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
    printf("%s  -->  %ld\n",num,dn);
    return dn;
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
    //convertor(2);
    //convertor(8);
    //convertor(16);
    printf("Binary to Decimal\n");
    toDec("0",2);
    toDec("1",2);
    toDec("10",2);
    toDec("11",2);
    toDec("100",2);
    toDec("101",2);
    toDec("110",2);
    toDec("111",2);
    toDec("1000",2);
    toDec("1001",2);
    toDec("1010",2);
    toDec("1011",2);
    toDec("1100",2);
    toDec("1101",2);
    toDec("1110",2);
    toDec("1111",2);
    printf("--------------\nHexadecimal to Decimal\n");
    toDec("0",16);
    toDec("1",16);
    toDec("2",16);
    toDec("3",16);
    toDec("4",16);
    toDec("5",16);
    toDec("6",16);
    toDec("7",16);
    toDec("8",16);
    toDec("9",16);
    toDec("A",16);
    toDec("B",16);
    toDec("C",16);
    toDec("D",16);
    toDec("E",16);
    toDec("F",16);
    toDec("10",16);
    printf("--------------\nOctal to Decimal\n");
    toDec("0",8);
    toDec("1",8);
    toDec("2",8);
    toDec("3",8);
    toDec("4",8);
    toDec("5",8);
    toDec("6",8);
    toDec("7",8);
    toDec("10",8);
    toDec("11",8);
    toDec("12",8);
    toDec("13",8);
    toDec("14",8);
    toDec("15",8);
    toDec("16",8);
    toDec("17",8);
    toDec("18",8);
    return 0;
}