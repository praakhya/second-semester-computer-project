#include <stdio.h>
//#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "functionHeaders.h"
void A_Circle(char c1)
{
    int r;
    printf("\n Enter the radius of the circle: \n");
    fflush(stdin);
    scanf("%d", &r);
    fflush(stdin);
    if (c1=='1')
    {
        printf("\n The area of the circle is: %.3f\t", ((22 / 7) * pow(r,2)));
    }
    else
    {
        printf("\n The Circumference of the circle is:%.3d\t", (2 * (22 / 7) * r));
    }
}
void A_Rect(char r1)
{
    int l, b;
    printf("\n Enter the length and breadth of the rectangle: \n");
    fflush(stdin);
    scanf("%d%d", &l, &b);
    fflush(stdin);
    if (r1 == '1')
    {
        printf("\n The area of the rectangle is: %.3d\t", (l * b));
    }
    else
    {
        printf("\n The perimeter of the rectangle is: %.3d\t", (2 * (l + b)));
    }
}
void A_Sq(char sq1)
{
    int side;
    printf("\n Enter the side of the square: \n");
    fflush(stdin);
    scanf("%d", &side);
    fflush(stdin);
    if (sq1 == '1')
    {
        printf("\n The area of the square is:%.3f \t", (pow(side, 2)));
    }
    else
    {
        printf("\n The perimeter of the square is: %.3d\t", (4 * side));
    }
}
void A_Rhom(char rh1)
{
    int side1, side2, diag1, diag2;
    printf("\n Enter the values of the sides and the diagonals of the rhombus: \n");
    fflush(stdin);
    scanf("%d%d%d%d", &side1, &side2, &diag1, &diag2);
    fflush(stdin);
    if (rh1 == '1')
    {
        printf("\n The area of the rhombus is:%.3f \t", (0.5 * diag1 * diag2));
    }
    else
    {
        printf("\n The perimeter of the rhombus is: %.3d\t", (2 * (side1 + side2)));
    }
}
void A_Prll(char prl1)
{
    int pside1, pside2, pbase, pheight;
    printf("\n Enter the values of the sides, base and height of the parallelogram: \n");
    fflush(stdin);
    scanf("%d%d%d%d", &pside1, &pside2, &pbase, &pheight);
    fflush(stdin);
    if (prl1 == '1')
    {
        printf("\n The area of the parallelogram  is:%.3d\t", (pbase * pheight));
    }
    else
    {
        printf("\n The perimeter of the parallelogram is: %.3d\t", (2 * (pside1 + pside2)));
    }
}
void A_Tri(char tri1)
{
    int ta, tb, tc, sp;
    printf("\n Enter the values sides of the triangle: \n");
    fflush(stdin);
    scanf("%d%d%d", &ta, &tb, &tc);
    fflush(stdin);
    if (tri1 == '1')
    {
        sp = (ta + tb + tc) / 2;
        printf("\n The area of the triangle is:%.3f \t", (sqrt(sp * (sp - ta) * (sp - tb) * (sp - tc))));
    }
    else
    {
        printf("\n The perimeter of the triangle is: %.3d\t", (ta + tb + tc));
    }
}
void A_trpzoid(char trp1)
{
    int trs1, trs2, trh;
    printf("\n Enter the values of parallel  sides and height of the trapezoid: \n");
    fflush(stdin);
    scanf("%d%d%d", &trs1, &trs2, &trh);
    fflush(stdin);
    if (trp1 == '1')
    {
        printf("\n The area of the trapezoid is:%.3f \t", (0.5 * (trs1 + trs2) * trh));
    }
    else
    {
        int trs3, trs4;
        printf("\nEnter the values of the other two sides of the trapezoid\n:");
        scanf("%d%d", &trs3, &trs4);
        printf("\n The perimeter of the trapezoid is: %.3d\t", (trs1 + trs2 + trs3 + trs4));
    }
}
void A_SemiCrcl(char sc1)
{
    int scr;
    printf("\n Enter the radius of the semi-circle: \n");
    fflush(stdin);
    scanf("%d", &scr);
    fflush(stdin);
    if (sc1 == '1')
    {
        printf("\n The area of the semi-circle is:%.3f \t", (0.5 * (22 / 7) * pow(scr, 2)));
    }
    else
    {
        printf("\n The perimeter of the semi-circle is: %.3d\t", ((scr * (22 / 7)) + (2 * scr)));
    }
}
void V_Cboid(char cuboid)
{
    int cl, cb, ch;
    printf("\n Enter the length, breadth and height of the cuboid: \n");
    fflush(stdin);
    scanf("%d%d%d", &cl, &cb, &ch);
    fflush(stdin);
    if (cuboid == '2')
    {
        printf("\n The volume of the cuboid is:%.3d \t", (cl * cb * ch));
    }
    else
    {
        printf("\n The Total surface of the cuboid is: %.3d\t", (2 * ((cl * cb) + (cl * ch) + (ch * cb))));
    }
}
void V_Cube(char cube)
{
    int csa;
    printf("\nEnter the value of side of cube: \n");
    fflush(stdin);
    scanf("%d", &csa);
    fflush(stdin);
    if (cube != '2')
    {
        printf("\n The volume of the cube is:%.3f \t", (pow(csa, 3)));
    }
    else
    {
        printf("\n The Total surface of the cube is: %.3f\t", (6 * pow(csa, 2)));
    }
}
void V_Cyln(char cyl1)
{

    int cyr, cyh;
    printf("\n Enter the radius and height of the cylinder: \n");
    fflush(stdin);
    scanf("%d%d", &cyr, &cyh);
    fflush(stdin);
    if (cyl1 == '2')
    {
        printf("\n The volume of the cylinder is:%.3d \t", ((22 / 7) * cyr * cyh));
    }
    else
    {
        printf("\n The Total surface of the cylinder is: %.3d\nThe Curved Surface Area of the cylinder is:%.3d", (2 * (22 / 7) * cyr * (cyr + cyh)), (2 * (22 / 7) * cyr * cyh));
    }
}
void V_Cone(char cone1)
{
    int col, cor, coh;
    printf("\n Enter the length and height of the cone: \n");
    fflush(stdin);
    scanf("%d%d", &col, &coh);
    fflush(stdin);
    col = sqrt((pow(cor, 2) + pow(coh, 2)));
    if (cone1 == '2')
    {
        printf("\n The volume of the cone is:%.3f \t", ((1 / 3) * (22 / 7) * pow(cor, 2) * coh));
    }
    else
    {
        printf("\n The Total surface of the cone is: %.3d\t\n The Curved Surface Area:%.3d\t \n", ((22 / 7) * cor * (cor + col)), ((22 / 7) * cor * col));
    }
}
void V_Sphere(char sph1)
{
    int spr;
    printf("\n Enter the radius of the sphere: \n");
    fflush(stdin);
    scanf("%d", &spr);
    fflush(stdin);
    if (sph1 == '2')
    {
        printf("\n The volume of the sphere is:%.3f \t", ((4 / 3) * (22 / 7) * pow(spr, 3)));
    }
    else
    {
        printf("\n The Total surface of the sphere is: %.3f\t", (4 * (22 / 7) * pow(spr, 2)));
    }
}
void V_HSphere(char HS1)
{
    int hsr;
    printf("\n Enter the radius of the hemisphere: \n");
    fflush(stdin);
    scanf("%d", &hsr);
    fflush(stdin);
    if (HS1 == '2')
    {
        printf("\n The volume of the hemisphere  is:%.3f \t", ((2 / 3) * (22 / 7) * pow(hsr, 3)));
    }
    else
    {
        printf("\n The Total surface of the hemisphere is: %.3f\t\nThe Curved Surface Area of the hemisphere  is:%.3f", (3 * (22 / 7) * pow(hsr, 2)), (2 * (22 / 7) * pow(hsr, 2)));
    }
}
void V_Frustrum(char Frstm1)
{
    int fur, flr, fsl, fh, fb1, fb2;
    printf("\n Enter the upper radius, lower radius, slant height, altitude/height, base area1, base area2: \n");
    fflush(stdin);
    scanf("%d%d%d%d%d%d", &fur, &flr, &fsl, &fh, &fb1, &fb2);
    fflush(stdin);
    if (Frstm1 == '2')
    {
        printf("\n The volume of the frustum is:%.3f \t", ((1 / 3) * fh * (fb1 + fb2 + (sqrt(fb1 * fb2)))));
    }
    else
    {
        printf("\n The Total surface of the frustum is: %.3f\t", (((22 / 7) * (fur + flr) * fsl) + ((22 / 7) * pow(fur, 2)) + ((22 / 7) * pow(flr, 2))));
    }
}
void quit()
{
    printf("----------------\nThank You\n----------------\n");
}
void areaVolMain()
{
    // int ch;
    char ch, ch1;
    do
    {
        printf("________________________\nSelect :\n________________________\n");
        printf("1. Area\n2.Volume\n3.Perimeter\n4.Surface Area\nQ:Quit.\n________________________\n");
        fflush(stdin);
        scanf("%c", &ch);
        fflush(stdin);
        if ((ch == '1') || (ch == '3'))
        {
            printf("************\nSelect the surface:\n************");
            printf("\na.Circle\nb.Rectangle\nc.Square\nd.Rhombus\ne.Parallelogram\nf.Triangle\ng.Trapezoid\nh:Semi Circle\n");
            fflush(stdin);
            scanf("%c\n", &ch1);
            fflush(stdin);
            switch (ch1)
            {
            case 'a':
            {
                A_Circle(ch1);
                break;
            }
            case 'b':
            {
                A_Rect(ch1);
                break;
            }
            case 'c':
            {
                A_Sq(ch1);
                break;
            }
            case 'd':
            {
                A_Rhom(ch1);
                break;
            }
            case 'e':
            {
                A_Prll(ch1);
                break;
            }
            case 'f':
            {
                A_Tri(ch1);
                break;
            }
            case 'g':
            {
                A_trpzoid(ch1);
                break;
            }
            case 'h':
            {
                A_SemiCrcl(ch1);
                break;
            }
            default:
                printf("\nInvalid Choice!\n");
            }
        }
        else if ((ch == '2') || (ch == '4'))
        {
            printf("Select the solid : \n");
            printf("A.Cuboid\nB.Cube\nC.Cylinder\nD.Cone\nE.Sphere\nF.Hemisphere\nG:Frustum\n");
            fflush(stdin);
            scanf("%c", &ch1);
            fflush(stdin);
            switch (ch1)
            {
            case 'A':
            {
                V_Cboid(ch1);
                break;
            }
            case 'B':
            {
                V_Cube(ch1);
                break;
            }
            case 'C':
            {
                V_Cyln(ch1);
                break;
            }
            case 'D':
            {
                V_Cone(ch1);
                break;
            }
            case 'E':
            {
                V_Sphere(ch1);
                break;
            }
            case 'F':
            {
                V_HSphere(ch1);
                break;
            }
            case 'G':
            {
                V_Frustrum(ch1);
                break;
            }
            default:
                printf("\nInvalid Choice!");
            }
        }

        else if (tolower(ch) == 'q')
        {
            quit();
        }
        else
        {
            printf("Choice invalid\n");
            continue;
        }
    } while (tolower(ch)!='q');
}



