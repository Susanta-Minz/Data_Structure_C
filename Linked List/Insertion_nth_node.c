#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *head=NULL,*current;

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


void new_ele(int x,int y)
{
	int count=0,j=1;
	struct node *temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	if(x>count||x<=0)
	{
		printf("postion is out of bounds\n");
		return;
	}
	
	struct node *temp1 = (struct node *)malloc(sizeof(struct node));
	temp1->data =y;
	if(x==1)
	{
		temp1->link=head;
		head=temp1;
		return;
	}
	
	temp=head;
	while(j!=x-1)
	{
		temp=temp->link;
		j++;
		
	}
	temp1->link=temp->link;
	temp->link=temp1;
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
		disp();
	}
	printf("Enter in which position and what is the data you wanna insert \n");
	scanf("%d %d",&pos,&value);
	new_ele(pos,value);
	
	printf("The current linked list is ");
	disp();
	return 0;
}
