#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int f[10][10], s[10][10], r[10][10];
int c1, c2, r1, r2;
char opt;
int sc;

void read(int f[][10], int r0, int c0);

void display(int f[][10], int r2, int c2);
void add(int f[][10], int s[][10], int r[][10], int x, int y);
void subtract(int f[][10], int s[][10], int r[][10], int x, int y);
void scalarm(int f[][10], int r[][10], int scalar, int x, int y);
void multi(int f[][10], int s[][10], int r[][10], int r1, int c2, int r2);
void transpose(int f[][10], int x, int y);
float det(int f[][10], int n);
void cofac(int f[][10], int t[][10], int z, int i, int n);
int dsum(int f[][10], int n);
int adsum(int f[][10], int n);
void rsum(int f[][10], int n, int m);
void csum(int f[][10], int n, int m);
void adjoint(int f[][10], int r[][10], int n, int m);
void matMain()
{   
    printf("________________________________________________________________________________\n");
    printf("\n\n\t\t\t\tMatrix operations:\t\t\t\n\n");
    do
    {
        printf("________________________________________________________________________________\n");

        printf("A) Addition\n");
        printf("B) Subtraction\n");
        printf("C) Scalar multiplication \n");
        printf("D) Matrix multiplication\n");
        printf("E) Transpose\n");
        printf("F) Determinant\n");
        printf("G) Sum of diagonal elements \n");
        printf("H) Trace of the matrix\n");
        printf("I) Row and column sum \n");
        printf("J)Adjoint and inverse\n");
        printf("K)Exit\n");
        printf("________________________________________________________________________________\n");
        printf("Enter the operation to be performed:\t");
        fflush(stdin);
        scanf("%c", &opt);
        
        switch (opt)
        {
        case 'A':
            printf("Enter the row size of the first matrix: ");
           
            scanf("%d", &r1);
            printf("\nEnter the column size of the first matrix: ");
            
            scanf("%d", &c1);
            printf("\nEnter the elements of the first matrix:\n");
            
            read(f, r1, c1);
            printf("\nThe elements of the first matrix are :\n");
            
            display(f, r1, c1);
            printf("\nEnter the row size of the second matrix: ");
            
            scanf("%d", &r2);
            printf("\nEnter the column size of the second matrix: ");
            
            scanf("%d", &c2);
            printf("\nEnter the elements of the second matrix:\n");
            
            read(s, r2, c2);
            printf("\nThe elements of the second matrix are :\n");
           
            display(s, r2, c2);
            
            if ((c1 != c2) || (r1 != r2))
            {
                printf("Addition is not possible\n");
            }
            else
            {
                add(f, s, r, r1, c1);
                printf("\nThe sum of the two matrices:\n");
                display(r, r1, c1);
            }
            break;
        case 'B':
            printf("Enter the row size of the first matrix: ");
            
            scanf("%d", &r1);
            printf("\nEnter the column size of the first matrix: ");
            
            scanf("%d", &c1);
            printf("\nEnter the elements of the first matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the first matrix are :\n");
            display(f, r1, c1);
            printf("\nEnter the row size of the second matrix: ");
            scanf("%d", &r2);
            printf("\nEnter the column size of the second matrix: ");
            scanf("%d", &c2);
            printf("\nEnter the elements of the second matrix:\n");
            read(s, r2, c2);
            printf("\nThe elements of the second matrix are :\n");
            display(s, r2, c2);
            if ((c1 != c2) || (r1 != r2))
            {
                printf("Subtraction is not possible\n");
            }
            else
            {
                subtract(f, s, r, r1, c1);
                printf("\nThe difference of the two matrices:\n");
                display(r, r1, c1);
            }
            
            break;
        case 'C':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);

            printf("Enter the scalar value to be multiplied with the matrix: ");
            scanf("%d", &sc);
            scalarm(f, r, sc, r1, c1);
            printf("\nThe matrix after scalar multiplication:\n");
            display(r, r1, c1);
            
            break;
        case 'D':
            printf("Enter the row size of the first matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the first matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the first matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the first matrix are :\n");
            display(f, r1, c1);
            printf("\nEnter the row size of the second matrix: ");
            scanf("%d", &r2);
            printf("\nEnter the column size of the second matrix: ");
            scanf("%d", &c2);
            printf("\nEnter the elements of the second matrix:\n");
            read(s, r2, c2);
            printf("\nThe elements of the second matrix are :\n");
            display(s, r2, c2);
            if (c1 != r2)
            {
                printf("Matrix multiplication is not possible\n");
            }
            else
            {
                multi(f, s, r, r1, c2, r2);
                printf("The matrix after multiplication:\n");
                display(r, r1, c2);
            }
            
            break;
        case 'E':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);
            printf("Transpose of the matrix is:\n");
            transpose(f, r1, c1);
            

            break;
        case 'F':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);
            if ((c1 != r1))
            {
                printf("Determinant only exists for square matrices\n");
            }
            else
            {

                printf("Determinant of the matrix is : %.0f \n", det(f, r1));
            }
            
            break;
        case 'G':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);
            if (r1 == c1)
            {
                printf("The sum of the principle diagonal elements of  the  matrix:%d\n", dsum(f, r1));
                printf("The sum of the counter diagonal elements of  the  matrix:%d\n\n", adsum(f, r1));
            }
            else
            {
                printf("matrix is not a square matrix,sum of diagonals does not exist.\n");
            }
            
            break;
        case 'H':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);
            if (r1 == c1)
            {
                printf("Trace of the matrix is: %d \n", dsum(f, r1));
            }
            else
                printf("Trace of the matrix cannot be found.\n");
            
            break;
        case 'I':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);
            rsum(f, r1, c1);
            csum(f, r1, c1);
            break;
        case 'J':
            printf("Enter the row size of the matrix: ");
            scanf("%d", &r1);
            printf("\nEnter the column size of the  matrix: ");
            scanf("%d", &c1);
            printf("\nEnter the elements of the  matrix:\n");
            read(f, r1, c1);
            printf("\nThe elements of the matrix are :\n");
            display(f, r1, c1);
            if (r1 != c1)
            {
                printf("Adjoint and inverse dont exist\n");
            }
            else
            {
                if (det(f, r1) == 0)
                {
                    printf("Inverse doesn't exist\n");
                }
                else
                    adjoint(f, r, r1, c1);
            }
            

            break;
        case 'K':
            printf("Thank you ;)\n");
            exit(0);
            
            break;
        default:
            {
            printf("Invalid input.\n");
            printf("Please enter the correct input.\n");
            break;
            }

        }
    }while(opt);
    
}

