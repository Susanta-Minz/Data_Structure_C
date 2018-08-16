#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max_size 30
char stack[max_size];

//Declaration for the top
int top=-1;

//Making fuction for pair
int ArePair(char opening,char closing){
	if(opening=='{' && closing=='}')
	{
		return 1;
	}
	else if(opening=='(' && closing==')')
	{
		return 1;
	}
	else if(opening=='[' && closing==']')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//Making pop function
void pop()
{
	if(top==-1)
	{
		printf("Stack is already empty\n");
		return;
	}
	top--;
}

//Making push function
void push(char c)
{
	if(top==max_size-1){
		printf("Stack is full\n");
		return;
	}
	
	if(c=='{' || c== '[' || c=='(')
	{
	stack[++top]=c;
	}
	else if(c== '}'|| c== ']' || c==')')
	{
		
		if(ArePair(stack[top],c)==1)
		{
			pop();
		}
	}
}



//Making Top function
char Top()
{
	return stack[top];
}

int main()
{
	int i;
	char data[max_size];
	printf("Enter the parantheses\n");
	gets(data);
	printf("Input paranthese string is\n");
	puts(data);
	
	//Push data into the stack
	for(i=0;i<strlen(data);i++)
	{
		push(data[i]);
	}
	//Call for checking parathese fucntion
	if(top==-1)
	{
		printf("The parantheses is balanced\n");
	}
	else
	{
		printf("The parantheses is not balanced\n");
	}
	return 0;
}
