/************************************************\
* Filename:      queue.c                         *
* Author:        Sue Bogar                       *
* Date Written:  4/22/98                         *
* Section:       101                             *
* EMail:         bogar@cs.umbc.edu               *
*                                                *
* Description:  This file contains the functions *
* necessary to work with a queue.                *
* This set of functions provide the operations   *
* needed including adding an item to the queue,  *
* enqueue; deleting an item from the queue,      *
* dequeue; determining if the queue is empty and *
* the printing the items in the queue.           *
* Since the queue is being implemented as a      *
* linked list, some functions needed for a list  *
* have been added to this file, although they    *
* would normally be in a seperate header file,   *
* the one for linked lists.  Those functions     *
* are CreateNode and GetData.                    *
\************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/******************
* Enqueue takes two pointers to NODEPTRs, and a
* NODEPTR as arguments.  The first argument will
* contain the address of head, the second argument
* will contain the address of tail, and the third
* argument is a pointer to the node to be inserted.  
* Enqueue will insert the item at the end of the 
* queue.  The address of head and tail are passed 
* into this function, because this function may
* need to change the address held in head, and 
* always changes the address held in tail.
******************/ 
void Enqueue (NODEPTR* headPtr, 
	      NODEPTR* tailPtr, NODEPTR temp)
{
   if (IsEmpty (*headPtr))
   {
      *headPtr = temp;
      *tailPtr = temp;
   }
   else
   {
      (*tailPtr) -> next = temp;
      *tailPtr = temp;
   }
}


/******************
* Dequeue takes two pointers to NODEPTR as 
* its arguments.  The first argument will
* contain the address of head, the second 
* argument will contain the address of tail.
* This function removes an item from the 
* queue and returns the data value stored 
* there.  This function may alter the addresses 
* held in either head or tail.
******************/ 
int Dequeue (NODEPTR *headPtr, NODEPTR *tailPtr)
{
   int value;
   NODEPTR temp;

   if (IsEmpty (*headPtr))
   {
      printf ("Can't delete from an empty queue\n");
      return (-1);
   }
   else
   {
      temp = *headPtr;
      value = (*headPtr) -> data;
      *headPtr = (*headPtr) -> next;
      
      if (*headPtr == NULL)
      {
	 *tailPtr = NULL;
      }
      free (temp);
      return value;
   }      
}


/******************
* IsEmpty takes a NODEPTR as its first
* argument, which is a pointer to the list, 
* known as head.  It determines whether the
* queue is empty and returns 1 (true) if 
* the queue is empty and 0 (false) if it
* is not empty.
******************/ 
int IsEmpty (NODEPTR head)
{
   /* If the pointer to the list is
   NULL then there is no list.  The
   list is empty, so we return true.
   */
   if(head == NULL)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}


/******************
* PrintQueue takes a NODEPTR as an argument
* which is initially the head.  The queue is 
* traversed and the value of the data member 
* of each item is printed.
******************/ 
void PrintQueue (NODEPTR curr)
{
   if (IsEmpty (curr))
   {
      printf ("The queue is empty\n\n");
   }
   else
   {
      printf ("The queue contains :\n");
      /*Until the end of the list*/
      while (curr != NULL)
      {
          /* print the current data item */
          printf("%d ", curr -> data);

	  /* move to the next node */
	  curr = curr -> next;
      }
      printf ("\n\n");
   }   
}

/******************
* CreateNode mallocs the space needed to
* hold a struct of type node, initializes
* the members, and returns a pointer to
* the new node.
******************/ 
NODEPTR CreateNode (void)
{
   NODEPTR newNode;

   /* Get the space needed for the node */
   newNode = (NODEPTR) malloc (sizeof(NODE));
   if (newNode == NULL)
   {
      fprintf (stderr, "Out of Memory - CreateNode\n");
      exit (-1);
   }

   /* Initialize the members */
   newNode -> data = 0;
   newNode -> next = NULL;

   return newNode;
}


/******************
* SetData assigns a value passed in into the 
* data member of the node pointed to by the 
* NODEPTR it receives as an argument.
******************/ 
void SetData (NODEPTR temp, int value)
{
   temp -> data = value;
} 
