#include <stdio.h>
 
int main()
{
  int array[10], maximum, size, c, location = 1;
 
  //printf("Enter the number of elements in array\n");
  //scanf("%d", &size);
 
  //printf("Enter %d integers\n", size);
 int *Largest( int *array, int size )
{
	int *array[10]={3,5,4,2,6,4,13,7,1,9};
	int temp=array[0];
 
  for (c = 0; c < size; c++)
    scanf("%d", &array[c]);
 
  maximum = array[0];
 
  for (c = 1; c < size; c++)
  {
    if (array[c] > maximum)
    {
       maximum  = array[c];
       location = c+1;
    }
  }
 
  printf("Maximum element is present at location %d and it's value is %d.\n", location, maximum);
  return 0;
}
}