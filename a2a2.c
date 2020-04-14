
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <stdbool.h>

int readNum(); 
int factorial(int);
int is_prime(int);
int find_prime_count(int, int, int *);


int main(void) // main function
{
	int input = readNum();
	int x = is_prime(x);
	int prime = 2;
	printf("%d= ",input);
	//printf ("%d",factorial(x));
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

int find_prime_count(int primeCur, int x, int *pairNumPtr){
	int repCount=0, tempi;
	bool ifPrime = true;
	for (int i = 2;i<=x;i++){
		ifPrime = is_prime(i);
		//if it is a prime have if(i==primeCur) repCount++
		if (ifPrime){
			if(i==primeCur)
				repCount++;
		}
		//if not prime 
		tempi = i;
		while(!ifPrime){
			if (i%primeCur==0){
				repCount++;
				i /= primeCur;
			}
			else{
				ifPrime = true;
				i = tempi;
			}
		}
	}
	if (*pairNumPtr == 9){
		printf("\n	");
		*pairNumPtr = 0;
	}
	if (repCount != 0 && primeCur == 2){
		printf("(%d^%d)", primeCur, repCount);
		*pairNumPtr += 1;
	}
	else if (repCount != 0){
		printf("*(%d^%d)", primeCur, repCount);
		*pairNumPtr += 1;
	}
	return 0;
}


bool is_prime(int x) //function #2 to check if readnum input is a prime number
{
	int readnum(int x);
	int i, prime;
	int count = 2;
	while (count<x){
		prime = x%i;
	if(prime == 0){
			return false;
		}
		else
			count++;
	}
	return true;
}
	
		
	



/*int find_next_prime(int x , int i)
{
	int count = 2
	is_prime(int x);
	
}

*/

