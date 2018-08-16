#include<stdio.h>
#include<stdlib.h>

//making structure of node
struct node{
	int data;
	struct node *link;
};

struct node *top=NULL;

//Making push function
void push(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Error:Overflow occured");
		return;
	}
	temp->data=x;
	temp->link=top;
	top=temp;
}

//Making Pop function
void pop()
{
	struct node *temp =top,*temp1;
	temp1=top->link;
	top=temp1;
	free(temp);
}

void disp()
{
	struct node *temp=top;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->link;
	}

}
int main()
{
	push(1);
	push(2);
	push(3);
	pop();
	push(5);
	disp(top);
	return 0;
}
