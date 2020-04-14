/*
Emily Addison
Lab 9
11/25/16
*/
#include <stdio.h>


int readnum ()
{
	int n, number;
	
	while(1)
	{
	
		printf("Enter a number larger than 1: "); // asks for user input
		scanf("%d",&n);
		if (n >= 1)	return n; // checks if digit is greater than 1
	
		else	printf("Invalid digit\n ");
		
	
	}
	
		
	
}
int recursiveTriangularNumber(int n) //recursive triangle function
{
	
	
	
	if (n ==1){
		return n;
	}
	
    
    
	
	return n + recursiveTriangularNumber(n-1);
	

}
int ireterativeTriangularNumber(int n) //iterative triangle function
{
	
	int i, iterative=0;
	for(i = 0; i <= n; i++){
		//printf("%d,%d", n, i);
		iterative = iterative + i;
	}
	
	return iterative;
	
}

int main() //main function
{
	int n, triangularNumber, iterative, number, i, recurance;
	n = readnum();
	recurance = recursiveTriangularNumber(n);
	iterative = ireterativeTriangularNumber(n);
	number = n;
	recursiveTriangularNumber(n);
	ireterativeTriangularNumber(n);
	printf("Recursive: %d,%d\n",n,recurance); //outputs final value for recurance function
	printf("Iterative:%d,%d", n, iterative); // outputs final value for iterative function
	

return 0;
}
	