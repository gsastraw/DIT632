// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31 (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)
#include <stdlib.h>
#include <stdio.h>

// -----typedefs -------

typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)

PERSON input_record(void);             // Reads a person’s record.
void print_menu();                     // Prints menu to console
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void);                  // Prints out all persons in the file
void search_by_firstname(char *name);  // Prints out the person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file

int main(void)
{
    PERSON ppost;
    int menu_input;

    while (menu_input != '5')
    {
        //prints menu function
        print_menu();
        menu_input = getchar();

        if (10 == menu_input)
        {
            continue;
            //checks if new line and ignores
        }

        if (menu_input > 0 && menu_input < 6)
        {
            switch (menu_input)
            {
            case 1:
                // create and delete old file
                break;
            case 2:
                //add new person to file
                break;
            case 3:
                //search for person in file
                break;
            case 4:
                //print all in file
                break;
            case 5:
                //exit system
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Please choose from the options listed in the main menu.\n");
                break;
            }
        }
    }

    return (0);
}

void print_menu()
{
    printf("Enter your choice from the list below:\n");
    printf("1. Create a new and delete the old file\n");
    printf("2. Add a new person to the file\n");
    printf("3. Search for a person in the file\n");
    printf("4. Print out all in the file\n");
    printf("5. Exit the program\n");
}

void append_file(PERSON *inrecord)
{
    /**
    if (NULL == inrecord)
    {
        return NULL;
    }

    PERSON *new_record;

    new_record = (PERSON *)malloc(sizeof(PERSON));
    //set var to default value, point to 0 or NULL
    **/
}
