/*
Emily Addison
104553525
Lab 7 Part 20*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct myWord{ //defining the structure
    char Word[21];
    int Length;
};

int main() {
    struct myWord wordList[20]; //adding an array to the structure 
    struct myWord temp;
    char *token; //for the strtok
    int i, j, Count = 0;

    char myString[] = "the cat in the hat jumped over the lazy fox";

    token = strtok(myString, " "); //creating delimiters

    while (token != NULL) { //a while loop for finding delimiters in the string and adding to the array
        strcpy(wordList[Count].Word, token); //copies string onto array
        wordList[Count].Length = strlen(token);//finds string length
        Count++; //ads one to counter to continue looping

        token = strtok(NULL, " ");
    }

    printf("The unsorted word list:\n");
    for(i = 0; i < Count; i++) //goes through wordlist array and prints the words in the list with the length
        printf("%s\t%d\n", wordList[i].Word, wordList[i].Length);

  //sorts the words alphabetically 
    for(i = 0; i < Count; i++) { //scans through entire list
        for(j = 0; j < Count - 1; j++) {
            if(strcmp(wordList[j].Word, wordList[j+1].Word) > 0) { //compares two words to eachother
                temp = wordList[j]; //uses tempword to switch around words
                wordList[j] = wordList[j+1];
                wordList[j+1] = temp;
            }
        }
    }
    printf("The sorted word list:\n");
    for(i = 0; i < Count; i++) //prints the list alphabetically and the list length
        printf("%s\t%d\n", wordList[i].Word, wordList[i].Length);

    return 0;
}