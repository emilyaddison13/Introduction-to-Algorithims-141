
/*
Emily addison
104553525
March 23rd, 2015
*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define DELIM ","

void loadCourseInfo();
void displayCourseInfo();
void addCourseInfo();
void searchCourseInfo();

struct CourseInfo{
	int courseID;
	char courseName[50];
	char courseCode[12];
	char Term[6];
	};
typedef struct CourseInfo course;
course courseInput[100];
//Global Variable for adding courses keeps the ID all together
int IDcount=0;

int main(void)
{
	
	int menu=0;
	loadCourseInfo();
	//Keeps  interactive menu availalbe until the user terminates it by entering 5
	while(menu!=4)
	{
		printf("Select an option:\n");
		printf("[1] Display course information\n");
		printf("[2] Add a new course\n");
		printf("[3] Search for a course\n");
		printf("[4] Exit\n");
		
		scanf("%d", &menu);
		
		//Switch case between the options, each initiating a certain function
		switch(menu)
		{
			case 1: displayCourseInfo(); break;
			case 2: addCourseInfo(); break;
			case 3: searchCourseInfo(menu); break;
			case 4: printf("PROGRAM TERMINATED"); break;
			default: printf("Invalid entry try again please!\n"); break;
		}		
	}
	
	return 0;
}
//purpose:to load info from the file into the program
void loadCourseInfo()
{
	char *token;
	char courseInfo[100];
	char program[50];
	char code[12];
	char term[6];
	FILE *input;
	int count;
	input = fopen("input.csv", "r");//opens input.csv for reading
	
	while(fscanf(input, "%s\n", courseInfo) != EOF)
	{
		//Sets the count of commas equal to 0
		count=0;

		token=strtok(courseInfo, DELIM);//checks for delimiters in the fiel
		
		while(token != NULL)
		{
			switch (count)
			{
				case 0: 
					strcpy(program, token); 
					for(int i=0; i<strlen(program); i++)
					{
						program[i]=toupper(program[i]);
					}
					break;
				case 1:
					strcpy(code, token);
					break;
				case 2:
					strcat(code, token);
					strcat(code, "-");
					break;
				case 3:
					strcat(code, token);
					strcat(code, "-");
					break;
				case 4: 
					strcat(code, token);
					break;
				case 5:
					strcpy(term, token);
					break;
				case 6:
					strcat(term, token);
					break;
			}
			count++;
			token = strtok(NULL, DELIM);
		}
		//Adds the taken information
		strcpy(courseInput[IDcount].courseName, program);//puts info into proper format
		strcpy(courseInput[IDcount].courseCode, code);
		strcpy(courseInput[IDcount].Term, term);
		courseInput[IDcount].courseID = ++IDcount;
	}
	fclose(input);
	return;
}
//purpose: to print course info
void displayCourseInfo()
{
	printf("CourseID\tCourseName\tCourseCode\tTerm\n");
	for(int i=0; i<IDcount; i++)
	{
		printf("%-15d %-16s%-16s%s\n", courseInput[i].courseID, courseInput[i].courseName, courseInput[i].courseCode, courseInput[i].Term);//prints course info
	}
	printf("\n");
	return;
}
//purpose: to add a new course
void addCourseInfo()
{
	char courseInfo[100];
	char program[50];
	char code[12];
	char term[6];
	
	printf("Enter the name of the program please\n");//enter rpogram name
	scanf("%s", program);
	
	for(int i=0; i<strlen(program); i++)
	{
		program[i] = toupper(program[i]);//change to capital
	}
	
	printf("Enter the course code eg. xxxx-xxx-xx(faculty/subject-level-section)\n");
	scanf("%s", code);
	for(int i=0; i<IDcount; i++)
	{
		if(!strcmp(courseInput[i].courseCode, code))//check if code exits
		{
			printf("This course already exists\n");
			return;
		}
	}
	
	printf("Enter the term(W, S, F for season and the year please)\n");
	scanf("%s", term);
	term[0] = toupper(term[0]);
	
	strcpy(courseInput[IDcount].courseName, program);
	strcpy(courseInput[IDcount].courseCode, code);
	strcpy(courseInput[IDcount].Term, term);
	courseInput[IDcount].courseID = ++IDcount;//adds info to list
	
	return;
}
//purpose: To search the file
void searchCourseInfo()
{
	int id, menu = 0;
	char program[20];
	
	printf("Do you wish to search by courseID or course name?\n");
	printf("[1] Course ID\n[2] Course name\n");
	scanf("%d", &menu);
	
	switch(menu)
	{
		case 1:
			printf("Please enter the course ID\n");//checks id to see if id exits
			scanf("%d", &id);
			for (int i=0; i<IDcount; i++)
			{
				if(courseInput[i].courseID == id)
				{
					printf("This is the course with ID %d\n", id);
					printf("CourseID\tCourseName\tCourseCode\tTerm\n");
					printf("%-15d %-16s%-16s%s\n", courseInput[i].courseID, courseInput[i].courseName, courseInput[i].courseCode, courseInput[i].Term);
					return;
				}
			}
			printf("The course with ID %d does not exists\n");
			break;
		case 2: 
			printf("Please enter the name of the program\n");//checks if program name esits
			scanf(" %[^\n]s", program);
			for(int i=0; i<strlen(program); i++)
			{
				program[i]= toupper(program[i]);
			}
			
			for (int i=0; i<IDcount; i++)
			{
				if(!strcmp(courseInput[i].courseName, program))//compares input with file info
				{
					printf("CourseID\tCourseName\tCourseCode\tTerm\n");
					printf("%-15d %-16s%-16s%s\n", courseInput[i].courseID, courseInput[i].courseName, courseInput[i].courseCode, courseInput[i].Term);
					return;
				}
			}
			printf("%s does not exists in our database\n");
			break;
		default: printf("Invalid entry\n"); break;
	}
}