/*
Emily Addison
Lab 7 part A
104553525
*/



#include<stdio.h>
#include<stdlib.h>

int AtoI ( const char * str );
int StrCmp ( const char * str1, const char * str2 );
char * StrCpy ( char * dest, const char * src );
char * StrCat ( char * dest, const char * src );
char * StrChr ( char * str, int ch );

int main()
{
	int choice, result;
	char ch, one[20], two[20];

	

	printf("Enter a numeric string to convert: "); //converts a numeric written word to a numeric digit
	scanf(" %[^\n]", one);
	printf("%s to integer = %d\n", one, AtoI(one));

	printf("Enter string 1: ");//compares the length of two strings
	scanf(" %[^\n]", one);
	printf("Enter string 2: ");
	scanf(" %[^\n]", two);
	result = StrCmp(one, two);
	if(result > 0)
		printf("String 1 is greater than String 2.\n");
	else if(result < 0)
		printf("String 1 is less than String 2.\n");
	else
		printf("String 1 and String 2 are equal.\n");

	printf("Enter a string: "); //copies a word onto string 1
	scanf(" %[^\n]", one);
	//StrCpy(two, one);
	printf("Original string is: %s.\n", two);
	StrCpy(two, one);
	printf("Copied  string  is: %s.\n", one);

	printf("Enter string 1: "); //concatenates two strings together
	scanf(" %[^\n]", two);
	printf("Enter string 2: ");
	scanf(" %[^\n]", one);
	StrCat(two, one);
	printf("String 1 + String 2: %s.\n", two);

	printf("Enter a string: "); //searches a string to see if a letter given is in the string
	scanf(" %[^\n]", one);
	printf("Enter a charcter to search: ");
	scanf(" %c", &ch);
	printf("Character %c %s in the string %s.\n", ch, StrChr(one, ch)?"is":"is not", one);

}
//Purpose: To change a alphabetically given number to a digit number
//Input: A number in letters
//Output: A number in digits
int AtoI ( const char * one )
{
	int i = 0, num = 0;
	while(one[i] != '\0')
	{
		if(one[i] == '.') break;
		if(one[i] >= '0' && one[i] <= '9') 
			num = (num*10) + one[i] - '0';
		i++;
	}
	return num;
}

//Purpose: To compare the length of two given strings
//Input: Two strings
//Output: The largest string
int StrCmp ( const char * str1, const char * str2 )
{
	int i = 0, flag = 0;
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] < str2[i]) return -1;
		if(str1[i] > str2[i]) return 1;
		i++;
	}
	if(str1[i] == '\0') return -1;
	if(str2[i] == '\0') return 1;
	else
	return 0;
}
//Purpose: copies a new string onto the string 1 originally given
//Input: A new string
//Output: The new string copied onto string 1
char * StrCpy ( char * two, const char * one )
{
	int i = 0;

	while(one[i] != '\0')
	{
		two[i] = one[i];
		i++;
	}
	two[i] = '\0';

	return two;
}
//Purpose:Concatenates two strings together
//Input: Two strings
//Output: One string
char * StrCat ( char * two, const char * one )
{
	int i = 0, j = 0;

	while(two[i] != '\0') i++;

	while(one[j] != '\0')
	{
		two[i] = one[j];
		i++; j++;
	}
	two[i] = '\0';

	return two;
}
//Purpose: To search trhough a string for a given character
//Input: a string and a given digit to search for
//Output: A result as to wether or not the character was found in the string
char * StrChr ( char * one, int ch )
{
	int i = 0;
	while(one[i] != ch && one[i] != '\0') i++;

	if(one[i] == ch) return &one[i];
	return NULL;
}