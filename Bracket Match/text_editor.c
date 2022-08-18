/*
    Name: Ishita Sinha
    Reg: 202000506
    Algorithm to implement kill character and erase character
    Source Code: Use functions whereever possible
*/
#include <stdio.h>
#include <string.h>
#define MAX 10

int top = -1;

void initialise(char stack[])
{
    top=-1;
}
void push(char stack[], char letter)
{
    if(top==(MAX-1))
    {
        printf("Stack Overflow error. Delete an element to continue.\n");
    }
    else
    {
        //printf("%c has been pushed.\n",letter);
        stack[++top]=letter;
    }
}
char pop(char stack[])
{
    char letter = ' ';
    if(top==-1)
    {
        printf("Stack Underflow error. Enter an element to continue.\n");
    }
    else
    {
        letter = stack[top];
        top--;
        return letter;
    }
}
void display(char stack[])
{
    int i = 0;
    for(i=0;i<=top;i++)
    {
        printf("%c",stack[i]);
    }
}
int eraseOrKill(char string[], char stack[])
{
    int i = 0;
    int strLength = 0;
    char poppedCharacter = ' ';
    int flag=0;
    
    strLength = strlen(string);
    printf("string = %s length = %d \n",string, strLength);
    
    for(i = 0; i<strLength; i++)
    {
        if((string[i]!='#') && (string[i]!='@'))
        {
            push(stack, string[i]);
        }
        else if(string[i]=='#')
        {
            if(top==-1)
            {
                flag=1;
                break;
            }
            else
                poppedCharacter = pop(stack);
        }
        else if(string[i]=='@')
        {
            if(top==-1)
            {
                flag=1;
                break;
            }
            else
                initialise(stack);
        }
    }
    return flag;
}
int main()
{
    char string[MAX];
    char stack[MAX]={'\0'};
    int flag=0;
    
    printf("Enter a string without spaces with # and @ to kill and erase characters respectively: ");
    scanf("%s",string);
    
    flag=eraseOrKill(string, stack);
    if(flag==0)
    {
        printf("The output string is: ");
        display(stack);
    }
    else
        printf("Erroneous String\n");
    return 0;
}