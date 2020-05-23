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
	char poly[50];
	gets(poly);
	int cf;
	int n,i;
	int coef1=0;
	int exp1=0,num;
	int len=0;
	
	nd *node =(nd*)malloc(sizeof(nd));	
	nd *temp=node;
	nd *print=node;
	int p=1;
	int flag=0;
	
		
	for(i=0;poly[i]!='\0';i++)
	{
		     while(isdigit(poly[i]))
		     {
			    num=poly[i]-48;
			    coef1=coef1*p+num;
			    p=10;
			    len++;
			    i++;
		     }
		     	
		     	if( (poly[i]=='x') || ((poly[i-len-1]=='-')||(poly[i-len-1]=='+')) )
				{
				
				
			    node->coef=coef1;
		    	flag=0;
			
			    }
			    
			    else if(isalpha(poly[i-1]))
				{
			   	    flag=0;
			   	    
			       if(poly[i]!='x')
				   {
						printf("Invalid Polynomial");
						return;
				   }
			   }
			   
		   		else if((poly[i-len-1]=='x'))
		   		{
					node->exp=coef1;
					flag==1;
		   		}
		   len=0;	
		   p=1;
		   coef1=0;
		 
		 if((poly[i]=='-')||(poly[i]=='+'))
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
	
		if(print!=NULL)
	    {
			nd *tmp3;
			tmp3=print;
			printf("\nList1: ");
			while(tmp3!= NULL)
			{
				printf("\ncoef%d ",tmp3->coef);
				printf("\nexp%d ",tmp3->exp);
				tmp3=tmp3->ptr;
			}
		}			
    
    
    
    //second list
    char poly2[50];
    printf("/nEnter polynomial2");
	gets(poly2);
	int n2;
	int coef2=0;
	int num2;
	int len2=0;
	
	nd *node2 =(nd*)malloc(sizeof(nd));	
	nd *temp2=node2;
	nd *print2=node2;
	int p2=1;
	
	
		
	for(i=0;poly2[i]!='\0';i++)
	{
		     while(isdigit(poly2[i]))
		     {
			    num2=poly2[i]-48;
			    coef2=coef2*p2+num2;
			    p2=10;
			    len2++;
			    i++;
		     }
		     	
			
		     	if( (poly2[i]=='x') || ((poly2[i-len2-1]=='-')||(poly[i-len2-1]=='+')) )
				{	
				    node2->coef=coef2;
			    }
			    
			    else if(isalpha(poly2[i-1]))
				{
			       if(poly2[i]!='x')
				   {
					printf("Invalid Polynomial");
					return;
				   }
			    }
			   
		   		else if((poly2[i-len2-1]=='x'))
		   		{
				 	node2->exp=coef2;
		   		}
		   len2=0;	
		   p2=1;
		   coef2=0;
		 
		 if((poly2[i]=='-')||(poly2[i]=='+'))
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
    
		printf("Loop2");	
		if(print2!=NULL)
	    {
			nd *tmp2;
			tmp2=print2;
			printf("\nList2 : ");
			while(tmp2!= NULL)
			{
				printf("\ncoef%d ",tmp2->coef);
				printf("\nexp%d ",tmp2->exp);
				tmp2=tmp2->ptr;
			}
		}
		
		printf("adding\n");
		//adding
		int a,b,C;
		nd *head=print;
		nd *head2=print2;
		nd *first3;
		printf("adding\n");
		
			//setting head;		
			if(head!=NULL && head2!=NULL)
			{
				if(head->exp == head2->exp)
				{
					a=head->coef;
					b=head2->coef;
					C=a+b;
					printf("C %d",C);
					first3=head;
					first3->coef=C;
					head=head->ptr;
					head2=head2->ptr;
				}	
				
				if(head->exp > head2->exp)
				{
					first3=head;
					head=head->ptr;
				}
				
				else
				{
					first3=head2;
					head2=head2->ptr;
				}			
			 }
			 //	printf("adding %d \n", first3->coef);
			
	/*	nd *prnt=first3;
		
		while(head!=NULL && head2!=NULL)
		{
				if(head->exp > head2->exp)
				{
					first3->ptr=head;
					first3=head;
					head=first3->ptr;
				}
				else
				{
					first3->ptr=head2;
					first3=head;
					head2=first3->ptr;
				}
				if(head->exp == head2->exp)
				{
					a= head->coef;
					b=head2->coef;
					C=a+b;
					printf("C%d ",C);
					first3->ptr=head;
					first3=head;
					first3->coef=C;
					head=head->ptr;
					head2=head2->ptr;		
				}
						
		}
				
		if(head!=NULL)
			first3->ptr=head;		
		if(head2!=NULL)
			first3->ptr=head2;		
			
		if(prnt!=NULL)
	    {
			nd *t;
			t=prnt;
			printf("\naddition: ");
			while(t!= NULL)
			{
				printf("Coef%d \n ",t->coef);
				printf("Exp%d \n ",t->exp);
				t=t->ptr;
			}
		}
*/					
    
	getch();
}

