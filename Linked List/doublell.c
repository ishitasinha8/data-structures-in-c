 
#include <stdio.h>
#include <stdlib.h>

struct node     
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *head = NULL;

void insertAtBeg(int num)       //Insert a node at the beginning of list.
{
    //If there are no pre-existing nodes, new node's link will point to NULL and it will become the head
    //If there are pre-existing nodes, the new node's link will point to head and it will become the head
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->left = NULL;
    new->right = head;
    head = new;
    printf("%d has been inserted.\n",num);
}
void insertAtEnd(int num)       //Insert a node at the end of list.
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    new->data = num;
    new->right = NULL;
    if(head==NULL)      //If there are no pre-existing nodes, the new node itself will be head
    {
        head = new;
        new->left = NULL;
    }
    else                //If there are pre-existing nodes
    {
        temp = head;
        while( (temp->right) != NULL)
        {
            temp = temp->right;
        }
        temp->right = new;
        new->left = temp;
    }
    printf("%d has been inserted.\n",num);
}
void reverse()          //From DS quiz
{   
    struct node *temp = NULL;
    struct node *current = head;

    while(current!=NULL)
    {
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        current = current->left;
    }
    if(temp!=NULL)
    {
        head = temp->left;
    }
}
/*void insertAtPos(int num, int pos)      //Insert at any position
{
    int i = 0;
    
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    
    new->data = num;
    if(pos<=0) 
    {
        printf("This position does not exist.\n");
    }
    else 
    {
        if(pos==1 || head==NULL)        //If user enters 1st position when there are pre-existing nodes or user enters 1 when there are no pre-existing nodes
        {
            new->link = head;
            head = new;
        }
        else                            //If user enters any other position other than the first position
        {
            for(i = 2;i<pos;i++)
            {
                temp = temp->link;
            }
            new->link = temp->link;
            temp->link = new;
        }
        printf("%d has been inserted.\n",num);
    }
}*/
void display()          //Display the linked list
{
    struct node *temp = head;
    printf("The linked list is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->right;
    }
    printf("\n");
}
int main()          //Menu-driven main function to call the other functions
{
    printf("%d",sizeof(struct node));
    int data = 0, ch = 0;
    unsigned int pos = 0;
    do
    {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n4. Display\n5. Reverse\n6. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("Enter a data: ");
                scanf("%d",&data);
                insertAtBeg(data);
                break;
            case 2:
                printf("Enter a data: ");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter a data and the position it should be inserted at: ");
                scanf("%d %u",&data, &pos);
                //insertAtPos(data, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                break;
            case 6:
                break;
            default:
                printf("Enter a number between 1 and 5\n");
        }
    }while(ch!=6);
    
    return 0;
}