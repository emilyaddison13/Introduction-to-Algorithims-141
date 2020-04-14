/*
Emily Addison
104553525
March 21st,2017
*/



#include<stdio.h>

struct employee {
char firstname[40];
char lastname[40];
int id;
int GPA;
};
typedef struct employee Employee;




 int main ()
 {
	 
	FILE *outputfile = NULL;
	outputfile=fopen (“employee.dat”, “wb”);
	Employee EmpList[3];
	InputEmpRecord(EmpList);
	//PrintEmpList(EmpList);
	//SaveEmpList(EmpList, "employee.dat");
	fclose(outfile);
	return 0;
 }
 
 /* Input the employee data interactively from the keyboard */

void InputEmpRecord(Employee *EmpList)
{
	for(int i =0;i<4;i++)
	printf("Enter your first name: \n");
	printf("Enter your last name: \n");
	printf("Enter your student ID: \n");
	printf("Enter your GPA: \n");
	scanf("%s%s%d%d",&Employee[i].firstname,&Employee[i].lastname,Employee[i].id,Employee[i].GPA);
	
}


/* Display the contents of Employee records from the list */

//void PrintEmpList(const Employee *EmpList)



/* Save the employee records from the list to the newly created text
file specified by FileName */
//void SaveEmpList(const Employee *EmpList, const char *FileName)





