#include<stdio.h>

void selection_sort(int array[],int size)
{
	int i,j,min;
	for(i=0;i<size;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]<=array[min])
			{
				min=j;
			}
		}
		int temp=array[min];
		array[min]=array[i];
		array[i]=temp;
	}

}


int main()
{
	int n;
	printf("Eneter the no of the array\n");
	scanf("%d",&n);
	
	//Creating the input array
	int A[n];
	int i;
	//Getting the userinput
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		A[i]=x;
	}
	selection_sort(A,n);
	
	//Printing the array after sorting
	for(i=0;i<n;i++)
	{
		printf("%d  ",A[i]);
	}
	return 0;
}
