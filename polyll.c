#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node nd;

struct node
{
	int coef;
	int exp;
	struct node *ptr;
}*first,*first2,*first3;

void main()
{
	char poly[30];
	gets(poly);
	char c='x';
	int cf;
	int n,i;
	int coef1=0;
	int exp1=0,num;
	int len=0;
	
	nd *node =(nd*)malloc(sizeof(nd));	
	nd *temp=node;
	nd *print=node;
	int p=1;
		
	for(i=0;poly[i]!='\0';i++)
	{
		printf("%d",coef1);
		     while(isdigit(poly[i]))
		     {
			    num=poly[i]-48;
			    coef1=coef1*p+num;
			    p=10;
			    len++;
		     }
		     printf("%d",coef1);
			/*if((isdigit(poly[i])) && (isalpha(poly[i+1])) || ((poly[i-len]=='-')||(poly[i-len]=='+')) )
			{
			    node->coef=coef1;
			    printf("\nCoefficient");
		     	printf("%d",node->coef);
		     	printf("%d",coef1);
			    coef1=0;
			}
			else if(isalpha(poly[i]))
		   {
			   printf("poly x");
			   if(poly[i]!='x')
			   {
				printf("Invalid Polynomial");
				return;
			   }
		   }
		   	else if((poly[i-len]=='x'))
		   {
				node->exp=coef1;
				printf("\nExponent");
				printf("%d",coef1);
				printf("%d",node->exp);
		   }
		   len=0;	
		   p=1;*/
		
    }	
    
	getch();
}

  
