#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node nd;
nd* createPoly();
nd* Multiply(nd *f1, nd *f2);
void AddsameExp(nd *f);

struct node
{
	int coeff;
	int exp;
	struct node *ptr;
}*f1,*f2;

int main()
{	
	nd *f1= NULL;
	f1=createPoly(f1);
	if(f1!=NULL)
	  {
			nd *tmp;
			tmp=f1;
			printf("Polynomial 1 : \n");
			while(tmp != NULL)
			{
				printf("Coeff: %d ",tmp->coeff);
				printf("Exp: %d \n",tmp->exp);
				tmp=tmp->ptr;
			}
		}
		
	nd *f2= NULL;
	f2=createPoly(f2);
	if(f2!=NULL)
	  {
			nd *tmp;
			tmp=f2;
			printf("Polynomial 2 : \n");
			while(tmp != NULL)
			{
				printf("Coeff: %d ",tmp->coeff);
				printf("Exp: %d \n",tmp->exp);
				tmp=tmp->ptr;
			}
		}
		
	Multiply(f1,f2);
			
		getch();
		return 0;
}

nd* createPoly(nd *first)
{
	nd *newn,*temp;
	int n,i;
	first=(nd*)malloc(sizeof(nd));
	if(first==NULL)
	{
		printf("Overflow");
		return;
	}	
	else
	{
		printf("Enter no of terms in polynomial: ");
		scanf("%d",&n);
		printf("Enter Coeff: ");
		scanf("%d",&first->coeff);
		printf("Enter Exp: ");
		scanf("%d",&first->exp);
		first->ptr=NULL;
		temp=first;
		for(i=2;i<=n;i++)
		{
			nd *nod =(nd*)malloc(sizeof(nd));
			if(nod==NULL)
	        {
				printf("Overflow");
				return;
	        }	
	        else
	        {
				printf("Enter Coeff: ");
				scanf("%d",&nod->coeff);
				printf("Enter Exp: ");
				scanf("%d",&nod->exp);
				nod->ptr=NULL;
				temp->ptr=nod;
				temp=temp->ptr;
			}	
		 }
		
	  }
	  
		
		return first;
}

nd* Multiply(nd *f1, nd *f2)
{
	nd *f3=NULL;
	nd *poly1,*poly2;
	int c,e;
	nd *first3=(nd*)malloc(sizeof(nd));
	nd *prnt=first3;
	for(poly1=f1; poly1!=NULL;poly1=poly1->ptr)
	{
		for(poly2=f2; poly2!=NULL;poly2=poly2->ptr)
		{
			c=poly1->coeff*poly2->coeff;
			e=poly1->exp+poly2->exp;
			
			first3->coeff=c;
			first3->exp=e;
			
				first3->ptr=(nd*)malloc(sizeof(nd));
				first3=first3->ptr;	
				first3->coeff = 0;
				first3->exp =0;
				first3->ptr=NULL;
		}
	}		
	
	AddsameExp(prnt);
			
			nd *t;
			t=prnt;
			printf("\nMultiplication: \n");
			while(t != NULL)
			{
				printf("\ncoef%d ",t->coeff);
				printf("\nexp%d ",t->exp);
				t=t->ptr;
			}
					
}


void AddsameExp(nd *f)
{   
   nd *p1, *p2, *delete; 
    p1 = f; 
  
    while (p1 != NULL && p1->ptr != NULL) 
	{ 
        p2 = p1; 
  
        while (p2->ptr != NULL) 
		{ 
            if (p1->exp == p2->ptr->exp) 
			{ 
                p1->coeff = p1->coeff + p2->ptr->coeff; 
                delete = p2->ptr;     //next term
                p2->ptr = p2->ptr->ptr; 
  
                free(delete); 
            } 
            else
                p2 = p2->ptr; 
        } 
        p1 = p1->ptr; 
    }
}
