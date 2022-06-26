#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sciMain()
{
    double x,y,result;
    int choice;
    int running=1;
    do
    {
        printf("Enter the operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. X^Y\n6. X^(1/Y)(nth root)\n7. e^X\n8. ln(X)\n9. log10(X)\n10.10^x\n11.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nY= ");
            scanf("%lf",&y);
            printf("\n%.1f + %.1f = %.1f\n",x,y,x+y);
            break;
            case 2:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nY= ");
            scanf("%lf",&y);
            printf("\n%.1f - %.1f = %.1f\n",x,y,x-y);
            break;
            case 3:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nY= ");
            scanf("%lf",&y);
            printf("\n%.1f * %.1f = %.1f\n",x,y,x*y);
            break;
            case 4:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nY= ");
            scanf("%lf",&y);
            printf("\n%.1f/%.1f = %.2f\n",x,y,(x/y));
            break;
            case 5:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nY= ");
            scanf("%lf",&y);
            printf("\n%.1f^%.1f = %.1f\n",x,y,pow(x,y));
            break;
            case 6:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nY= ");
            scanf("%lf",&y);
            printf("\n%.1f^(1/%.1f) = %.3f\n",x,y,pow(x,1/y));
            break;
            
            case 7:
            printf("\nX= ");
            scanf("%lf",&x);
            
            printf("\ne^(%.1f)= %.3f\n",x,exp(x));

            break;
            case 8:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nln(%.1f)= %.3f\n",x,log(x));
            break;
            case 9:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\nlog10(%.1f)= %.3f\n",x,log10(x));
            break;
            case 10:
            printf("\nX= ");
            scanf("%lf",&x);
            printf("\n10^(%.1f)= %.3f\n",x,pow(10,x));
            break;
            case 11:
            running=0;
            break;
            default:
            printf("\nInvalid Choice!\n");
         }
        



    }while(running);

}