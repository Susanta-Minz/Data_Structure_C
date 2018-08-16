














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
	merge_sort(A,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	return 0;
}
