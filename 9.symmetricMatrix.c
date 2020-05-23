#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
	int i,j,r,c,flag=0;
	printf("Enter number of rows : ");
	scanf("%d",&r);
	printf("Enter number of columns : ");
	scanf("%d",&c);
	int A[20][20];
	printf("Enter elements of matrix1: ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(A[i][j]!=A[j][i])
			{
				flag=1;
				break;
			}
		}
		
	}
	
	
	if(flag==0)
	{
		printf("Symmetric matrix");
	  for(i=0;i<r;i++)
	  {
		for(j=0;j<c;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	  }
	}
	else
		printf("Not Symmetric matrix");
	getch();
}
