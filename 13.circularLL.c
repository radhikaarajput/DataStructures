#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void createList();
void insertBeg();
void insertEnd();
void insertValue();
void deleteEnd();
void deleteBeg();
void deleteValue();
void sort();
void reverse();
void merge();


typedef struct node nd;

struct node
{
	int val;
	struct node *ptr;
}*first,*first2,*first3;

int main()
{	
	nd *first=NULL;
	nd *first2=NULL;
	nd *first3=NULL;
	int c;
	char ch='y';
	
	printf("Menu \n0.Create List \n1.Insert at beggining \n2.Insert at end \n3.Insert after a given value \n4.Delete from begining \n5.Delete from end\n6.Delete a value\n7.Sort Link List \n8.Reverse the list \n9.Merge two link list");
  do
 {
	printf("\nEnter your choice: ");
	scanf("%d",&c);
	switch(c)
	{
		case 0:
			createList();
			break;
		case 1:
			insertBeg();
			break;
		case 2:
			insertEnd();
			break;
		case 3:
			insertValue();
			break;	
		case 4:
			deleteBeg();
			break;
		case 5:
			deleteEnd();
			break;	
		case 6:
			deleteValue();
			break;	
		case 7:
			sort();
			break;
		case 8:
			reverse();
			break;
		case 9:
			merge();
			break;		
				
	}
	//printf("\nWant to Continue: ");
	//scanf("%c",&ch);
 }while(c<=5);
	
	getch();
	return 0;
}

void createList()
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
		printf("Enter no of nodes: ");
		scanf("%d",&n);
		printf("Enter value of node1: ");
		scanf("%d",&first->val);
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
				printf("Enter value of node%d: ",i);
				scanf("%d",&nod->val);
				if(i==n)
				 nod->ptr=first;
				else 
				 nod->ptr=NULL;
				temp->ptr=nod;
				temp=temp->ptr;
			}	
		 }
		
	  }
	  if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
}

void insertBeg( )
{
	nd *newn;
	nd *temp;
	temp=first;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
	
	while(temp->ptr!=first)
	{
		temp=temp->ptr;
	}
	
		printf("Enter value for insertion: ");
		scanf("%d",&newn->val);
		newn->ptr=first;
		
	if(first!=NULL)
	{
		temp->ptr=newn;
		first=newn;
   }
   else
   {
		newn->ptr=newn;
		first=newn;
   }
		
	
	 if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
	}
}

