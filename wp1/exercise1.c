// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 123 __ (2022) 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Initialise the sentences as a pointer that points to an array containing these characters (or in our case, arbitrary quotes)
const char* sentences[] = {
    "Hey there dude",
    "Hello there, friend",
    "Greetings, compadre",
    "Greetings, m'dude",
    "Salutations, fellow dude"
};

// Boolean flag is created to take user input and dictate the behavior of the while loop.
bool flag = true;

int main() {
    /*
    A variable called "buffer" is declared which stores the user's inputted text as characters. An arbitrary buffer size of 1024kb is delegated.
    1024kb is probably a lot of space for just inputting of a simple number, but we intended to make this program relatively foolproof.
    */

    char buffer[1024];
    printf("\nInput a number between 1-5 to receive a random quote!");

    /*
    After the program has prompted the user to input a number between 1-5, we use fgets() in order to obtain the number.
    The reason why we use fgets() instead of scanf() is because scanf() doesn't take into account buffer overflow. If the user inputs
    an excessive amount of characters, a buffer overflow error is thrown upon running the code. 

    fgets() takes into account this buffer overflow in the second argument to the method, which cuts out the remaining characters violating
    this buffer. 

    Therefore, we invoke fgets() and if input reading fails, a status code of 1 (error) is returned. 
    */
    if (!fgets(buffer, 1024, stdin)) {
        return 1;
    } else {
        // atoi() = All to Integer. The result from fgets() is contained in the buffer, and parses the result to an integer.
        int input = atoi(buffer);
        // If the input could not be parsed to an integer, 0 is returned from atoi.
        if (input == 0) {
            printf("\nInvalid character! Try again.");
            main();
        }
        while (flag) {
            // All cases print out sentences based on the input provided.
            switch (input) {
                case 1:
                    printf("%s", sentences[0]);
                    main();
                    break;
                
                case 2: 
                    printf("%s", sentences[1]);
                    main();
                    break;

                case 3:
                    printf("%s", sentences[2]);
                    main();
                    break;

                case 4:
                    printf("%s", sentences[3]);
                    main();
                    break;

                case 5: 
                    printf("%s", sentences[4]);
                    main();
                    break;
                
                // If the user inputs a number not between 1-5, trip up the flag to false in order to end while loop + end the program. 
                default:
                    printf("Invalid number! Must be between 1-5!");
                    flag = false;
                    break;
            }
        }
        // Program ran successfully
        return 0;
    }
    // Program ran unsuccessfully
    return 1;
} 
 