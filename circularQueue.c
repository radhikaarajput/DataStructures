#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5

int queue[max];
int Queue2[max];
int front=-1;
int rear=-1;

void insert(int n);
void traverse();
void delete();

void main()
{
	int a,ch;
	char c='y';
	printf("Queue Menu");
		printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Exit");
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
					
			case 2: delete();
					printf("Queue Now: ");
					traverse();
					break;

			case 3: traverse();
					break;
					
			case 4: exit(0);
					break;									
			
			default: printf("\nWrong Choice!!");
		}
	//	printf("\nContinue: ");
	//	fflush(stdin); 
	//	scanf("%c",&c);
	}	
	getch();
}



void insert(int n)
{
	if((rear==max && front ==0) && (front== rear+1))
	{
		printf("Full");
		return;
	}
	
	if(front== -1)
	{
		front=rear=0;
	}
	
	else if(rear==(max-1))
	{
		rear=0;
	}
	else{
		rear++;
	}
	
	queue[rear]=n;
}



void delete()
{
	if(front<0)
	{
		printf("Empty");
		return;
	}
	
	int temp=front;
	if(front== rear)
	{
		front=rear=-1;
	}
	else if(front == max-1)
	{
		front=0;
	}
	else{
		front++;
	}
	
	queue[temp]='\0';
}


void traverse()
{
	if(front==-1)
	{
		printf("Empty");
		return;
	}
	
		
	int temp=front;
	do
	{
		printf("%d ",queue[temp]);
		
		if(temp==max)
			temp=0;
		else
			temp++;
	
	}while(temp!=rear);
	
	if(front != rear)
		printf("%d ",queue[temp]);
}

