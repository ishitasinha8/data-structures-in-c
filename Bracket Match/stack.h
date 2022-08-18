/*
	Header file to implement Push,Pop and Peek in a character array
*/
int top,size;

void stack_init(int n)
{
	top = -1;
	size = n;
}

//Input: S - character array , item - input character
void Push(char S[],char item)
{
	//Check for overflow
	if(top == size-1)
	{
		printf("Overflow\n");
	}
	else
	{
		//Insert item at the top of the stack
		top++;
		S[top] = item;
	}
}

//Input: S - character array
//Return type - char (popped element)
char Pop(char S[])
{
	char popped_element;
	//Check for underflow condition
	if(top == -1)
	{
		printf("Underflow\n");
	}
	else
	{
		popped_element = S[top];
		top--;
		return popped_element;
	}
}





