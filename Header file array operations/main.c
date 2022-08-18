/*
	Registration Number: 202000506
    Name: Ishita Sinha
    Main Program(menu-driven) to take user input and call functions from header file (myheader.h)
*/
/*
Algorithm:
**********
Step 1: Start
Step 2: Declare following variables choice, size,i,switchChoice,pos=0,num,key,keyPos and initialise all to 0. Also delcare array variable arr of size 20
Step 3: Take in size of array into size from user
Step 4: Check if (i<size). If yes, go to step 5 else step 6
Step 5: Accept numbers into array and increment i by 1. Go to step 4 
Step 6: Display the menu:
		1. Insert an element at specified position
		2. Delete an element at specified position
		3. Search for an element
		4. Display the array
		5. Reverse the list
		6. Move all zeros at the bottom of an array	
		and take user's choice and store it into switchChoice
Step 7: Make the first case for inserting element
Step 8: Check if (size>=20). If yes, then display message that element cannot be inserted. Else go to step 9
Step 9: Call insertElement(arr, pos, size, num) with parameters. Make size = size+1
Step 10: Make the second case for deleting element
Step 11: Check if (size<=0). If yes, then display message that element cannot be deleted. Else go to step 12
Step 12: Call deleteElement(arr, pos, size) with parameters. Make size = size-1
Step 13: Make the third case for searching for an element
Step 14: Call linearSearch(arr,size,key) and assign its value to keyPos
Step 15: Check if (keyPos==-1). If yes, then display that search value does not exist, else display keyPos
Step 16: Make the fourth case for displaying the array
Step 17: Call display(arr,size) with the parameters
Step 18: Make the fifth case for reversing the array
Step 19: Call reverseArr(arr,size) with the parameters
Step 20: Make the sixth case for pushing zeros to bottom of the array
Step 21: Call zeroToBottom(arr,size) with the parameters
Step 22: Make a default case
Step 23: Ask if user wants to enter again. Store their choice in choice variable.
Step 24: Check if (choice==1). If yes, go to step 6. If no, go to step 25
Step 25: Stop
*/
#include <stdio.h>
#include "myheader.h"
int main()
{
	int choice = 0, size = 0, i = 0, switchChoice = 0;
	int arr[20]={0};
	int pos=0,num=0,key=0, keyPos=0;
	printf("Enter number of elements to be entered in the array:\n"); //Take number of elements in array
	scanf("%d",&size);
	printf("Enter %d elements:",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	do
	{
		printf("1. Insert an element at specified position\n2. Delete an element at specified position\n3. Search for an element\n"); //Display menu and taeke user's choice
		printf("4. Display the array\n5. Reverse the list\n6. Move all zeros at the bottom of an array\n");
		printf("Enter your choice:\n");
		scanf("%d",&switchChoice);
		switch(switchChoice)
		{
			case 1: //Make first case to insert an element
				if(size>=20)
				{
					printf("Number cannot be inserted, delete element to continue\n");
				}
				else
				{
					printf("Enter the position the number should be entered at and enter the number to be entered:\n");
					scanf("%d %d",&pos, &num);
					insertElement(arr, pos, size, num);
					size = size+1;
					printf("Number successfully inserted\n");
				}
				break;
				
			case 2: //Make second case to delete an element
				if(size==0)
				{
					printf("Number cannot be deleted, insert element to continue\n");
				}
				else
				{
					printf("Enter the position the number should be deleted from:\n");
					scanf("%d",&pos);
					deleteElement(arr, pos, size);
					size = size-1;
					printf("Number successfully deleted\n");
				}
				break;
			case 3:	//Make third case to search for an element
				printf("Enter number to be searched:\n");
				scanf("%d",&key);
				keyPos = linearSearch(arr,size,key);
				if(keyPos == -1)	
				{
					printf("Number not found\n");
				}
				else	
				{
					printf("Number found at: %d\n",keyPos);
				}
				break;
			case 4: //Make fourth case to display the array
				display(arr,size);
				break;
			case 5: //Make fifth case to reverse array
				reverseArr(arr,size);
				printf("Array successfully reversed\n");
				break;
				
			case 6: //Make sixth case to push zeros to bottom
				zeroToBottom(arr,size);
				printf("Zeros pushed to the bottom successfully\n");
				break;
			default:
				printf("Enter number between 1 and 6\n");
			
		}
		printf("\nIf you want to enter again, press 1. Press any other key to exit\n"); //Ask if user wants to enter again
		scanf("%d",&choice);
	}while(choice == 1);
	return 0;
}
/*
Sample inputs and outputs:
************************
Enter number of elements to be entered in the array:
4
Enter 4 elements:1 0 3 4
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
1
Enter the position the number should be entered at and enter the number to be entered:
2 2
Number successfully inserted

If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
6
Zeros pushed to the bottom successfully

If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
4
1       2       3       4       0
If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
2
Enter the position the number should be deleted from:
5
Number successfully deleted

If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
4
1       2       3       4
If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
5
Array successfully reversed

If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
4
4       3       2       1
If you want to enter again, press 1. Press any other key to exit
1
1. Insert an element at specified position
2. Delete an element at specified position
3. Search for an element
4. Display the array
5. Reverse the list
6. Move all zeros at the bottom of an array
Enter your choice:
3
Enter number to be searched:
2
Number found at: 3

If you want to enter again, press 1. Press any other key to exit
0

--------------------------------
Process exited after 75.23 seconds with return value 0
Press any key to continue . . .
*/
