/*
Emily Addison
104553525
Lab 6
*/
#include <stdio.h>
#include<string.h>

void Reverse(char *buffer);
void ParseSentance(char *pBuffer2);

int main()
{

char buffer1[] = {'T', 'h', 'i', 's',' ', 'i','s', ' ', 't', 'h', 'e', ' ', 'f', 'i','r','s','t',' ','b','u','f','f','e','r','\0'}; //string array initilization

char buffer2[] = "This is the second buffer"; // a character string 

char buffer3[80] = {'\0'};// an empty character string

printf("Enter a string ");//ask user to enter a string into the third buffer
scanf("%[^\n]s", buffer3); //scans user input

printf(" %s\n", buffer1);//prints the buffers
printf(" %s\n", buffer2);
printf(" %s\n", buffer3);

char * pBuffer = buffer3; //sets the pointer to buffer3
printf("String printed with pointer: %s\n",  pBuffer);//prints the buffer using the pointer
pBuffer+=5; //shifts the pointer

printf("String shifted: %s\n",  pBuffer);//prints the shifted pointer
pBuffer -=5;//shifts the pointer back


Reverse(pBuffer); //initiliazes the reverse buffer function
printf("Reversed: %s\n", pBuffer); //prints the reverse buffer 
Reverse(pBuffer);

char *pBuffer2 = buffer2;
ParseSentance(pBuffer); //initiliazes the ParseSentance function
	return 0;

}
//Input: the pointer too pBuffer
//Output: A reversed string 

void Reverse(char *pBuffer)

{
int len = strlen(pBuffer);	// takes the string length of pBuffer
int j=len; //sets j equal to the length of the string
	char temp;//creates a temp car variable
	
	
	for(int i=0; i<len/2; i++)
	{
		//Initializes temp to the corresponding position of pBuffer[i]
		temp = pBuffer[i];
		//Initializes 
		pBuffer[i] = pBuffer[j-i-1];
		pBuffer[j-1-i] = temp;
	}
}
//Input: a pointer to pBuffer
void ParseSentance(char *pBuffer2)
{
	const char delim[2]={" "};
	char *token;
	
	token= strtok(pBuffer2, delim);
	
	while(token != NULL) //When the token is not empty it will go through the while loop
	{
		printf("%s\n", token);//prints tokens 
		
		token = strtok(NULL, delim);//gets first token 
	}
	
}
	
