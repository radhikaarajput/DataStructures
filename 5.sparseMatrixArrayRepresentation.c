#include<stdio.h>
#include<conio.h>
int n,r,c;
int create();
void traverse(int n);

struct sp_mt
{
	int row;
	int col;
	int val;
}spMatrix[10];

void main()
{
	int	num;
	num=create();
	traverse(num);		
	getch();
}
	
int create()
{
	n=0;
	char ch='y';
	printf("Enter number of rows in Sparse matrix: ");
	scanf("%d",&r);
	printf("Enter number of columns in Sparse matrix: ");
	scanf("%d",&c);
	while(ch=='y'||ch=='Y')
	{
		printf("Enter element %d ",n);
		printf("\nRow:");
		scanf("%d",&spMatrix[n].row);
		printf("Column:");
		scanf("%d",&spMatrix[n].col);
		printf("Value:");
		scanf("%d",&spMatrix[n].val);
		printf("Want to enter more elements");
		scanf("%c",&ch);
		n++;
	}
	return n;	
}		
		
void traverse(int n)
{
	printf("Sparse matrix is: ");
	int i,j,k=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if((spMatrix[k].row == i+1)&& (spMatrix[k].col == j+1))
			{
					printf("%d",spMatrix[k]);
					k++;
			}else
				printf("0\t");
		}
		printf("\n");	
	}
}
