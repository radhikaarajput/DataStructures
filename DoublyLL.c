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
void search();
void traversal();
void length();
int len=0;


typedef struct node nd;

struct node
{
	int val;
	struct node *prev;
	struct node *next;
}*first,*first2,*first3;

int main()
{	
	nd *first=NULL;
	nd *first2=NULL;
	nd *first3=NULL;
	int c;
	char ch='y';
	
	printf("Menu \n0.Create List \n1.Insert at beggining \n2.Insert at end \n3.Insert after a given value \n4.Delete from begining \n5.Delete from end\n6.Delete a value\n7.Search \n8.Traversal \n9.Length");
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
			search();
			break;
		case 8:
			traversal();
			break;
		case 9:
			length();
			break;
	/*	case 8:
			reverse();
			break;
		case 9:
			merge();
			break;	
			*/	
				
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
		first->next=NULL;
		first->prev=NULL;
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
				nod->next=NULL;
				nod->prev=temp;
				temp->next=nod;
				temp=temp->next;
			}	
		 }
		
	  }
	  if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("Link List after insertion: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
		}
}

void insertBeg( )
{
	nd *newn;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
		
		printf("Enter value for insertion: ");
		scanf("%d",&newn->val);
		newn->prev=NULL;
		newn->next=first;
		if(first!=NULL)
		{
			first->prev=newn;
		}
		first=newn;
		
	nd *temp;
	temp=first;
	printf("Link List after insertion: ");
	while(temp != NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
}

void insertEnd()
{
	nd *newn,*temp,*last=NULL;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
		
		printf("Enter value for insertion: ");
		scanf("%d",&newn->val);
		
		temp=first;
		newn->next=NULL;
		while(temp!=NULL)
		{
			last=temp;
			temp=temp->next;
		}
	if(first!=NULL)
	{
		newn->prev=last;
		last->next=newn;
	}
	else
	{
		newn->prev=NULL;
		first=newn;
	}
	nd *tmp=first;
	printf("Link List after insertion: ");
	while(tmp != NULL)
	{
		printf("%d ",tmp->val);
		tmp=tmp->next;
	}
}

void length()
{
	if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("\nLink List after insertion: ");
			while(tmp != NULL)
			{
				tmp=tmp->next;
				len++;
			}
		}
		
		printf("Length is: %d ",len);	
}
void traversal()
{
	if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("\nLink List after insertion: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
		}
}
void insertValue()
{
	int value;
	printf("Enter value: ");
	scanf("%d",&value);
	nd *newn,*temp,*tmp,*ntemp;
	newn=(nd*)malloc(sizeof(nd));

	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
		
	temp=first;
	while(temp!=NULL)
	{
		if(temp->val==value)
			break;
		else
			temp=temp->next;
	}
	printf("Enter value for insertion: ");
	scanf("%d",&newn->val);
	if(temp==NULL)
		printf("Element not found");
	else
	{
		ntemp=temp->next;
		if(ntemp!=NULL)
		{
			ntemp->prev=newn;
		}
		else
		{
			newn->next=NULL;
		}
		newn->next=ntemp;
		temp->next=newn;
		newn->prev=temp;
	}
	
	  if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("\nLink List after insertion: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
		}
}

void deleteBeg()
{
	if(first==NULL)
	{	printf("UnderFlow");
		return;
	}
	nd *temp;
	temp=first;
	first=first->next;
	first->prev=NULL;
	free(temp);	
	
	if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("\nLink List: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
		}
}

void deleteEnd()
{
	if(first==NULL)
	{	printf("UnderFlow");
		return;
	}
	nd *temp,*prev;
	temp=first;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
	
	if(first!=NULL)
	  {
			nd *tmp;
			tmp=first;
			printf("\nLink List: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
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
	nd *temp,*prev,*t;
	temp=first;
	
	if(temp!=NULL && temp->val==value)   //deleting first element
	{
		printf("Element 1");
		first=temp->next;
		first->prev=NULL;
		free(temp);
		return;
		
	}
	
	while(temp!=NULL && temp->val!=value)    //element in-b/w
	{
		//printf("Traversing");
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)                        //element not present
	{
		printf("\n element not found");
		return;
	}
	
	prev->next=temp->next;
	if(temp->next != NULL)
	 temp->next->prev=temp->prev;
	free(temp);	

	
	
	if(first!=NULL)
	{
			nd *tmp;
			tmp=first;
			printf("\nLink List: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
	}
}

void search()
{
	int v,len=0,flag=0;
	printf("Enter value for searching");
	scanf("%d",&v);
	nd *temp=first;
	while(temp->next != NULL)
	{
		len++;
		temp=temp->next;
		if(temp->val==v)
		{
			flag=1;
			break;
		}
		
	}
	if(flag==1)
		printf("Found at %d" ,len);
	else
		printf("not found");	
	
}

/*void sort()
{
	nd *f,*s;
	f=first;
	int temp;
	for(f=first;f->ptr!=NULL;f=f->ptr)
	{
		for(s=f->ptr;s!=NULL;s=s->ptr)
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
			printf("\nLink List: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}
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
	}
	nd *cur,*next,*prev;
	prev=NULL;
	cur=first;
	next=first;
	while(cur != NULL)
	{
		next=next->ptr;
		cur->ptr=prev;
		prev=cur;
		cur= next;
	}
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
			printf("\nLink List1 after insertion: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}
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
		first2->ptr=NULL;
		temp2=first2;
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
				nod2->ptr=NULL;
				temp2->ptr=nod2;
				temp2=temp2->ptr;
			}	
		 }
		
	  }
	  if(first2!=NULL)
	  {
			nd *tmp2;
			tmp2=first2;
			printf("\nLink List2 after insertion: ");
			while(tmp2 != NULL)
			{
				printf("%d ",tmp2->val);
				tmp2=tmp2->ptr;
			}
		}
		
		
		
		nd *head=first;
		nd *head2=first2;
		
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
		nd *print=first3;		
		
		
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
			
		if(print!=NULL)
	    {
			nd *tmp3;
			tmp3=print;
			printf("\nMerge: ");
			while(tmp3 != NULL)
			{
				printf("%d ",tmp3->val);
				tmp3=tmp3->ptr;
			}
		}		
}
*/
