#include "apc.h"

status multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1, *temp2;
    Dlist *headR1 = NULL, *tailR1 = NULL;
    Dlist *headR2 = NULL, *tailR2 = NULL;
    int carry, count = 0;

    // checks for the smallest multiplier to reduce iteration
    if(check_greater(*head1, *tail1, *head2, *tail2) == second)
    {
        temp1 = *tail2;

        headR1 = *head1;
        tailR1 = *tail1;

        *head1 = *head2;
        *tail1 = *tail2;

        *head2 = headR1;
        *tail2 = tailR1;

        headR1 = NULL;
        tailR1 = NULL;
    }

    // output loop to generate the result
    while (temp1 != NULL)
    {
        temp2 = *tail2;
        carry = 0;
        *headR = NULL;
        *tailR = NULL;

        // inner loop to multiply the digit with the multiplicand
        while (temp2 != NULL)
        {
            // multiplication logic
            int result = (temp1->data * temp2->data) + carry;
            carry = result / 10;
            result = result % 10;
            insert_at_first(headR, tailR, result);
            temp2 = temp2->prev;
        }

        // if carry is left after the inner loop
        if (carry)
            insert_at_first(headR, tailR, carry);

        // insert 0 at the last according to the position
        for (int i = 0; i < count; i++)
            insert_at_last(headR, tailR);

        // adding the result of each multiplication
        if (headR1 != NULL)
        {
            headR2 = NULL;
            tailR2 = NULL;
            // add to the previous result
            addition(&headR1, &tailR1, headR, tailR, &headR2, &tailR2);
            headR1 = headR2;
            tailR1 = tailR2;
        }
        else
        {
            headR1 = *headR;
            tailR1 = *tailR;
        }

        count++;
        temp1 = temp1->prev;
    }

    *headR = headR1;
    *tailR = tailR1;
    return success;
}

