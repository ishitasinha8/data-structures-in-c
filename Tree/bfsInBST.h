#include <stdio.h>
struct node *queue[10] = {NULL};
int front = -1, rear = -1;
void enqueue(struct node *new)       //insert element into queue[]
{
    if(rear==-1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = new;
}
struct node* dequeue()               //delete element from queue[]
{
    struct node *num = NULL;
    num = queue[front];
    //printf("%d ",queue[front]);
    front++;
    return num;
}
void levelPrint(struct node *root)
{
    /*printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root : start from root
3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children 
      (first left then right children) to q
    c) Dequeue a node from q.*/
    int num = 0;
    struct node *tempNode = root, *prevNode = NULL;
    if(tempNode==NULL)
    {
        return;
    }
    else
    {
        while(tempNode!=NULL)
        {
            
            //prevNode = tempNode;
            //printf("%d",tempNode->data);
            if(tempNode->left!=NULL)
            {
                //tempNode = tempNode->left;
                enqueue(tempNode->left);
            }
            else if(tempNode->right!=NULL)
            {
                //tempNode = tempNode->right;
                enqueue(tempNode->right);
            }
            tempNode = dequeue();
            printf("%d",tempNode->data);
        }
    }
    
}
