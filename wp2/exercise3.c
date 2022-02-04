// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31 (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILE_NAME "ex3.bin"
#define INIT '1'

// -----typedefs -------

typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
void write_new_file() {
    FILE* fp;
    fp = fopen(FILE_NAME, "wb");

    if (fp == NULL) {
        printf("COULD NOT WRITE TO FILE! INTERNAL ERROR");
        exit(0);
    } else {
        PERSON person = { "Ayyyy", "lmao", "102410241024" };
        fwrite(&person, sizeof(person), 1, fp);
        fclose(fp);
    }
    printf("DONE!");
}

PERSON input_record(void) {
    FILE* fp;
    PERSON person;

    printf("Input a first name: \n");
    fgets(person.firstname, sizeof(person.firstname), stdin);
    printf("Input your last name. \n");
    fgets(person.famname, sizeof(person.famname), stdin);
    printf("Input your personnummer:");
    fgets(person.pers_number, sizeof(person.pers_number), stdin);

    if (fopen(FILE_NAME, "rb") == NULL) {
        write_new_file();
    } else {
        fclose(fopen(FILE_NAME, "rb"));
    }

    fwrite(&person, sizeof(person), 1, fopen(FILE_NAME, "ab"));
    getchar();
    fclose(fopen(FILE_NAME, "ab"));

    printf("\nFIRST NAME: %s\n", person.firstname);
    printf("LAST NAME: %s\n", person.famname);
    printf("PERSONNUMMER: %s\n", person.pers_number);
}       

void printfile(void) {
    FILE* fp;
    PERSON person;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("COULD NOT READ TO FILE! INTERNAL ERROR!");
        exit(1);
    } else {
        fp = fopen(FILE_NAME, "rb");
        while (fread(&person, sizeof(person), 1, fp) != 0) {
            printf("First name: %s\n", person.firstname);
            printf("Last name: %s\n", person.famname);
            printf("Personnummer: %s\n", person.pers_number);
        }
        fclose(fopen(FILE_NAME, "rb"));
    }
}    

void search_by_firstname(char *name) {
    name[strcspn(name, "\r\n")] = 0;
    FILE* fileToSearch;
    fileToSearch = fopen(FILE_NAME, "rb");
    int hits = 0;
    if (fileToSearch == NULL) {
        printf("ERROR! FILE COULD NOT BE READ!");
        exit(1);
    } else {
        PERSON* pvalToRead;
        pvalToRead = malloc(sizeof(PERSON));

        while (fread(pvalToRead, sizeof(PERSON), 1, fileToSearch) == 1) {
            if (strcmp(&pvalToRead->firstname, name) == 0) {
                ++hits;
                printf("Hit! Found person with first name:\n");
                printf("%s, ", &pvalToRead->pers_number);
                printf("%s ", &pvalToRead->firstname);
                printf("%s\n", &pvalToRead->famname);
            } else if (strcmp(&pvalToRead->famname, name) == 0) {
                ++hits;
                printf("Hit! Found person with family name:\n");
                printf("%s, ", &pvalToRead->pers_number);
                printf("%s ", &pvalToRead->firstname);
                printf("%s\n", &pvalToRead->famname);
            }
        }
        if (hits == 0) {
            printf("No such person found in registry.\n");
        }
    }
    fclose(fileToSearch);
}

void append_file(PERSON* inrecord) {
    FILE* appendedFile;
    appendedFile = fopen(FILE_NAME, "ab");

    if (appendedFile != NULL) {
        // BUFFERS TO HOLD INPUT
        // 14 is needed to hold complete personal numbers in the form of yyyymmddnnnc and produces bugs if set lower.
        char pers_buf[14];
        char name_buf[20];

        printf("Enter personal number:\n");

        fgets(pers_buf, 14, stdin);
        pers_buf[strcspn(pers_buf, "\r\n")] = 0;
        strcpy(inrecord->pers_number, pers_buf);
        printf("Enter first name:\n");
        fgets(name_buf, 20, stdin);
        name_buf[strcspn(name_buf, "\r\n")] = 0;
        strcpy(inrecord->firstname, name_buf);
        printf("Enter family name:\n");
        fgets(name_buf, 20, stdin);
        name_buf[strcspn(name_buf, "\r\n")] = 0;
        strcpy(inrecord->famname, name_buf);
        fwrite(inrecord, sizeof(PERSON), 1, appendedFile);
        printf("Successful in adding person to registy, returning...\n");
    } else {
        printf("Error opening file %s.", FILE_NAME);
    }
    fclose(appendedFile);
}   

void print_menu() {
    PERSON ppost;
    int menu_input;
    char* name;
    printf("\nEnter your choice from the list below:\n");
    printf("1. Create a new and delete the old file\n");
    printf("2. Add a new person to the file\n");
    printf("3. Search for a person in the file\n");
    printf("4. Print out all in the file\n");
    printf("5. Exit the program\n");

    char input = getchar();
    getchar();

    switch(input) {
        case '1':
            write_new_file(); 
            break;
        
        case '2':
            append_file(&ppost);
            break;

        case '3':
            printf("Enter a first name or family name: \n");
            if (!fgets(&name, 50, stdin)) {
                printf("UNSUCCESSFUL READING FROM INPUT!");
                exit(1);
            } else {
                search_by_firstname(&name);
            }
            break;
        
        case '4':
            printfile();
            break;
        
        case '5':
            exit(0);
            break;
    }
}     

int main(void) {
    while (INIT) {
        print_menu();
    }
    return 0;
}