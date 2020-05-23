#include<stdio.h>
#include<stdlib.h>
int main()
{
int i=0,j=0,k=0;	
int n1,n2;

			printf("Enter size of array1: ");
			scanf("%d",&n1);
			int *A1=(int*)calloc(n1,sizeof(int));
			printf("Enter elements of array1: ");
			for(i=0;i<n1;i++)
				scanf("%d",&A1[i]);
				
			
			printf("Enter size of array2: ");
			scanf("%d",&n2);
			int *A2=(int*)calloc(n2,sizeof(int));
			printf("Enter elements of array1: ");
			for(i=0;i<n2;i++)
				scanf("%d",&A2[i]);	
				
			
				
			int m=n1+n2;
			int *A3=(int*)calloc(m,sizeof(int));
			i=0;	
				
			while((i<n1) && (j<n2))
			{
				if(A1[i]<A2[j])
				{
					A3[k]=A1[i];
					i++;
				}
				else
				{
					A3[k]=A2[j];
					j++;
				}
					k++;	
			}	
				
				if(i<n1)
				{
					while(i<=n1)
					{
						A3[k]=A1[i];
						i++;
						k++;
						}
				}
				
					
				if(j<n2)
				{
					while(j<=n2)
					{
						A3[k]=A2[j];
						j++;
						k++;
						}
					}
		printf("Merged Array is: ");		
		for(i=0;i<m;i++)
			printf("%d ",A3[i]);
			
		getch();
		}
		
		
