// Assignment 04 - Solution
// This program uses string processing functions to format a comma separated values file
// of course information and store them into an array of structures. The program can add
// a new course, search for course information using name or course number, and display
// all or any course data.



#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct CourseInfo
{
	int CourseID;
	char courseName[50];
	char courseCode[12];
	char Term[6];
};
typedef struct CourseInfo Course;


Course courses[100];
int courseCount = 0;
char cName[50];
char cCode[12];
char term[6];



void loadCourseInfo();
void displayCourseInfo();
void searchCourseInfo(int);
void addNewCourse();

// Main

int main ()
{
	int user;

	loadCourseInfo();

	do {
		printf("\n\nSelect an option from the menu:\n");
	printf("1. Add a new course\n");
	printf("2. Search for a course by course ID\n");
	printf("3. Search for a course by course Name\n");
	printf("4. Display course data\n");
	printf("5. Exit\n->");		// function call to display the menu
		scanf("%d", &user);
		while (user<1 || user>5)
		{
			printf("\n%d is not a valid input, please select a option between 1 and 5\n", user);
			scanf("%d", &user);
		}

		if (user == 1)
			addNewCourse();
		else if (user == 2)
			searchCourseInfo(1);
		else if (user == 3)
			searchCourseInfo(2);
		else if (user == 4)
			displayCourseInfo();

	} while (user != 5);

return 0;
} // End of main.

// Function: loadCourseInfo
// Purpose: Reads all the data from input file and format and store them in an array of
//			structures.
// Input: no parameters for this function
// Output: void, no output.

void loadCourseInfo()
{
	char *token;
	FILE *inputfile;
	char line[100];
	char courseName[50];
	char courseCode[12];
	char term[6];
	int d = 0;

	inputfile = fopen("input.csv","r"); 	// Open . file in read mode

	while (fscanf (inputfile, "%s\n", line) != EOF)
	{

// split into tokens, with "," as the delimiter, and store the tokens into the structure items

		token = strtok(line, ",");

		while(token != NULL)
		{
				if(d==0)
				
					strcpy(courseName, token);
					
				else if(d==1){
					strcpy(courseCode,token);
				}
				else if(d==2){
					strcat(courseCode,token);
					strcat(courseCode,"-");
				}
				else if(d==3){
					strcat(courseCode,token);
					strcat(courseCode,"-");
				}
				else if(d==4){	
					strcat(courseCode,token);
				}
				else if(d==5){
					strcpy(term, token);
				}
				else if(d==6){
					strcat(term, token);
				}
			
			d++;
			token = strtok(NULL, ",");
		}
		d=0;	// must re-initialize d

		
		
		
		
	for (int k = 0; k < strlen(cName); k++)
	{
		cName[k] = toupper(cName[k]); // store course name in uppercase
	}
	//course count is a global variable
	strcpy(courses[courseCount].courseName, cName);
	strcpy(courses[courseCount].courseCode, cCode);
	strcpy(courses[courseCount].Term, term);
	courseCount++;
	courses[courseCount].CourseID = courseCount;
		
	}
	fclose(inputfile); 	// close file!

} 

//Function: displayCourseInfo
// Purpose: Prints a table indicating the course information.
// Input: no parameters for this function
// Output: void, no return

void displayCourseInfo()
{
	

	printf("ID\tName\t\tCode\t\tTerm\n\n");

	for (int i = 0; i < courseCount; i ++)
	{
			printf("%-8d", (courses[i].CourseID)+1);
			printf("%-16s", courses[i].courseName);
			printf("%-16s", courses[i].courseCode);
			printf("%s", courses[i].Term);
			printf("\n");
	}
	printf("\n");
} // End of displayCourseInfo.



// Function: searchCourseInfo
// Purpose: To search for a course information using courseID or course Name and print the course
// 			information is it exists.
// Input: menu option
// Output: void, no return.

