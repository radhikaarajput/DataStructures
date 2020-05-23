#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertBeg(int A[], int n);
void insertEnd(int A[], int n);
void insertAtAnyPosition(int A[], int n);
void traverseSearch(int A[], int n);
void deleteBeg(int A[], int n);
void deleteEnd(int A[], int n);
void deleteAnyElement(int A[], int n);
void concatenate(int A[], int n);
void reverse(int A[], int n);
void printArray(int A[],int n);
void bubbleSort(int *A, int n);
void selectionSort(int *A, int n);
void insertionSort(int *A, int n);
void LinearSearch(int *A,int find,int n );
int BinarySearch(int *A,int find,int left, int right );
void frequency(int *A, int n);
void secondSmallest(int *A, int n);
int main()
{
	int n,i,val,pos,ch,find;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int *A= (int*)calloc(n,sizeof(int));
	printf("Enter elements of array: ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	printf("Menu \n 1.Insert at beggining \n 2.Insert at end \n 3.Insert at given position \n 4.Traverse \n 5.Delete from beggining \n 6.Delete from end \n 7. Delete given element \n 8.Concatenate \n 9. Reverse \n 10.Print Array \n 11.Linear Search \n 12.Binary Search \n 13.Bubble Sort \n 14.Selection sort \n 15.Bubble Sort \n 16.Frequency of each element \n 17.Second Smallest Number");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			insertBeg(A,n);
			break;
			
		case 2:
			insertEnd(A,n);
			break;
			
		case 3:
			insertAtAnyPosition(A,n);
			break;
			
		case 4:
			traverseSearch(A,n);
			break;	
				
		case 5:
			deleteBeg(A,n);
			break;
				
		case 6: 
			deleteEnd(A,n);
			break;
				
		case 7:
			deleteAnyElement(A,n);
			break;
				
		case 8:
			concatenate(A,n);
			break;	
			
			
	    case 9:
			reverse(A,n);
			break;
			
				
		case 10:
			printArray(A,n);
			break;
		case 11:printf("Enter element to find: ");
				scanf("%d",&find);
				LinearSearch(A,find,n );
				break;
		case 12:printf("Enter element to find: ");
				scanf("%d",&find);
				BinarySearch(A,find,0,n);
				break;
		case 13:
			bubbleSort(A,n);
			printArray(A,n);
			break;
		case 14:
			selectionSort(A,n);
			printArray(A,n);
			break;
		case 15:
			insertionSort(A,n);
			printArray(A,n);
			break;
		case 16:
			frequency(A,n);
			break;	
		case 17:
			secondSmallest(A, n);
			break;			
	}
	
	getch();
	return 0;
	
}

void insertBeg(int *A, int n)
{
	int val,i;
		printf("\nEnter value for insertion: ");
		scanf("%d",&val);
		
		for(i=n;i>=0;i--)
			A[i+1]=A[i];
			
		n++;	
		A[0]=val;
		printf("Now array is: ");
			for(i=0;i<n;i++)
				printf("%d  ",A[i]);		
}

void insertEnd(int *A, int n)
{
	int val,i;
		printf("\nEnter value for insertion: ");
		scanf("%d",&val);
		A[n]=val;
		n=n+1;
		
		printf("Now array is: ");
			for(i=0;i<n;i++)
				printf("%d  ",A[i]);		
}

void insertAtAnyPosition(int *A, int n)
{
	int val,i,pos;
		printf("\nEnter value for insertion: ");
		scanf("%d",&val);
		printf("Enter position: ");
		scanf("%d",&pos);
		for(i=n;i>=pos;i--)
				A[i+1]=A[i];
				
		A[pos]=val;
		n=n+1;
		
		printf("Now array is: ");
			for(i=0;i<n;i++)
				printf("%d  ",A[i]);	
}

void traverseSearch(int *A, int n)
{
	int val,i,pos,flag=1;
		printf("Enter element to search: ");
		scanf("%d",&val);
			
		for(i=0;i<n;i++)
		{ 
			if(A[i]==val)
			{
				pos=i;
				printf("Element found at position %d",pos);
				flag=0;
				break;
			}	
			
		}
		if(flag==1)
			printf("Element not found");		
}

void deleteEnd(int *A, int n)
{	
	int i;
		n=n-1;
		printf("Now array is: ");
		for(i=0;i<n;i++)
			printf("%d  ",A[i]);
}

void deleteBeg(int *A, int n)
{
	int i;
	for(i=n;i>=0;i--)
		A[i]=A[i-1];
			 
	 n=n-1;
	 printf("Now array is: ");
	 for(i=0;i<n;i++)
		printf("%d  ",A[i]);
}

