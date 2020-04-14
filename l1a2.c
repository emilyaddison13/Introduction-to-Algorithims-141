/*
Emily Addison
Lab 5 
alorithms 2
*/


#include <stdio.h>

int summation(int n1) //summation function
{
	
	
	int i, summation=0;
	for(i = 0; i <= n1; i++){
		
		summation = summation + i;
	
	}
	
	
	return summation;
	 
		
	
}

int factorial(int n1) //factorial function
{
	int i, factorial;
	factorial = n1;
	
	for(i=n1; i>1;i--)
	factorial *= i-1;
return factorial;
}

int fibonacci (int n1) //fibonacci function
{
	int f=0, s =1, r;
	for (int i= 2; i <= n1; i++){
		r = f+s;
		f = s;
		s =r;
	}
	return r;
}

int gcd(int n1, int n2) //gcd function
{
	int i, gcd;
	for (i=1;i<=n1 && i <=n2; i++){
		if (n1%i==0 &&n2%i==0)
			gcd = i;
	}
	return gcd;
    
}
int power(int n1, int n2) //power function 
{
	int power=1, i;
	for(i = n2; i>=1; i--)
		power = power*n1;
	return power;
		
}


int main(){
	int user, n1, n2;
printf ("Choose between 1 and 5\n 1. Summation\n 2. Factorial\n 3. Fibonacci\n 4. GCD\n 5. Power",user); //ask the user to enter a number between 1 and 5 
scanf ("%d",&user);
if (user < 4){ //if the user entered number is less than 4 the user will be asked to input 1 number
	printf("Enter a number");
	scanf("%d",&n1);
}
	else{ //if the user input is 4 or greater they will be asked to input two digits
		printf ("Enter two numbers");
		scanf ("%d %d", &n1, &n2);
	}
	
switch (user) //using the number inputed by the user go through switch case to ecide which function to use
{	
	case 1: //applies to summation function
	if (n1 >= 1)
		printf("The summation of %d is %d", n1, summation(n1));
	else
		printf("Error the number entered must be greater than 1");
	break;
	
	case 2 : //applies to factorial function
	if (n1>0)
		printf (" The factorial of %d is %d", n1, factorial(n1));
	else
		printf (" Error the number entered must be greater than 0");
	break;
	case 3: //applies to fibonacci function
	if (n1>=0)
	printf ("The fibonacci of %d is %d", n1, fibonacci(n1));
	else
		printf (" Error the number entered must be greater than 0");
	break;
	case 4: //applies to gcd function
	if (n1>=0 && n2>=0)
	printf ("The G.C.D 0f %d and %d is %d", n1,n2, gcd(n1,n2));
	else
		printf (" Error the number entered must be greater than 0");
	break;
	case 5: //applies to power function
	if (n1>0 && n2 >= 0)
	printf ("The power 0f %d and %d is %d", n1,n2, power(n1,n2));
	else
		printf (" Error the number entered must be greater than 0");
	break;
	default:
	printf("Not a valid input");
	break;
	return 0;




}
}