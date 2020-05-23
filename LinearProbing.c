#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert(int A[], int max);
struct hash_item
{
	int val;
	int flag;
};
typedef struct hash_item h;

void main()
{
	int i,max;
	printf("Enter size of table: ");
	scanf("%d",&max);
	h A[max];
	int Array[max];   //stores element
	//initialize flag with 0 and value also
	for(i=0;i<max;i++)
	{
		A[i].val=0;
		A[i].flag=0;
	}
	
	int key,hc;
	int j=0;
	for(j=0;j<max;j++)
	{
		i=0;
		printf("Enter Element: ");
		scanf("%d",&key);
	
	
		//hash code
		 hc=((key % max + i) % max);
	
		//element not present flag=0
		if(A[hc].flag==0)
		{
			Array[hc]=key;
		}

		if(A[hc].flag==1)
		{
			while(A[hc].flag == 1)
			{
				i++;
				hc=((key % max + i) % max);
			}
			Array[hc]=key;
		}
	}
	
	for(i=0;i<max;i++)
	{
		printf("Index %d Element: %d\n",i,Array[i]);		
	}
	getch();
}

/*void insert(int A[], int max)
{
	int key,i=0;
	printf("Enter Element: ");
	scanf("%d",&key);
	
	
	//hash code
	int hc=((key % max + i) % max);
	
	//element not present flag=0
	if(A[hc].flag==0)
	{
		Array[hc]=key;
	}

	if(A[hc].flag==1)
	{
		while(A[hc].flag == 1)
		{
			i++;
			hc=((key % max + i) % max);
		}
		Array[hc]=x;
	}
}
*/
