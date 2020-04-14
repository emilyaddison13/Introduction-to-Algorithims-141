#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct CourseInfo{
 int courseID;
 char courseName[30];
};
struct studentInfo{
char StudentId[9];
char FirstName[20];
char LastName[25];
int Courses;
char CourseInfo[10];
//struct studentInfo *next;

}; typedef struct studentInfo StudentInfo;
struct Node{
	StudentInfo Data; 
	struct Node *next;
}; typedef struct Node node;

node *NewNode, *Node, *Root, *Temp;
	int StudentInfosize = sizeof(StudentInfo);
	int nodeSize = sizeof(node);

void loadStudentinfo();
void displayStudentInfo();
int main()
{
	loadStudentinfo();
	int user;
	printf("Select what you would like to do\n");
	printf("1:Add new student\n");
	printf("2:Delete a student\n");
	printf("3:Search for a student\n");
	printf("4:Display current students\n");
	printf("5:Save student information to file\n");
	printf("6:Exit\n");
	scanf("%d",&user);
	
	switch (user)
	{
		//case 1: addStudent (); break;
		//case 2: deleteStudent(); break;
		//case 3: searchStudentID(); 
				//searchStudentlName()
				//break;
		case 4: displayStudentInfo(); break;
		//case 5: saveStudentInfo(); break;
		//case 6: exit(); break;
	}
	return user;
	
}

void loadStudentinfo()
{
	
	FILE *inputfile;
	inputfile = fopen("studentList.txt","r");
	Root = malloc(nodeSize);
	fread(Root,StudentInfosize,1,inputfile);
	Root->next = NULL;
	Node = Root;
	while (! feof (inputfile)){
		NewNode = malloc(nodeSize);
		fread(NewNode, StudentInfosize,1,inputfile);
		NewNode->next=NULL;
		
		NewNode->next = NewNode;
		Node = NewNode;
	}
	fclose(inputfile);
}
void displayStudentInfo()
{
	Node = Root;
	while(Node!=NULL){
		printf("%s %s %s %d\n", Node->Data.StudentId,Node->Data.FirstName,Node->Data.LastName,Node->Data.Courses);
		Node = Node->next;
	}
}
