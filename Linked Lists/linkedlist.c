/************************************************\
* Filename:     linkedlist.c                     *
* Author:       Sue Bogar                        *
* Date Written: 11/17/98                         *
* Section: 101                                   *
* EMail: bogar@cs.umbc.edu                       *
*                                                *
* Description:  This file contains the functions *
* necessary to work with a linked list.          *
* This set of functions provide the operations   *
* needed including creation of a node, insertion,*
* deletion, determining if a list is empty and   *
* the printing of the list.                      *
\************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/**************************************
** Function: CreateNode
** Input:    none
** Output:  memory for a node is malloced
**           and a pointer (nodePtr) to the memory
**           is returned to the user
** Note:
**      CreateNode initializes the members
**      CreateNode exits if there is insufficient
**      memory
**************************************/ 
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


/**************************************
** Function: SetData
** Input:    a pointer to a node (NODEPTR), and
**           the value to be placed into the node
** Output:   the data member of the node pointed to is 
**           populated with the value passed in.
**
**************************************/
void SetData (NODEPTR temp, int value)
{
   temp -> data = value;
} 


/**************************************
* Function: Insert
* Input:    a pointer to a pointer to the head of the 
*             linked list (headPtr)
*           a pointer to the node (NODEPTR) to be 
*             inserted
* Output:   the node is inserted at the end of the 
*             linked list
*           there is no return value
**************************************/ 
void Insert (NODEPTR* headPtr, NODEPTR temp)
{
   NODEPTR prev, curr;

   if ( IsEmpty (*headPtr))
   {
       *headPtr = temp;
   }
   else
   {
      prev = NULL;
      curr = *headPtr;

      /* traverse the list until the end */
      while (curr != NULL)
      {
	 prev = curr;
	 curr = curr -> next;
      }
  
      /* insert the node, temp, at the end */
      prev -> next = temp;
   }
}


/**************************************
* Function: Delete
* Input:    a pointer to a pointer to the head 
*             (headPtr) of the linked list
*           an integer (target) containing the value 
*             of the data in the node to be deleted
* Output:   if found, the first node with the corresponding
*             value (target) is deleted from the 
*             linked list
*           if the node is deleted, the value found 
*             in the deleted node (NOT target) is
*             returned
*           if no node is deleted, an error is 
*             printed and -1 is returned
**************************************/ 
int Delete (NODEPTR* headPtr, int target)
{
   int value;
   NODEPTR temp, prev, curr;

   if (IsEmpty (*headPtr))
   {
      printf ("Can't delete from an empty list\n");
      return (-1);
   }

   /* if the target value is the first
   in the list, move head */
   else if (target == (*headPtr) -> data)
   {
      temp = *headPtr;
      value = (*headPtr) -> data;
      *headPtr = (*headPtr) -> next;
      free (temp);
      return (value);
   }
   
   /* traverse the list until the 
   target value is found */
   else
   {
      prev = *headPtr;
      curr = (*headPtr) -> next;

      while (curr != NULL &&
	     curr -> data != target)
      {
	 prev = curr;
	 curr = curr -> next;
      }
      
      if(curr != NULL)
      {
	
	/* delete the node the contains
	the target value */
	temp = curr;
	prev -> next = curr -> next;
	value = curr -> data;
	free(temp);
	return (value);
      }
      else
      {
	printf("%d was not in the list\n", target);
	return (-1);
      }
   }      
}


/**************************************
* Function: IsEmpty
* Input:    a pointer to the head of the linked list
* Output:   returns 1 (true) if the list is empty
*           returns 0 (false) if the list is not empty
*********************************************/
int IsEmpty (NODEPTR head)
{
   /* If the pointer to the list is
   NULL then there is no list.  The
   list is empty, so we return true.
   */
   return (head == NULL);
}


/**************************************
* Function: PrintList
* Input:    a pointer to the head of the list
* Ouput:    each node in the list is printed according
*             to the format specified in this code
**************************************/ 
void PrintList (NODEPTR head)
{
   NODEPTR curr;

   if (IsEmpty (head))
   {
      printf ("The list is empty\n");
   }
   else
   {
      /* set the current pointer to the first
      ** node of the list */
      curr = head;

      /* Until the end of the list */
      while (curr != NULL)
      {
          /* print the current data item */
          printf("%d ", curr -> data);

	  /* move to the next node */
	  curr = curr -> next;
      }
      printf ("\n");
   }   
}
