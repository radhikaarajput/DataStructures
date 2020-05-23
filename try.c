#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define max 40
void push(char e);
void ipush(int i);
int priority(char op);
void infixToPostfix(char *exp, char *result);
int eval(char *result);
char pop();
int ipop();
char peek();
void emptyStack();
char stack[50];


int top = -1;
int itop=-1;

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
 
int ipop()
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
    int i,n=0,num=0,p=1,j=10;
    int no=0;
    char  s,c;
	int k=0,y;
    
    for(i=0;exp[i]!='\0';i++)
    {
        s=exp[i];
        
        switch(s)
        {
			case '(': push(exp[i]);
					  break;
					  
			case ')': 	while(stack[top]!='(')
						{
							c=pop;
							eval(c);
						}
						cpop();
						break;
					  
			case '+':
			case '-':
			case '*':
			case '/':	 while(priority(peek()) >= priority(exp[i]))
			            {	
							c=pop();
			                printf("%c",c);
			                result[k++]=c;
			                eval(c);
						}   
			            push(s);
						break;	
						
			deafault: eval(s);
					   break;								
									  
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

int eval(char c)
{
	
	int a,b,i=0;
	
		
			switch(c)
			{	
				 case '^' : a=ipop();
			                b=ipop();
							push(b^a); 
				             break;
				 case '%' : a=ipop();
			                b=ipop();
							push(b%a); 
				 			break;
				 case '+' : a=ipop();
			                b=ipop();
							push(b+a); 
				 			break;
				 case '-' : a=ipop();
			                b=ipop(); 
							push(b-a); 
				 			break;
				 case '*' : a=ipop();
			                b=ipop(); 
							push(b*a);
				 			break;
				 case '/' : a=ipop();
			                b=ipop(); 
							push(b*a);
							push(b/a);
				 break;
			}
		}
		
		i++;
	}
	int x=pop();
	return x;	
}

