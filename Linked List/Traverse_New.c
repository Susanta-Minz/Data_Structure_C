#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//Creating the structure for the node
struct node
{
	int data;
	struct node *link;  //Pointer to node--link contains the address of next node
};

//Creating the starting pointer
struct node *start=NULL;

int main()
{	
	char ch;
	struct node *new_node,*current;
	do
	{
	new_node = (struct node *)malloc(sizeof(struct node)); //malloc returns the void pointer hence we need to type-cast
	printf("\nPlease enter the data ");
	scanf("%d",&new_node->data);
	new_node->link=NULL;
	
	if(start== NULL)
	{
		start=new_node;
		current=new_node;
	}
	else
	{
		current->link=new_node;
		current=new_node;
	}
	
	printf("\nDo you want to create another node? : ");
	ch=getch();
	}while(ch!='n');
	
	//printing all the data in linked list
	while(start!=NULL)
	{
		printf("%d-->",start->data);
		start=start->link;
	}
	getch();
	return 0;
}
