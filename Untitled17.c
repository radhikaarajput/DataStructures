#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define max 40
void push(char e);
int priority(char op);
void infixToPostfix(char *exp, char *result);
int evaluate(char *exp);
char pop();
char peek();
int ipush(int i);
int ipop();
void emptyStack();
char stack[50];
int istack[max];

int top = -1;
int itop = -1;

void main()
{
    char exp[40];
  	char result[40];
    printf("Enter the expression: ");
    gets(exp);
    infixToPostfix(exp,result);
    printf("\nPOSTFIX is %s",result);
    
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
        c=exp[i];
        switch(c)
        {
			case '(': push(c);
						break;
			case ')': while(peek()!='(')
					 {
							c=pop();
							evaluate(c);
					 }
					 pop();
					 break;
        	case '+':
			case '-':
			case '*':
			case '/':
	            while(priority(peek()) >= priority(exp[i]))
	            {	
					c=pop();
	                printf("%c",c);
	                result[k++]=c;
				}   
	            push(exp[i]);	
	            break;
	            
	       default: evaluate(s);
		   			break;
	   }			    
        
		i++;	   
    }

}

int evaluate(char c)
{
	int a,b,i=0,n;
	
			switch(c)
			{	
				 case '^' : a=pop();
				 		    b=pop();
							push(b^a); 
							break;
								
				 case '%' : a=pop();
				 			b=pop();  
							push(b%a); 
				 			break;
				 				
				 case '+' : a=pop();
				 		    b=pop(); 
							push(b+a); 
				 			break;
				 case '-' : a=pop();
				 		    b=pop(); 
							push(b-a); 
				 			break;
				 case '*' : a=pop();
				 		    b=pop();
						 	push(b*a);
							break;
				 case '/' : a=pop();
				 		    b=pop(); 
							push(b/a);
				 			break;
				 			
				 default:  if(c>=48 && c<=57)
				 			{
								a=c-48;
								ipush(a);
							}			
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


void ipush(int e)
{
    if(top==max)
	{
		printf("Full");
		return;
	}
	
		itop++;
		stack[itop] = e;		
}
 
char ipop()
{
	
    if(top==-1)
	{
		printf("Full");
		return;
	}
	
	int s=stack[itop];
	stack[itop]=0;
	itop--;  
	return s;  
}
