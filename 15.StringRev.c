#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define max 40
void push(char e);
char pop();

char stack[max];

int top = -1;

void main()
{
    char s[40];
  	char rev[40];
  	int i;
    printf("Enter the string: ");
    gets(s);
    for(i=0;s[i]!='\0';i++)
    	push(s[i]);
    	
     for(i=0;s[i]!='\0';i++)
    	rev[i]=pop();	
    
	rev[i]='\0';	
    printf("\nReverse of %s is: %s",s,rev);
    getch();
}

void push(char e)
{
    if(top==max)
	{
		printf("Full");
		return;
	}
	
		top++;
		stack[top] = e;		
}
 
char pop()
{
	
    if(top==-1)
	{
		printf("Full");
		return;
	}
	
	char s=stack[top];
	stack[top]=0;
	top--;  
	return s;  
}

