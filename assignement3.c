/*
Emily Addison
104553525
March 12th, 2017
Assignement 3
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINES 10
#define LENGTH 81


void letterAnalysis(int intlines, char input[LINES][LENGTH]);
int wordLengthAnalysis( char input[LINES][LENGTH], int intlines,int n);
void wordAnalysis(char input[LINES][LENGTH],int intlines);


int main()
{
	int intlines, wordlength; 
	char input [LINES][LENGTH];
  scanf("%d", &intlines);//The next three lines of code are used to open the text file when inputed by the user in cygwin
  for (int i=0;i<intlines;i++)
  {
	scanf(" %[^\n]s", input[i]);
  }
	
  letterAnalysis(intlines, input);//initializes the first function passing two parameters through it
  
  for (int i=1; i<20;i++) //a for loop for initializing the word length analysis function, the for loop also prints the results into a table 
  {
	  wordlength= wordLengthAnalysis(input,intlines,i);
	  if(wordlength >0)
	  {
		  printf("%-2d  word",wordlength); //prints results to the left side 
		  if(wordlength > 1)
			printf("s");
		  printf(" the length of %d\n",i);
	  }
  }
  wordAnalysis(input, intlines); //initializes final function
    return 0;
}

//purpose: to count how many times each letter a-z appears in the given text
//Input: text file
//Output: letter count
void letterAnalysis(int intlines, char input[LINES][LENGTH])
{
	int alphabet[26]={}; //creates an array of all letters from the alphabet 
	
	for (int i=0; i<intlines; i++) //runs each letter in the text file array to count how many of each letter there is 
	{
		int j= 0;
		while(input[i][j] != '\0')
		{
			if(isalpha(input[i][j]))
				alphabet[tolower(input[i][j])-'a']++;
			
			j++;
		}
	}
	printf("The total letter count is:\n "); //prints the total number of each letter counted 
	int i=0;
	while(i<26)
	{
		printf("%c: %d\n", i+'a', alphabet[i]);
		i++;
	}
	return;
}
//Purpose: to find the length of words in the text file
//Input: text file with length of number lines
//Output: the length of the word to the main fuction
int wordLengthAnalysis( char input[LINES][LENGTH], int intlines,int n)

{
	char temp[LINES][LENGTH];
	char *token;
	int wordlength = 0;
	const char *delim={" \n\r"};
	for (int i = 0; i<intlines;i++)
	{
		strcpy(temp[i],input[i]); //breaks down each word in order to count the letters inside of the word 
		token = strtok(temp[i],delim);
		while(token!=NULL)
		{
			if(strlen(token)==n) //adds number to counter to display each time a one letter, two letter... word is shown 
				wordlength++;
			token=strtok(NULL,delim);
		}
	}
	return wordlength; //returns word length to the main function in order to print results
}

//purpose: to count the times each word is seen in the text file
//Input: text file
//Output: number of times each word is seen
void wordAnalysis(char input[LINES][LENGTH],int intlines)
{
	char temp[LINES][LENGTH];
	char *token;
	char *tokenarray[200];
	int wordc = 0, wordnum;
	const char *delim={" \n\r"};
	for (int i = 0; i<intlines;i++)
	{
		strcpy(temp[i],input[i]); //breaks down word to compare to others to count each time the same word is shown in the text
		token = strtok(temp[i],delim);
		while(token!=NULL)
		{
			tokenarray[wordc]=token;
			token = strtok(NULL,delim);
				wordc++;
		}

	}
	for(int i =0;i<wordc;i++)	
	{
		wordnum = 0;
		for(int j = 0;j<wordc;j++)
		{
			if (!strcmp(tokenarray[i],tokenarray[j]))
			
				wordnum++;
			
		}
	
		printf (" \"%s\" appeared %d times",tokenarray[i],wordnum); //prints each time the same word is displayed
	
		if(wordc>1)printf("s"); //spaces results 
		printf("\n");
	}
}






  
