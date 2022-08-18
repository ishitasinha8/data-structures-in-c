/*
    Registration Number: 202000506
    Name: Ishita Sinha
Write algorithm for these three functions

Algorithms:
***********
    
Enqueue:
********
Step 1: Start
Step 2: Make function: void cirEnqueue(int num)
Step 3: Check if ((rear+1)%size==front). 
            If yes, then print "Queue is full" and go to step 6
            Else, go to next step
Step 4: Check if (front==-1).
            If yes, then assign 0 to front and rear 
            Else, rear = (rear+1)%size
Step 5: Assign num to cirQ[rear]
Step 6: Stop

Dequeue:
********
Step 1: Start
Step 2: Make function: void cirDequeue()
Step 3: Declare an integer variable "num"
Step 4: Check if(front==-1)
            If yes, print "Queue is empty". Go to step 7
            Else, go to step 5
Step 5: Assign num = cirQ[front] and display that num is removed.
Step 6: Check if front==rear. 
            If yes, assign front = rear = -1
            Else, assign front = (front+1)%size
Step 7: Stop

Display:
********
Step 1: Start
Step 2: Make a function: void cirQueueDisplay()
Step 3: Declare an integer loop counter variable "i"
Step 4: Check if(front==-1). If yes, print "Queue is empty" and go to Step 7. Otherwise follow through
Step 5: Check if (front<=rear). 
            If yes, then take the loop counter variable "i" from front to rear and print cirQ[i] each time. Then go to step 7
            Else, go to step 6
Step 6: Take loop counter "i" from front to size and print cirQ[i].
        Now, take loop counter variable "i" from 0 to rear and print cirQ[i].
Step 7: Stop

Implement functions related to Circular Queue here: Enqueue, Dequeue and Display
*/
#include <stdio.h>

extern int front;
extern int rear;
extern int size;
extern int cirQ[];

void cirQueueInit()
{
    rear = front = -1;
}
void cirEnqueue(int num)
{
    if((rear+1)%size==front)
    {
        printf("Queue is full.\n");
    }
    else 
    {
        if(front==-1)
            front = rear = 0;
        else
            rear = (rear+1)%size;
        cirQ[rear]=num;
        printf("%d has been entered.\n", num);
    }
}
void cirDequeue()
{
    int num = 0;
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    else 
    {
        num = cirQ[front];
        printf("%d has been removed.\n",num);
        if(front==rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%size;
        }
    }
}
void cirQueueDisplay()
{
    int i = 0;
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    else if(front<=rear)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",cirQ[i]);
        }
        printf("\n");
    }
    else
    {
        for(i=front;i<size;i++)
        {
            printf("%d\t",cirQ[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\t",cirQ[i]);
        }
        printf("\n");
    }
}