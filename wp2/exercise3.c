// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31 (2022)
// Work package 2
// Exercise 3
// Submission code: qKHW0fDS5 (provided by your TA-s)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILE_NAME "ex3.bin" // Defines the file name
#define INIT '1' // Defines a status code of '1' for initialising program

// -----typedefs -------

typedef struct {
    char firstname[20]; // First name buffer
    char famname[20]; // Last name buffer
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Writes a new file to the program
void write_new_file() {
    // Instantiate pointer to FILE 
    FILE* fp;
    // Open "ex3.bin" and write to it
    fp = fopen(FILE_NAME, "wb");

    // If program could not open the file whatsoever, then return error message and then pass off exit code. 
    if (fp == NULL) {
        printf("COULD NOT WRITE TO FILE! INTERNAL ERROR");
        exit(1);
    } else {
        // Otherwise, create dummy data with a first name, last name, and personnummer
        PERSON person = { "Ayyyy", "lmao", "102410241024" };
        // Write this person into the file
        fwrite(&person, sizeof(person), 1, fp);
        // Close the file 
        fclose(fp);
    }
    // Print confirmation that the file has been written
    printf("DONE!");
}

void printfile(void) {
    // Instantiate pointer to FILE
    FILE* fp;
    // Instantiate variable corresponding to person struct
    PERSON person;
    // Open the file with read mode
    fp = fopen(FILE_NAME, "rb");
    // If the file could not be opened, print out an error message and pass exit code of 1 = FAIL
    if (fp == NULL) {
        printf("COULD NOT READ TO FILE! INTERNAL ERROR!");
        exit(1);
    } else {
        // Else, while the file is being read and it is not EOF
        while (fread(&person, sizeof(person), 1, fp) != 0) {
            // Print out the person's first name, fam name, and personnummer
            printf("First name: %s\n", person.firstname);
            printf("Last name: %s\n", person.famname);
            printf("Personnummer: %s\n", person.pers_number);
        }
        // Close the file in read mode
        fclose(fopen(FILE_NAME, "rb"));
    }
}    

// search_by_firstname() takes a char pointer (string) which corresponds to the name in question
void search_by_firstname(char *name) {
    // Deletes any unnecessary characters within the string
    name[strcspn(name, "\r\n")] = 0;
    // Create a pointer to the file we are searching for
    FILE* fileToSearch;
    // Open the file with read mode
    fileToSearch = fopen(FILE_NAME, "rb");
    // Store number of results when looking for the file
    int hits = 0;
    // If the file could not be opened, print out error message and exit with code of 1
    if (fileToSearch == NULL) {
        printf("ERROR! FILE COULD NOT BE READ!");
        exit(1);
    } else {
        // Create a pointer to the person which corresponds to the person currently being read from the file at the moment
        PERSON* pvalToRead;
        // Allocate sufficient memory for the person variable so that data can be stored within it 
        pvalToRead = malloc(sizeof(PERSON));

        // While the file is being read and we are not at EOF...
        while (fread(pvalToRead, sizeof(PERSON), 1, fileToSearch) != 0) {
            // access the person's firstname that the pointer points to and compare to the string passed into the function
            // strcmp returns 0 if strings are equal
            if (strcmp(&pvalToRead->firstname, name) == 0) {
                // Increment hits by 1 because we've found one result
                ++hits;
                // Print the result
                printf("Hit! Found person with first name:\n");
                printf("%s, ", &pvalToRead->pers_number); // Print the personnummer that the memory address points to
                printf("%s ", &pvalToRead->firstname); // Print the first name that the memory address points to
                printf("%s\n", &pvalToRead->famname); // Print the family name that the memory address points to 
            // access the person's lastname that the pointer points to and compare to the string passed into the function
            // strcmp returns 0 if strings are equal
            } else if (strcmp(&pvalToRead->famname, name) == 0) {
                // Increment hits by 1 because we've found one result
                ++hits;
                // Print the result 
                printf("Hit! Found person with family name:\n");
                printf("%s, ", &pvalToRead->pers_number); // Print the personnummer that the memory address points to 
                printf("%s ", &pvalToRead->firstname); // Print the first name that the memory address points to 
                printf("%s\n", &pvalToRead->famname); // Print the last name that the memory address points to 
            }
        }
        // if no hits were found, print message to reflect that to the user
        if (hits == 0) {
            printf("No such person found in registry.\n");
        }
    }
    // Close the file when done printing
    fclose(fileToSearch);
}

// append_file() is meant to add a person to the file, and takes a pointer to a person as argument which will then be stored into the file.
void append_file(PERSON* inrecord) {
    // Create pointer to FILE
    FILE* appendedFile;
    // Open file with "ab" mode which corresponds to appending to the file 
    appendedFile = fopen(FILE_NAME, "ab");

    // If the file can be opened, then proceed to append person to the file
    if (appendedFile != NULL) {
        // BUFFERS TO HOLD INPUT
        char pers_buf[14]; // 14 is needed to hold complete personal numbers in the form of yyyymmddnnnc and produces bugs if set lower
        char name_buf[20]; // 20 is an arbitrary value to contain a string containing someone's name

        // Request for personnummer
        printf("Enter personal number:\n");

        // Get personnummer from user as input 
        fgets(pers_buf, 14, stdin);
        // Delete all unnecessary characters from string (sanitise value)
        pers_buf[strcspn(pers_buf, "\r\n")] = 0;
        // Copy whatever is in pers_buf and add to the pers_number in the pointer that points to the person
        strcpy(inrecord->pers_number, pers_buf);
        // Query for first name from user
        printf("Enter first name:\n");
        // Store user's first name in name_buf
        fgets(name_buf, 20, stdin);
        // Delete all unnecessary characters from string (sanitise value)
        name_buf[strcspn(name_buf, "\r\n")] = 0;
        // Copy whatever is in name_buf and add to the firstname attribute in the pointer that points to the person
        strcpy(inrecord->firstname, name_buf);
        // Query for last name from user
        printf("Enter family name:\n");
        // Store user's last name in name_buf
        fgets(name_buf, 20, stdin);
        // Delete all unnecessary characters from string (sanitise value)
        name_buf[strcspn(name_buf, "\r\n")] = 0;
        // Copy whatever is in name_buf and add to the famname attribute in the pointer that points to the person
        strcpy(inrecord->famname, name_buf);
        // Write the final result to the document
        fwrite(inrecord, sizeof(PERSON), 1, appendedFile);
        // Give confirmation that writing was successful
        printf("Successful in adding person to registy, returning...\n");
    } else {
        // Print error message that the file could not be opened whatsoever
        printf("Error opening file %s.", FILE_NAME);
    }
    // Close the file when everything is done
    fclose(appendedFile);
}   

// Print the menu
void print_menu() {
    // create person object 
    PERSON ppost;
    char* name; // Store name as string
    // Menu options
    printf("\nEnter your choice from the list below:\n");
    printf("1. Create a new and delete the old file\n");
    printf("2. Add a new person to the file\n");
    printf("3. Search for a person in the file\n");
    printf("4. Print out all in the file\n");
    printf("5. Exit the program\n");

    // Store user input in variable via getchar() which gets characters from stdin
    char input = getchar();
    // Take into account enter key in order to not break program
    getchar();

    // Behaviour of program that corresponds to menu options
    switch(input) {
        case '1':
        // Write a new file
            write_new_file(); 
            break;
        
        case '2':
        // Append a new file and pass in the memory address as a parameter to the method to allow writing to that specific memory address
            append_file(&ppost);
            break;

        case '3':
        // Search by first name 
        // Request first name or family name 
            printf("Enter a first name or family name: \n");
            // If user input was unable to be obtained, print error message with exit code of 1 
            if (!fgets(&name, 50, stdin)) {
                printf("UNSUCCESSFUL READING FROM INPUT!");
                exit(1);
            } else {
                // Search by first name if input was able to be obtained
                search_by_firstname(&name);
            }
            break;
        
        case '4':
        // Print file contents
            printfile();
            break;
        
        case '5':
        // Exit code of 0 because 5 is the exit number to end the program
            exit(0);
            break;
    }
}     

// Create infinite loop that prints menu that can only be stopped when external methods call exit(1) or return
int main(void) {
    while (INIT) {
        print_menu();
    }
    return 0;
}