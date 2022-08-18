/*
    Registration Number:202000506
    Name:Ishita Sinha
    Main Program to take user input and call functions from header file (convert.h)
*/
#include <stdio.h>
#include "convert.h"

void acceptSparse(int sparse[10][10], int row, int col)
{
    int i=0,j=0;
    printf("Enter %d elements in sparse matrix:\n",row*col);
    for(i=0;i<row;i++)
    {
        printf("Enter %d elements in row %d: ",col,i);
        for(j=0;j<col;j++)
        {
            scanf("%d",&sparse[i][j]);
        }
    }
}
void acceptCompact(int compact[15][3], int nz)
{
    int i=0,j=0;
    printf("Enter rows and columns that will be in the sparse matrix: ");
    scanf("%d %d",&compact[0][0],&compact[0][1]);
    printf("Compact matrix with following header row is created: %d %d %d\n",compact[0][0],compact[0][1], compact[0][2]);
    printf("Enter %d elements in compact matrix in following format- row_index column_index value:\n",(nz)*3);
    for(i=1;i<(nz+1);i++)
    {
        printf("Enter 3 elements in row %d: ",i);
        for(j=0;j<3;j++)
        {
            scanf("%d",&compact[i][j]);
        }
    }
}
void displaySparse(int sparse[10][10], int row, int col)
{
    int i=0,j=0;
    printf("\nThe sparse matrix:\n");
    for(i=0;i<row;i++)
    {	 	  	   	    	      	   	        	 	
        for(j=0;j<col;j++)
        {
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }
}
void displayCompact(int compact[15][3], int nz)
{
    int i=0,j=0;
    printf("\nThe compact matrix:\n");
    for(i=0;i<(nz+1);i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",compact[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int choice=0,switchChoice=0, nz=0;
    int row=0, col=0, i=0,j=0;
    int sparse[10][10]={0};
    int compact[15][3]={0};
    
    do
    {
        printf("1. Sparse Matrix\n2. Compact Matrix\nWhich one would you like to enter?\n");
        scanf("%d",&switchChoice);
        switch(switchChoice)
        {
            case 1:
                printf("Enter row size and column size of Sparse Matrix:\n");
                scanf("%d %d",&row,&col);
                
                acceptSparse(sparse,row,col);
                displaySparse(sparse,row,col);
                nz=sparseToCompact(sparse,compact,row,col);
                displayCompact(compact,nz);
                break;
            case 2:
                //printf("Enter header row of compact matrix:\n");
                //scanf("%d %d %d",&compact[0][0],&compact[0][1],&compact[0][2]);
                //nz=compact[0][2];
                //printf("Header row of compact matrix is successfully created.\n");
                //nz=2;
                printf("Enter number of rows in compact matrix excluding header row: ");
                scanf("%d",&nz);
                compact[0][2]=nz;
                acceptCompact(compact,nz);
                displayCompact(compact,nz);
                row=compact[0][0];
                col=compact[0][1];
                compactToSparse(sparse,compact,nz);
                displaySparse(sparse,row,col);
                
        }	 	  	   	    	      	   	        	 	
        printf("Press 1 to enter again.Press any other key to exit\n");
        scanf("%d",&choice);
    }while (choice==1);
    
    return 0;
}
