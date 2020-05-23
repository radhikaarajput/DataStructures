#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

struct queue
{
	int val;
	int pri;
	struct queue *ptr;
}*front, *rear;


typedef struct queue nd;

void insert(int n, int p);
void traverse();
int delete();

void main()
{
	int a,ch,p;
	char c='y';
	front=NULL;
	rear=NULL;
	printf("Queue Menu");
		printf("\n1.Insert\n2.Delete\n3.Traverse\n8.Exit");
		while(1)	
		{
		printf("\n\nEnter your choice: ");
	//	fflush(stdin); 
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: printf("Enter element: ");
					scanf("%d",&a);
					printf("Enter priority: ");
					scanf("%d",&p);
					insert(a,p);
					printf("Queue Now: ");
					traverse();
					break;
					
			case 2: 
					delete();
					printf("Queue Now: ");
					traverse();
					break;	
					
						
			
			case 3: printf("Queue Now: ");
					traverse();
					break;	
					
			case 8: exit(0);
					break;				
					
		}
	}
	getch();	
	
}


void insert(int n, int p)
{
	nd *temp,*prior;
	temp=(nd*)malloc(sizeof(nd));
	if(temp==NULL)
	{
		printf("Overflow");
		return;
	}
	
	
	
	temp->val=n;
	temp->pri=p;
	
	
	if(front==NULL || p < front->pri )
	{
		temp->ptr=front;
		front=temp;
	}
	else{
		prior=front;
		while((prior->ptr!=NULL) &&  (prior->ptr->pri < p))
		{
			prior=prior->ptr;
		}	
			
		temp->ptr=prior->ptr;
		prior->ptr=temp;	
	}
}





void traverse()
{
	if(front==NULL)
	{
		printf("Empty");
		return;
	}
	
	nd *temp=front;
	while(temp != NULL)
	{
		printf("%d ",temp->val);
		printf("%d -> ",temp->pri);
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


