#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int no,n,i=1,k=0,rem,decimal;
	int A[20];
	long binary=0;
	printf("Decimal to binary conversion \n");

		printf("Enter decimal number: ");
		scanf("%d",&decimal);
		int num=decimal;
		n=10;
		i=1;
		
		n=decimal;
		while(decimal!=0)
		{
			rem=decimal%2;
			decimal=decimal/2;
			A[k]=rem;
			k++;
		} 
		int start=0, end=k-1,temp;
		while(start<end)
		{
			temp =A[start];
			A[start]=A[end];
			A[end]=temp;
			start++;
			end--;
		}	
		printf("Binary Equivalent of %d is ",num);
		for(i=0;i<k;i++)
		printf("%d",A[i]);	
	
	

	getch();
}

