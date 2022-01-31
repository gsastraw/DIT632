#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5
#define NUMBER 15

// ##### typedefs          ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations   #####

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;

    REGTYPE *act_post, *head = NULL;

    srand(time(0)); //   Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    //test by exerising, 999 is different from all other records generated from list (out of 100 upper limit specified)
    head = add_first(head, 999);
    //test function for segment B
    printf("\nFirst value is %d", head->number);

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}

// ====     End of main   ======================================

REGTYPE *random_list(void)
{
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    time_t t;

    //top = (REGTYPE *)malloc(sizeof(REGTYPE));

    //cast malloc to reg type pointer because malloc always returns a void pointer

    //access the members of a structure of a pointer with arrow operator
    //created and allocated memory for top, and filled out structure for a single element case

    //if NUMBER > 0 then top will never be null, because always returning 1 or more records in list
    //if NUMBER is 0 then there is nothing in list and should return null

    if (NUMBER <= 0)
    {
        return NULL;
    }

    //collection is not empty thus space needs to be allocated to top
    top = (REGTYPE *)malloc(sizeof(REGTYPE));

    //The value of the variable data is given a random number between 0 and 100
    /* Intializes random number generator */
    srand((unsigned)time(&t));

    /*Generate random number between 0 and 100 */
    top->number = rand() % 101;
    top->prev = NULL;
    top->next = NULL;

    //old points to top
    old = top;

    //loop to handle lists more than 1, start from one to n
    for (i = 1; i < NUMBER; i++)
    {
        //references must move along
        //allocate memory to item
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        item->number = rand() % 101;
        item->prev = old;
        item->next = NULL;
        //if item exists then old must have something in line in the list
        old->next = item;
        //current item is set to old, which is referenced in the loop
        //old acts as a cursor to iterate where in the list our position is
        old = item;
    }

    /**
    top->prev = NULL;
    top->number = 10;
    top->next = NULL;

    old = (REGTYPE *)malloc(sizeof(REGTYPE));
    old->prev = top;
    old->number = 127;
    old->next = NULL;
    **/

    //add to the list, and now theyre part of the list
    //top->next = old;

    return (top);
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    /*
    Adds a new record to the first position of the list and assign the field numbers the value of data. 
    The function must return a pointer to the new first entry in the list. Extend main() so that this 
    function is tested. */

    //temp is some variable in the list, position unknown
    if (NULL == temp)
    {
        return NULL;
    }

    //while not in the head of list
    while (temp->prev != NULL)
    {
        //keep overwriting temp to previous entry in list
        temp = temp->prev;
    }

    //create new record and assign value of data
    REGTYPE *new_record;

    new_record = (REGTYPE *)malloc(sizeof(REGTYPE));
    //set var to default value, point to 0 or NULL
    new_record->prev = NULL;
    new_record->number = data;
    new_record->next = temp;
    //overwrites new head of list
    temp->prev = new_record;

    //return
    return (new_record);
}