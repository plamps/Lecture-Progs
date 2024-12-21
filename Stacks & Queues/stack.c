/************************************************\
* Filename:     stack.c                          *
* Author:       Sue Bogar                        *
* Date Written: 4/25/98                          *
* Section:       101                             *
* EMail:         bogar@cs.umbc.edu               *
*                                                *
* Description:  This file contains the functions *
* necessary to work with a stack.                *
* This set of functions provide the operations   *
* needed including adding an item to the stack,  *
* push; deleting an item from the stack, pop;    *
* determining if the stack is empty and the      *
* printing the items in the stack.  Since the    *
* stack is being implemented as a linked list,   *
* some functions needed for a list have been     *
* added to this file.  Those functions are       *
* CreateNode and SetData.                        *
\************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


/******************
* Push takes a pointer to NODEPTR as its first
* argument, which holds the address of top.  
* The second argument is a pointer to the node 
* that's to be inserted.  Push will insert the 
* item at the top of the stack.  The address of 
* top is passed into this function, because the 
* function may need to change the address held 
* in top.
******************/ 
void Push (NODEPTR *topPtr, NODEPTR temp)
{
   if (IsEmpty (*topPtr))
   {
      *topPtr = temp;
   }
   else
   {
      temp -> next = *topPtr;
      *topPtr = temp;
   }
}



/******************
* Pop takes a pointer to a NODEPTR as its
* only argument.  It will hold the address
* of top.  This function removes an item from 
* the stack and returns the data value stored 
* there.  This function may alter the value 
* of top.
******************/ 
int Pop (NODEPTR *topPtr)
{
   int     value;
   NODEPTR temp = *topPtr;

   if (IsEmpty (*topPtr))
   {
      printf ("Can't pop an empty stack\n");
      return -1;
   }
   else
   {
      value = (*topPtr) -> data;
      *topPtr = (*topPtr) -> next;
      
      free (temp);
      return value;
   }      
}


/******************
* IsEmpty takes a NODEPTR as its first
* argument, which is top.  It determines 
* if the stack is empty and returns 1 (true) 
* if the stack is empty and 0 (false) if it
* is not empty.
******************/ 
int IsEmpty (NODEPTR top)
{
   /* If the pointer to the list is
   NULL then there is no list.  The
   list is empty, so we return true.
   */
   if(top == NULL)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}


/******************
* PrintStack takes a NODEPTR as an argument
* which is initially the top.  The stack is 
* traversed and the value of the data member 
* of each item is printed.
******************/ 
void PrintStack (NODEPTR curr)
{
   if (IsEmpty (curr))
   {
      printf ("The stack is empty\n\n");
   }
   else
   {
      printf ("The stack contains :\n");
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
* GetData gets the value of data
* from the user and puts it into the
* node pointed to by the NODEPTR it
* receives as an argument.
******************/ 
void SetData (NODEPTR temp, int value)
{
   temp -> data = value;
} 
