#include<stdio.h>
#include<stdlib.h>//for exit(0)
#define MAX 5
int rear=-1,front=-1;
int queue[MAX]; //priority queue
int priority[MAX]; //stores the priority of queue elements

void empty_queue()
{
	front = -1;
	rear = -1;
}

int is_empty()
{
	if(front==-1 && rear==-1)
		return 1;
		
	return 0;
}

int is_full()
{
	if(rear == MAX-1)
		return 1;
		
	return 0;
		
}

void enqueue(int n, int p)
{
	//Input: n-> queue element and p->priority of the queue
	int i,j;
	if(is_full())
	{
		printf("QUEUE FULL\n");
	}
	else if(is_empty())
	{
		//inserting element for the first time
		rear++;
		front++;
		queue[rear]=n;
		priority[rear]=p;
	}	
	else
	{
		//atleast one element available in the queue
		//find the appropriate position to insert a new element
		for(i=front;i<=rear;i++)
		{
			if(priority[i]<p)
			{
				break;	
			}	
		}	
		//shift all element (with index>=i) to the right by one position
		for(j=rear;j>=i;j--)
		{
			queue[j+1]=queue[j];
			priority[j+1]=priority[j];
		}
		//insert the new element(n) at position i
		queue[i]=n;
		priority[i]=p;//update its priority
		rear++;//one more element updated in the queue, hence rear is updated
	}
}

void dequeue()
{
	if(is_empty())
	{
		printf("Queue Empty\n");
	}
	else
	{
		int n;
		n = queue[front];
		printf("%d is deleted\n",n);
		front++;
	}
	//whenever front equals rear=>no element in the queue=>hence, empty the queue
	if(front==rear)
		empty_queue();
}



void display()
{
	if(is_empty())
	{
		printf("Queue Empty: Nothing to Display\n");
	}
	else
	{
		int i;
		//Display queue elements
		printf("Queue Elements:\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
		printf("\n");
		//Display the priority of each element
		printf("Priority:\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",priority[i]);
		printf("\n");
	}
}

int main()
{
	int arr[MAX],choice,n,p;
	do
	{
		printf("\n1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Empty Queue\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				printf("Enter the item and its priority: \n");
				scanf("%d%d",&n,&p);
				enqueue(n,p);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4: 
				empty_queue();
				break;
			case 5:
				break;				
			default: 
				printf("Invalid Choice\n");					
		}		
	}while(choice!=5);
	return 0;
}
