#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Method that takes in an array which stores the result of the computation, and the value which corresponds to the hexadecimal (converted to long)
// The result is a binary string.
void convertHexToBinary(int* arr, long value) {
    // Declare a variable "compare" which 
    int compare;
    // We assume the binary result will have 8 bits, so we loop from 7.
    for (int bytes = 7; bytes >= 0; bytes--) {
        // the "compare" value is bitshifted depending on the "bytes" variable
        compare = value >> bytes;
        // if both bits are 1, store "1" in arr[bytes], else store "0".
        arr[bytes] = compare & 1 ? 1 : 0;
    }
}

// Credit taken from https://stackoverflow.com/questions/12700497/how-to-concatenate-two-integers-in-c#:~:text=char%20str%5B100%5D%3B%20int,the%20number%20with%20strtol()%20.
// Given the scenario where we want to isolate specific ranges within the binary number, we have to concatenate the numbers together.
// For example, in the scenario 10100100, if we want to decipher gear_pos, we have to isolate 010 by concatenating 0 - 1 - 0 together.

// The method takes in two unsigned variables because the arguments must never be negative.
unsigned concatenateNumbers(unsigned x, unsigned y) {
    // FOR EXAMPLE, given two numbers which are 0 and 1 respectively
    // Set power to 10 because our numbers is based on 10. 
    unsigned pow = 10;
    // If the y value is greater than the actual power, then we increase the power exponentially
    while (y >= pow) {
        pow *= 10;
    }
    // Concatenate numbers together (0 * 10 + 1 = 1). This result is then intended to be converted to decimal format, in this example after conversion it would be the value of gear_pos.
    return x * pow + y;
}

// This method converts from binary to decimal format. It takes in a long value, which corresponds to the binary representation.
int convertBinaryToDec(long value) {
    int i = 0, decimal = 0;
    while (value != 0) {
        int digit = value % 10;
        decimal += digit * pow(2, i);
        value /= 10;
        i++;
    }
    return decimal;
}

int main(int argc, char* argv[]) {
    // Stores the 8 bit representation of the car values
    int result[8];
    // If arguments are not equal to 2, print an error message and return an exit code of 1 = FAIL
    if (argc != 2) {
        printf("ERROR: No arguments given!");
        return 1; 
    }
    
    // Convert from string to a long to convert to binary
    long hexToNumber = strtol(argv[1], NULL, 16);
    // Convert to binary 
    convertHexToBinary(result, hexToNumber);

    // Instantiate car variables to 0
    int engine_on = 0;
    int gear_pos = 0;
    int key_pos = 0;
    int brake1 = 0;
    int brake2 = 0;

    // If the MSB is 1, we know that corresponds to engine_on and because we already know 1 in binary is 1 in decimal format, we can skip conversions
    if (result[7] == 1) {
        engine_on++;
    }

    // Concatenate the sixth and fifth bits together to get a binary representation, and then convert from binary to decimal.
    int firstConcat = convertBinaryToDec(concatenateNumbers(result[6], result[5]));
    // Then, because gear_pos is three bits long, we have to concatenate the first result with the fourth bit and then convert from binary to decimal.
    int secondConcat = convertBinaryToDec(concatenateNumbers(firstConcat, result[4]));
    // gear_pos then equals the second concatenated value
    gear_pos = secondConcat;

    // concatenate the third and second bits together and then convert from binary to decimal to get the key_pos value
    key_pos = convertBinaryToDec(concatenateNumbers(result[3], result[2]));

    // If the second argument = 1, we know that 1 in binary is 1 in decimal format, so we just increment brake1 by 1 because second argument contains 1 bit
    if (result[1] == 1) {
        brake1++;
    }

    // If the first argument = 1, we know that 1 in binary is 1 in decimal format, so we just increment brake2 by 1 because first argument contains 1 bit
    if (result[0] == 1) {
        brake2++;
    }

    // Print out values
    printf("Name\t\tValue\n");
    printf("----------------------------\n");
    printf("engine_on\t\t%d\n", engine_on);
    printf("gear_pos\t\t%d\n", gear_pos);
    printf("key_pos\t\t\t%d\n", key_pos);
    printf("brake1\t\t\t%d\n", brake1);
    printf("brake2\t\t\t%d\n", brake2);

    // Return status code of 0. 
    return 0;
}