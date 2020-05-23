#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define max 50

void push(char c);
void pop();
char stack[max];
int top=0;
void main()
{
	int ch;
	int flag=0;
	int i=0;
	char exp[max];
	printf("Enter expression: ");
	scanf("%s",&exp);
	int l=strlen(exp);
	for(i=0;i<l;i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(exp[i]);
		}
		 if(exp[i]==')')
		{
			if(stack[top]== '(' )
				pop();
			else
			{
				flag=1;
				printf("Not a valid expression");
				return;
			}	
		}
		
		if(exp[i]==']')
		{
			if(stack[top]== '[' )
				pop();
			else
			{
				flag=1;
				printf("Not a valid expression");
				return;
			}	
		}
		
		else if(exp[top]=='}')
		{
			if(stack[i]== '{' )
				pop();
			else
			{
				flag=1;
				printf("Not a valid expression");
				return;
			}
		}
		
	
	}
	
		printf("Valid Expression");
		getch();
}


void push(char c)
{
	if(top==max)
		return;
	
		top++;	
		stack[top]=c;
	
}

void pop()
{
	if(top==0)
		return;
		
	stack[top]=0;
	top--;
}
