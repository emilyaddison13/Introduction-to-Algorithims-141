/*
Emily Addison
Lab3 
Febuary 2nd, 2017
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 6
#define N 5

int PopulateRandom2D(int[][N], int(*)[]);
int PrintArray2D(int[][N]);
bool LinearSearch2D(int [][N],int);
int LeftShift2D(int(*)[]);
int main()
{
int array[M][N]={0}; //intializing an array of MxN of zeros
	int user, key, (*aPtr)[N];
	bool done=true;
	aPtr=array;
	srand(time(NULL)); //create a random number
	while(done){
	printf("Type 1 if you would like to randomly populate an array\nType 2 if you would like to print an array\nType 3 if you would like to search the array\nType 4 if you would like to left shift the array\nType 5 If you want to exit the program\n");
	scanf("%d",&user); //Take user input
	switch(user)
	{
		case 1:
		PopulateRandom2D(array,aPtr); //User input to randomly popoulate the 2d array
		break;
		
		case 2:
		PrintArray2D(array); //User input to print the 2d array
		break;
		
		case 3:
		printf("what number would you like to search for: "); //User input to search an array for a value given by user
		scanf("%d",&key);
		bool found = false;
		found = LinearSearch2D(array,key);
		if(found)
			printf("You found the number!!!");
		else
			printf("The number doesnt exsits");
		break;
		case 4:
		LeftShift2D(aPtr); //left shift the array 
		break;
		
		case 5: //Closes the program 
			done = false;
			break;
			
		default:
		printf("Not a proper input. Try again\n");
		break;
	}
	}

return 0;
	
}
//Purpose:To print the array 
//Input: The array 
//Output: The function returns 0
int PrintArray2D(int array[M][N])
{
    
	for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
         //aPtr[i] = rand() % 500 + 100;
          printf("%*d ",4,array[i][j] );
		   }
        printf("\n");
	}
}
//Purpose: Randomly populate an array from numbers 1 to 30
//Input: An array and a pointer to the array
//Output: The function returns 0
int PopulateRandom2D(int array[M][N],int (*aPtr)[N]) // to populate the array with pseudo-random numbers.
{
    
    int j, i,key;
    
    for (i = 0; i < M; i++){
		
		for (j=0;j<N;j++)
		{
			key = rand()%30+1;
			while(LinearSearch2D(aPtr,key))
			{
				key = rand()%30+1;
				
			}
			*(aPtr[i]+j) = key;
		}
         
    
	
		 }
	
	return 0;
}
 // to search the array for a value, return true if found.
 //Purpose: Use a linear search to see if the variable entered is in the randomly given array
 //Input: A user entered value
 //Output: Returns either true or false
bool LinearSearch2D(int array[M][N],  int key){
    int i, j;
    for (i = 0; i < M; i++){
        for (j = 0; j < M; j++){
            if ( array[i][j] == key )
                return true;
		}
	}
    return false;
}

//Purpose: To left shift and entire array 
//Input:Pointer to an array
//OUtput:Function returns 0
int LeftShift2D(int (*aPtr)[N]) //Shifts the entire array one to the left and one down 
{
	int temp;
	for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
		{
			if (j==0 && i!=0)
				*(aPtr[i-1]+ N - 1) = *(aPtr[i]+j);
			else if (i==0 && j==0)
				temp= *(aPtr[i]+j);
			else if (i==M-1&&j==N-1){
				//*(aPtr[i]+j-1) = *(aPtr[i]+j);
				*(aPtr[i]+j)= temp;
			}
				
			else
				*(aPtr[i]+j-1) = *(aPtr[i]+j);
		}
		
	
}
}
