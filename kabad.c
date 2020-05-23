#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

struct queue
{
	int val;
	int pri;
	struct node *ptr;
}*front, *rear;


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

		while(1)	
		{
		printf("\nQueue Menu");
		printf("\n1.Insert\n2.Delete\n3.Merge\n4.Sort\n5.Search\n6.reverse\n7.Traverse\n8.Exit");
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
			
			case 7: printf("Queue Now: ");
					traverse();
					break;	
					
		}
	}
	getch();	
	
}



void insert(int n, int p)
{

	int j,flag=0,flagbetween=0,fst=0,sec=0,flag1=0;
	
	if(i== -1)
	{
		fst=1;          //first element 
	}
	
	if(i==0)
	{
		sec=1;
	}
	else
	{
			for(j=0;j<=i;j++)        
			{
				if(priority[j]==p)
				{
					flag=1;
					break;
				}
				
				
				if(priority[j+1] > p)              //insert in-b/w priority array
				{
					flagbetween=1;
					break;
				}
				
				if(priority[j] > p)              //if first postiton has to be shifted of priority
				{
					flag1=1;
					break;
				}
				
			}
	
	}
	
	if(fst==1)				//first element 
	{
		
		i++;
		priority[i]=p;
		
		front=(nd*)malloc(sizeof(nd));
		if(front==NULL)
		{
			printf("Overflow");
			return;
		}
		
		
		add[i] =(nd*)malloc(sizeof(nd));
		add[i]=front;
			
		front->ptr=NULL;
		front->val=n;
		front->pri=p;
	}
	
	else if(sec==1)				//first element 
	{
		
		i++;
		priority[i]=p;
		
		front=(nd*)malloc(sizeof(nd));
		if(front==NULL)
		{
			printf("Overflow");
			return;
		}
		
		
		add[i] =(nd*)malloc(sizeof(nd));
		add[i]=front;
			
		front->ptr=NULL;
		front->val=n;
		front->pri=p;
		
		nd *tempa;
		int temp;
		if(priority[0]>priority[1])
		{
			tempa=add[0];
			add[0]=add[1];
			add[1]=tempa;
			
			temp=priority[0];
			priority[0]=priority[1];
			priority[1]=temp;
		}
	}
	
	else if(flag==0 && flagbetween==0)	
	{						//element not found of that priority so create new one as p>priority[last]
		i++;
		priority[i]=p;
		
		front=(nd*)malloc(sizeof(nd));
		if(front==NULL)
		{
			printf("Overflow");
			return;
		}
		
		
		add[i] =(nd*)malloc(sizeof(nd));
		add[i]=front;
			
		front->ptr=NULL;
		front->val=n;
		front->pri=p;
		
	}	
	
	else if(flagbetween==1)	   //element inbetween 
	{
		int m=i+1;					
		
		while(j<m)
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
		
		priority[j+1]=p;
		add[j+1]= &front;
			
		front->ptr=NULL;
		front->val=n;
		front->pri=p;
		
	}	
		
	else if(flagbetween==0 && flag==1)				//list exist insert in
	{
		nd *temp=add[j];
		int k=0;
		int length=-1;
		while(temp!=NULL)
		{
			temp=temp->ptr;
			
		}
		
		nd *node=(nd*)malloc(sizeof(nd));
		node->val=n;
		node->pri=p;
		temp->ptr=node;
		node->ptr=NULL;
			
	}	
	else if(flag1==1)				//list exist insert in
	{
		int m=i+1;					
		
		while(j<m)
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
		
		priority[j]=p;
		add[j]= &front;
			
		front->ptr=NULL;
		front->val=n;
		front->pri=p;
			
		}	
	
		else if(flag==0 && flag1==0 && flagbetween==0 && fst==0 && sec=0)				//first element 
		{
		
		i++;
		priority[i]=p;
		
		front=(nd*)malloc(sizeof(nd));
		if(front==NULL)
		{
			printf("Overflow");
			return;
		}
		
		
		add[i] =(nd*)malloc(sizeof(nd));
		add[i]=front;
			
		front->ptr=NULL;
		front->val=n;
		front->pri=p;
		
		
	}
}



void traverse()
{
	int k=i,j;
	int a,p;
	
	
	for(k=i;k>=0;k--)
	{
	//	printf("in loop");
		a=add[k];
		p=priority[k];
		
		nd *temp=a;
			while(temp)
			{
				printf("%d ",temp->val);
				printf("%d ->",temp->pri);
				temp=temp->ptr;
			}
	}
}

/*
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
*/
