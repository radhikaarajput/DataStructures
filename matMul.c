#include<stdio.h>
#include<conio.h>
int main()
{
    int A1[10][10], A2[10][10], mul[10][10], sum=0, i, j, k,r1,c1,r2,c2;
    printf("Enter number of rows of matrix1: ");
	scanf("%d",&r1);
	printf("Enter number of columns of matrix1: ");
	scanf("%d",&c1);
    printf("Enter first 3*3 matrix element: ");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            scanf("%d", &A1[i][j]);
    }
    printf("Enter number of rows of matrix2: ");
	scanf("%d",&r2);
	printf("Enter number of columns of matrix2: ");
	scanf("%d",&c2);
    printf("Enter second 3*3 matrix element: ");
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            scanf("%d", &A2[i][j]);
    }
    printf("\nMultiplying two matrices...");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            sum=0;
            for(k=0; k<3; k++)
                sum = sum + A1[i][k] * A2[k][j];
            mul[i][j] = sum;
        }
    }
    printf("\nMultiplication is: \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%d\t", mul[i][j]);
        printf("\n");
    }
    getch();
    return 0;
}
