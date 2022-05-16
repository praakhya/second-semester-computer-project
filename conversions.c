#include <stdio.h>
#include <math.h>
#include <string.h>
long binToDec(long bn, int b){
    long temp=bn, dn=0;
    int n=0;
    printf("dn    temp     n\n");
    printf("%ld %ld %d\n", dn, temp, n);
    while (temp>0){
        dn+=pow(b, n)*(temp%10);
        printf("%ld %ld %d\n", dn, temp, n);
        temp/=10;
        n+=1;
        
    }
    return (long) dn;
}
long hexToDec(char* hn){
    long dn=0;
    int n=0, len=strlen(hn);
    printf("%10s    %3s     %3s\n","dn","hn[n]","n");
    printf("%10ld    %3c     %3d\n",dn,hn[n],n);
    while (n<len){
        int dig;
        
        if (hn[len-n-1]=='F'){
            dig=pow(16, n)*15;
        }
        else if (hn[len-n-1]=='E'){
            dig=pow(16, n)*14;
        }
        else if (hn[len-n-1]=='D'){
            dig=pow(16, n)*13;
        }
        else if (hn[len-n-1]=='C'){
            dig=pow(16, n)*12;
        }
        else if (hn[len-n-1]=='B'){
            dig=pow(16, n)*11;
        }
        else if (hn[len-n-1]=='A'){
            dig=pow(16, n)*10;
        }
        else {
            dig=pow(16, n)*hn[len-n-1];
        }
        printf("%10ld    %3c     %3d  %3.2f   %3d\n",dn,hn[len-n-1],n, pow(16, n),dig);
        dn+=dig;
        ++n;
    }
    return dn;
}
void convertor(int type){
    if (type==1){
        char n[100];
        scanf("%s",n);
        printf("\n%ld\n",hexToDec(n));
    }
}

int main(){
    long (*fun_ptr)(long,int);
    fun_ptr = &binToDec; 
    convertor(1);
}