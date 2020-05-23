#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node nd;
nd* createPoly();
nd* subtracrion(nd *f1, nd *f2);

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
		
	subtracrion(f1,f2);
			
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

nd* subtracrion(nd *f1, nd *f2)
{
	int a,b,C;
		nd *head=f1;
		nd *head2=f2;
		nd *first3=(nd*)malloc(sizeof(nd));
		nd *prnt=first3;
		int sign = -1;
		
		while(head && head2)
		{
							
				if(head->exp > head2->exp)
				{
					first3->coeff=head->coeff;
					first3->exp=head->exp;
					head=head->ptr;
				//	printf("\nPoly 1 is greater");
				}
				else if(head->exp < head2->exp)
				{
					first3->coeff= sign *(head2->coeff);
					first3->exp=head2->exp;
					head2=head2->ptr;	
				//	printf("\nPoly 2 is greater");			
				}
				else 
				{
					a= head->coeff;
					b=head2->coeff;
					C=a-b;
					first3->coeff=C;
					first3->exp=head->exp;
					
				//	first3=first3->ptr;	
					head=head->ptr;
					head2=head2->ptr;
				}
				
				first3->ptr=(nd*)malloc(sizeof(nd));
				first3=first3->ptr;	
				first3->coeff = 0;
				first3->exp =0;
				first3->ptr=NULL;
						
		}
	
		
				while(head)
				{
					first3->coeff=head->coeff;
					first3->exp=head->exp;
					head=head->ptr;
					first3->ptr=(nd*)malloc(sizeof(nd));
					first3=first3->ptr;	
					first3->coeff = 0;
					first3->exp =0;
					first3->ptr=NULL;
				}
			
						
				while(head2)
				{
					first3->coeff=head2->coeff;
					first3->exp=head2->exp;
					head2=head2->ptr;
					first3->ptr=(nd*)malloc(sizeof(nd));
					first3=first3->ptr;
					first3->coeff = 0;
					first3->exp =0;	
					first3->ptr=NULL;
				}
			
		
			
			nd *t;
			t=prnt;
			printf("\nSubtraction: \n");
			while(t->ptr != NULL)
			{
				printf("\ncoef%d ",t->coeff);
				printf("\nexp%d ",t->exp);
				t=t->ptr;
			}
					
}