void read(int f[][10], int r, int c)
{
    int i, j;
    if (r == 0 || c == 0)
    {
        printf("Invalid row/column size\n");
    }

    else
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                scanf("%d", &f[i][j]);
            }
        }
    }
}
void display(int f[][10], int r, int c)
{
    int i, j;
    if (r == 0 || c == 0)
    {
        printf("Invalid row/column size\n");
    }
    else
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%6d", f[i][j]);
            }
            printf("\n");
        }
    }
}
void add(int f[][10], int s[][10], int r[][10], int x, int y)
{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            r[i][j] = f[i][j] + s[i][j];
        }
    }
}

void subtract(int f[][10], int s[][10], int r[][10], int x, int y)

{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            r[i][j] = f[i][j] - s[i][j];
        }
    }
}

void scalarm(int f[][10], int r[][10], int sc, int x, int y)

{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            r[i][j] = sc * f[i][j];
        }
    }
}

void multi(int f[][10], int s[][10], int r[][10], int r1, int c2, int r2)
{
    int i, j, k, sum;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            sum = 0;
            for (k = 0; k < r2; k++)
            {
                sum = sum + (f[i][k] * s[k][j]);
            }
            r[i][j] = sum;
        }
    }
}
void transpose(int f[][10], int x, int y)
{
    int i, j;

    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%6d", f[j][i]);
        }
        printf("\n");
    }
}

float det(int f[][10], int n)
{
    int D = 0, sign = 1, i;
    int t[n][n];
    if (n == 1)
        return f[0][0];
    for (i = 0; i < n; i++)
    {
        cofac(f, t, 0, i, n);
        D += sign * f[0][i] * det(t, n - 1);
        sign = -sign;
    }
    return D;
}
void cofac(int f[][10], int t[][10], int z, int y, int n)
{
    int i = 0, j = 0, r = 0, c = 0;
    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (r != z && c != y)
            {
                t[i][j++] = f[r][c];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
int dsum(int f[][10], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + f[i][i];
    }
    return sum;
}
int adsum(int f[][10], int n)
{
    int i, j, sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if ((i + j) == (n - 1))
                sum = sum + f[i][j];
        }
    return sum;
}
void rsum(int f[][10], int n, int m)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum = sum + f[i][j];
        }
        printf("Sum of row %d is = %d\n", i + 1, sum);
        sum = 0;
    }
}
void csum(int f[][10], int n, int m)
{
    int i, j, sum = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum = sum + f[j][i];
        }
        printf("Sum of column %d is = %d\n", i + 1, sum);
        sum = 0;
    }
}
void adjoint(int f[][10], int r[][10], int n, int m)
{
    int g[10][10];
    int i, j;
    int sign;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cofac(f, g, i, j, n);
            if ((i + j) % 2 == 0)
                sign = 1;
            else
                sign = -1;

            r[j][i] = sign * det(g, n - 1);
        }
    }

    printf("The adjoint of the given matrix is\n");
    display(r, n, n);
    float inv[10][10];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            inv[i][j] = (r[i][j] / (det(f, n)));
        }
    }
    printf("The inverse of the given matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%7.1f", inv[i][j]);
        }
        printf("\n");
    }
}
