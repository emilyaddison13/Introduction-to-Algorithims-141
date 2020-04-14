/*
Emily Addison
104553525
Febuary 12th, 2017
Assignment 2
*/
#include<string.h> //Including libraries 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define R 12 //defining the array paramaters
#define C 12

#define DOWN 	0 //defining the positioning 
#define RIGHT 	1
#define UP 		2
#define LEFT	3
void mazeTraversal();// Establishing function paramaters
void printArray();
int validMove();
int coordsAreEdge();
void findStart();



int str_X, str_Y; //creating global variables

//Purpose: Main function, runs all other functions in proper order, heart of the program
//Input: An Array 
//Output: A printed Array maze
int main(void)
{
	char maze[R][C]={{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
					 {'1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
					 {'0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
					 {'1', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
					 {'1', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
					 {'1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
					 {'1', '0', '0', '1', '0', '1', '0', '0', '0', '1', '0', '1'},
					 {'1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
					 {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
					 {'1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
					 {'1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
					 {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};
	 
	findStart(maze);
	mazeTraversal(maze, str_X, str_Y, RIGHT);
}


//Purpose: To find the begining location for the maze to begining
void findStart(char maze[][C])
{
	str_Y=0;
	for(int i=0; i<12; i++)
	{
		if (maze[i][str_Y]=='0')
		{
			str_X=i;
			break;
		}
	}
}

//Purpose: To print the array each time the user hits enter
void printArray(char maze[R][C])

{
	char space;
	//For loop for coloumns 
	for (int i=0;i<12;i++)						
	{	
		//For loop for rows
		for (int j=0; j<12; j++)					
		{
			printf("%*c", 2, maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//Asks user to hit enter for the next move to appear 
	printf("Press enter to see next move\n");
	scanf("%c", &space);
}

//Purpose: Allows the 'x' to travel through the maze, checking for the proper position 
void mazeTraversal(char maze[R][C], int i, int j, int amove)
{
	int point=0;
	int move, count;
	maze[i][j] = 'X';
	printArray(maze);
	
	//Checks to see if the x has hit the edge of the maze 
	if(coordsAreEdge(i, j)&& i!=str_X && j!=str_Y){
		printf("The maze is Complete!!!\n");
		return;
	}
	//Checks to see if the x has hit a point that is not allowed and would send it back to the begining
	else if(i== str_X && j==str_Y && point==1){
		printf("Back to start");
		return;
	}
	else
	{
		
		point=1;
		//Sends it through a for loop to check if the x should be moved up, down, left or right
		for(int num=0, move=amove; num<4; ++move, ++num, move%=4)
		{
			switch(move)
			{
				case DOWN:
				//runs throught the validMove file to check where the i and j are, row and column 
					if(validMove(maze, i+1, j))
					{
						mazeTraversal(maze,i+1, j, LEFT);
						return;
					}
					break;
				case UP:
					if(validMove(maze, i-1, j))
					{
						mazeTraversal(maze, i-1, j, RIGHT);
						return;
					}
					break;
				case RIGHT:
					if(validMove(maze, i, j+1))
					{
						mazeTraversal(maze, i, j+1, DOWN);
						return;
					}
					break;
				case LEFT:
					if(validMove(maze, i, j-1))
					{
						mazeTraversal(maze, i , j-1, UP);
						return;
					}
					break;
			}
		}
		
	}
}


//Purpose: To check if the move the program chooses if a move that is allowed
int validMove(const char maze[R][C], int i, int j)
{	
	return(i>=0 && i<=11 && j>=0 && j<=11 && maze[i][j] != '1');
}
//purpose: To check if the x has hit the edge of the array 
int coordsAreEdge(int i,int j)
{
	int side;
	if((i == 0 || i==11)&&(j>=0||j<=11))
		side = 1;
	else if((j == 0 || j==11)&&(i>=0||i<=11))
		side =1;
	else 
		side=0;
	return side;
}





