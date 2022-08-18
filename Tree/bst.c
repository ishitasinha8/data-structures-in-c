/*
    Registration Number: 202000506
    Name: Ishita Sinha
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "bfsInBst.h"
int sum = 0;
struct node *queue[20] = {NULL};
int front = -1, rear = -1;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* insert(struct node *root, int num)     //Insert a node
{
    if(root==NULL)      //If no nodes exist
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = num;
        root->left = root->right = NULL;
    }
    else                //If nodes exist
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        struct node *temp = root, *prev = NULL;
        char side = '\0';
        new->data = num;
        new->left = new->right = NULL;
        
        while(temp!=NULL)
        {
            prev = temp;
            if(num<=temp->data)
            {
                temp = temp->left;
                side = 'L';
            }
            else
            {
                temp = temp->right;
                side = 'R';
            }
        }
        if(side == 'L')     //adding node to left of prev
        {
            prev->left = new;
        }
        else                //adding node to right of prev
        {
            prev->right = new;
        }
    }
    return root;
}
struct node* search(struct node *root, int num)     //recursively search for a node
{
    if(root==NULL || root->data==num)       //if no nodes exist or if the data matches, return root to main
    {
        return root;
    }   
    if(num<root->data)      //if num is smaller than current, go to the left subtree
    {
        return search(root->left,num);
    }
    else                    //if num is bigger than current, go to the right subtree
    {
        return search(root->right,num);
    }
}
struct node* minChild(struct node *parent)      //returning the inorder successor in the right subtree of node to be deleted
{
    struct node *min = parent;

    while((min!=NULL)&&(min->left!=NULL))   //if the node has no children or node has no left subtree then that node is the smallest
    {
        min = min->left;
    }
    return min;
}
struct node* delete(struct node *root, int num)     //delete a node
{
    if(root==NULL)          //if no nodes exist, return to main immediately
    {
        printf("No nodes");
        return root;
    }
    else if(num<root->data)     //if num is smaller than current, go to the left subtree
    {
        root->left = delete(root->left,num);
    }
    else if(num>root->data)     //if num is bigger than current, go to the left subtree
    {
        root->right = delete(root->right,num);
    }
    else        //if num matches the root->data
    {
        struct node *temp = NULL;
        if((root->left==NULL) && (root->right==NULL))       //when the root has no children, delete root
        {
            temp = root;
            free(root);
            return NULL;
        }
        else if((root->left==NULL)||(root->right==NULL))    //when the root has 1 child
        {
            printf("1 children.\n");
            if(root->left==NULL)
            {
                temp = root->right;
                free(root);
            }
            else
            {
                temp = root->left;
                free(root);
            }
            return temp;
        }
        else            //when the root has 2 children
        {
            printf("2 children.\n");
            temp = minChild(root->right);   //get smallest data in right of root
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
void inorder(struct node *root)     //inorder traversal: left - root - right
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)    //preorder traversal: root - left - right
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)   //postorder traversal: left - right - root
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void sumLeafNodes(struct node *root)
{
    if(!root)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        sum = sum + root->data;
    }
    sumLeafNodes(root->left);
    sumLeafNodes(root->right);
}
void sumInternalNodes(struct node *root)
{
    if(!root)
    {
        return;
    }
    if(root->left!=NULL || root->right!=NULL)
    {
        sum = sum + root->data;
    }
    sumInternalNodes(root->left);
    sumInternalNodes(root->right);
}
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
void levelWisePrint(struct node *root)
{
    int num = 0;
    struct node *tempNode = root;
    if(tempNode==NULL)
    {
        return;
    }
    else
    {
        enqueue(tempNode);
        while(front<=rear)
        {
            num = rear-front+1;
            while(num>0)
            {
                tempNode = dequeue();
                printf("%d ",tempNode->data);
                if(tempNode->left!=NULL)
                {
                    enqueue(tempNode->left);
                }
                if(tempNode->right!=NULL)
                {
                    enqueue(tempNode->right);
                }
                num--;
            }
            printf("\n");
        }
    }
    
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
    struct node *tempNode = root;
    if(tempNode==NULL)
    {
        return;
    }
    else
    {
        while(tempNode!=NULL)
        {
            
            printf("%d ",tempNode->data);
            if(tempNode->left!=NULL)
            {
                enqueue(tempNode->left);
            }
            if(tempNode->right!=NULL)
            {
                enqueue(tempNode->right);
            }
            tempNode = dequeue();
        }
    }
    
}


struct node* fooBST(struct node *root)  //from quiz ii paper
{
            if(root->right == NULL)
                       return root;
            return fooBST(root->right);
}
int main()      //menu-driven main() method
{
    int value = 0, ch = 0;
    int h;
    struct node *root = NULL;
    do
    {
        printf("\n1. Insertion of node\n");
        printf("2. Searching of node\n");
        printf("3. Deletion of node\n");
        printf("4. Inorder traversal\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("7. Level Wise Print\n");
        printf("8. Sum\n");
        printf("9. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                printf("Value: ");
                scanf("%d",&value);
                root = insert(root, value);
                printf("%d has been inserted.\n",value);
                break;
            case 2: 
                printf("\nEnter a value to be searched = ");
                scanf("%d",&value);
                if(search(root, value))
                {
                    printf("Element found.\n");
                }
                else
                {
                    printf("Element not found.\n");
                }
                break;
            case 3:
                printf("\nEnter a value to be deleted = ");
                scanf("%d",&value);
                if(search(root, value))
                {
                    root = delete(root,value);
                    printf("%d has been deleted.\n",value);
                    printf("Inorder traversal = ");
                    inorder(root);
                }
                else
                {
                    printf("Element not found.\n");
                }
                break;
            case 4: 
                printf("Inorder traversal = ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal = ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal = ");
                postorder(root);
                printf("\n");
            case 7:
                levelWisePrint(root);

                levelPrint(root);
                
                break;
            case 8:
                sumLeafNodes(root);
                printf("Sum of leaf nodes = %d\n",sum);
                sum = 0;

                sumInternalNodes(root);
                printf("Sum of internal nodes = %d\n",sum);
                sum = 0;

                break;
            case 9:
                break;
            default:
                printf("Incorrect choice.\n");
        }
    }while(ch!=9);
}