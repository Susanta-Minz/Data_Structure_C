#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//making struct of node
struct node{
	int data;
	struct node *link;
};
 struct node *head=NULL;

void insert(int x)
{
	struct node *temp= (struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->link=head;
	head=temp;
	
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

void reverse()
{
	struct node *current,*previous,*next;
	current=head;
	previous=NULL;
	while(current!=NULL)
	{
		next=current->link;
		current->link=previous;
		previous=current;
		current=next;
	}
	head=previous;
}


int main()
{
	int n,x,i;
	printf("Enter the no of items in linked list ");
	scanf("%d",&n);
	
	//Getting the items from user
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	disp();
	reverse();
	disp();
	return 0;
}
