#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Structre of node
struct node{
	int data;
	struct node *link;
};

struct node *head=NULL,*current;

void del(int x)
{
	int count=0,j=1;
	struct node *temp,*temp1;
	temp=head;
	
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	
	if(x>count || x<=0)
	{
		printf("Index is out of bound");
		return;
	}
	
	
	//While deleting position is inbounds then proceed for the deletation
	if(x==1)
	{
		struct node *temp=head,*temp1;
		temp1=temp->link;
		head=temp1;
		free(temp);
		return;
	}
	
	temp=head;
	for(j=1;j<x-1;j++)
	{
		temp=temp->link;
		temp1=temp->link;
	}
	temp->link=temp1->link;
	free(temp1);
}

void disp()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->link;
	}
	printf("\n");
}


void insert(int x)
{
	struct node *temp= (struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Overflow\n");
		return;
	}
	temp->data=x;
	if(head==NULL)
	{
		head=temp;
		temp->link=NULL;
		current=temp;
	}
	else
	{
		current->link=temp;
		temp->link=NULL;
		current=temp;
	}
}

int main()
{
	int n,x,i,pos;
	printf("Enter the no of items you wanna insert");
	scanf("%d",&n);
	
	//Getting user input
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	
	//Showing all the elements in the linked list
	printf("The current linked list is \n");
	disp();
	
	//Getting postion to delete the node
	printf("Enter the position for deleting the node ");
	scanf("%d",&pos);
	del(pos);
	disp();
	return 0;
}
