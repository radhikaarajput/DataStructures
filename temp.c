#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
typedef struct node nd;

struct node
{
	int coef;
	int exp;
	struct node *ptr;
}*first;

void main()
{
	char poly[30];
	gets(poly);
	int l= strlen(poly);
	printf("%d",l);
	
	char c='x';
	int cf=1;
	int n,i;
	int coef1=0;
	int exp1=0,num;
	int len=0;
	
	nd *node =(nd*)malloc(sizeof(nd));	
	nd *temp=node;
	nd *first=node;
	int p=1;
	
	
		
	for(i=0;poly[i]!='\0';i++)
	{
		printf("value of i %d",i);
				
		     while(isdigit(poly[i]))
		     {		
				printf("value of i %d",i);
			    num=poly[i]-48;
			    coef1=coef1*p+num;
			    p=10;
			    len++;
			    i++;
			    printf("Inside while");
		     }
		     
			//setting coef
		     	if( (poly[i]=='x') || ((poly[i-len-1]=='-')||(poly[i-len-1]=='+')) )
				{
				
					if(poly[i-len-1]=='-')
						node->coef= -coef1;
					else	
				    	node->coef=coef1;
			    }
			    
			    else if(isalpha(poly[i-1]))
				{
			   	    printf("poly x");
				       if(poly[i]!='x')
					   {
							printf("Invalid Polynomial");
							return;
					   }
			   }
			   
			   //setting exp
		   		if((poly[i-len-1]=='x'))
		   		{
				
					node->exp=coef1;
				
		   		}
		
		   len=0;	
		   p=1;
		   coef1=0;
		   cf=1;
		   
		  //setting last single coef
		   		if( (poly[i]=='/0') && ((poly[i-len-1]=='-')||(poly[i-len-1]=='+'))  )
				{
					if(poly[i-len-1]=='-')
					{
						node->coef= -coef1;
						node->exp=0;					}	
					else
					{	
				    	node->coef=coef1;
				    	node->exp=0;
					}
			    } 
		 
		 if(i!=0 && (poly[i]=='-')||(poly[i]=='+'))
		 {	
					
				node=(nd*)malloc(sizeof(nd));	    

				if(node==NULL)
		        {
					printf("Overflow");
					return;
		        }	
		        else
		        {
					node->ptr=NULL;
					temp->ptr=node;
					temp=temp->ptr;
				}
		}
		
				
		 
	    
    }
			
		if(first!=NULL)
	    {
			nd *tmp;
			tmp=first;
			printf("\nList1: ");
			while(tmp!= NULL)
			{
				printf("\ncoef%d ",tmp->coef);
				printf("\nexp%d ",tmp->exp);
				tmp=tmp->ptr;
			}
		}			
    
	getch();
}

