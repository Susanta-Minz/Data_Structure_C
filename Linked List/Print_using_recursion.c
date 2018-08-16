#include<stdio.h>
#include<stdlib.h>


//making structure for node
struct node{
	int data;
	struct node *link;
};


struct node *head=NULL,*current;
//makind display using recursion

void disp(struct node *p)
{
	printf("%d-->",p->data);
	p=p->link;
	if(p==NULL)
	{
		return;
	}
	disp(p);
}


//making reverse print
void disp_rev(struct node *p)
{
	

	if(p==NULL)
	{
		return;
	}
	disp_rev(p->link);
	printf("%d-->",p->data);
	
}

void insert(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		head=temp;
		temp->link=NULL;
	}
	else
	{
		current->link=temp;
		temp->link=NULL;
	}
	current=temp;
}


int main()
{
	//Creating a linked list;
	int n,x,i,pos,value;
	printf("Enter the no of items for the linked list \n");
	scanf("%d\n",&n);
	//Getting data from user
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	disp(head);
	printf("\n");
	disp_rev(head);
}
