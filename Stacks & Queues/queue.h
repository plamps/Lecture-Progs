/************************************************\
* Filename:      queue.h                         *
* Author:        Sue Bogar                       *
* Date Written:  4/22/98                         *
* Date modified: 11/28/98                        * 
* Section:       101                             *
* EMail:         bogar@cs.umbc.edu               *
*                                                *
* Description:  This file contains the function  *
* prototypes to work with queue.c.               *
* This set of functions provide the operations   *
* needed including adding an item to the queue,  *
* enqueue; deleting an item from the queue,      *
* dequeue; determining if the queue is empty and *
* the printing the items in the queue.           *
* Since the queue is being implemented as a      *
* linked list, some functions needed for a list  *
* have been added to this file, although they    *
* would normally be found in the linked list     *
* header file.  Those functions are CreateNode   *
* and SetData.                                   *
\************************************************/

#ifndef _queue_h
#define _queue_h

/******************
* This typedef allows us to call the type
* of a pointer to a node a NODEPTR
******************/ 
typedef struct node *NODEPTR;

/******************
* The queue is being implemented as a linked list
* and a linked list requires nodes.  Each node is 
* a structure that has two members, the first to
* hold data and the second, of type nodePtr is
* a pointer to the next node in the queue.
******************/ 
typedef struct node
{
   int     data;
   NODEPTR next;
}NODE;


/******************
* Enqueue takes two pointers to nodePtrs, and a
* nodePtr as arguments.  The first argument will
* contain the address of head, the second argument
* will contain the address of tail, and the third
* argument is a pointer to the node to be inserted.  
* Enqueue will insert the item at the end of the 
* queue.  The addresses of head and tail are passed 
* into this function, because this function may
* need to change the address held in head, and/or 
* the address held in tail.
******************/ 
void Enqueue (NODEPTR* headPtr, 
	      NODEPTR* tailPtr, NODEPTR temp);


/******************
* Dequeue takes two pointers to NODEPTR as 
* its arguments.  The first argument will
* contain the address of head, the second 
* argument will contain the address of tail.
* This function removes an item from the 
* queue and returns the data value stored 
* there.  This function may also alter the 
* address held in either head and/or tail.
******************/ 
int Dequeue (NODEPTR *headPtr, NODEPTR *tailPtr);


/******************
* IsEmpty takes a NODEPTR as its first
* argument, which is a pointer to the list, 
* known as head.  It determines whether the
* queue is empty and returns 1 (true) if 
* the queue is empty and 0 (false) if it
* is not empty.
******************/ 
int IsEmpty (NODEPTR head);


/******************
* PrintQueue takes a NODEPTR as an argument
* which is initially the head.  The queue is 
* traversed and the value of the data member 
* of each item is printed.
******************/ 
void PrintQueue (NODEPTR curr);


/******************
* CreateNode mallocs the space needed to
* hold a struct of type node, initializes
* the members, and returns a pointer to
* the new node.
******************/ 
NODEPTR CreateNode (void);


/******************
* SetData assigns a value passed in into the 
* data member of the node pointed to by the 
* NODEPTR it receives as an argument.
******************/ 
void SetData (NODEPTR temp, int value);

#endif