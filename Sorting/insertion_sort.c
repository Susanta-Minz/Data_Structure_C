#include<stdio.h>

//Function for the insertion sort
void insertion_sort(int A[],int n)
{
	int i,hole;
	for(i=1;i<=n-1;i++)
	{
		int value =A[i];
		hole=i;
		while(hole>0 && A[hole-1]>value)
		{
			A[hole]=A[hole-1];
			hole=hole-1;
		}
		A[hole]=value;
	}
}

int main()
{
	int n;
	printf("Enter no of elements in array \n");
	scanf("%d",&n);
	
	//Getting data for array
	int i;
	int A[n];
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		A[i]=x;
	}
	insertion_sort(A,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	return 0;
}
