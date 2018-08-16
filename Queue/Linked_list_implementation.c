#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Making structure for the linked list
struct node {
	int data;
	struct node *link;
};

struct node *front=NULL,*rear=NULL;

//Making function for IsEmpty
int IsEmpty()
{
	if(front==NULL && rear==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//Making function for the enqueue operation
void enq(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Cannot allocate memory\n");
		return;
	}
	temp->data=x;
	if(IsEmpty()==1)
	{
		front=rear=temp;
	}
	rear->link=temp;
	temp->link=NULL;
	rear=temp;
}

//making fuction for dequeue operation
void deq()
{
	struct node *temp=front;
	if(IsEmpty()==1)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front==rear)
	{
		front=NULL;
		rear=NULL;
		return;
	}
	front=front->link;
	free(temp);
}
void disp()
{
	struct node *temp=front;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int peek()
{
	if (front==NULL)
	{
		return 0;
		}	
		else
		{
			return front->data;
		}
}
int main()
{
	int i;
	do{
		printf("Choose a option\n");
		printf("1>Enqueue\n2>Dequeue\n3>Peek\n4>exit\n");
		scanf("%d",&i);
		if(i==1)
		{
			int x;
			printf("Please insert enqueue data\n");
			scanf("%d",&x);
			enq(x);
		}
		else if(i==2)
		{
			deq();
		}
		else if(i==3)
		{
			printf("%d\n",peek());
		}
		disp();
	}while(i!=4);
	return 0;
}
