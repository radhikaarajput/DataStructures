#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5
void create();
void push();
void pop();
void traverse();
int stack[max];
int top=0;
void main()
{
	int ch;
	printf("Stack Menu");
	printf("\n0.create\n1.Push\n2.Pop\n3.Display\n4.Exit");
	while(1)	
	{
		printf("\n\nEnter your choice(0-4):");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0: create();
					break;
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: traverse();
					break;
			case 4: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
}

void create()
{		
	int ch=max;
//	printf("Enter size");
//	scanf("%d",&ch);
	//stack.top=0;
	do{
		top++;
		printf("Enter element");
		scanf("%d",&stack[top]);
		ch--;
	}while(ch!=0);
} 

void push()
{
	if(top==max)
	{
		printf("Full");
		return;
	}
	
		top++;	
		printf("Enter element");
		scanf("%d",&stack[top]);
	
}

void pop()
{
	if(top==0)
	{
		printf("Empty");
		return;
	}
	printf("Element %d ",stack[top]);
	stack[top]=0;
	top--;
}

void traverse()
{
	if(top==0)
	{
		printf("Empty");
		return;
	}
	
	int a=top;
	for(a=top;a>0;a--)
	{
		printf("%d   ",stack[a]);
	}
}
