#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define max 40
void push(char e);
int priority(char op);
void infixToPostfix(char *exp, char *result);
int evaluatePostfix(char *result);
char pop();
char peek();
void emptyStack();
char stack[50];

int top = -1;

void main()
{
    char exp[40];
  	char result[40];
    printf("Enter the expression: ");
    gets(exp);
    infixToPostfix(exp,result);
    emptyStack();
    printf("\nPOSTFIX is %s",result);
    printf("\nPOSTFIX evaluation is %d",evaluatePostfix(result));
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

char peek()
{
	
    if(top==-1)
	{
		printf("Full");
		return;
	}
	
	return stack[top];  
}
 
int priority(char op)
{
	
	
    if(op == '^')
        return 4;
    if(op == '*' || op == '/')
        return 3;    
    if(op == '+' || op == '-')
        return 2;
    if(op == '%')
        return 1;
    else 
    	return 0;
}



void infixToPostfix(char *exp, char *result)
{
    char c;
    int i,n=0,num=0,p=1;
    char  x;
	int k=0;
    
    for(i=0;exp[i]!='\0';i++)
    {
        
        if(exp[i] == '(')
        {
            push(exp[i]);
		} 
		 else if(isalnum(exp[i]))
		{
	            printf("%c",exp[i]);
	            result[k++]=exp[i];
		}   
        else if(exp[i] == ')')
        {
            while((c = pop()) != '(')
            {
                printf("%c", c);
                result[k++]=c;
			}   
        }
		else 
        {
            while(priority(peek()) >= priority(exp[i]))
            {	
				c=pop();
                printf("%c",c);
                result[k++]=c;
			}   
            push(exp[i]);
        } 
		   
    }
   
	
    while(top != -1)
    {
        c=pop();
        printf("%c",c);
    	result[k++]=c;
    }
    result[k++]='\0';
}

int evaluatePostfix(char *result)
{
	char c;
	int a,b,i=0;
	while(result[i]!='\0')
	{
		if(isdigit(result[i]))
			push(result[i]-'0');
		else
		{
			a=pop();
			b=pop();
		//	a=a-48;
		//	b=b-48;
				printf("\n%d",a);
				printf("\n%d",b);
		
			switch(result[i])
			{	
				 case '^' : push(b^a); 
				 break;
				 case '%' : push(b%a); 
				 break;
				 case '+' : push(b+a); 
				 break;
				 case '-' : push(b-a); 
				 break;
				 case '*' : push(b*a);
				 break;
				 case '/' : push(b/a);
				 break;
			}
		}
		
		i++;
	}
	int x=pop();
	return x;	
}

void emptyStack()
{
	if(top!= -1)
	{
		pop();
	}
}
