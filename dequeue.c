#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

void insertfront(int n);
void insertrear(int n);
int deletefront();
int deleterear();
void traverse();


int queue[max];
int front=-1;
int rear=-1;
int length=0;

void main()
{
	int a,ch;
	char c='y';

		while(1)	
		{
		printf("\nQueue Menu");
		printf("\n1.Insert front\n2.Insert rear \n3.Delete front \n4.delete rear\n5..Traverse\n7.Exit");
		printf("\n\nEnter your choice(0-4):");
	//	fflush(stdin); 
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: printf("Enter element: ");
					scanf("%d",&a);
					insertfront(a);
					printf("Queue Now: ");
					traverse();
					break;
					
			case 2: printf("Enter element: ");
					scanf("%d",&a);
					insertrear(a);
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



void insertfront(int n)
{
	if(((rear==max-1) && (front==0)) ||  (front==rear+1))
	{
		printf("Full");
		return;
	}
	
	int temp;
	if(front== -1)
	{
		front=rear=0;
		queue[front]=n;
	}
	else if(front== 0)
	{
		temp=rear+1;
		while(temp>front)
		{
			queue[temp]= queue[temp-1];
			temp--;
		}
		
		queue[front]=n;
		rear++;
	}
	else{
		front--;
		queue[front]= n;
	}
}



void insertrear(int n)
{
	if(((rear==max-1) && (front==0))|| (front==rear+1))
	{
		printf("Full");
		return;
	}
	
		rear++;
		queue[rear]=n;
}


int deletefront()
{
	if(front== -1)
	{
		printf("Empty");
		return;
	}
	
	if(front== rear)
	{
		queue[front]='\0';
		front=rear=-1;
	}
	else{
		queue[front]='\0';
		front++;
	}
}

int deleterear()
{
	if(front== -1)
	{
		printf("Empty");
		return;
	}
	
	if(front== rear)
	{
		queue[front]='\0';
		front=rear=-1;
	}
	else{
		queue[rear]='\0';
		rear--;
	}
}

void traverse()
{
	if(front==-1)
	{
		printf("Empty");
		return;
	}
	
	int temp=front;
	while(temp<=rear)
	{
		printf("%d ",queue[temp]);
		temp++;
	}
}

