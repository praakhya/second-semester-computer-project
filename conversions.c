#include <stdio.h>
#include <math.h>
#include <string.h>
long binOctToDec(long bn, int b){
    long temp=bn, dn=0;
    int n=0;
    printf("dn    temp     n\n");
    printf("%ld %ld %d\n", dn, temp, n);
    while (temp>0){
        int dig=temp%10;
        if (dig<b){
            dn+=pow(b, n)*(dig);
            printf("%ld %ld %d\n", dn, temp, n);
            temp/=10;
            n+=1;
        }
        else {
            return -1;
        }
        
        
    }
    return (long) dn;
}
long hexToDec(char* hn){
    long dn=0;
    int n=0, len=strlen(hn);
    while (n<len){
        int dig, digA=10, dig0=48;
        if ((hn[len-n-1]>=65)&&(hn[len-n-1]<=70)){
            dig=digA+(hn[len-n-1]-'A');
        }
        else if((hn[len-n-1]>=48)&&(hn[len-n-1]<=57)) {
            dig= hn[len-n-1]-'0';
        }
        printf("char: %c, dig: %d\n",hn[len-n-1], dig);
        dn+=pow(16, n)*dig;
        ++n;
    }
    return dn;
}


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

int main(){
    convertor(2);
    convertor(8);
    convertor(16);
}