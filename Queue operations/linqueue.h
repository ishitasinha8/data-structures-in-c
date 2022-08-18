/*
    Registration Number: 202000506
    Name: Ishita Sinha

Write algorithm for these three functions:

Algorithms:
***********
    
Enqueue:
********
Step 1: Start
Step 2: Make function: void linEnqueue(int num)
Step 3: Check if (rear==size-1)
            If yes, then print "Queue is full" and go to step 6
            Else, go to next step
Step 4: Check if (rear==-1).
            If yes, then assign 0 to front and rear. Now assign "num" to linQ[rear]. Go to step 6
            Else, go to next step
Step 5: Increment rear by 1. Assign "num" to linQ[rear]
Step 6: Stop

Dequeue:
********
Step 1: Start
Step 2: Make function: void linDequeue()
Step 3: Declare an integer variable "num"
Step 4: Check if(front==-1)
            If yes, print "Queue is empty". Go to step 7
            Else, follow through
Step 5: Check if (front>rear). 
            If yes, then display front is greater than rear. Go to step 7
            Else, follow through
Step 6: Assign linQ[front] to "num". Increment front by 1 and display that num is deleted.
Step 7: Stop
   
Display:
********
Step 1: Start
Step 2: Make a function: void linQueueDisplay()
Step 3: Declare an integer loop counter variable "i"
Step 4: Check if(front==-1). 
            If yes, print "Queue is empty" and go to Step 7. 
            Else, follow through
Step 5: Check if (front>rear). 
            If yes, then display front is greater than rear. Go to step 7
            Else, follow through
Step 6: Take loop counter "i" from front to rear and print linQ[i].
Step 7: Stop

Implement functions related to Linear Queue here: Enqueue, Dequeue and Display
*/

#include <stdio.h>

extern int front;
extern int rear;
extern int size;
extern int linQ[];

void linQueueInit()
{
    front = rear = -1;
}
void linEnqueue(int num)
{
    if(rear==size-1)
    {
        printf("Queue is full. Initialise Queue to continue.\n");
    }
    else if(rear==-1)
    {
        front = rear = 0;
        linQ[rear] = num;
        printf("%d has been entered.\n", num);
    }
    else
    {
        rear++;
        linQ[rear] = num;
        printf("%d has been entered.\n", num);
    }
}
void linDequeue()
{
    int num = 0;
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    else if(front>rear)
    {
        printf("Front is greater than rear. Initialise queue to continue.\n");
    }
    else
    {
        num = linQ[front];
        front++;
        printf("%d has been removed.\n",num);
    }
}
void linQueueDisplay()
{
    int i=0;
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    else if(front>rear)
    {
        printf("No elements as front is greater than rear. Initialise queue to continue.\n");
    }
    else
    {
        for(i=front; i<=rear; i++)
        {
            printf("%d\t",linQ[i]);
        }
    }
    printf("\n");
}