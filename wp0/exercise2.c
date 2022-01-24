// (C) __Your names here, group: 123 __ (2022) 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h>
/*
    Here is how you print Hello World with arguments...

    @params:
        int argc = (number of arguments)
        char *argv[] = (an array of pointers that contains String arguments passed to program via CLI)
    
    Returns an int (exit code).
*/

int main(int argc, char * argv[]) {
   printf("Hello, World! - I'm %s", argv[1]);
   return 0;
}