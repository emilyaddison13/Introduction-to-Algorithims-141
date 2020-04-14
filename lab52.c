/*
Emily Adddison
104553525
Febuary 28th,2017
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 20

void fillArray(int *array, int size);
void printArray(int *array, int size);
void bubbleSort(int *array, int size);
void swap(int *, int *);

int main(void)
{
	int numList[SIZE] = {};
	int *array= numList; 
	
	srand(time(NULL));
	fillArray(array, SIZE);
	printArray(array, SIZE);
	bubbleSort(array,SIZE);
	printf("\n Descending order\n");
	printArray(array, SIZE);
	
	return 0;
}
//Puprose: To fill the array radomly
//Input: Size and a pointer to array
//Output: The filled array 
void fillArray(int *array, int size)
{
	for(int i=0; i<size; i++)
	{
		*array = rand() % 99 + 1;
		*array++;
	}
}
//Purpose: To print the array
//Input: Array and size 
//Output: The array
void printArray(int *array, int size)
{
	for(int i=0; i<size; i++)
	{
	printf("%d ", *array);
		*array++;
	}
	
} 
//Purpose: to swap the digits in the array
//Input: two pointers
//Output: swapped elements
void Swap(int *x, int *y)
 {
	
	int temp = *x;
	*x = *y;
	*y = temp;
 }
void bubbleSort(int *array, int size)
{
	int temp,n;
	for(int i=0;i<size;i++){
		for (int j=0; j<size;j++)
	{
		if(*(array+i)> *(array+j)) {  /* To sort in descending order, change > to < in this line. */
			Swap(array+i,array+j);
        }
}
	}

		
    //return 0;
}
