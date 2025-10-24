#include "apc.h"

status addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1, *t2 = *tail2;
    int rem = 0, n1, n2;

    // loop until both the lists are traversed
    while(t1 != NULL || t2 != NULL)
    {
        // if there is no node, consider the value as 0
        n1 = (t1 != NULL) ? t1->data : 0;
        n2 = (t2 != NULL) ? t2->data : 0;

        // add the digits and the carry
        int result = n1 + n2 + rem;
        rem = result / 10;
        result %= 10;

        // insert at the beginning of the result list
        insert_at_first(headR, tailR, result);
        if(t1 != NULL)
            t1 = t1->prev;
        if(t2 != NULL)
            t2 = t2->prev;
    }
    
    // if carry is left after the loop
    if(rem)
        insert_at_first(headR, tailR, rem);
    return success;
}
