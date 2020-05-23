#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
	int i,j,k,r1,c1,r2,c2,v,flag;
	printf("Enter number of rows of matrix1: ");
	scanf("%d",&r1);
	printf("Enter number of columns of matrix1: ");
	scanf("%d",&c1);
	int A[20][20];
	printf("Enter elements of matrix1: ");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}

	printf("Enter number to find: ");
	scanf("%d",&v);

	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			if(A[i][j]==v)
			{
				flag=1;
				break;
			}
		}
	}
	
	if(flag==1)
		printf("Element Found");
	else
		printf("element not found");	
	
	getch();
}
