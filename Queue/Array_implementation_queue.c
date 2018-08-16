#include<stdio.h>
#include<conio.h>
#define queue_size 10

//Delcalring the queue
int Q[queue_size];

//Defining the front and rear of the queue
int front=-1,rear=-1;

//Making IsEmpty function
int IsEmpty()
{
	if(front==-1&&rear==-1)
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
	if((rear+1)%queue_size==front)
	{
		printf("Queue is full\n");
		return;
	}
	else if (IsEmpty()==1)
	{
		front=rear=0;
	}
	else
	{
		rear=(rear+1)%queue_size;
	}
	Q[rear]=x;
}

//Making function for the dequeue operation
void deq()
{
	if (IsEmpty()==1)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=(front+1)%queue_size;
	}
}

//Making the peek fucntion
int peek()
{
	return Q[front];
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
	}while(i!=4);
	return 0;
}
