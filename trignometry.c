#include <stdio.h>
#include <string.h>
#include <math.h>// for pow()
#include <ctype.h> //for tolower()
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
double reduceAngle(double a)
{
    int iq=a/(pi);
    double fq=a/(pi);
    a= fq - iq;
    if (iq%2!=0)
    {
        a=-a;
    }
    return a*(pi);
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
    x=reduceAngle(x);
    long double term;
    long double sinVal=0;
    int prec=20;
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
    printf("sinVal: %Lf, cosecVal: %Lf\n",sinVal,cosecVal);
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
        printf("%Lf", val);
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
char* angleUnits()
{
    int opt;
    do
    {
        printf("Choose angle units:-\n1. Degrees\n2. Radians\n");
        scanf("%d",&opt); 
        switch(opt)
        {
            
            case 1:
                return "deg";
                break;
            case 2:
                return "rad";
                break;
            default:
                printf("Incorrect option\nTry again...\n");
                break;
        } 
    } 
    while ((opt!=1)&&(opt!=2));
    return NULL;
}
void calculate(float angle,char* units)
{
    int opt;
    long double (*trigFn)(float, char*);
    printf("Choose the trignometric function\n");
    printf("1. Sine(sin)\n2. Cosine(cos)\n3. Tangent(tan)\n4. Cosecant(cosec)\n5. Secant(sec)\n6.Cotangent(cot)\n");   
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
            printf("sin(%.2f(%s)) = ",angle,units);
            trigFn=&sine;
            break;
        case 2:
            printf("cos(%.2f(%s)) = ",angle,units);
            trigFn=&cosine;
            break;
        case 3:
            printf("tan(%.2f(%s)) = ",angle,units);
            trigFn=&tangent;
            break;
        case 4:
            printf("cosec(%.2f(%s)) = ",angle,units);
            trigFn=&cosecant;
            break;
        case 5:
            printf("sec(%.2f(%s)) = ",angle,units);
            trigFn=&secant;
            break;
        case 6:
            printf("cot(%.2f(%s)) = ",angle,units);
            trigFn=&cotangent;
            break;
        default:
            printf("This trignometric function does not exist\nTry Again...\n");
            calculate(angle,units);
    } 
    printTrigResult(trigFn(angle,units));
    printf("\n");
}
void trigMain()
{
    float angle;
    char* radDeg;
    char ch='y';
    printf("----------------------\n");
    printf("Trignometry Calculator\n");
    printf("----------------------\n");
    while (tolower(ch)=='y')
    {
        printf("---------------------\n");
        printf("Enter an angle: ");
        scanf("%f",&angle);
        radDeg=angleUnits();
        calculate(angle,radDeg);
        printf("Continue calculation?: ");
        fflush(stdin);
        scanf("%c",&ch);
        printf("--------------------\n");
    }
    printf("Program ended.\nThank you.\n------x------\n");
}

