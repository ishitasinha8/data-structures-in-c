/*
    Registration Number: 202000506
    Name: Ishita Sinha
*/
/*

	Algorithm for "Insert an element at specified position."
	********************************************************
Step 1: Start
Step 2: Make a function of the following prototype:
		insertElement(int arr[], int pos, int size, int num)
Step 3: Declare a loop counter variable i
Step 4: i=size
Step 5: Check if (i>=pos). If yes, follow through, otherwise go to step 7
Step 6: Do the following assignment:
		arr[i] = arr[i-1]
Step 7: Increment i by 1. Go to step 4.
Step 8: arr[pos-1] = num
Step 9: Stop

	Algorithm for "Delete an element at specified position."
	********************************************************
Step 1: Start
Step 2: Make a function of the following prototype:
		deleteElement(int arr[], int pos, int size)
Step 3: Declare temporary variable (temp) of integer type and intitialise it to arr[pos-1]
		Declare loop counter variable i
Step 4: i = (pos-1)
Step 5: Check if (i<(size-1)). if yes, follow through otherwise go to step 7
Step 6: Do the following assignment statements:
		arr[i] = arr[i+1];
        arr[i+1] = 0;
Step 7: Increment i by 1. Go to step 4.
Step 8: Stop
    
	Algorithm for "Search for an element."
	**************************************
Step 1: Start
Step 2: Make a function of the following prototype:
		int linearSearch(int arr[], int size, int key)
Step 3: Declare and initialise loop counter variable i to 0,flag variable to 0, Position of key (keyPos) to -1
Step 4: Check if (i<size). If yes, go to next step else go to step 7
Step 5: Check if (key==arr[i]). If yes, do the following assignment operations:
		flag=1
		keyPos = i
Step 6: Increment i by 1. Go to step 4.
Step 7: Check if (flag==1). If yes, return keyPos, else return -1
Step 8: Stop

	Algorithm for "Display the array."
	**********************************
Step 1: Start
Step 2: Make a function of the following prototype:
		display(int arr[], int size)
Step 3: Declare a loop counter variable i
Step 4: Check if (i<size). If yes, follow through, else go to step 7
Step 5: Display arr[i]
Step 6: Increment i by 1. Go to step 4.
Step 7: Stop

	Algorithm for "Reverse the list."
	*********************************
Step 1: Start
Step 2: Make a funtion of the following prototype:
		reverseArr(int arr[], int size)
Step 3: Declare a loop counter variable i and temporary variable temp and initialise both to 0
Step 4: Check if (i<(size/2)). If yes follow through, else go to step 7
Step 5: Make the following assignment statements:
		temp=arr[i]
		arr[i]=arr[size-(i+1)]
		arr[size-(i+1)]=temp
Step 6: Increment i by 1. Go to step 4.
Step 7: Stop

	Algorithm for "Move all zeros at the bottom of an array."
	*********************************************************
Step 1: Start
Step 2: Make a funtion of the following prototype:
		zeroToBottom(int arr[], int size)
Step 3: Declare a loop counter variable i and zeroPos variable and initialise both to 0
Step 4: Check if i<size. If yes follow through, else go to step 11
Step 5: Check if (arr[i]==0). If yes, follow through, else go to step 10
Step 6: Do the assignment: 
		zeroPos = i
Step 7: Check if (arr[zeroPos]==0&&(zeroPos<size)). If yes, follow through, else go to step 9
Step 8: Increment zeroPos by 1. Go to step 7.
Step 9: Do the assignments:
		arr[i]=arr[zeroPos]
		arr[zeroPos]=0
Step 10: Increment i by 1. Go to step 4
Step 11: Stop
*/
void insertElement(int arr[], int pos, int size, int num) //Function for inserting an element
{
    int i = 0;
    for(i = size;i>=pos;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = num;
}

void deleteElement(int arr[], int pos, int size) //Function for deleting an element
{
    int temp = arr[pos-1], i=0;
    for(i = (pos-1) ;i<(size-1);i++)
    {
        arr[i] = arr[i+1];
        arr[i+1] = 0;
    }
}

int linearSearch(int arr[], int size, int key) //Function for searching
{
	int i=0,flag=0, keyPos=-1;
	for(i=0;i<size;i++)
	{
		if(key==arr[i])
		{
			flag=1;
			keyPos = i;
		}
	}
	if(flag==1)	
		return (keyPos+1);
	else
		return -1;
	
}
void display(int arr[], int size) //Function for displaying array
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);		
	}
}
void reverseArr(int arr[], int size) //Function for reversing array
{
	int i=0, temp=0;
	for(i=0;i<(size/2);i++)
	{
		temp=arr[i];
		arr[i]=arr[size-(i+1)];
		arr[size-(i+1)]=temp;
	}
}
void zeroToBottom(int arr[], int size) //Function for pushing zeros to bottom of array
{
	int i=0, zeroPos=0;
	for(i=0;i<size;i++)
	{
		if(arr[i]==0)
		{
			zeroPos = i;
			while(arr[zeroPos]==0&&(zeroPos<size))
			{
				zeroPos++;
			}
			arr[i]=arr[zeroPos];
			arr[zeroPos]=0;
		}		
	}
}
