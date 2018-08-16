#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

struct node *new_node(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=x;	
	return temp;
}
void insert(int x)
{
	 struct node *temp = new_node(x);
	 if(head==NULL)
	 {
	 	head=temp;
	 }
	 else
	 {
	 	head->prev=temp;
	 	temp->next=head;
	 	head=temp;
	 }
}

void disp()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void reverse()
{
	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main()
{
	int x,i,n;
	printf("Enter the no of items in the linked list");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	disp();
	reverse();
	return 0; 
}
