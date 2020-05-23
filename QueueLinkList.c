#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

struct queue
{
	int val;
	struct node *ptr;
}*front, *rear,*front2,*rear2;


typedef struct queue nd;

void insert(int n);
void traverse();
int delete();
void sort();
void reverse();
void search();
void merge();

void main()
{
	int a,ch;
	char c='y';
	front=NULL;
	rear=NULL;
	front2=NULL;
	rear2=NULL;
	printf("\nQueue Menu");
		printf("\n1.Insert\n2.Delete\n3.Merge\n4.Sort\n5.Search\n6.reverse\n7.Traverse\n8.Exit");

		while(1)	
		{
		printf("\n\nEnter your choice: ");
	//	fflush(stdin);  
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: printf("Enter element: ");
					scanf("%d",&a);
					insert(a);
					printf("Queue Now: ");
					traverse();
					break;
					
			case 2: 
					delete();
					printf("Queue Now: ");
					traverse();
					break;	
					
			case 3:
					merge();
					break;				
				
			case 4: 
					sort();
					printf("Queue Now: ");
					traverse();
					break;
					
			case 5: 
					search();
					break;					
						
			case 6: 
					reverse();
					printf("Queue Now: ");
					traverse();
					break;				
			
			case 7: printf("Queue Now: ");
					traverse();
					break;		
					
		}
	}
	getch();	
	
}


void insert(int n)
{
	nd *temp;
	temp=(nd*)malloc(sizeof(nd));
	if(temp==NULL)
	{
		printf("Overflow");
		return;
	}
	
	//int a[5];
	//a[0]=&temp;
	//printf("ponter %d",a[0]);
	temp->ptr=NULL;
	temp->val=n;
	
	if(front==NULL)
	{
		front=rear=temp;
	}	
	else
	{
		rear->ptr=temp;
		rear=temp;
	}
}



void sort()
{
	
	
	if(front<0)
	{
		printf("Empty");
		return;
	}
	else if(front==rear)
	{
		printf("%d ",front->val);
	}
	
	nd *f,*s;
	f=front;
	int temp;
	for(f=front;f->ptr!=NULL;f=f->ptr)
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
	
	
}


void reverse()
{
	
	int length=0;
	nd *p,*q;
	nd *tmp=front;
	while(tmp != NULL)
	{
		tmp=tmp->ptr;
		length++;
	}
	int i=0,j=length-1,k=0,t;
	p=q=front;
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
		q=front;
	}
}


void search()
{
	int v,found=0,flag=0;
	nd *temp;
	printf("enter element to search: ");
	scanf("%d",&v);
	 for(temp=front;temp!=NULL;temp=temp->ptr)
	 {
		if(temp->val == v)
		{
				found++;
				flag=1;
				break;
	    }
	 }
	
	if(flag==1)
		printf("found at %d",found);	
	else
		printf("Not found");		
}



void traverse()
{
	if(front==NULL)
	{
		printf("Empty");
		return;
	}
	
	nd *temp=front;
	while(temp)
	{
		printf("%d ",temp->val);
		temp=temp->ptr;
	}
}


int delete()
{
	if(front==NULL)
	{
		printf("Empty");
		return;
	}
	
	nd *temp=front;
	if(front== rear)
	{
		front=rear=NULL;
	}
	else{
		front=front->ptr;
	}
	
	free(temp);
}


void merge()
{
	int i,n,n2;
	printf("Queue1: ");
	nd *temp,*temp2;		
	front=(nd*)malloc(sizeof(nd));
	if(front==NULL)
	{
		printf("Overflow");
		return;
	}	
	else
	{
		printf("Enter no of nodes: ");
		scanf("%d",&n);
		printf("Enter value of node1: ");
		scanf("%d",&front->val);
		front->ptr=NULL;
		temp=front;
		rear=front;
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
				rear->ptr=nod;
				rear=rear->ptr;
			}	
		 }
		
	  }
	  if(front!=NULL)
	  {
			nd *tmp;
			tmp=front;
			printf("\nLink List1 after insertion: ");
			while(tmp != NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->ptr;
			}
		}	
		
		
		
	printf("\nQueue: ");		
	front2=(nd*)malloc(sizeof(nd));
	if(front2==NULL)
	{
		printf("Overflow");
		return;
	}	
	else
	{
		printf("Enter no of nodes: ");
		scanf("%d",&n2);
		printf("Enter value of node1: ");
		scanf("%d",&front2->val);
		front2->ptr=NULL;
		rear2=front2;
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
				rear2->ptr=nod2;
				rear2=rear2->ptr;
			}	
		 }
		
	  }
	  if(front2!=NULL)
	  {
			nd *tmp2;
			tmp2=front2;
			printf("\nLink List2 after insertion: ");
			while(tmp2 != NULL)
			{
				printf("%d ",tmp2->val);
				tmp2=tmp2->ptr;
			}
		}
		
		
		
		nd *head=front;
		nd *head2=front2;
		nd *front3=NULL;
		nd *rear3=NULL;
		
			if(head && head2)
			{
				if(head->val < head2->val)
				{
					front3=head;
					rear3=head;
					head=head->ptr;
				}
				else
				{
					front3=head2;
					rear3=head2;
					head2=head2->ptr;
				}
						
			}
	
		
		while(head && head2)
		{
				if(head->val < head2->val)
				{
					rear3->ptr=head;
					rear3=head;
					head=head->ptr;
				}
				else
				{
				    rear3->ptr=head2;
					rear3=head2;
					head2=head2->ptr;
				}
						
		}	
				
		if(head)
			rear3->ptr=head;		
		if(head2)
			rear3->ptr=head2;		
			
		if(front!=NULL)
	    {
			nd *tmp3;
			tmp3=front3;
			printf("\nMerge: ");
			while(tmp3 != NULL)
			{
				printf("%d ",tmp3->val);
				tmp3=tmp3->ptr;
			}
		}		
}
