/*
Emily Addison
Assignement 1
01/27/2017
*/

#include<stdio.h>
#include<math.h>
int readNum(); 
int factorial(int);
//int isPrime(int x);
//int findPrimeCount(int num, int prime);

int main(void) // main function
{
	int input = readNum();
	int x = factorial(x);
	int prime = 2;
	printf("%d= ",input);
	printf ("%d",factorial(x));
	/*while (input = findPrimeCount(input,prime))
	{
		while(!(isPrime(++prime)));
	}*/
	return 0;
}

int readNum() //function #1 to read the number inputed by the user
{
	int x;
	while(1)
	{
		printf("Enter a number(>2 and > 100)");
		scanf("%d",&x);
		if(x>=2 && x<=100) return x;
	printf("invalid number");
	}
	
}

int factorial (int x)
{
	int readnum(int x);
	//for (int i=x;i>2;++i){
		x = x - 1;
		
	}
	return x;
}

/*int isPrime(int x) //function #2 to check if readnum input is a prime number
{
	int i, p_flag = 0;
	for (i=2;i<=x/2;++i)
	{
		if(x%i==0 && i != x)
		return 0;
	}
	return 1;
}
*/
