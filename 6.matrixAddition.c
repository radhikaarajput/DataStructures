#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
	int i,j,r,c;
	printf("Enter number of rows : ");
	scanf("%d",&r);
	printf("Enter number of columns : ");
	scanf("%d",&c);
	int A1[20][20];
	int A2[20][20];
	int sum[20][20];
	printf("Enter elements of matrix1: ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&A1[i][j]);
		}
		printf("\n");
	}
	printf("Enter elements of matrix2: ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&A2[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sum[i][j]=A1[i][j]+A2[i][j];
			}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}
	getch();
}
