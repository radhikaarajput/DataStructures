#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
	int val;
	struct stack *ptr;
};

typedef struct stack nd;

nd *top;
void push();
void pop();
void traverse();
void main()
{
	int ch,n;
	printf("Stack Menu");
	printf("\n0.create\n1.Push\n2.Pop\n3.Display\n4.Exit");
	while(1)	
	{
		printf("\n\nEnter your choice(0-4):");
		scanf("%d",&ch);
		
		switch(ch)
		{
		
			case 1: 
					printf("Enter value: ");
					scanf("%d",&n);
					push(n);
					break;
			case 2: pop();
					break;
			case 3: traverse();
					break;
			case 4: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	getch();
}



void push(int value)
{
	nd *node=(nd*)malloc(sizeof(nd));
	if(node==NULL)
	{
		printf("Overflow");
		return;
	}
	node->ptr=NULL;
	node->val=value;
	node->ptr=top;
	top=node;
}

void pop()
{
	if(top==NULL)
	{
		printf("Underflow");
		return;
	}

	nd *temp=top;
	printf("%d ",top->val);
	top=top->ptr;
	free(temp);
}

void peek()
{
	if(top==NULL)
	{
		printf("Underflow");
		return;
	}

	printf("%d",&top->val);
	
}

void traverse()
{
	if(top==NULL)
	{
		printf("Underflow");
		return;
	}

	nd *temp=top;
	while(temp!=NULL)
	{
		printf("%d  ",temp->val);
		temp=temp->ptr;
	}
	
}

