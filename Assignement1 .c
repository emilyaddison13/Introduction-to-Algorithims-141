/*
Emily Addison
104553525
Assignement 1
*/

#include<stdio.h>

int is_Prime(int);
int find_Prime_Count(int, int);
int findNextPrime(int);
int main(void)
{
	int  x, result, prime =2, count; //global variables 
	FILE *input=fopen("input.txt", "r+"); //imports text file 
	while(x!=0) //while loop to check if the txt file is still running
	{
	fscanf(input,"%d", &x); //scanf to check the digit in the txt file
	if (x!=0)
	{
		printf("%d",x); //prints txt file digit
	}
	break;
	}
	while(prime<=x)
	{
		count=0;
		for(int i=2; i<=x; i++) //loop to start the txt file digit into program 
		{
			count+= find_Prime_Count(i, prime); //counter to find prime count 
		}
		printf("(%d^%d) * ", prime, count); //prints in appropriate format
		prime=findNextPrime(prime); //transfers to other function 
	}
	
	return 0;
}
int findNextPrime(int prime) //function to find the next prime number in the factorial 
{
	while(!is_Prime(++prime));
	return prime;
}
int find_Prime_Count(int x, int prime) //finds the prime number and counts how many times it goes through the factorial number
{
	int count=0;
	while((x/prime)!=0 && x%prime==0)
	{
		x/= prime;
		count++;
	}
	
	return count;
}

int is_Prime(int scan)// function to check if the number entered is a prime number or not 
{
	int i;
	
	for (i=2; i<=scan-1; i++) //loop to keep checking the digit choosen 
	{
		if (scan % i == 0)
			return 0; //returns false
	}
	if (i == scan) 
		return 1; //returns true 
}

