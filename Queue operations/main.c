/*
    Registration Number: 202000506
    Name: Ishita Sinha
    Write menu driven program to access all operations of Linear and Circular Queue
*/
#include <stdio.h>
#include "linqueue.h"
#include "cirqueue.h"
#define MAX 10

int front = -1;
int rear = -1;
int size = 0;
int linQ[MAX];
int cirQ[MAX];

void linQueueOperations()
{
    int ch = 0, num = 0;
    
    linQueueInit();
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Initialise Queue\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                linEnqueue(num);
                break;
            case 2:
                linDequeue();
                break;
            case 3:
                linQueueDisplay();
                break;
            case 4:
                linQueueInit();
                printf("Queue has been initialised.\n");
                break;
            case 5:
                break;
            default:
                printf("Incorrect choice. Enter a number between 1 and 4 only.\n");
        }
    }while(ch!=5);
}
void cirQueueOperations()
{
    int ch = 0, num = 0;
    
    cirQueueInit();
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Initialise Queue\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                cirEnqueue(num);
                break;
            case 2:
                cirDequeue();
                break;
            case 3:
                cirQueueDisplay();
                break;
            case 4:
                cirQueueInit();
                printf("Queue has been initialised.\n");
                break;
            case 5:
                break;
            default:
                printf("Incorrect choice. Enter a number between 1 and 4 only.\n");
        }
    }while(ch!=5);
}
int main()
{
    int linOrCir = 0;
    
    printf("1. Linear Queue\n2. Circular Queue\nEnter your choice: ");
    scanf("%d", &linOrCir);
    
    printf("Enter the array size for queue to be implemented on. (MAX size is 10) : ");
    scanf("%d", &size);
    while(size>10)
    {
        printf("Size should be less than 10. Enter a size again: ");
        scanf("%d", &size);
    }
    switch(linOrCir)
    {
        case 1:
            linQueueOperations();
            break;
        case 2:
            cirQueueOperations();
            break;
        default:
            printf("Incorrect Choice. Exiting\n");
    }
}