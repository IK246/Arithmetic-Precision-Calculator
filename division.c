#include "apc.h"

status division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    /* Definition goes here */
    Dlist *headR1 = NULL, *tailR1 = NULL;
    status result = check_greater(*head1, *tail1, *head2, *tail2), quotient = 0;

    // Check for division by zero
    if ((*head2)->data == 0 && (*head2)->next == NULL) 
    {
        printf("Division by zero is infinite\n");
        return failure;
    }

    // if first number is greater than to second number
    if(result == first)
    {
        while(1)
        {
            // if quotient is 0, subtract from the first number
            if(quotient == 0)
                subtraction(head1, tail1, head2, tail2, headR, tailR);
            // else subtract from the result of previous subtraction
            else
                subtraction(&headR1, &tailR1, head2, tail2, headR, tailR);
            quotient++;
            headR1 = *headR;
            tailR1 = *tailR;
            *headR = NULL;
            *tailR = NULL;

            // remove leading zeros from the result
            remove_zero(&headR1);

            // check if the result is less than the second number
            if((result = check_greater(headR1, tailR1, *head2, *tail2)) == second)
                break;
        }
    }

    // if second number is greater, quotient is 0
    else if(result == second)
        quotient = 0;

    // if both numbers are equal, quotient is 1
    else if(result == equal)
        quotient++;

    if((*headR = malloc(sizeof(Dlist))) == NULL)
    {
        printf("Heap segment full!!\n");
        return failure;
    }

    // insert the quotient in the result list
    *tailR = *headR;
    (*headR)->prev = NULL;
    (*headR)->next = NULL;
    (*headR)->data = quotient;

    return success;
}