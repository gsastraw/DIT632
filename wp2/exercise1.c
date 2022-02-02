// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31 (2022) 
// Work package 1 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ##### Given in assignment brief   #####
enum DIRECTION
{
    N,
    E,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

// ##### Functions  #####
void move(ROBOT *robot) /*function to move robot forward given the user input and based on where the robot is currently facing*/
{
    if (robot->dir == 'N')
    {
        robot->ypos++;
    }
    else if (robot->dir == 'E')
    {
        robot->xpos++;
    }
    else if (robot->dir == 'S')
    {
        robot->ypos--;
    }
    else if (robot->dir == 'W')
    {
        robot->xpos--;
    }
}

void turn(ROBOT *robot) /*function to turn robot 90 degrees cockwise and update the direction it's currently facing*/
{
    if (robot->dir == 'N')
    {
        robot->dir = 'E';
    }
    else if (robot->dir == 'E')
    {
        robot->dir = 'S';
    }
    else if (robot->dir == 'S')
    {
        robot->dir = 'W';
    }
    else if (robot->dir == 'W')
    {
        robot->dir = 'N';
    }
}

// #####   Main Program   #####
int main(void)
{
    ROBOT *robot; //initialize pointer *robot of type ROBOT
    char coordinates[10]; //variable to store user inputted coordinates
    char userInput[1024]; //variable to store 'move' and 'turn' inputs
    bool invalidcoord = true; //boolean for while loop
    bool invalidmove = true; //boolean for while loop
    bool cont = true; //boolean for while loop
    robot->dir = 'N'; //Initially setting direction of robot to North, given the assignment brief
    do
    {
        do
        {
            printf("\nPlease input X starting coordinate\n");
            fgets(coordinates, 10, stdin); //reading user input and storing in variable
            int xcoord = atoi(coordinates); // If the input could not be parsed to an integer, 0 is returned from atoi.
            if (xcoord == 0) //therefore if xcoord is 0 it is an invalid character
            {
                printf("\nInvalid character! Try again.\n");
            }
            else
            {
                robot->xpos = xcoord; //setting the position on x axis 
                invalidcoord = false; //allowing to get out of loop
            }
        } while (invalidcoord);

        do //new loop so user wont have to redo both coordinates inputs
        {
            printf("\nPlease input Y starting coordinate\n");
            fgets(coordinates, 10, stdin);
            int ycoord = atoi(coordinates); // If the input could not be parsed to an integer, 0 is returned from atoi.
            if (ycoord == 0) //therefore if ycoord is 0 it is an invalid character
            {
                printf("\nInvalid character! Try again.\n");
                invalidcoord = true; //Will let user input only y again
            }
            else
            {
                robot->ypos = ycoord;//setting the position on y axis
                invalidcoord = false; //allowing to get out of loop
            }
        } while (invalidcoord); //condition to break loop

        printf("\n Your current position is %d,%d facing %c\n ", robot->xpos, robot->ypos, robot->dir);

        do
        {
            printf("\n Please input desired movement for robot. \n M=Move forward \n T=Turn 90 degrees clockwise\n");
            fgets(userInput, 1024, stdin);
            if (!(*userInput == 'M' || *userInput == 'm' || *userInput == 'T' || *userInput == 't')) //Grouped condition to check valid input
            {
                printf("\nInvalid character! Only 'm' and 't' are allowed. Try again.\n");
                //Since invalidmove is originally set to true, loop continues and user is allowed to input again
            }
            else
            {
                int len = strlen(userInput); //gets the length of the string input
                for (int i = 0; i < len - 1; i++) //for each valid character in userInput - newline
                {
                    if (userInput[i] == 't' || userInput[i] == 'T')
                    {
                        turn(robot); //call turn function
                        invalidmove = false; //gets out of do while loop
                    }
                    else if (userInput[i] == 'm' || userInput[i] == 'M')
                    {
                        move(robot); //call move function
                        invalidmove = false; //gets out of do while loop
                    }
                }
            }
        } while (invalidmove); //loop if user has not inputted valid characters
        printf("\n Your current position is %d,%d facing %c\n ", robot->xpos, robot->ypos, robot->dir);

        printf("\n Q=Quit or hit enter to continue\n");
        int c = getchar();
        if (c == 'Q' || c == 'q')
        {
            cont = false; //changes boolean to quit program
        }

    } while (cont); //Program will loop until boolean is changed from user input
    return 0;
}