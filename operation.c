#include "apc.h"

status digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    int i=0, size = strlen(argv[1]);

    // add each digit to the doubly linked list for first number
    while(size--)
    {
        Dlist *new = malloc(sizeof(Dlist));
        if(new == NULL)
        {
            printf("Heap segment full!!\n");
            return failure;
        }
        new->prev = NULL;
        new->next = NULL;
        new->data = argv[1][size] - '0';

        // insert at the beginning
        if(*head1 == NULL)
        {
            *head1 = new;
            *tail1 = new;
        }
        else
        {
            (*head1)->prev = new;
            new->next = *head1;
            *head1 = new;
        }
    }

    i = 0, size = strlen(argv[3]);

    // add each digit to the doubly linked list for second number
    while(size--)
    {
        Dlist *new = malloc(sizeof(Dlist));
        if(new == NULL)
        {
            printf("Heap segment full!!\n");
            return failure;
        }
        new->prev = NULL;
        new->next = NULL;
        new->data = argv[3][size] - '0';

        // insert at the beginning
        if(*head2 == NULL)
        {
            *head2 = new;
            *tail2 = new;
        }
        else
        {
            (*head2)->prev = new;
            new->next = *head2;
            *head2 = new;
        }
    }
    return success;
}

status remove_zero(Dlist **head)
{
    // removing the zero if it is at the beginning
    while(*head != NULL && (*head)->next != NULL && (*head)->data == 0)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    return success;
}

// function to print the number
status print_number(Dlist *head)
{
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    return success;
}

// function to insert at the beginning
status insert_at_first(Dlist **headR, Dlist **tailR, int result)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        printf("Heap segment full!!\n");
        return failure;
    }
    new->prev = NULL;
    new->next = NULL;
    new->data = result;

    // logic to insert at the beginning
    if(*headR == NULL)
    {
        *headR = new;
        *tailR = new;
    }
    else
    {
        new->next = *headR;
        (*headR)->prev = new;
        *headR = new;
    }
    return success;
}

// function to insert at the end
status insert_at_last(Dlist **head, Dlist **tail)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        printf("Heap segment full!!\n");
        return failure;
    }
    new->prev = NULL;
    new->next = NULL;
    new->data = 0;

    // logic to insert at the end
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = (*tail)->next;
    }
    return success;
}

// function to check which number is greater
status check_greater(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    int Dlist1_count = 0, Dlist2_count = 0;

    // counting the number of digits in both the numbers
    while(tail1 != NULL || tail2 != NULL)
    {
        if(tail1 != NULL)
        {
            Dlist1_count++;
            tail1 = tail1->prev;
        }
        if(tail2 != NULL)
        {
            Dlist2_count++;
            tail2 = tail2->prev;
        }
    }

    // checking which number is greater
    if(Dlist1_count > Dlist2_count)
        return first;
    else if(Dlist1_count < Dlist2_count)
        return second;

    // if both have same number of digits, compare each digit from the beginning of the list
    while(head1 != NULL)
    {
        if(head1->data > head2->data)
            return first;
        else if(head1->data < head2->data)
            return second;
        head1 = head1->next;
        head2 = head2->next;
    }
    return equal;
}
