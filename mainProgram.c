#include <stdio.h>
#include <stdlib.h>
#include "functionHeaders.h"
#include <ctype.h>
#include <unistd.h>

int main(){
    char ch;
    
    do{
        sleep(2);
        system("clear");
        printf("------*------*------*------*------*------\n");
        printf("Choose an Option:- \n");
        printf("1. Perform Matrix Calculations\n2. Calculate Area, Volume, Perimeter...\n3. Convert number\n4. Trignometric Operations\n5. Scientific Calculator\nQ For Quit\n");
        fflush(stdin);
        printf("------*------*------*------*------*------\n>>> ");
        scanf("%c",&ch);
        fflush(stdin);
        switch(ch)
        {
            case '1':
                matMain();
                break;
            case '2':
                areaVolMain();
                break;
            case '3':
                convertMain();
                break;
            case '4':
                trigMain();
                break;
            case '5':
                sciMain();
                break;
            default:
                if(tolower(ch)=='q'){
                    printf("Quitting...\n");
                }
                else{
                    printf("Invalid Option. Try again\n");
                    continue;
                }
        }
        
    } while(tolower(ch)!='q');
    return 0;
}