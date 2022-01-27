#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));               /*Ensures psuedo-random number*/
    int number = (rand() % 100 + 1); /*Generates a random number between 1-100*/
    int guess = 0;
    const int MAX_NUMBER = 9; /*The maximum amount of times the user can guess*/
    int guesses = 0;
    int choice = 1;

    printf("Guess the number (1-100)\n");

    do
    {
        printf("Enter your guess:");
        //printf("The answer is %d", number);
        scanf("%d", &guess);
        if (guess > 100 || guess < 1) /*Program will only accept numbers between 1-100*/
        {
            printf("Invalid input, guess a number 1-100.\n\n", guess);
            break;
        }

        guesses++;
        if (number == guess)
        {
            printf("Correct!");
            printf("You answered correctly after %d guess/guesses!\n", guesses);
            printf("Continue? 1=yes 0=no\n");
            scanf("%d", &choice);
            number = (rand() % 100 + 1);
            guesses = 0;
        }
        else if (guesses >= MAX_NUMBER)
        {
            printf("You have reached the max amount of tries.\n", guess);
            printf("Continue? 1=yes 0=no\n");
            scanf("%d", &choice);
            number = (rand() % 100 + 1);
            guesses = 0;
        }
        else if (number > guess)
        {
            printf("%d is smaller than the correct answer.\n", guess);
            printf("You have guessed %d times.\n\n", guesses);
        }
        else
        {
            printf("%d is greater than the correct answer.\n", guess);
            printf("You have guessed %d times.\n\n", guesses);
        }

    } while (choice); /*Do while loop continues until user chooses to stop program*/

    return 0;
}