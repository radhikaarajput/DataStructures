#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

struct queue
{
	int val;
	int pri;
	struct node *ptr;
}*front, *rear,*front2,*rear2;


typedef struct queue nd;

nd *add[max];
int priority[max];
int i =-1;

void insert(int n, int p);
void traverse();
//int delete();

void main()
{
	int a,ch,pri;
	char c='y';
	front=NULL;
	rear=NULL;
	front2=NULL;
	rear2=NULL;
	
		printf("\nQueue Menu");
		printf("\n1.Insert\n2.Delete\n3.Traverse\n8.Exit");

		while(1)	
		{
		printf("\n\nEnter your choice(0-4):");
	//	fflush(stdin); 
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: printf("Enter element: ");
					scanf("%d",&a);
					printf("Enter priority: ");
					scanf("%d",&pri);
					insert(a,pri);
					printf("Queue Now: ");
					traverse();
					break;
					
		/*	case 2: 
					delete();
					printf("Queue Now: ");
					traverse();
					break;	
						*/
			
			case 3: printf("Queue Now: ");
					traverse();
					break;	
					
		}
	}
	getch();	
	
}



void insert(int n, int p)
{

		int j,flag=0,flagbetween=0,pos;
	
	for(j=0;j<=i;j++)
	{
		if(priority[j] == p)
		{
			flag=1;
			break;
		}
		
		
		if(priority[j+1] > p)
		{
			flagbetween=1;
			pos=j;
			break;
		}
		
	}
	
	if(i==-1 || flag==0)	
	{	
		//first element, element not found
			
		priority[++i]=p;
			
		front=(nd*)malloc(sizeof(nd));
		if(front==NULL)
		{
			printf("Overflow");
			return;
		}
				
		add[++i]=front;
						
		front->val=n;
		front->pri=p;
		front->ptr=NULL;
		
	}	
	
	
	
	else if(flagbetween==1)	   //element inbetween priority
	{
		i++;
		int m=i;					
		pos++;
		while(pos<m)
		{
			priority[m]=priority[m-1];
			add[m]=add[m-1];
			m--;
		}	
		
		
		front=(nd*)malloc(sizeof(nd));
		if(front==NULL)
		{
			printf("Overflow");
			return;
		}
		
		priority[pos]=p;
		add[pos]=front;
			
		
		front->val=n;
		front->pri=p;
		front->ptr=NULL;
	
	}	
		
	else if(flag==1)				//element found insert first
	{
		int k=0;
		while(priority[k] != p)
		{
			k++;
		}
		
		nd *first=add[k];
		nd *node=(nd*)malloc(sizeof(nd));
		
		node->ptr=first;
		add[k]=node;
		node->val=n;
		node->pri=p;
			
	}	
	
}




void traverse()
{
	int k=i;
	nd *temp;
	
	for(k=i;k>=0;k--)
	{
		temp=add[k];
			while(temp!=NULL)
			{
				printf("%d - ",temp->val);
				printf("%d \n",temp->pri);
				temp=temp->ptr;
			}
	}
}


