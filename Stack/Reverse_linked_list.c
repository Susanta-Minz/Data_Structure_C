#include<stdio.h>
#include<stdlib.h>

//structure of node
struct node{
	int data;
	struct node *link;
};

//Declaring the head pointer
struct node *head=NULL,*current;

//making stack which store the reference of the linked list
struct node *stack[30];

//Declaring the top
int top=-1; //Initializing the empty stack

//making display function
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

//Making insert function for the linked list (inserting from tail)
void insert(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Cannot allocate memeory for the new node\n");
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


//making function for push
void push(struct node *x)
{
	stack[++top]=x;
}

//Making pop function
void pop()
{
	top--;
}

//Making top function
struct node *Top()
{
	return stack[top];
}

//making the reverse function
void reverse(struct node *p)
{
	struct node *start=p,*temp;
	while(start!=NULL)
	{
		push(start->link);
		start=start->link;
	}
	temp=Top();
	head=temp;

}
int main()
{
	int i,n,x;
	printf("Enter the no of elements in the linked list \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	disp();
	reverse(head);
	disp();
	return 0;
}
