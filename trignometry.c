#include <stdio.h>
#include <string.h>
#include <math.h>// for pow()
const double pi=3.141592653589793238;
double radians(float a)
{
    return a*(pi/180); 

}
long double fact(long n)
{
    if (n<=0)
    {
        return 1.0;
    }
    return n*fact(n-1);
}
long double sine(float angle,char* radDeg)
{
    int n;
    double x;
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
    long double term;
    long double sinVal=0;
    int prec=7;
    for (n=0; n<prec; ++n)
    {
        
        term=(pow(x,(2*n)+1)/fact((2*n)+1))*(n%2==0?1:-1);
        sinVal+=term;
    }
    return sinVal;
    
}
long double cosine(float angle,char* radDeg)
{
    long double cosVal = sqrt(1-pow(sine(angle,radDeg),2));
    return cosVal;
}
long double tangent(float angle,char* radDeg)
{
    long double cosVal = cosine(angle,radDeg);
    long double sinVal = sine(angle,radDeg);
    long double tanVal = sinVal/cosVal;
    return tanVal;
}
long double cotangent(float angle,char* radDeg)
{
    long double tanVal = tangent(angle,radDeg);
    long double cotVal=1/tanVal;
    return cotVal;
}
long double secant(float angle,char* radDeg)
{
    long double cosVal = cosine(angle,radDeg);
    long double secVal=1/cosVal;
    return secVal;
}
long double cosecant(float angle,char* radDeg)
{
    long double sinVal = sine(angle,radDeg);
    long double cosecVal=1/sinVal;
    return cosecVal;
}
void printTrigResult(long double val)
{
    if (isnan(val)||isinf(val))
    {
        printf("\u221E(inf)");
    }
    else
    {
        printf("%.3Lf", val);
    }
    
}
void printTrigTable(int step)
{
    printf("%5s:\t%5s\t%5s\t%5s\t%5s\t%5s\t%5s\n","angle","sin","cos","tan","cosec","sec","cot");
    for(int i=0; i<361; i+=step)
    {
        printf("%5d\t",i);
        printTrigResult(sine(i,"deg"));
        printf("\t ");
        printTrigResult(cosine(i,"deg"));
        printf("\t ");
        printTrigResult(tangent(i,"deg"));
        printf("\t ");
        printTrigResult(cosecant(i,"deg"));
        printf("\t ");
        printTrigResult(secant(i,"deg"));
        printf("\t ");
        printTrigResult(cotangent(i,"deg"));
        printf("\n");
    }
}

int main()
{
    printTrigTable(10);

}