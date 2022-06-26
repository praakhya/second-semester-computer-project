#include <stdio.h>
#include <string.h>
#include <math.h> //for pow() function
int radians(float a)
{
    return a*(3.14/180); 

}
int fact(int n)
{
    if (n<=0)
    {
        return 1;
    }
    return n*fact(n-1);
}
float sine(float angle,char* radDeg)
{
    int n;
    float x;
    if (strcmp(radDeg,"deg")==0)
    {
        x=radians(angle);
    }
    else if(strcmp(radDeg,"rad")==0)
    {
        x=angle;
    }
    else
    {
        printf("Error: Angle is neither in radians or degrees or specified incorectly.\n");
        return -2; //value to show error is -2 since sine can never have values less than -1.
    }
    float term;
    float sinVal=0;
    float prevVal=-1;
    for (n=0; n<50; ++n)
    {
        printf("%d: %f, %f\n",n,sinVal,term);
        term=(x/fact((2*n)+1))*pow(-1,n);
        /*if (prevVal==sinVal)
        {
            return sinVal;
        }*/
        prevVal=sinVal;
        sinVal+=term;
    }
    return sinVal;
    
}

int main()
{
    printf("%f\n", sine(60,"deg"));

}