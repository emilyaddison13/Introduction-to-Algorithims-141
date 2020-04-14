/*
Emily Addison
Lab 4
Febuary 15th, 2017
*/


#include<stdio.h>
#define SIZE 10

int *Largest(int *array, int size);
void Swap(int *x, int *y);

int main()
 {
	int i;
	int array[SIZE] = {3,5,4,2,6,4,13,7,1,9};
	int *Largele = NULL, *array1 = NULL;
	
	array1 = array;
	printf("The original array is:\n");
	for( i = 0; i < SIZE; i++)
	{
		//uses pointer logic to print out elemts in the array 
		printf("%d ", *array1); 
		array1++;
	}
	printf("\n");
	
	
	//Uses function largest to find the largest value in the array
	Largele = Largest( array, SIZE );
	printf("The largest element is %d and the adress is %u\n",*Largele,&(*Largele));
	
	//uses swap function to swap the first two elements in the array 
	Swap(array, array+1);
	
	//prints out the array with the two swapped elements 
	array1 = array;
	printf("The swapped array is:\n");
	for( i = 0; i < SIZE; i++)
	{
		printf("%d ", *array1);
		array1++;
	}
	printf("\n");
	
	
	return 0;
 }
 
 //Purpose: To find the largest element in the array of 10 digits given
 //Input: Array and array size
 //Output: Largest element in the array
 int *Largest(int *array, int size)
 {
	int i, *Largele;
	Largele = array;
	for( i = 0; i < SIZE; i++)
	{
		if(*Largele < *(array+i))
			Largele = array+i;
	}
	return Largele;
 }
 //Purpose: To swap the first two elemnts in the array that have pointers directed at them 
 //Input: The pointer pointing to the first two elements in the array
 //Output: The new array 
 void Swap(int *x, int *y)
 {
	
	int temp = *x;
	*x = *y;
	*y = temp;
 }
 