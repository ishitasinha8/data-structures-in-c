/*
Write a menu-driven program with following operations to implement stack using array. Consider each element in the stack to be a character.

    Push
    Pop
    Peek
    Display
    Check whether the given input sequence of brackets () {} and [] is balanced or not (matching or not)

Implement functions from (1). to (5) in a header file stack.h. Write a main function main.c to write a menu-driven program to demonstrate working of all functions specified.
*/
#include<stdio.h>
#include"stack.h"
#define MAX 20

/*
	Input: two brackets b1(opening bracket) and b2(closing bracket)
	Return 1 if they match
	Else return 0
*/
int check_match(char b1,char b2)
{
	if(b1 == '(' && b2 == ')')
		return 1;
	else if(b1 == '{' && b2 == '}')
		return 1;
	else if(b1 == '[' && b2 == ']')
		return 1;
	else
		return 0;
}

int main()
{
	//INPUT
	char input[MAX];
	printf("Enter your sequence of brackets -restricting to {} [] and {} without any space\n");
	scanf("%s",input);
	printf("Input Sequence is: %s\n",input);
	
	//STACK INITIALIZATION
	char stack[MAX]; //char array which represents my stack
	stack_init(MAX);//function call
	
	//Scan through all character in input array until \0 (null char) is encountered
	int i = 0,ans; 
	int flag = 0; //Balanced (flag = 1) Unbalanced (flag = 0)
	char popped_bracket;
	while(input[i] != '\0')
	{
		//printf("scanned element is: %c\n",input[i]);
		//Check if scanned element is an opening bracket
		if(input[i] == '(' || input[i] == '{' || input[i] == '[')
		{
			//Push 
			Push(stack,input[i]);
		}
		else
		{
			//Closing bracket
			//1. Pop the element and store it in a variable popped_bracket
			//2. Check if popped_element and the current scanned element match
			//3. If it does match, continue
			//2. If no match, Display unbalanced and exit from your program
			popped_bracket = Pop(stack); //ITS always opening bracket
			//Check if popped_bracket and input[i] is matching
			ans = check_match(popped_bracket,input[i]);
			if(ans==0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		i++;
	}
	if(flag==0)
		printf("Unbalanced\n");
	else
		printf("Balanced\n");
	return 0;
}
