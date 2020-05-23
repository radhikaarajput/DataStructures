#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5
void create();
void push1();
int pop1();
void push2();
int pop2();
void traverse();
int A[max];
int top1=-1;
int top2=max;

void main()
{
	int ch;
	int n;
	int *A= (int*)malloc(max*sizeof(int));
	
		printf("\nStack Menu");
		printf("\n\n1.Push in stack1\n2.Push in stack2\n3Pop from stack1Pop\n4Pop From stack2\n5.Display\n6.Exit");
		
		
	while(1)	
	{
		printf("\n\nEnter your choice(1-6):");
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: printf("Enter element ");
					scanf("%d",&n);
					push1(n);
					break;
			case 2: printf("Enter element ");
					scanf("%d",&n); 
					push2(n);
					break;
			case 3: printf("Popped form stack1 %d ",pop1());
					break;
			case 4: printf("Popped form stack2 %d ",pop2());
					break;		
			case 5: traverse();
					break;
			case 6: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	
	getch();	
}


void push1(int x)
{
	if(top1<top2-1)
	{
		top1++;
		A[top1]=x; 
	}
	else{
		printf("Overflow");
		exit(1);
	}
	
	
}

void push2(int x)
{
	if(top1<top2-1)
	{
		top2--;
		A[top1]=x; 
	}
	else{
		printf("Overflow");
		exit(1);
	}
	
	
}
int pop1()
{
	if(top1>=0)
	{
		int x=A[top1];
		top1--;
		return x;
	}
	else{
		printf("Overflow");
		exit(1);
	}
}

int pop2()
{
	if(top2<max)
	{
		int x=A[top2];
		top2++;
		return x;
	}
	else{
		printf("Overflow");
		exit(1);
	}
}	

void traverse()
{
	if(top1== -1 || top2==max)
	{
		printf("Empty");
		exit(0);
	}
	else 
	{
		int i;
		for(i=top1;i<=0;i++)
			printf("%d ",A[i]);
			
		for(i=top2;i<max;i++)
			printf("%d ",A[i]);	
			
	}
}

