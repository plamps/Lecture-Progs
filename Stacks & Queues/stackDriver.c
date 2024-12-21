/*******************************************
* File: stackdriver.c
* Author: Sue Bogar
* Date: 4/25/98
* Section: 101
* Email: bogar@cs.umbc.edu
*
* Description: driver for testing stacks implemented 
*                as linked lists
*******************************************/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main ()
{
    int     value;
    NODEPTR top, temp;

    top = NULL;

    PrintStack (top);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    printf("Pushing the value, %d\n", 
	   temp -> data);
    Push (&top, temp);
    PrintStack (top);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    printf("Pushing the value, %d\n", 
	   temp -> data);
    Push (&top, temp);
    PrintStack (top);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    printf("Pushing the value, %d\n", 
	   temp -> data);
    Push (&top, temp);
    PrintStack (top);

    printf ("Popping :\n");
    value = Pop (&top);
    printf ("The value was %d\n", value);
    PrintStack (top);

    printf ("Popping :\n");
    value = Pop (&top);
    printf ("The value was %d\n", value);
    PrintStack (top);

    printf ("Popping :\n");
    value = Pop (&top);
    printf ("The value was %d\n", value);
    PrintStack (top);

    printf ("Popping :\n");
    value = Pop (&top);
    printf ("The value was %d\n", value);
    PrintStack (top);

    return 0;
}