void searchCourseInfo(int user)
{
	int i, j, m;
	int searchI;
	char searchN[50];
	int foundName = 0;

//  searching by course ID
	if (user == 1) {

		printf("\nPlease enter the course ID you wish to look for.\n->   ");
		scanf("%d", &searchI);
		printf("\nResults:\n\n");

		if(searchI <= courseCount)
		{
			printf("%-8d", searchI);

			for (j = 0; j < strlen(courses[searchI-1].courseName); j++)
			{
				courses[searchI-1].courseName[j] = toupper(courses[searchI-1].courseName[j]);
			}

			printf("%-16s", courses[searchI-1].courseName);
			printf("%-16s", courses[searchI-1].courseCode);
			printf("%s\n", courses[searchI-1].Term);
		}
		else
		{
			printf("Course ID %d was not found.\n", searchI);
		}

	}

// searching by course name
	else {

		printf("\nPlease enter the course name you wish to search for.\n->   ");
		scanf("%s", searchN);

		for (j = 0; j < strlen(searchN); j++)
			searchN[j] = toupper(searchN[j]); // convert to uppercase

		printf("\nResults:\n");

		for (i = 0; i < courseCount; i ++)
		{
			if (strcmp(courses[i].courseName, searchN) == 0)
			{

				printf("%-8d", (courses[i].CourseID)+1);

				for (m = 0; m < strlen(courses[m].courseName); m++)
				{
					courses[i].courseName[m] = toupper(courses[i].courseName[m]);
				}

				printf("%-16s", courses[i].courseName);
				printf("%-16s", courses[i].courseCode);
				printf("%s", courses[i].Term);
				printf("\n");

				foundName++;
			}
		}

		if (foundName == 0)
		{
		printf("%s course was not found.\n", searchN);
		}
	}
} // End of searchCourseInfo.

// Function: addNewCourse
// Purpose: To read new course information from the user and store in structure
// Input: user input
// Output: void

void addNewCourse()
{
	char courseName[50];
	char courseCode[12];
	char term[6];
	char faculty[2];
	char subject[2];
	char level[3]; 
	char section[2];
	char semester[1];
	char year[4];
	int i, foundCode=0;

// scan from user, and store each element 

	printf("\nPlease enter the Course Name you wish to add -> ");
	scanf("%s", courseName);
	getchar();
			
	printf("Please enter the Course Faculty code (format xx) ->  ");
	scanf("%s", faculty);
	getchar();
	
	printf("Please enter the Course Subject code (format xx) ->  ");
	scanf("%s", subject);
	getchar();

	printf("Please enter the Course Level code (format xxx) ->  ");
	scanf("%s", level);	
	getchar();	
			
	printf("Please enter the Course Section code (format xx) ->  ");
	scanf("%s", section);
	getchar();

// create course code
	strcpy(courseCode, faculty);
	strcat(courseCode, subject);
	strcat(courseCode,"-");
	strcat(courseCode, level);
	strcat(courseCode,"-");
	strcat(courseCode, section);
	
// search for course code. check for duplicate.
	for (i = 0; i < courseCount; i ++)
	{ 
		if (strcmp(courses[i].courseCode, courseCode) == 0)
			foundCode++;	
	}
	if (foundCode > 0)
	{
		printf("A duplicate Course Code was found.\n");		
		return;
	}
			
	printf("Please enter the Course Semester (S, F or W) ->  ");
	scanf("%s", semester);
	getchar();
	semester[0] = toupper(semester[0]);

	printf("Please enter the Course Year (format yyyy) ->  ");
	scanf("%s", year);			
	getchar();
	
// create term
	strcpy(term, semester);
	strcat(term, year);
	
	//char cName[50];
	//char cCode[12];
	//char term[6];
	
	//addCourseInfo(courseName,courseCode,term);	
	
	for (int k = 0; k < strlen(cName); k++)
	{
			cName[k] = toupper(cName[k]); // store course name in uppercase
	}
	//course count is a global variable
	strcpy(courses[courseCount].courseName, cName);
	strcpy(courses[courseCount].courseCode, cCode);
	strcpy(courses[courseCount].Term, term);
	courseCount++;
	courses[courseCount].CourseID = courseCount;
}


