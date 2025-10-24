#ifndef APC_H
#define APC_H

// header files for the file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enum to know the status of the function
typedef enum status
{

    failure,
    success,
    first,
    second,
	equal

}status;

// structure to store the values
typedef struct node
{

	struct node *prev;
	int data;
	struct node *next;

}Dlist;

/* Include the prototypes here */
status read_and_validate(int , char *[]);
status digit_to_list(Dlist **, Dlist **, Dlist **, Dlist **, char *[]);
status remove_zero(Dlist **);
status print_number(Dlist *);
status addition(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);
status subtraction(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);
status multiplication(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);
status division(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);
status insert_at_first(Dlist **, Dlist **, int);
status insert_at_last(Dlist **, Dlist **);
status check_greater(Dlist *, Dlist *, Dlist *, Dlist *); 

#endif