#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//making structure of node
struct node{
	int data;
	struct node *next; //Pointer to node
};

//Makin an head pointer

struct node *start=NULL;

// Inserting elements in the beginning of the list
/*
void insert(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(start !=NULL)
	{
		temp->next=start;
		start=temp;
	}
	
}
*/


//Alternative method
void insert(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=start;
	start=temp;
	
}




void disp()
{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int i,n,x;
	printf("Enter how many numbers do you wanna insert into the linked list \n");
	scanf("%d",&n);
	
	//Getting the user input
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
		disp();
	}
	
	return 0;
}
