#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

void insert(int n);
int delete();
void merge();
void traverse();
void search();
void sort();

int queue[max];
int Queue2[max];
int front=-1;
int rear=-1;
int length=0;

void main()
{
	int a,ch;
	char c='y';
	
		printf("Queue Menu");
		printf("\n1.Insert\n2.Delete\n3.Merge\n4.Sort\n5.Search\n6.Traverse\n7.Exit");
		while(1)	
		{
	
		printf("\nEnter your choice: ");
	//	fflush(stdin); 
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1: printf("Enter element: ");
					scanf("%d",&a);
					insert(a);
					break;
			case 2: delete();
					break;
			case 3: merge();
					break;
			case 4: sort();
					break;
			case 5: search();
					break;
			case 6: traverse();
					break;						
			case 7: exit(0);
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
	if(rear==max-1)
	{
		printf("Full");
		return;
	}
	
	if(front== -1)
	{
		front=rear=0;
		queue[rear]=n;
		length++;
	}
	else{
		rear++;
		queue[rear]= n;
		length++;
	}
}

int delete()
{
	if(front<0)
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

void traverse()
{
	if(front<0)
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

void sort()
{
	int i,j,temp;
	if(front<0)
	{
		printf("Empty");
		return;
	}
	else if(front==rear)
	{
		printf("%d ",queue[front]);
	}
	else{
		for(i=front;i<=rear-1;i++)
		{
			for(j=i+1;j<=rear-i;j++)
			{
			//	printf("Before i %d j %d \n",queue[i],queue[j]);
				if(queue[j]<queue[j-1])
				{
					temp=queue[j];
					queue[j]=queue[j-1];
					queue[j-1]=temp;
				}
				//	printf("after i %d j %d \n",queue[i],queue[j]);
			}
		}
	}
	traverse();
}

void reverse()
{
	int start=0, end=rear-1,i,temp;
	while(start<end)
	{
			temp =queue[start];
			queue[start]=queue[end];
			queue[end]=temp;
			start++;
			end--;
	}	
	printf("Now queue is: ");
	 for(temp=front;temp<=length;temp++)
	{
				printf("%d ",queue[temp]);
	}	
}

void search()
{
	int v,temp,found,flag=0;
	printf("enter element to search: ");
	scanf("%d",&v);
	 for(temp=front;temp<=rear;temp++)
	 {
		if(queue[temp]== v)
		{
				found=temp;
				flag=1;
				break;
	    }
	 }
	
	if(flag==1)
		printf("found at %d",found);	
	else
		printf("Not found");		
}

void merge()
{
	int n1,n2,i,j;
	int rear1=0,rear2=0;
	int front1=0,front2=0;
		printf("Enter size of Queue1: ");
			scanf("%d",&n1);
			printf("Enter elements: ");
			int *queue1=(int*)calloc(n1,sizeof(int));
			for(rear1=0;rear1<n1;rear1++)
				scanf("%d",&queue1[rear1]);
				
			
			printf("Enter size of queue2: ");
			scanf("%d",&n2);
			printf("Enter elements: ");
			int *queue2=(int*)calloc(n2,sizeof(int));
			for(rear2=0;rear2<n2;rear2++)
				scanf("%d",&queue2[rear2]);	
				
			
				
			int m=n1+n2;
			int queue3[m];
			i=front1;
			j=front2;
			int rear3=0,front3=0;
				
			while((i<n1) && (j<n2))
			{
				if(queue1[i]<queue2[j])
				{
					queue3[rear3]=queue1[i];
					i++;
				}
				else
				{
					queue3[rear3]=queue2[j];
					j++;
				}
					rear3++;	
			}	
				
				if(i<n1)
				{
					while(i<=n1)
					{
						queue3[rear3]=queue1[i];
						i++;
						rear3++;
						}
				}
				
					
				if(j<n2)
				{
					while(j<=n2)
					{
						queue3[rear3]=queue2[j];
						j++;
						rear3++;
						}
					}
		printf("Merged Array is: ");		
		for(i=front3;i<rear3-1;i++)
			printf("%d ",queue3[i]);
}
