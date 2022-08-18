#include <stdio.h>
#include <stdlib.h>


struct node     //Make nodes of linked list
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head = NULL;
struct node *tail = NULL;
void insertAtBegin(int num)     //Insert at beginning
{
    struct node *new = (struct node *)malloc(sizeof(struct node)); 
    struct node *temp;
    new->data = num;
    if(head==NULL)
    {
        tail = head = new;
        new->left = new->right = NULL;
    }
    else
    {
        new->left = tail;
        new->right = head;
        tail->right = head->left = new;
        head = new;
    }
    printf("%d has been inserted.\n",num);
}
void insertAtEnd(int num)   //Insert at end
{
    struct node *new = (struct node *)malloc(sizeof(struct node)); 
    struct node *temp;
    new->data = num;
    if(head==NULL)
    {
        tail = head = new;
        new->left = new->right = NULL;
    }
    else
    {
        new->left = tail;
        new->right = head;
        tail->right = head->left = new;
        tail = new;
    }
    printf("%d has been inserted.\n",num);
}
void insertAtPos(int num, int pos)      //Insert at position
{
    struct node *new = (struct node *)malloc(sizeof(struct node)); 
    int i = 0;
    struct node *temp = head, *tempNext = NULL;
    new->data = num;
    if(pos<=0)      //If position is less than 0.
    {
        printf("This position does not exist.\n");
    }
    else            
    {
        if(head==NULL)      //If no elements exist and this is first node
        {
            tail = head = new;
            new->left = NULL;
            new->right = NULL;
            printf("%d has been inserted.\n",num);
        }
        else if(pos==1)     //If node has to be inserted at beginning
        {
            insertAtBegin(num);
        }
        else                //If node has to be inserted at any other position
        {
            for(i=2; i<pos; i++)
            {
                temp = temp->right;
            }
            tempNext = temp->right;
            
            new->right = tempNext;
            new->left = temp;
            temp->right = tempNext->left = new;
            printf("%d has been inserted.\n",num);
        }
    }
}
void deleteFromBegin()          //delete from beginning
{
    int num;
    struct node *temp;
    if(head==NULL)      //If list is empty
    {
        printf("List is empty.\n");
    }
    else                //If list is not empty
    {
        num = head->data;
        temp = head->right;
        free(head); 
        if(temp==NULL)  //If this is the only node in the list
        {
            head = tail = NULL;
            printf("%d has been deleted.\n",num);
            return;
        }
        else if(temp==tail)     //If there are only two nodes in the list
        {
            tail->left = tail->right = NULL;
            head = tail;
            printf("%d has been deleted.\n",num);
        }
        else            //If there are more than 2 nodes in the list
        {
            tail->right = temp;
            temp->left = tail;
            head = temp;
            printf("%d has been deleted.\n",num);
        }
    }
}
void deleteFromEnd()            //delete from end
{
    int num;
    struct node *temp;  
    if(tail==NULL)      //if list is empty
    {   
        printf("List is empty.\n");
    }
    else                //if list is not empty
    {
        num = tail->data;
        temp = tail->left;
        free(tail);
        if(temp==NULL)      //if there is only 1 node
        {
            head = tail = NULL;
            return;
        }
        else if(temp==head)     //if there are only 2 nodes
        {
            head->left = head->right = NULL;
            tail = head;
            printf("%d has been deleted.\n",num);
        }
        else            //if there are more than 2 nodes
        {
            temp->right = head;
            head->left = temp;
            tail = temp;
            printf("%d has been deleted.\n",num);
        }
    }
}
void deleteFromPos(int pos)     //delete from any position
{
    int i = 0, num = 0;
    struct node *temp = head, *prev = NULL, *next = NULL;
    if(pos<=0)          
    {
        printf("This position does not exist.\n");
    }
    else if(head==NULL)     //if list is empty
    {
        printf("List is empty.\n");
    }
    else
    {
        if(pos==1)      //if position to be deleted is from beginning
        {
            deleteFromBegin();
        }
        else            //if position is any other position
        {
            for(i=1;i<pos;i++)
            {
                temp = temp->right;
            }
            prev = temp->left;
            next = temp->right;
            prev->right = next;
            next->left = prev;
            num = temp->data;
            temp = NULL;
            free(temp);
            printf("%d has been deleted.\n",num);
        }
    }
}
void display()      //display list
{
    struct node *temp = head;
    printf("The list is: ");
    if(temp==NULL)      //if list is empty
    {
        printf("Empty");
    }
    else if(temp==tail)     //if there is just 1 node
    {
        printf("%d ",temp->data);
    }
    else        //if there are more than 1 nodes
    {
        while((temp->right)!=head)
        {
            printf("%d ",temp->data);
            temp = temp->right;
        }
        printf("%d ",temp->data);
    }
    printf("\n");
}
int main()      //menu-driven main() method
{
    int ch = 0, num = 0, pos = 0;
    
    do
    {
        printf("\n1. Insert At Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Position\n");
        printf("4. Delete From Beginning\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Position\n");
        printf("7. Display\n");
        printf("8. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number: ");
                scanf("%d",&num);
                insertAtBegin(num);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d",&num);
                insertAtEnd(num);
                break;
            case 3:
                printf("Enter the number and position: ");
                scanf("%d %d",&num, &pos);
                insertAtPos(num,pos);
                break;
            case 4:
                deleteFromBegin();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d",&pos);
                deleteFromPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                break;
            default:
                printf("Incorrect choice.\n");
        }
    }while(ch!=8);
    return 0;
}