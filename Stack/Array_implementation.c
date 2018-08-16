#include<stdio.h>
#define maxsize 101

//Making stack
int stack[maxsize];

//Declaring the top counter
int top =-1;
//making push function
void push(int x)
{
	if(top==maxsize-1)
	{
		printf("Stack is overflowed\n");
		return;
	}
	stack[++top] =x;                         // Can be written as top++ then A[top]=x; but here i am using
}										// But here i am using preincrement operator, hence increment will occure before assignment

//Making pop function
void pop()
{
	if(top==-1)
	{
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

//Making top function
int Top()
{
	return stack[top];
}

//Making the display function
void disp()
{
	int i;
	printf("The elements in the stack are\n");
	for(i=0;i<=top;i++)
	{
		printf("%d\n",stack[i]);
	}
}
int main()
{
	push(2);
	push(100);
	push(200);
	pop();
	push(1000);
	push(123);
	disp();
	return 0;
}
