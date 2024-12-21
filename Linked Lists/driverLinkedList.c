/******************************************
* Author: Sue Bogar
* Date: 11/17/98
* Section: 101
* Email: bogar@cs.umbc.edu
* 
* Description: a driver for testing linked list code
*******************************************/


#include <stdio.h>

#include "linkedlist.h"

int main ()
{
    int num, value;
    NODEPTR head, temp;

    head = NULL;

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    Insert (&head, temp);
    PrintList (head);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    Insert (&head, temp);
    PrintList (head);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    Insert (&head, temp);
    PrintList (head);

    printf("\nEnter a value to be deleted :");
    scanf ("%d", &num);
    value = Delete(&head, num);
    printf("The value %d was returned\n", value);
    PrintList (head);

    printf("\nEnter a value to be deleted :");
    scanf ("%d", &num);
    value = Delete(&head, num);
    printf("The value %d was returned\n", value);
    PrintList (head);

    printf("\nEnter a value to be deleted :");
    scanf ("%d", &num);
    value = Delete(&head, num);
    printf("The value %d was returned\n", value);
    PrintList (head);

    printf("\nEnter a value to be deleted :");
    scanf ("%d", &num);
    value = Delete(&head, num);
    printf("The value %d was returned\n", value);
    PrintList (head);

    printf("\nEnter a value to be deleted :");
    scanf ("%d", &num);
    value = Delete(&head, num);
    printf("The value %d was returned\n", value);
    PrintList (head);

    return 0;
}