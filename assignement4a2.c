/*
Emily addison
104553525
March 23rd, 2015
*/


struct CourseInfo{
 int courseID;
 char courseName[50];
 char courseCode[12];
 char Term [6];
};
typedef struct CourseInfo courseInfo; 



int main()
{
	FILE *inputfile;
	inputfile=fopen ("input.csv", "r");
}