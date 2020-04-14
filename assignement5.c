/*
Emily Addison
104553524
March29th,2017
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct CourseInfo{
 int courseID;
 char courseName[30];
};
struct studentInfo{ //student info structure to organize the student infor from the list
char StudentId[9];
char FirstName[20];
char LastName[25];
int Courses;
char CourseInfo[10];
//struct studentInfo *next;

}; typedef struct studentInfo StudentInfo;
struct Node{ //structure for the node to pass the linked list onward
	StudentInfo Data; 
	struct Node *next;
}; typedef struct Node node;

node *NewNode, *Node, *Root, *Temp; //global variables for node structure
int StudentInfosize = sizeof(StudentInfo);
int nodeSize = sizeof(node);

void loadStudentinfo();
void displayStudentInfo(node *Root);
int searchStudentID(char *searchID);
void searchStudentName(char *name);
int addStudent();
int deleteStudent(char *enterID)
void saveStudentInfo(FILE *input2);
int main()
{
	loadStudentinfo(); //load student info from the file into a linked list 
	int user;
	printf("Select what you would like to do\n"); //ask for user input
	printf("1:Add new student\n");
	printf("2:Delete a student\n");
	printf("3:Search for a student\n");
	printf("4:Display current students\n");
	printf("5:Save student information to file\n");
	printf("6:Exit\n");
	scanf("%d",&user);
	
	switch (user) //switch case to decide which user input to allocate which function to call upon
	{
		case 1: addStudent (); break;
		case 2: deleteStudent(enterID); break;
		case 3: searchStudentID(searchID); 
				searchStudentlName(name)
				break;
		case 4: displayStudentInfo(Root); break;
		case 5: saveStudentInfo(input2);
				fclose(inputfile);
				FILE *input2;
				input2 = fopen("studentList.txt", "wb");
				saveStudentInfo(input2);
				fclose(input2);
				FILE *inputfile = fopen("studentList.txt", "r");
				break;
		case 6: exit();
				fclose(input);
				//FILE *input2;
				input2 = fopen("studentList.txt", "wb");
				saveStudentInfo(input2);
				fclose(input2);
				done=1;
				break;
				return 0;
		
	}
	
	return user;
	
}
//Purpose: To load student info from the text file into a linked list 

void loadStudentinfo()
{
	//node *NewNode, *Node, *Root, *Temp;
	//int StudentInfosize = sizeof(StudentInfo);
	//int nodeSize = sizeof(node);
	FILE *inputfile;
	inputfile = fopen("studentList.txt","rb"); //open a read only file 
	Root = malloc(nodeSize); //set the head of the file to the memory allocation of the nodesize variable
	fread(Root,StudentInfosize,1,inputfile); //file read the begining, studentinfosize variable, and inputfile file
	Root->next = NULL;//sets the next after the beginning to null
	Node = Root;//sets node to begining
	while (! feof (inputfile)){ //while it is not the end of the file 
		NewNode = malloc(nodeSize);//set the new node to the memory allocation of the nodesize 
		fread(NewNode, StudentInfosize,1,inputfile);//file read the new node, the studentinputsize variable and inputfile 
		NewNode->next = NULL;//set new node to next equal to null
		Node->next = NewNode; //set node to next equal to null
		Node = NewNode;//set node equal to new node
	}
	fclose(inputfile);//close the file 
}

//Purpose: Display the info from the file 
//Input: Begining of file or linked list
void displayStudentInfo(node *Root)
{
	Node = Root; //set node equal to begining of linked list 
	while(Node!=NULL){ //while node is not equal to null
		
		printf("ID = %d,Name = %s %s, Course = %f\n", Node->Data.StudentId,Node->Data.FirstName,Node->Data.LastName,Node->Data.Courses); //print info
		Node = Node->next; //set node equal to next node
	}
	
	
}
//purpose: To search for a student in the file
int searchStudentID(char *searchID){
	int intSearchID = atoi(searchID);
	int intStudentID;
	StudentInfo*NewNode = Root;//set node equal to the begining of the list
	while(NewNode->next != NULL){//while list is not empty 
		intStudentID = atoi(NewNode->StudentID);
		if (intStudentID==intSearchID)//if the student id entered equals one in the file return 1 
			return 1;
		NewNode = NewNode->next;
	}
	if (intStudentID==intSearchID)
			return 1;
	return 0;//else return 0
}
//purpose: To search for a student name 
void searchStudentName(char *name){
	StudentInfo*NewNode = Root;
	if (name[0]!=toupper(name[0]))//change to capital in order to match list 
		name[0] = toupper(name[0]);
	
	while(NewNode->next!= NULL){//while list is not null
		if(!strcmp(name, NewNode->LastName)){
			printf("%s\n%s\n%s\n%d\n", NewNode->StudentID,NewNode->FirstName,NewNode->LastName,NewNode->numCourses);//check to see if name mathcehs any in file
			for (int i=0;i< NewNode->numCourses;i++)
				printf("%s %d\n", NewNode->cinfo[i].courseName, NewNode->cinfo[i].courseID);
		}
		NewNode = NewNode->next;//continue going through list 
	}
	if(!strcmp(name, NewNode->LastName)){
		printf("%s\n%s\n%s\n%d\n", NewNode->StudentID,NewNode->FirstName,NewNode->LastName,NewNode->numCourses);
		for (int i=0;i< NewNode->numCourses;i++)
			printf("%s %d\n", NewNode->cinfo[i].courseName, NewNode->cinfo[i].courseID);
	}
}
//Purpose: add a new student to file
int addStudent(){
	int intID, intStructID;
	char name[256], id[10];
	StudentInfo* NewNode = (StudentInfo*)malloc(sizeof(StudentInfo));
	
	printf("Student ID: ");//enter student id
	scanf("%s", id);
	if(searchStudentID(id)){
		printf("Student ID must be unique.");
		return 0;
	}
	strcpy(NewNode->StudentID, id);
	
	printf("First Name: ");//enter student name 
	scanf("%s", name);
	name[0] = toupper(name[0]);change to capital 
	strcpy(NewNode->FirstName, name);//move into file
	strcpy(name, "");
	
	printf("Last Name: ");//enter student last name
	scanf("%s", name);
	name[0] = toupper(name[0]);//change to capital 
	strcpy(NewNode->LastName, name);//move into file
	strcpy(name, "");
	
	printf("Number of courses: ");//add courses 
	scanf("%d", &NewNode>numCourses);
	
	for(int i=0;i< NewNode->numCourses; i++){//add course id and name 
		printf("Course ID: ");
		scanf("%d", &NewNode->cinfo[i].courseID);
		printf("Course Name: ");
		scanf("%s", NewNode->cinfo[i].courseName);
	}
	NewNode intID = atoi(NewNode->StudentID);
	StudentInfo *net, *prev;
	net = Root;
	prev = NULL;
	int i=0;
	
	while(net->next != NULL){
		intStructID = atoi(net->StudentID);
		if (intStructID>intID){
			if(i==0){
				NewNode->next = Root; //creating tempoary variables to set new nodes to the proper spots in the list
				Root = NewNode;
				return 0;
			}
			else{
				prev->next = NewNode;
				NewNode->next = net;
				return 0;
			}
		}
		else{
			prev = net;
			net = net->next;
		}
		i++;
	}
	intStructID = atoi(net->StudentID);
	if (intStructID>intID){
		prev->next = NewNode;
		NewNode->next = NULL;
		return 0;
	}
	else if (intStructID<intID){
		net->next = NewNode;
		return 0;
	}
	
	return 0;
}
//Purpose: to delete a student from the file
int deleteStudent(char *enterID){
	int intEnterID = atoi(enterID), i=0, intStudentID;
	StudentInfo*net, *prev;
	net = Root; //using temp variables as to not lose the linked nodes in the list
	prev = NULL;
	
	while(net->next != NULL){//loop through to find node to delete and delete 
		intStudentID = atoi(net->StudentID);
		if (intStudentID==intEnterID){
			if(i==0){
				Root = net->next;//continues looping
				return 0;
			}
			else{
				prev->next = net->next;
				free(net);//frees memory stored in the net pointer 
				return 0;
			}
		}
		prev = net;
		net = net->next;//resets variables
		i++;
	}
	intStudentID = atoi(net->StudentID);
	if (intStudentID==intEnterID){//checks if equal to user id entered 
		prev->next = NULL;
		free(net);//frees memory in net 
	}
	

}
//Purpose: to save student info into a new file
void saveStudentInfo(FILE *input2){
	StudentInfo *NewNode=Root;//start at begining of list 
	while(NewNode->next !=NULL){
		fprintf(input2, "%s\n%s\n%s\n%d\n", NewNode->StudentID,NewNode->FirstName,NewNode->LastName,NewNode->numCourses);//use fprint to print into the file stated
		for (int i=0;i< NewNode->numCourses;i++)
			fprintf(input2, "%s %d\n",NewNode->cinfo[i].courseName, NewNode->cinfo[i].courseID);
		NewNode = NewNode->next;
	}
	fprintf(input2, "%s\n%s\n%s\n%d\n", NewNode->StudentID,NewNode->FirstName,NewNode->LastName,NewNode->numCourses);//use fprint to print 
	for (int i=0;i< NewNode>numCourses;i++)
		fprintf(input2, "%s %d\n", NewNode->cinfo[i].courseName, NewNode->cinfo[i].courseID);
	fprintf(input2, "***");//print astricks at end of file 
}



 