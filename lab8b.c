/*
Emily Addison
104553525
March 21st,2017
*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct employee{
    char firstName[40];
    char lastName[40];
    int ID;
	int GPA;
};

typedef struct employee Employee;

char CapWord(char *word);
void ReadEmpList(Employee *EmpList, const char *FileName);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);


int main() {

    Employee EmpList[3];
	int i;

    ReadEmpList(EmpList, "employee.dat");

    for(i = 0; i < 2; i++)
    {
		CapWord(EmpList[i].firstName);
		CapWord(EmpList[i].lastName);
	}

	PrintEmpList(EmpList);
    SaveEmpList(EmpList, "employee.dat");

    return 0;
}

//purpose: To read the information put into the file created in the last program
//input: |file
void ReadEmpList(Employee *EmpList, const char *FileName)
{
    FILE *fp;
	fp = fopen("employee.dat", "rb+");
    int i;
    char temp[40];
	
  
    for(i=0; i<2; i++)//takes the info from the file
    {
        fscanf(fp, "%d %s %s %d", &EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName, &EmpList[i].GPA);
    }
    fclose(fp);
}

//usage: capitalises the first letter in the word
//input: words from the file
//output: capitalized word
char CapWord(char *word)
{
	word[0] = toupper(word[0]);//changes first letter to capital
	//return word;
}

//usage:opens the file and prints info into file
//input:list 
void SaveEmpList(const Employee *EmpList, const char *FileName)
{
    FILE *fp;//opens file
    int i;
    fp = fopen(FileName, "wb");
   
    fprintf(fp, "ID\tFirstName\t\tLastName\tGPA\n");
    for(i=0; i<2; i++)//prints file
    {
        fprintf(fp, "%d\t%s\t\t%s\t\t%d\n", EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName,EmpList[i].GPA);
    }
    fclose(fp);
}

//usage:to print the file info
void PrintEmpList(const Employee *EmpList)
{
    int i;

    printf("ID\tFirstName\tLastName\tGPA\n");//prints all ingo from file
    for(i=0; i<2; i++)
    {
        printf("%d\t%s\t\t%s\t\t%d\n", EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName,EmpList[i].GPA);
    }
}