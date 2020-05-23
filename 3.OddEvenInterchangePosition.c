#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int n,i,temp;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int *A= (int*)calloc(n,sizeof(int));
	printf("\nEnter elements of array: ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
		
	for(i=0;i<n;i+=2)
	{
		temp=A[i];
		A[i]=A[i+1];
		A[i+1]=temp;
	}	
		
		for(i=0;i<n;i++)
		printf("%d ",A[i]);	
	
	getch();
}

