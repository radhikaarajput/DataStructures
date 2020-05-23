#include<stdio.h>
#include<conio.h>

int Quicksort(int A[], int lb,int ub );
int partition(int A[],int lb, int ub);
int mergesort(int A[], int s,int e);                      //s=start, e= end
int merge(int A[],int s, int e, int mid);


int main()
{
	int i,n,c;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int A[n];
	printf("Enter Elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);	
   }
   printf("1.Quick Sort \n2.Merge Sort \n\nEnter choice: ");
	scanf("%d",&c);
	if(c==1)
   		Quicksort(A,0,n-1);
    if(c==2)
		mergesort(A,0,n-1);
		
	printf("Sorted Array");
   	for(i=0;i<n;i++)
    {
		printf("%d  ",A[i]);	
	}
	getch();
	return 0;
}


int mergesort(int A[],int s, int e)
{
	if(s<e)     //if there are more than one element as one element is always sorted
	{
	int mid=(s+(e-1))/2;
	mergesort(A,s,mid);
	mergesort(A,mid+1,e);
	merge(A,s,e,mid);
	
    }
	return 0;
}

int merge(int A[],int s, int e, int mid)
{
	int i,j,k;
	int n1=mid-s+1;     //size of temporary array 1;
	int n2=e-mid;         //size of temp array 2;
	int l[n1];            //two temp array l,r 
	int r[n2];          
	
	//copy data from main  array A to temp array l and r or comparisions
	for(i=0;i<n1;i++)
	{
		l[i]=A[i];
	}
	for(i=0;i<n2;i++)             //elements after mid
	{
		r[i]=A[mid+1+i];
	}
	while(i<=n1 && j<=n2)
	{
		if(A[i]>=A[j])	
		{
			A[k]=l[i];
			i++;
		}
		else
		{
			A[k]=r[j];
			j++;
	    }	
	    k++;
	}
	
	while(i<=mid)
	{
		A[k++]=l[i++];
	}
	while(j<=e)
	{
		A[k++]==r[j++];
	}
	
	return 0;
}

int Quicksort(int A[], int lb,int ub )
{
	if(lb<ub)
	{
		int part=partition(A,lb,ub);
		Quicksort(A,lb,part-1);
		Quicksort(A,part+1,ub);
	}
	return 0;
}

int partition(int A[], int lb, int ub)
{
	int pivot=A[lb],temp;   // chosing last element as pivot
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(A[start]<=pivot)
		{
			start++;
		}
		while(A[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
				temp=A[start];
				A[start]=A[end];
				A[end]=temp;
		}
		temp=A[lb];
		A[lb]=A[end];
		A[end]=temp;
	}
	
	return end;
}
