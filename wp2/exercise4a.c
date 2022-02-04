#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Declare an unsigned char variable (corresponding to a byte)
    unsigned char value = 0;

    // Check if arguments are equal to five, if not, print an error message.
    if (argc != 6) {
        printf("ERROR: You need only five arguments.");
        return 1;
    }

    // Check if first argument is within range of 0-1. Atoi (all to integer) is used to parse the argument as an integer.
    if (!(atoi(argv[1]) >= 0 && atoi(argv[1]) <= 1)) {
        printf("ERROR: Your first argument is not in the range of 0-1!");
        return 1;
    }

    // Check if first argument is within range of 0-4. Atoi (all to integer) is used to parse the argument as an integer.
    if (!(atoi(argv[2]) >= 0 && atoi(argv[2]) <= 4)) {
        printf("ERROR: Your second argument is not in the range of 0-4!");
        return 1;
    }

    // Check if first argument is within range of 0-2. Atoi (all to integer) is used to parse the argument as an integer.
    if (!(atoi(argv[3]) >= 0 && atoi(argv[3]) <= 2)) {
        printf("ERROR: Your third argument is not in the range of 0-2!");
        return 1;
    }

    // Check if first argument is within range of 0-1. Atoi (all to integer) is used to parse the argument as an integer.
    if (!(atoi(argv[4]) >= 0 && atoi(argv[4]) <= 1)) {
        printf("ERROR: Your fourth argument is not in the range of 0-1!");
        return 1;
    }

    // Check if first argument is within range of 0-1. Atoi (all to integer) is used to parse the argument as an integer.
    if (!(atoi(argv[5]) >= 0 && atoi(argv[5]) <= 1)) {
        printf("ERROR: Your fifth argument is not in the range of 0-1!");
        return 1;
    }

    // Whenever we shift left, '0' bits are inserted on the right end based off how many places are shifted.
    // We increment the value by the appropriate bitshifted argument to give us our hexadecimal representation.
    
    value += atoi(argv[1]) << 7; // Here, we shift the first argument by seven bits.  
    value += atoi(argv[2]) << 4; // Here, we subtract by three (7 - 3 = 4 bits shifted) which corresponds to the number of bits to represent the second argument in bits.
    value += atoi(argv[3]) << 2; // Here, we subtract by two (4 - 2 = 2 bits shifted) which corresponds to the number of bits to represent the third argument in bits.
    value += atoi(argv[4]) << 1; // Here, we subtract by one (2 - 1 = 1 bit shifted) which corresponds to the number of bits to represent the fourth argument in bits.
    value += atoi(argv[5]); // Here, we can just increment the result by the fifth argument because we don't need to shift anymore (1 - 1 = 0), it corresponds to the LSB.

    // Print out the unique code in hexadecimal format, the capital X ensures it is in capitals.
    printf("\nYour unique code is: %2X\n", value);
    // Return 0 as exit code = OK
    return 0;
}
