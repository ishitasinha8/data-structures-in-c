/*
Author: Ishita Sinha
Date: 10/12/21
Description: To store student's name as information in BST with functions to insert a student, search for student and display names in sorted order
*/

/*
1. Name, Registration Number
*****************************
Name: Ishita Sinha
Registration Number: 202000506

2. Question Number and Description
***********************************
Question Number: 1
Description: Write a program to store student's name as information in a binary search tree. Implement the following functions:
    a) Inserting student's name in BST
    b) Searching for a student by his/her name
    c) Display names in sorted order
    
3. Algorithm
*************
    a) Inserting student's name in BST
    ***********************************
Step 1: Start
Step 2: Make a function: struct node* insert(struct node *root, char name[])
Step 3: Check if(root==NULL)
            If yes, go to step 4
            Else, go to step 5
Step 4: Dynamically allocate memory to 'root' 
        Assign 'name' to 'root->data'
        Make 'left' and 'right' of 'root' as NULL
        Go to step 9
Step 5: Make pointer to structure: *new, *temp, *prev. 
        Declare character variable: side
        Dynamically allocate memory to 'new'
        Assign 'name' to 'new->data'
        Make 'left' and 'right' of 'new' as NULL
        Go to next step
Step 6: Check if(temp!=NULL)
            If yes, go to next step
            Else, go to step 8
Step 7: Assign prev = temp
            Now, check if(strcmp(name,temp->data)<=0)
                If yes, assign: temp = temp->left. Make side = 'L'
                Else, assign: temp = temp->right. Make side = 'R'
            Go to step 6
Step 8: Check if(side=='L')
            If yes, assign: prev->left = new
            Else, assign: prev->right = new
Step 9: Return root
Step 10: Stop

    b) Searching for a student by his/her name
    ******************************************
Step 1: Start 
Step 2: Make a function: struct node* search(struct node *root, char name[])
Step 3: Check if((root==NULL) || (strcmp(root->data,name)==0))
            If yes, return root. Go to step
            Otherwise, follow through
Step 4: Check if(strcmp(root->data,name)>0)
            If yes, return search(root->left, name)
            Else, return search(root->right, name)

    c) Display names in sorted order
    *********************************
Step 1: Start
Step 2: Make a function: void displaySort(struct node *root)
Step 3: Check if(root!=NULL)
            If yes, call displaySort(root->left)
                    Then display root->data
                    call displaySort(root->right)
Step 4: Stop
*/

//4. Source Code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node     //Structure to represent each node of BST with student's name as data of node
{
    char data[20];
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *root, char name[])     //Function to insert a node
{
    if(root==NULL)      //if no nodes exist previously, the node is inserted at root
    {
        root = (struct node *)malloc(sizeof(struct node));
        strcpy(root->data,name);
        root->left = root->right = NULL;
    }
    else                //if nodes exist, check where the new node should be placed and accordingly add it to the tree
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        struct node *temp = root, *prev = NULL;
        char side = '\0';
        strcpy(new->data,name);
        new->left = new->right = NULL;
        
        while(temp!=NULL)   //find the correct position for the new node by comparing its data to existing nodes' data
        {
            prev = temp;
            if(strcmp(name,temp->data)<=0)
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
        if(side=='L')       //if node is to be inserted to left of previous node
        {
            prev->left = new;
        }
        else                //if node is to be inserted to right of previous node
        {
            prev->right = new;
        }
    }
    return root;
}
struct node* search(struct node *root, char name[])     //search for a node in the tree by the name of student (search is case sensitive)
{
    if((root==NULL) || (strcmp(root->data,name)==0))
    {
        return root;
    }
    if(strcmp(root->data,name)>0)       //if the name of the student has lower ascii value than root->data, then go to left subtree of root
    {
        return search(root->left, name);
    }
    else                                //if the name of the student has higher ascii value than root->data, then go to right subtree of root
    {
        return search(root->right, name);
    }
}
void displaySort(struct node *root)     //display the names in sorted order (inorder traversal)
{
    if(root!=NULL)
    {
        displaySort(root->left);
        printf("%s \n",root->data);
        displaySort(root->right);
    }
}
int main()              //Menu-driven main method to call the functions
{
    struct node *root = NULL;
    int choice = 0;
    char name[20] = {'\0'};
    
    do
    {
        printf("\n1. Insert student's name\n");
        printf("2. Search for student's name\n");
        printf("3. Display names in sorted order\n");
        printf("4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:                                         //if a name is to be inserted
                printf("Enter student's first name (Not more than 19 characters): ");
                scanf("%s",name);
                root = insert(root, name);
                break;
            case 2:                                         //if a name is to be searched
                printf("Enter a name to be searched (Case Sensitive): ");
                scanf("%s",name);
                if(search(root, name))
                {
                    printf("Student found.\n");
                }
                else
                {
                    printf("Student not found.\n");
                }
                break;
            case 3:                                         //displaying the names in sorted order
                printf("The names in sorted order: \n");
                displaySort(root);
                printf("\n");
                break;
            case 4:                                         //if user wants to exit
                printf("Exiting..");
                break;
            default:
                printf("Incorrect Choice.\n");
        }
    }while(choice!=4);
}
/*
5. Expected input and output
****************************

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  1
Enter student's first name: Nisha

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  1
Enter student's first name: Ishita

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  1
Enter student's first name: Sheetal

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  3
The names in sorted order:
Ishita
Nisha
Sheetal

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  2
Enter a name to be searched: Sheetal
Student found.

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  2
Enter a name to be searched: Shilpa
Student not found.

1. Insert student's name
2. Search for student's name
3. Display names in sorted order
4. Exit
Enter your choice:  4
*/