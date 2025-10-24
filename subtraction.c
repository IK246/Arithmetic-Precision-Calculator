#include "apc.h"

status subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0, n1, n2;
    Dlist *t1 = *tail1, *t2 = *tail2;

    // loop until both the lists are traversed
    while((t1 != NULL) || (t2 != NULL))
    {
        // if there is no node, consider the value as 0
        n1 = (t1 != NULL) ? t1->data : 0;
        n2 = (t2 != NULL) ? t2->data : 0;

        // if borrow is there, subtract 1 from the digit
        if(borrow)
        {
            n1--;
            borrow--;
        }

        // if n1 is less than n2, borrow 10 from the next digit
        if(n1 < n2)
        {
            n1 += 10;
            borrow++;
        }

        // subtract the digits and insert at the beginning of the result list
        int result = n1 - n2;
        insert_at_first(headR, tailR, result);
        if(t1 != NULL)
            t1 = t1->prev;
        if(t2 != NULL)
            t2 = t2->prev;
    }
    return success;
}