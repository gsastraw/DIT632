#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX_BITS 64

void print_help()
{
    printf("Usage: dec2bin.exe <decimal number>\n");
    printf("Input must be under 19 digits.\n");
    //print how many digits is needed for long -> upper limit
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        print_help();
        return 2;
    }

    if ((argv[1][0] == '-') && (argv[1][1] == 'h' || argv[1][1] == 'H'))
    {
        print_help();
        return 2;
    }

    //max_bits + 1, in order to know when to terminate string
    unsigned char bit_handler[MAX_BITS];

    //find length of string and make sure less than 64
    //iterate over string and check if each value is 0 or 1
    int cursor = 0;
    while (argv[1][cursor] > 0)
    {
        //bit handler will be an array of bits instead of string to make for easier mathematical compuatation
        //if the elements of the array are not 0 or 1 then break out with error
        if (argv[1][cursor] == '0')
        {
            //set value of corresponding position in bit handler to an actual 0
            bit_handler[cursor] = 0;
            //printf("pars: cursor = %d, char = 0\n", cursor);
            //convert char 0 to value 0
            //assign value to bit position in bit handler
            //if char val isnt 0 or 1, return error and leave
        }
        else if (argv[1][cursor] == '1')
        {
            bit_handler[cursor] = 1;
            //printf("pars: cursor = %d, char = 1, array = %d\n", cursor, bit_handler[cursor]);
        }
        else
        {
            //argv is neither 0 or 1
            //throw error and exit function
            printf("Error: input must be comprised of 0s or 1s\n");
            print_help();
            return 2;
        }

        cursor++;

        if (cursor > (MAX_BITS - 1))
        {
            printf("Error: input has too many digits.\n");
            print_help();
            return 2;
        }
    }

    unsigned long converted = 0;

    //iterate through bit_handler array, from right to left, and compute the decimal value of each bit
    for (int i = 0; i < cursor; i++)
    {
        //2^(zero based position)* bit value
        //cursor 0 i is last byte of bit handler
        converted += pow(2, i) * bit_handler[cursor - i - 1];
        //printf("cnv: cursor = %d, index = %d, char = %d\n", i, cursor - i - 1, bit_handler[cursor - i - 1]);
        //count from right
    }
    //converted now contains the decimal value of the bits

    //printf("%ld binary\n", converted);

    unsigned char char_max = 0;
    unsigned short short_max = 0;
    unsigned int int_max = 0;
    unsigned long long_max = 0;

    char_max--;
    short_max--;
    int_max--;
    long_max--;

    //maximum number of bytes needed to contain the value
    int j = 0;
    //every byte is 2 nibbles
    if (converted < char_max)
    {
        j = 1;
    }
    else if (converted < short_max)
    {
        j = 2;
    }
    else if (converted < int_max)
    {
        j = 4;
    }
    else if (converted < long_max)
    {
        j = 8;
    }

    //j now has number of nibbles needed
    j *= 2;
    //printf("Nibbles = %d\n", j);

    //how many chars are needed to contain hex representation of converted value
    //i corresponds to nibble

    //the hexadecimal digits corresponding to nibbles of converted
    //hex digit represents exactly 4 bits, always
    //octal digit represents exactly 2 bits, always
    //to extract a hex digit, you can mask with 0x0f to isolate the right most 4 bits and shift >> 4 to move the bits over

    //there are always 2 hex digits per byte, because a byte has 8 bits
    //4 bits is called a nibble
    char hex_handler[j + 1];

    //function that takes byte and prints hex
    for (int i = 0; i < j; i++)
    {
        //print hex
        //takes the number of bytes needed and adds how many iterations are happening
        //starts from the left/ position of interest
        //print_hex(hex_handler[offset + i]);
        unsigned char nibble = (converted >> (4 * i)) & 0x0F;

        //switch statement to convert nibble to hex character
        //character that corresponds to hex digit
        switch (nibble)
        {
        //if between 0-9 then add 48
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            nibble += 48;
            break;

        case 0xa:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
            nibble += 65;
            break; //if between a-f add 65
        }

        //put nibble into array, and does so backwards because it's mirrored
        hex_handler[j - i - 1] = nibble;
        //printf("nibble = %d, index = %d, hex_handler = %d\n", nibble, j - i - 1, hex_handler[j - i - 1]);
    }

    //0 based so can only take maximum amount of value
    hex_handler[j] = 0;
    printf("%s", hex_handler);

    return 0;
}