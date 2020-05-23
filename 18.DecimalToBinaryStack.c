#include<stdio.h>
#include<conio.h>
#define max 10
void push(int i);
int pop();
int stack[max];
int top=0;
int main()
{
	
	int no,n,i=1,k=0,rem,decimal,len=0;
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
			push(rem);
			len++;
			printf("%d",len);
		} 
			
		printf("Binary Equivalent of %d is ",num);
		for(i=0;i<len;i++)
		printf("%d",pop());	
	
	getch();
	return 0;
	

}


void push(int i)
{
	if(top==max)
	{
		printf("Full");
		return;
	}
	
		top++;	
		stack[top]=i;
}

int pop()
{
	if(top==0)
	{
		printf("Empty");
		return -1;
	}
	int i= stack[top];
	stack[top]=0;
	top--;
	return i;
}

