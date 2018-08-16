#include<stdio.h>

void disp(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",A[i]);
	printf("\n");
}


void bubble_sort(int A[],int n)
{
	int i,k;
	int flag=0;
	for(k=0;k<n-1;k++)
	{
	
	for(i=0;i<=n-2;i++) //  can be written as <n-1 or <=n-2
	{
		if(A[i]>=A[i+1])
		{
			int temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
			flag++;
		}
	}
	//Improvement factor
	if(flag==0) 
	{
		break;
	}
	else
	{
		flag=0;
		disp(A,n);
	}
	
}
}



int main()
{
	int n;
	printf("Enter the side of array ");
	scanf("%d",&n);
	
	//Taking array input
	int A[n];
	int i;
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		A[i]=x;
	}
	bubble_sort(A,n);
	
	
	//Printint the output
	printf("\n Sorted array is given by \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	
	return 0;
}
