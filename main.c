/*
    Name : Karthick I
    Title : Arithmatic Precession Calculator
    Date : 10-06-2024
 */

#include "apc.h"

int main(int argc, char *argv[])
{
    /* Declare the pointers */

    int sign = 0;
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL; 
    Dlist *headR = NULL, *tailR = NULL;
    if(read_and_validate(argc, argv) == failure)
        return 0;

    if(digit_to_list(&head1, &tail1 ,&head2 ,&tail2, argv) == failure)
        return 0;
    remove_zero(&head1);
    remove_zero(&head2);

    switch (argv[2][0])
    {
        case '+':
            {
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                break;
            }
        case '-':	
            {
                // check which number is greater
                status result = check_greater(head1, tail1, head2, tail2);

                if(result == first)
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                // if second number is greater, result will be negative
                else if(result == second)
                {
                    // set the sign flag
                    sign++;
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                }
                else if(result == equal)
                {
                    // if both numbers are equal, result is 0
                    if((headR = malloc(sizeof(Dlist))) == NULL)
                    {
                        printf("Heap segment is full!!i\n");
                        return 0;
                    }
                    headR->prev = NULL;
                    headR->next = NULL;
                    headR->data = 0;
                }
                break;
            }
        case 'x':
            {
                multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                break;
            }
        case '/':
            {
                if(division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == failure)
                    return 0;
                break;
            }
        default:
            {
                printf("Invalid Input:-( Try again...\n");
                return 0;
            }
    }

    // print the first operand
    print_number(head1);

    // print the operator
    printf(" %c ", argv[2][0]);

    // print the second operand
    print_number(head2);
    printf(" = ");

    // if the result is negative, print the sign
    if(sign)
        putchar('-');

    // remove the leading zeros and print the result
    remove_zero(&headR);
    print_number(headR);
    printf("\n");
    return 0;
}

status read_and_validate(int argc, char *argv[])
{
    if (argc != 4) 
    {
        printf("Usage message: ./a.out <operand1> <operator> <operand2>\n");
        return failure;
    }
    return success;
}
