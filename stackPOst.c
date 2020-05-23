#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5

struct stack
{
	int val;
	struct stack *ptr;
};

typedef struct stack nd;

nd *top;
void push();
char pop(nd *node);
void traverse();
void main()
{
	char exp[50];
	printf("Enter expression");
	gets(exp);
	int ch,n;
	postfix(exp);
	
	getch();
}

struct stack* createStack() 
{ 
    nd *node=(nd*)malloc(sizeof(nd));
    nd *s=node;
    int n=max,value;
    while(n!=0)
    {
		if(node==NULL)
		{
			printf("Overflow");
			return;
		}
		printf("Enter value");
		scanf("%d",&value);
		node->ptr=NULL;
		node->val=value;
		node->ptr=top;
		top=node;
	}       
    return s; 
} 

int postfix(char *exp)
{
	nd *new=(nd*)malloc(sizeof(nd));
	int i;
		if(new==NULL)
		{
			printf("Overflow");
			return;
		}
		
	int	j=0;	
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(' )
			push(new,exp[i]);
		
		else if(isdigit(exp[i]))
			push(new,exp[i]);
			
		else if(exp[i]==')') 	
		{
			while(exp[i]=='(' )
			{
				while (!top== -1 && peek(new) != '(') 
                 exp[++j] = pop(new); 
            	if (!top== -1 && peek(new) != '(') 
                return -1;              
            	else
                pop(new);
			}
		}
	}	
	
}

void push(nd *node,int value)
{
	node=(nd*)malloc(sizeof(nd));
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

char pop(nd *node)
{
	if(top==NULL)
	{
		printf("Underflow");
		return;
	}

	nd *temp=node;
	printf("%d",&node->val);
	node=node->ptr;
	free(temp);
}

void peek(nd *node)
{
	if(top==NULL)
	{
		printf("Underflow");
		return;
	}

	printf("%d",&node->val);
	
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
		printf("%d",temp->val);
		temp=temp->ptr;
	}
	
}

