#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

void insertfront();
void insertrear();
int deletefront();
int deleterear();
void traverse();


typedef struct node nd;

struct node
{
	int val;
	struct node *ptr;
}*front,*rear;

void main()
{
	int a,ch;
	char c='y';
	nd *front=NULL;
	nd *rear=NULL;

		while(1)	
		{
		printf("\nQueue Menu");
		printf("\n1.Insert front\n2.Insert rear \n3.Delete front \n4.delete rear\n5..Traverse\n7.Exit");
		printf("\n\nEnter your choice(0-4):");
	//	fflush(stdin); 
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: 
					insertfront();
					printf("Queue Now: ");
					traverse();
					break;
					
			case 2: 
					insertrear();
					printf("Queue Now: ");
					traverse();
					break;
					
			case 3: printf("Enter element: ");
					deletefront();
					printf("Queue Now: ");
					traverse();
					break;
					
			case 4: printf("Enter element: ");
					deleterear();
					printf("Queue Now: ");
					traverse();
					break;						
						
			case 5: 
					printf("Queue Now: ");
					traverse();
					break;						
											
			
			default: printf("\nWrong Choice!!");
		}
	//	printf("\nContinue: ");
	//	fflush(stdin); 
	//	scanf("%c",&c);
	}	
	getch();
}



void insertfront()
{
	nd *newn;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("Overflow");
		return;
	}	
		newn->ptr=front;
		printf("Enter value for insertion: ");
		scanf("%d",&newn->val);
		
	if(front==NULL)
		front=rear=newn;
		
	else
		front=newn;		

}



void insertrear()
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
		newn->ptr=NULL;
	
        
        temp = front;

    
        while(temp->ptr != NULL)
            temp = temp->ptr;

        temp->ptr = newn;
        rear=newn;
		
	
}


int deletefront()
{
	if(front==NULL)
	{	printf("UnderFlow");
		return;
	}
	nd *temp;
	temp=front;
	front=front->ptr;
	free(temp);	
}

int deleterear()
{
	if(rear==NULL)
	{	printf("UnderFlow");
		return;
	}
	nd *temp,*prev;
	temp=front;
	while(temp->ptr!=NULL)
	{
		prev=temp;
		temp=temp->ptr;
	}
	prev->ptr=NULL;
	rear=prev;
	free(temp);
	
	
}


void traverse()
{
		
	if(front== NULL)
	{
		printf("Empty");
		return;
	}
	
		
	nd *temp=front;
	do
	{
		printf("%d ",temp->val);
		temp=temp->ptr;
	
	}while(temp!= rear);
	
		
}
