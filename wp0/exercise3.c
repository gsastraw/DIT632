#include <stdio.h>
#include <string.h>
/*
    The help() method just displays info as to how the user can use this program.
*/
void help() {
    printf("Ever wanted a program that greets you by name? Ayy lmao here you have it");
    printf("\nTIP: Run this program with your name as an argument.");
    printf("\ne.g: gcc -o exercise3 exercise3.c && ./exercise3 Joe");
}

int main(int argc, char *argv[]) {
    /* If there are more than 2 arguments, run the intended functionality of this program.
       The first argument is the file path of the executed C file - therefore the second is what the user inputs as argument.
    */
    if (argc == 2) {
        // If -h is inputted, invoke the help() method
        if (strcmp(argv[1], "-h") == 0) {
            help();
            return 0;
        } else {
            // Else greet the user based on the argument provided
            printf("Hello, World! - I'm %s", argv[1]);
        }
    } else {
        // Else no arguments are provided
        printf("No arguments provided!");
        help();
        return 1;
    }
}