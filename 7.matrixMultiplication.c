#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
	int i,j,k,r1,c1,r2,c2;
	printf("Enter number of rows of matrix1: ");
	scanf("%d",&r1);
	printf("Enter number of columns of matrix1: ");
	scanf("%d",&c1);
	int A1[5][5];
	int A2[5][5];
	printf("Enter elements of matrix1: ");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&A1[i][j]);
		}
	}
	
	printf("Enter number of rows of matrix2: ");
	scanf("%d",&r2);
	printf("Enter number of columns of matrix2: ");
	scanf("%d",&c2);
	printf("Enter elements of matrix2: ");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&A2[i][j]);
		}
	}
	int mul[r1][c2];
	if(c1!=r2)
		printf("Can't perform multiplication");
	else{
	
	for(i=0;i<r1;++i)
	{
		for(j=0;j<c2;++j)
		{
			for(k=0;k<c1;++k)
			{
					mul[i][j]+=A1[i][k]*A2[k][j];
			}
		}	
	}
	
	printf("Multilpcation result");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d    ",mul[i][j]);
		}
		printf("\n");
	}
}	
	getch();
}
