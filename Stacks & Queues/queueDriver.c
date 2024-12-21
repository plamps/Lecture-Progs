/*********************************
* File: queuedriver.c
* Author: Sue Bogar
* Date: 4/22/98
* SSN: 123-45-6789
* Section: 101
* Email: bogar@cs.umbc.edu
*
* Description: driver to test queues implemented as 
*                linked lists
**********************************/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main ()
{
    int value;
    NODEPTR head, tail, temp;

    head = tail = NULL;

    PrintQueue (head);


    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    printf("Enqueueing the value, %d\n", 
	   temp -> data);
    Enqueue (&head, &tail, temp);
    PrintQueue (head);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    printf("Enqueueing the value, %d\n", 
	   temp -> data);
    Enqueue (&head, &tail, temp);
    PrintQueue (head);

    temp = CreateNode();
    printf ("\nEnter the value of data : ");
    scanf ("%d", &value);
    SetData (temp, value);
    printf("Enqueueing the value, %d\n", 
	   temp -> data);
    Enqueue (&head, &tail, temp);
    PrintQueue (head);

    printf ("Dequeueing :\n");
    value = Dequeue(&head, &tail);
    printf ("The value was %d\n", value);
    PrintQueue (head);

    printf ("Dequeueing :\n");
    value = Dequeue(&head, &tail);
    printf ("The value was %d\n", value);
    PrintQueue (head);

    printf ("Dequeueing :\n");
    value = Dequeue(&head, &tail);
    printf ("The value was %d\n", value);
    PrintQueue (head);

    printf ("Dequeueing :\n");
    value = Dequeue(&head, &tail);
    PrintQueue (head);

    return 0;
}