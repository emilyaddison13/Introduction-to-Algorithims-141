/*
Emily Addison
104553525
March 29th, 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student { //structure for students 
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;
//Function prototypes 
int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
void printListRR(Student *List);
void searchList(Student *List);

int main() {
    int choice = 0;
    Student *SLIST = NULL; //set student list equal to null

    choice = getChoice();

    while(choice >= 0) {
        switch(choice) {
            case 0 : printf("Exit\n"); exit(0);
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }

    if(SLIST) free(SLIST);
    return 0;
}
//Purpose: To get users choice
int getChoice() {
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Add a student to list.\n");
    printf("2. Print the list, beginning to end.\n");
    printf("3. Print the student list starting from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);//ask user for choice and scan choice 

    return choice;
}
//Purpose: Add a student to the list 
Student *addToList(Student *List) {

    Student *aStudent = (Student *) malloc(sizeof(Student)); //set function equal to the memory allocation of the size of the student structure 

    printf("Enter student's ID: ");//ask for user input
    scanf("%d", &(aStudent->ID));
    printf("Enter student's name: ");
    scanf(" %[^\n]s", aStudent->name);
	
	aStudent->next = NULL;
    if (List == NULL) return aStudent; //if the list is null return pointer 

    Student *tStudent = List; //set pointer equal to a list 

    while(tStudent->next != NULL) //while the next element in the list is not empty 
        tStudent = tStudent->next;//continue moving through the list 

    tStudent->next = aStudent; //

    return List;//return the list 
}
//Purpose: Print the student info
//Input: Student list
void printList(Student *List) {
    while(List != NULL) { //while list is not empty 
        printf("%d %s\n", List->ID, List->name);//print student info 
		List = List->next;
		}
    
	return;
}
//Purpose: Prints the list of students andinfo recursivly
//Input: student list 
void printListRR(Student *List) {
    if(List == NULL) return;//if list is empty return null
    printListRR(List->next);//if not empr=ty run through list
    printf("%d %s\n", List->ID, List->name);//prunt list recursivly 
}

//Purpose: Seach the list for a student 
//Input: Student list pointer 
void searchList(Student *List) {
    int s;
    printf("Enter student's ID: "); //Enter the students ID
    scanf("%d", &s);

    while(List != NULL) { //while the list is null
        if(List->ID == s){ //If the list number is equal to the ID entered 
            printf("%d %s\n", List->ID, List->name); //Then it will return the list id and the student name 
            return;
        }
        List = List->next;// if not equal search continues 
    }
    printf("ID %d not found", s); //if not found this is printed 
}