#include <stdio.h>
#include <stdlib.h>
#include "functionHeaders.h"
#include <ctype.h>

int main(){
    char ch;
    do{
        printf("------*------*------*------*------*------\n");
        printf("Choose an Option:- \n");
        printf("1. Perform Matrix Calculations\n2. Calculate Area, Volume, Perimeter...\n3. Convert number\nQ For Quit\n");
        fflush(stdin);
        printf("------*------*------*------*------*------\n>>> ");
        scanf("%c",&ch);
        if (ch=='1'){
            matMain();
        }
        else if (ch=='2'){
            areaVolMain();
        }
        else if(ch=='3'){
            convertMain();
        }
        else if(tolower(ch)=='q'){
            printf("Quitting...\n");
        }
        else{
            printf("Invalid Option. Try again\n");
            continue;
        }
    }while(tolower(ch)!='q');
    return 0;
}