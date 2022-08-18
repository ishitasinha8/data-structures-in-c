#include <stdio.h>
#include <stdlib.h>

struct node     
{
    int data;
    char data2;
    struct node *link;
};
struct node *head = NULL;

void insertAtEnd(int num)       //Insert a node at the end of list.
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    new->data = num;
    new->link = NULL;
    if(head==NULL)      //If there are no pre-existing nodes, the new node itself will be head
    {
        head = new;
    }
    else                //If there are pre-existing nodes
    {
        temp = head;
        while( (temp->link) != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    printf("%d has been inserted.\n",num);
}
void display()          //Display the linked list
{
    struct node *temp = head;
    printf("The linked list is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void sort()
{
    struct node *temp = NULL, *prev = head, *next = NULL;
    while(next->link!=NULL)
    {
        if(head)
    }
}