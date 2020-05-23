#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
typedef struct node nd;

struct node
{
	int coef;
	int exp;
	struct node *ptr;
}*first,*first2,*first3;

void main()
{
	printf("Enter Polynomial 1: ");
	char poly[30];
	gets(poly);
	int length=strlen(poly);
	//printf("Length is: %d",length);
	char c='x';
	int cf=1;
	int n,i,flag=0;
	int coef1=0;
	int exp1=0,num;
	int len=0;
	int pexp;
	
	nd *node =(nd*)malloc(sizeof(nd));	
	nd *temp=node;
	nd *first=node;
	int p=1;
	
	
		
	for(i=0;poly[i]!='\0';i++)
	{
	
				
		     while(isdigit(poly[i]))
		     {
			    num=poly[i]-48;
			    coef1=coef1*p+num;
			    p=10;
			    len++;
			    i++;
			   // printf("Inside while");
		     }
		     if(i==length)
		     	i--;
		     
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
				       if(poly[i-1]!='x')
					   {
							printf("Invalid Polynomial");
							return;
					   }
			   }
			   
			   //setting exp
		   		else if((poly[i-len-1]=='x'))
		   		{
				
							node->exp=coef1;
					
		   		}
		   		
		   		
		   		
				if(poly[i]=='x' &&  !isdigit(poly[i+1]))
				{
						node->exp=1;
					//	printf("exp is 1");
						
				}else if(poly[length-1]=='x' && i==length-1)             
				{
						node->exp=1;
					//	printf("exp is 1");
						
				}
				
				if((poly[i-len]=='-' || poly[i-len]=='+') && i==length-1)             
				{
						node->exp=0;
						if(poly[i-len]=='-')
						 node->coef= -coef1;
						else	
				    	 node->coef=coef1;
					//	printf("exp is 0");
						
				}
			
		
		   len=0;	
		   p=1;
		   coef1=0;
		   cf=1;
		   flag=0;
		 
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
		
	
    
   //list2
    char poly2[30];
    printf("\nEnter polynomial 2: ");
	gets(poly2);
	int n2,length2;
	length2=strlen(poly2);
	int coef2=0;
	int num2;
	int len2=0;
	
	nd *node2 =(nd*)malloc(sizeof(nd));	
	nd *temp2=node2;
	nd *first2=node2;
	p=1;
	
	
	 printf("starting loop");	
	for(i=0;poly2[i]!='\0';i++)
	{		
		     while(isdigit(poly2[i]))
		     {
			    num2=poly2[i]-48;
			    coef2=coef2*10+num2;
			    len2++;
			    i++;
			    printf("Inside while");
		     }
		     
		     if(i==length2)
		     	i--;
		     
			//setting coef
		     	if( (poly2[i]=='x') || ((poly2[i-len2-1]=='-')||(poly2[i-len2-1]=='+')) )
				{
				
					if(poly2[i-len2-1]=='-')
						node2->coef= -coef2;
					else	
				    	node2->coef=coef2;
			    }
			    
			    else if(isalpha(poly2[i-1]))
				{
				       if(poly2[i-1]!='x')
					   {
							printf("Invalid Polynomial");
							return;
					   }
			   }
			   
			   //setting exp
		   		if((poly2[i-len2-1]=='x'))
		   		{
					node2->exp=coef2;
				
		   		}
		   		
		   		if(poly2[i]=='x' &&  !isdigit(poly[i+1]))
				{
						node2->exp=1;
						//printf("exp is 1");
						
				}else if(poly2[length2-1]=='x' && i==length2-1)             
				{
						node2->exp=1;
					//	printf("exp is 1");
						
				}
				
				if((poly2[i-len2]=='-' || poly2[i-len2]=='+') && i==length2-1)             
				{
						node2->exp=0;
						if(poly2[i-len]=='-')
						 node2->coef= -coef2;
						else	
				    	 node2->coef=coef2;
					//	printf("exp is 0");
						
				}
		
		   len2=0;	
		   coef2=0;
		   
		 
		 if(i!=0 && (poly2[i]=='-')||(poly2[i]=='+'))
		 {	
					
				node2=(nd*)malloc(sizeof(nd));	    

				if(node2==NULL)
		        {
					printf("Overflow");
					return;
		        }	
		        else
		        {
					node2->ptr=NULL;
					temp2->ptr=node2;
					temp2=temp2->ptr;
				}
		}
		
				
		 
	    
    }
			
		if(first2!=NULL)
	    {
			nd *tmp2;
			tmp2=first2;
			printf("\nList1: ");
			while(tmp2!= NULL)
			{
				printf("\ncoef%d ",tmp2->coef);
				printf("\nexp%d ",tmp2->exp);
				tmp2=tmp2->ptr;
			}
		}			
     
     
     
     
     	int a,b,C;
		nd *head=first;
		nd *head2=first2;
		nd *first3=(nd*)malloc(sizeof(nd));
		nd *prnt=first3;
		int sign = -1;
		
		while(head && head2)
		{
							
				if(head->exp > head2->exp)
				{
					first3->coef=head->coef;
					first3->exp=head->exp;
					head=head->ptr;
				//	printf("\nPoly 1 is greater");
				}
				else if(head->exp < head2->exp)
				{
					first3->coef= sign *(head2->coef);
					first3->exp=head2->exp;
					head2=head2->ptr;	
				//	printf("\nPoly 2 is greater");			
				}
				else 
				{
					a= head->coef;
					b=head2->coef;
					C=a-b;
					first3->coef=C;
					if(C==0)
					{
						free(first3);
						first3=NULL;
						
					}
					first3->exp=head->exp;
					head=head->ptr;
					head2=head2->ptr;
				//	printf("\nBoth equal");
				}
				
				first3->ptr=(nd*)malloc(sizeof(nd));
				first3=first3->ptr;	
				first3->coef = 0;
				first3->exp =0;
				first3->ptr=NULL;
						
		}
		
	//remaining elements print
		
				while(head)
				{
					first3->coef=head->coef;
					first3->exp=head->exp;
					head=head->ptr;
					first3->ptr=(nd*)malloc(sizeof(nd));
					first3=first3->ptr;	
					first3->coef = 0;
					first3->exp =0;
					first3->ptr=NULL;
					//printf("\nAdding ist poly rest data");
				}
			
			

			
				while(head2)
				{
					first3->coef=head2->coef;
					first3->exp=head2->exp;
					head2=head2->ptr;
					first3->ptr=(nd*)malloc(sizeof(nd));
					first3=first3->ptr;
					first3->coef = 0;
					first3->exp =0;	
					first3->ptr=NULL;
					//printf("\nAdding ist poly rest data");
				}
			
			//Drop nodes with zero coeff
			
			nd *drop=prnt;
			nd *d=NULL;
			nd *prev=prnt;
			while(drop->ptr!=NULL)
			{
				prev=drop;
				
				if(drop->coef==0)
				{
					d=drop;
					prev->ptr=drop->ptr;
					drop=drop->ptr;
					free(d);
					
				}
					else
					{
						drop=drop->ptr;
					}	
					
				//	drop=drop->ptr;
			}
			
			nd *t;
			t=prnt;
			printf("\nAddition1: ");
			while(t->ptr != NULL)
			{
				printf("\ncoef%d ",t->coef);
				printf("\nexp%d ",t->exp);
				t=t->ptr;
			}
					
    
	getch();
}