void insertEnd()
{
	nd *newn,*temp,*prev=NULL;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
		
		printf("Enter value for insertion: ");
		scanf("%d",&newn->val);
		temp=first;
		
		
		while(temp->ptr!=first)
		{
		 temp=temp->ptr;
	    }
	    
	    if(first==NULL)
	    {
			printf("Link List after insertion: ");
			newn->ptr=newn;
		    first=newn;
			//first=newn;
			//newn->ptr=first;
			
		}
		else
		{
			newn->ptr=temp->ptr;
			temp->ptr=newn;
			
		}
		
		
		if(first!=NULL)
	  	{
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
	
}

void insertValue()
{
	int value;
	printf("Enter value: ");
	scanf("%d",&value);
	nd *newn,*temp,*tmp;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
		
	temp=first;
	while(temp->ptr!=first)
	{
		if(temp->val==value)
			break;
		else
			temp=temp->ptr;
	}
	if(temp==NULL)
		printf("Element not found");
	else
	{
			if(temp->ptr==first)
				newn->ptr=first;
			else	
				newn->ptr=temp->ptr;
			printf("Enter value for insertion: ");
	        scanf("%d",&newn->val);
	        temp->ptr=newn;
	}
	
	  	if(first!=NULL)
	  	{
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
	
}

void deleteBeg()
{
	if(first==NULL)
	{	printf("UnderFlow");
		return;
	}
	nd *temp,*temp2;
	temp=first;
	temp2=first;
	
		while(temp2->ptr!=first)
		{
		 temp2=temp2->ptr;
	    }
	if(temp->ptr == first)
	{
		first=NULL;
	}
	else{
	first=first->ptr;
	temp2->ptr=first; 
    }
	free(temp); 	
	
		if(first!=NULL)
	  	{
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
	
}

void deleteEnd()
{
	if(first==NULL)
	{	printf("UnderFlow");
		return;
	}
	nd *temp,*prev,*ctemp;
	temp=first;
	ctemp=first;
	while(temp->ptr!=first)
	{
		prev=temp;
		temp=temp->ptr;
	}
	if(ctemp->ptr==first)
	{
		first=NULL;
		printf("No element left");
	}
	else
	 prev->ptr=first;
	 
	free(temp);
	
	
		if(first!=NULL)
	  	{
			nd *tmp;
			tmp=first;
			printf("Link List: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
	
	
}

void deleteValue()
{
	if(first==NULL)
	{	printf("UnderFlow");
		return;
	}
	int value;
	printf("Enter element for deletion");
	scanf("%d",&value);
	nd *temp,*prev,*t,*last,*previous;
	temp=first;
	last=first;
		
	while(last->ptr!=first)
	{
		last=last->ptr;
	}	
	
	while(temp->val!=value)          //traversing to last 
	{
		if(temp->ptr==first)
		{
			printf("NOt found");
			return;
	    }	
	    prev=temp;
		temp=temp->ptr;
	}
	
	if(temp->ptr==first && temp->val==value)    //only first element present delete it
	{
		first=NULL;
		free(temp);
		
	}
	
	//more than 1 element present
	if(temp==first)      //deleting first element
	{
		first=temp->ptr;
		last->ptr=first;
		free(temp);
		
		
	}
	
	else if(temp->ptr==first && temp->val==value)    //last element delete
	{
		prev->ptr=first;
		free(last);
	}
	
	else{                                             //in between present
	prev->ptr=temp->ptr;
	free(temp);	
    }

	
	
	if(first!=NULL)
	  	{
			nd *tmp;
			tmp=first;
			printf("Link List: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
	
	
}

void sort()
{
	nd *f,*s;
	f=first;
	int temp;
	for(f=first;f->ptr!=first;f=f->ptr)
	{
		for(s=f->ptr;s!=first;s=s->ptr)
		{
			if(f->val > s->val)
			{
				temp=f->val;
				f->val=s->val;
				s->val=temp;
			}
		}
	}
	
	
	if(first!=NULL)
	  	{
			nd *tmp;
			tmp=first;
			printf("Link List: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
}


void reverse()
{
	int length=0;
	/*nd *tmp,*p,*q;
	while(tmp != NULL)
	{
		tmp=tmp->ptr;
		length++;
	}
	int i=0,j=length-1,k=0,t;
	p=q=first;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->ptr;
			k++;
		}
		t=p->val;
		p->val=q->val;
		q->val=t;
		i++;
		j--;
		p=p->ptr;
		q=first;
	}*/
	nd *cur,*next,*prev;
	prev=NULL;
	cur=first;
	next=first;
	
	do{
		next=next->ptr;
		cur->ptr=prev;
		prev=cur;
		cur= next;
	}	while(cur != first);
	first=prev;
	
	
		if(first!=NULL)
	    {
			nd *tp;
			tp=first;
			printf("\nReverse: ");
			while(tp != NULL)
			{
				printf("%d ",tp->val);
				tp=tp->ptr;			
			}
		}	
}


void merge()
{
	int i,n,n2;
	printf("Link List1: ");
	nd *temp,*temp2;		
	first=(nd*)malloc(sizeof(nd));
	if(first==NULL)
	{
		printf("Overflow");
		return;
	}	
	else
	{
		printf("Enter no of nodes: ");
		scanf("%d",&n);
		printf("Enter value of node1: ");
		scanf("%d",&first->val);
		first->ptr=first;
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
				printf("Enter value of node%d: ",i);
				scanf("%d",&nod->val);
				if(i==n)
				 nod->ptr=first;
				else 
				 nod->ptr=NULL;
				temp->ptr=nod;
				temp=temp->ptr;
			}	
		 }
		
	  }
	  if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first);
		}
	 
		
		
	printf("\nLink List2: ");		
	first2=(nd*)malloc(sizeof(nd));
	if(first2==NULL)
	{
		printf("Overflow");
		return;
	}	
	else
	 {
		printf("Enter no of nodes: ");
		scanf("%d",&n2);
		printf("Enter value of node1: ");
		scanf("%d",&first2->val);
		first2->ptr=first2;
		temp=first2;
		for(i=2;i<=n2;i++)
		{
			nd *nod2 =(nd*)malloc(sizeof(nd));
			if(nod2==NULL)
	        {
				printf("Overflow");
				return;
	        }	
	        else
	        {
				printf("Enter value of node%d: ",i);
				scanf("%d",&nod2->val);
				if(i==n2)
				 nod2->ptr=first;
				else 
				 nod2->ptr=NULL;
				temp->ptr=nod2;
				temp=temp->ptr;
			}	
		 }
		
	  }
	  if(first2!=NULL)
	  {
			nd *tmp;
			tmp=first2;
			printf("Link List after insertion: ");
			do
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}while(tmp != first2);
		}
		
		
		nd *head=first;
		nd *head2=first2;
		
		
			//setting head;		
			if(head && head2)
			{
				if(head->val < head2->val)
				{
					first3=head;
					head=first3->ptr;
				}
				else
				{
					first3=head2;
					head2=first3->ptr;
				}
						
			}
		nd *mergehead=first3;		
		
		
		while(head && head2)
			{
				if(head->val < head2->val)
				{
					first3->ptr=head;
					first3=head;
					head=first3->ptr;
				}
				else
				{
				    first3->ptr=head2;
					first3=head2;
					head2=first3->ptr;
				}
						
			}	
				
		if(head!=NULL)
			first3->ptr=head;		
		if(head2!=NULL)
			first3->ptr=head2;
			
		//setting last
		nd *last;
		last=mergehead;
		while(last->ptr!=mergehead)
		{
			last=last->ptr;
		}			
		
		last->ptr=mergehead;
			
		if(mergehead != NULL)
	    {
			nd *tmp3;
			tmp3=mergehead;
			printf("\nMerge: ");
			
			do{
				printf("%d ",tmp3->val);
				tmp3=tmp3->ptr;
			}while(tmp3 != mergehead);
		}		
}