void deleteAnyElement(int *A, int n)
{
	int val,i,pos,flag=0;
	  printf("\nEnter element to delete: ");
	  scanf("%d",&val);
	
	for(i=0;i<n;i++)
	{
		if(A[i]==val)
		{
			pos=i;
			flag=1;
			break;
		}
		
	}
	if(flag==0)
		printf("Element not found");
	else
		{
			for(i=pos;i<n;i++)
				A[i]=A[i+1];
		}
	n--;		
					
	printf("/nArray is: ");
	 for(i=0;i<n;i++)
		printf("%d  ",A[i]);
}

void concatenate(int *A, int n)
{
	int n1,n2,i;
	printf("Enter size of array1: ");
	scanf("%d",&n1);
	int *A1=(int*)calloc(n1,sizeof(int));
	printf("Enter elements of array1: ");
		for(i=0;i<n1;i++)
			scanf("%d",&A1[i]);	
	
	printf("Enter size of array2: ");
	scanf("%d",&n2);
	int *A2=(int*)calloc(n2,sizeof(int));
	printf("Enter elements of array2: ");
		for(i=0;i<n2;i++)
			scanf("%d",&A2[i]);			
								
	int k;	
	int m=n1+n2;
	for(i=n1, k=0 ;i<m, k<n2;i++,k++)
		A1[i]=A2[k];
			
	printf("Now array is: ");
	 for(i=0;i<m;i++)
		printf("%d ",A1[i]);
		
}		

void reverse(int *A,int n)
{
	int start=0, end=n-1,i,temp;
	while(start<end)
	{
			temp =A[start];
			A[start]=A[end];
			A[end]=temp;
			start++;
			end--;
	}	
	printf("Now array is: ");
	 for(i=0;i<n;i++)
		printf("%d ",A[i]);				
}

void printArray(int *A,int n)
{
	int i;
	printf("Array is: ");
	 for(i=0;i<n;i++)
		printf("%d ",A[i]);			
}

void bubbleSort(int *A, int n)
{
	int i,j,flag,k;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(k=0; k<n-i-1;k++)
        {
            if(A[k]>A[k+1])
            {
                int temp=A[k];
                A[k]=A[k+1];
                A[k+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("Sorted Already");
            break;
        }
    }
}

void selectionSort(int *A, int n)
{
	int i,j;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        
        int temp=A[min];
        A[min]=A[i];
        A[i]=temp;
    }
}

void insertionSort(int *A, int n)
{
	int i,j;
    for(i=0;i<n;i++)
    {
       int val=A[i];
       int hole=i;
       
       while(hole>0 && A[hole-1]>val)
       {
           A[hole]=A[hole-1];
           hole--;
       }
       
       A[hole]=val;
    }
}

int BinarySearch(int *A,int find,int left, int right )
{
	int i;
	if(right>left)
	{
		int mid=(left+right)/2;
		if(A[i]== mid)
		{
			printf("Found");
			return mid;
		}
		else if(A[mid]<find)
		{
			return BinarySearch(A,find,mid+1,right);
		}
		else if(A[mid]>find)
		{
			return BinarySearch(A,find,left,mid-1);	
		}
	}
	return -1;	
}

void LinearSearch(int *A,int find,int n )
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]== find)
		{
			printf("Found %d",i+1);
		}
	}
}

void frequency(int *A, int n)
{
	int i,j,freq[n],count;
	
	for(i=0; i<n; i++)
    	freq[i]=-1;
    	
	for(i=0; i<n; i++)
    {
        count = 1;
        for(j=i+1; j<n; j++)
        {
            if(A[i]==A[j])
            {
                count++;

                freq[j] = 0;
            }
        }

        /* If frequency of current element is not counted */
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    
    for(i=0;i<n;i++)
    {
		if(freq[i] != 0)
        	printf("Frequency of %d is %d \n", A[i],freq[i]);
	}
}


void secondSmallest(int *A, int n)
{
	int i, smallest,secondsmallest;
	
	if (A[0] < A[1]) {
        smallest = A[0];
        secondsmallest = A[1];
    }
    else {
      smallest = A[1];
      secondsmallest = A[0];
    }
    for (i = 2; i < n; i++) {
        if (A[i] < smallest) {
        secondsmallest = smallest;
        smallest = A[i];
        }
        else if (A[i] < secondsmallest) {
            secondsmallest = A[i];
        }
    }
    printf(" \nSecond smallest element is %d", secondsmallest);
	
}

