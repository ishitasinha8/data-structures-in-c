/*
    Registration Number: 202000506
    Name: Ishita Sinha
    Algorithm for "Push"
    ********************
Step 1: Start
Step 2: Make a function to push an element as follows: 
        void push(char stack[], int *top, char character)
        The parameter stack[] holds the stack passed from main, *top holds the topmost element and character holds the character to be entered
Step 3: Check if (*top)==(MAX-1). If yes, print stack overflow. Else, go to step 3
Step 4: Increment *top by 1
Step 5: Store character in stack[*top]
Step 6: Stop

    Algorithm for "Pop"
    *******************
Step 1: Start
Step 2: Make a function to pop an element as follows: 
        char pop(char stack[], int *top)
Step 3: Declare and initialise character variable of char type
Step 4: Check if ((*top)==-1). If yes, print stack underflow. Else, go to step 5
Step 5: Store stack[*top] in character
Step 6: Now, decrement *top by 1.
Step 7: Return character to main
Step 8: Stop

    Algorithm for "Peek"
    ********************
Step 1: Start
Step 2: Make a function to pop an element as follows: 
        void peek(char stack[], int *top)
Step 3: Check if ((*top)==-1). If yes, print no elements found. Else, go to step 4
Step 4: Print the element at top of the stack - stack[*top]
Step 5: Stop

    Algorithm for "Display"
    ***********************
Step 1: Start
Step 2: Make a function to pop an element as follows: 
        void display(char stack[], int *top)
Step 3: Declare and initialise loop counter variable i to 0
Step 4:  Check if ((*top)==-1). If yes, print no elements found. Else, go to step 5
Step 5: i = *top
Step 6: Check if i>=0. If yes, go to next step. Else go to step 8
Step 7: Print stack[i]. Decrement i by 1. Go to step 6.
Step 8: Stop

    Algorithm for "balanced paranthesis checking"
    *********************************************
Step 1: Start
Step 2: Make a function to pop an element as follows: 
        void bracketMatch(char stack[])
Step 3: Make the following declarations:
        a character array inputBrackString with size MAX
        integer variables - loop counter i, top=-1, flag variable = -1, strLength=0
        character variables character and poppedCharacter
Step 4: Take the sequence of brackets using %s into inputBrackString
Step 5: Remove the buffer stream containing \n using while((getchar())!='\n')
Step 6: Take the string length of inputBrackString and store it in strLength
Step 7: Check if i<strLength. If yes, go to next step. Else go to step 
Step 8: Do the following assignment: character = inputBrackString[i]
Step 9: Check if (character=='{'||character=='('||character=='['). If yes, then call push function as follows:
         push(stack,&top,character)
         Otherwise go to next step
Step 10: Check if (character=='}'||character==')'||character==']'). If yes, then call pop function and store its return value in poppedCharacter as follows:
         poppedCharacter = pop(stack,&top)
Step 11: Check if (poppedCharacter =='{'&& character=='}')||(poppedCharacter=='('&&character==')')||(poppedCharacter=='['&&character==']').
         If yes, then flag=0. Else, break from the loop
Step 12: Make an else for the if. Print incorrect input and ask user to enter brackets only
Step 13: Check if flag==0. If yes, then print "Bracket sequence matched". Else print "Did not match"
*/
#include <string.h>
#include <stdio.h>
#define MAX 10
void push(char stack[], int *top, char character)
{
    if((*top)==(MAX-1))
    {
        printf("Stack Overflow Error. POP an element to continue\n");
    }
    else
    {
        (*top)++;
        stack[*top] = character;
    }
}
char pop(char stack[], int *top)
{
    char character = 0;
    if((*top)==-1)
    {
        printf("Stack Underflow Error. PUSH an element to continue\n");
    }
    else
    {
        character = stack[*top];
        (*top)--;
    }
    return character;
}
void peek(char stack[], int *top)
{
    if((*top)==-1)
    {
        printf("No elements found.\n");
    }
    else
    {
        printf("The element at top of the stack is: %c\n",stack[*top]);
    }
}
void display(char stack[], int *top)
{
    int i = 0;
    if((*top)==-1)
    {
        printf("No elements found.\n");
    }
    else
    {
        printf("Elements in the stack are:\n");
        for(i=(*top); i>=0; i--)
        {
            printf("%c\n",stack[i]);
        }
    }
}
void bracketMatch(char stack[])
{   
    char inputBrackString[MAX];
    int i=0, top=-1, flag=1, strLength=0;
    char character = ' ', poppedCharacter=' ';

    printf("Enter a sequence of brackets: ");
    scanf("%s",inputBrackString);
    while((getchar())!='\n');
    strLength = strlen(inputBrackString);
    
    for(i = 0 ; i < strLength ; i++)
    {
        character = inputBrackString[i];
        if(character=='{'||character=='('||character=='[')
        {
            push(stack,&top,character);
        }
        else if(character=='}'||character==')'||character==']')
        {
            poppedCharacter = pop(stack,&top);
            if((poppedCharacter =='{'&& character=='}')||(poppedCharacter=='('&&character==')')||(poppedCharacter=='['&&character==']'))
            {
                flag=0;
            }
            else
            {
            	flag =1;
                break;
            }
        }
        else
        {
            printf("Incorrect Input. Enter Brackets only.\n");
        }
    }
    if(flag==0)
    {
        printf("Bracket sequence matched.\n");
    }
    else
    {
        printf("Bracket sequence did not match.\n");
    }
}
