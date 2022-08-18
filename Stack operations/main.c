#include <stdio.h>
#include "stack.h"
#define MAX 10


int main()
{
    char stack[MAX];
    int top = -1;
    char num = ' ';
    int choice = 1, i=0;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check whether sequence of brackets match or not\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        //fflush(stdin);
        while((getchar())!='\n');
        switch(choice)
        {
            case 1:
                printf("Enter character in the stack: ");
                scanf("%c",&num);
                while((getchar())!='\n');
                push(stack, &top, num);
                break;
            case 2:
                num = pop(stack, &top);
                printf("%c is removed\n",num);
                break;
            case 3:
                peek(stack, &top);
                break;
            case 4:
                display(stack, &top);
                break;
            case 5:
                printf("To Check bracket sequence existing elements of the stack will be deleted.\n");
                bracketMatch(stack);
                top=-1;
                printf("All brackets deleted.\n");
                break;
            case 6:
                return 0;
            default:
                printf("Incorrect Choice.\n");
        }
    }while(choice >= 1 && choice <= 6);
    return 0;
}
/*
Sample input and output:
************************
1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 1
Enter character in the stack: a

1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 1
Enter character in the stack: b

1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 3
The element at the top of the stack is: b

1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 4
Elements in the stack are:
b
a

1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 5
To Check bracket sequence existing elements of the stack will be deleted.
Enter a sequence of brackets: ({})
Bracket sequence matched.
All brackets deleted

1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 5
To Check bracket sequence existing elements of the stack will be deleted.
Enter a sequence of brackets: ({])
Bracket sequence did not match.
All brackets deleted

1. Push
2. Pop
3. Peek
4. Display
5. Check whether sequence of brackets match or not
6. Exit
Enter your choice: 6
*/