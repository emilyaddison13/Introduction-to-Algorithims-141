/*
 * C Program to Count the Number of Occurrence of
 * each Character Ignoring the Case of Alphabets
 * & Display them
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
struct detail
{
    char c;
    int freq;
};
 
int main()
{
	
	//FILE *fp;
 //char filename[100];
 FILE * file;
 char *code = malloc(1000 * sizeof(char));
file = fopen( "hey.txt" , "r");

    struct detail s[26];
	
    char  c;
    int i = 0, index;
 
    for (i = 0; i < 26; i++)
    {
       s[i].c = i + 'a';
       s[i].freq = 0;
    }
   
	 // Prompt user to enter filename
  //printf("Enter a filename :");
  //gets(filename);
  
    // Open file in read-only mode
   //fp = fopen(filename,"r");
    i = 0;
    do
    {
        fflush(stdin);
        c = getchar();
        file[i++]; //= c;
        if (c == '\n')
        {
            break;
        }
        c = tolower(c);
        index = c - 'a';
        s[index].freq++;
    } while (1);
    //file[i - 1] = '\0';
    //printf("The string entered is: %s\n", filename);
 
    printf("*************************\nCharacter\tFrequency\n*************************\n");
    for (i = 0; i < 26; i++)
    {
        if (s[i].freq)
        {
            printf("     %c\t\t   %d\n", s[i].c, s[i].freq);
        }
    }
 
    return 0;
}