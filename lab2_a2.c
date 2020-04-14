
/*
Emily Addison
Lab 2 
alorithms 2
January 30th, 2017
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int factorial(int n1 ) //Calculates the factorial of a given number
{
	if (n1<= 1)
		return 1;
	return n1*factorial(n1-1);
}

int summation (int n1) //Calculates the summation of a given number
{
	if (n1 ==1){
		return n1;
	}
	return n1 + summation(n1-1);	
}

int fibonacci(int n1) //Calculates the fibonacciof a given number 
{
	if (n1 ==0){
		return 0;
	}
	if (n1==1){
		return 1;
	}
	return fibonacci(n1-1)+fibonacci(n1-2);
}

int gcd(int n1, int n2) //Finds the greatest commom denominator between two number
{
	 if (n2 != 0)
       return gcd(n2, n1%n2);
    else 
       return n1;
}

int power(int n1, int n2)//Finds the power of the two numbers
{
	 if (n2 == 0)
       return 1;
    else
        return n1*power(n1, n2-1);
} 


int main(void){
	int user=0, n1, n2;
	bool done=true;
	
	while(done)
	{
	printf ("Choose between 1 and 5\n 1. Summation\n 2. Factorial\n 3. Fibonacci\n 4. GCD\n 5. Power\n Enter a choice: "); //ask the user to enter a number between 1 and 5 

	scanf ("%d",&user);

	if (user < 4 && user !=0){ //if the user entered number is less than 4 the user will be asked to input 1 number
		printf("\nEnter a number");
		scanf("%d",&n1);
	}
	else if(user >= 4)
	{ 
		//if the user input is 4 or greater they will be asked to input two digits
		printf ("\nEnter two numbers");
		scanf ("%d %d", &n1, &n2);
	}
	
	switch (user) //using the number inputed by the user go through switch case to ecide which function to use
{	
		case 0:
			return 0;
		case 1: //applies to summation function
		if (n1 >= 1)
			printf("The summation of %d is %d\n", n1, summation(n1));
		else
			printf("Error the number entered must be greater than 1");
		break;
		
		case 2 : //applies to factorial function
		if (n1>0)
			printf (" The factorial of %d is %d\n", n1, factorial(n1));
		else
			printf (" Error the number entered must be greater than 0");
		break;
		
		case 3: //applies to fibonacci function
		if (n1>=0)
		printf ("The fibonacci of %d is %d\n", n1, fibonacci(n1));
		else
			printf (" Error the number entered must be greater than 0");
		break;
		
		case 4: //applies to gcd function
		if (n1>=0 && n2>=0)
		printf ("The G.C.D 0f %d and %d is %d\n", n1,n2, gcd(n1,n2));
		else
			printf (" Error the number entered must be greater than 0");
		break;
		
		case 5: //applies to power function
		if (n1>0 && n2 >= 0)
		printf ("The power 0f %d and %d is %d\n", n1,n2, power(n1,n2));
		else
			printf (" Error the number entered must be greater than 0");
		break;
		default:
		printf("Not a valid input");
		
		break;
		return 0;


}

}
}
