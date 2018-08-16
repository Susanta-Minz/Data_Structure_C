 #include<stdio.h>
 #include<stdlib.h>
 
 //Making structure for node
 struct node{
 	int data;
 	struct node *link;
 };
 
 
 struct node *head=NULL,*current;
 
 void insert(int x)
 {
 	struct node *temp = (struct node *)malloc(sizeof(struct node));
 	if(temp==NULL)
 	{
 		return;
	}
 	temp->data=x;
 	temp->link=NULL;
 	if(head==NULL)
 	{
 		head=temp;
 		current=temp;
	}
	else
	{
		current->link=temp;
		current=temp;
	}
 }
 
 void disp(struct node *p)
 {
 	if(p==NULL)
 	{
 		printf("\n");
 		return;
	}
	printf("%d-->",p->data);
	p=p->link;
	disp(p);
 }
 
void reverse_recur(struct node *p)
{
	if(p->link==NULL)
	{
		head=p; 
		return;
	}
	reverse_recur(p->link);
	struct node *q = p->link;
	q->link=p;
	p->link=NULL;
	
}
 
 int main()
 {
 	int x,n,i;
 	printf("Enter the no of elements in the linked list ");
 	scanf("%d",&n);
 	
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&x);
 		insert(x);
	}
	disp(head);
	reverse_recur(head);
	disp(head);
 	return 0;
 }
