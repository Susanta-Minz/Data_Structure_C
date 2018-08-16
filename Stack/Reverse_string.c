#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maximum_str_len 80

//making charactor stack;
char stack[maximum_str_len];
int top=-1;  //Empty stack

//Making Push function
void push(char c)
{
	stack[++top]=c;
}

//Maing pop function
void pop()
{
	top--;
}

char Top()
{
	return stack[top];
}

//making reverse function
void reverse(char c[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		push(c[i]);
	}
	printf("The pushed characters in stack are:- \n");
	printf("%s\n",stack);
	
	//Now rewriting the string in reverse order;
	for(i=0;i<x;i++)
	{
		c[i]=Top();
		pop();
	}
	printf("The reverse order of the input string is:- \n");
	printf("%s\n",c);
}

int main()
{	
	char s1[maximum_str_len];
	printf("Enter the input string ");
	gets(s1);                               //Can be written as ("%s",&s1);
	printf("The current input string is :- \n");
	puts(s1);  							   // Can be written as printf("%s",s1);
	reverse(s1,strlen(s1));
	return 0;
}
