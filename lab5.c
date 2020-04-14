#include <stdio.h> //adds the studio.h library to the program
int main() //opens up the main library 
{
int a = 7 ; //creates a integer variable a that is set to equal 7
int *aPtr ; //creates a pointer 
aPtr = &a ; //sets the pointer to the location of a
printf( "%p\n", &a ); //prints the address of a 
printf( "%p\n", aPtr ); //prints the pointer
printf( "%p\n", &aPtr );//prints the adress of the pointer
printf( "%d\n", a ); //prints the value a is attached to 7
printf( "%d\n", *aPtr ); //prints the value of the pointer, 7
printf( "%p\n", *&aPtr ); //prints the adress of the pointer
printf( "%p\n", &*aPtr ); //prints the address of the pointer
printf( "%d\n", *&a ); // prints the integer value of the pointer,7
//printf( "%d", &*a );//produces an error as you are trying to find were a is pointed to but it is not pointed to anyting, integer cant be pointed too
return 0;
}