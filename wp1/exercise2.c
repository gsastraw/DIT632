#include <stdio.h>
#include <stdlib.h>

#define FALSE 0

void calculation(char *input, int shift)
{
    int cursor;
    printf("Your input was %s\n", input);

    //loop through characters of input
    //loop through every chracter until 0
    //cursor vars
    cursor = 0;
    while (input[cursor] > 0)
    {
        int value = input[cursor];
        //check if cursor points to linefeed in order to ignore
        if (10 == value)
        {
            input[cursor] = 0;
            cursor++;
            continue;
        }

        if (value > 64 && value < 91)
        {
            int finalValue = (value - 65 + shift) % 26;
            input[cursor] = finalValue + 65;

            //convert until end of string (value = 0)
            //check end of file
        }

        if (value > 96 && value < 123)
        {
            int finalValue = (value - 97 + shift) % 26;
            input[cursor] = finalValue + 97;

            //convert until end of string (value = 0)
            //check end of file
        }
        cursor++;
    }

    printf("Encrypted message %s\n", input);
}

int main(int argc, char **argv)
{
    int shift;
    char input[100];

    if (argc != 2)
    {
        printf("Invalid number of params");
        return -1;
    }

    //asign content of string to shift
    shift = atoi(argv[1]);
    printf("Shift was %d\n", shift);

    do
    {
        printf("Enter your input:\n");
        //fgets(input, 100, stdin);

        //evaluate if input is EOF
        if (scanf("%s", input) == EOF)
        {
            //ctrl+d returns empty string and not eof
            break;
        }

        calculation(input, shift);
    } while (!FALSE);

    return 0;
}
