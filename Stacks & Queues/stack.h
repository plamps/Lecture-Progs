/************************************************\
* Filename:     stack.h                          *
* Author:       Sue Bogar                        *
* Date Written: 4/25/98                          *
* Section:      101                              *
* EMail:        bogar@cs.umbc.edu                *
*                                                *
* Description:  This file contains the function  *
* prototypes to work with stack.c.               *
* This set of functions provide the operations   *
* needed including adding an item to the stack,  *
* pushing; deleting an item from the stack,      *
* popping; determining if the stack is empty and *
* the printing the items in the stack.           *
* Since the stack is being implemented as a      *
* linked list, some functions needed for a list  *
* have been added to this file.  Those functions *
* are CreateNode and SetData.                    *
\************************************************/

#ifndef _stack_h
#define _stack_h

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
* a pointer to the next node in the list.
******************/ 
typedef struct node
{
   int     data;
   NODEPTR next;
}NODE;


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
void Push (NODEPTR *topPtr, NODEPTR temp);


/******************
* Pop takes a pointer to a NODEPTR as its
* only argument.  It will hold the address
* of top.  This function removes an item from 
* the stack and returns the data value stored 
* there.  This function may alter the value 
* of top.
******************/ 
int Pop (NODEPTR *topPtr);


/******************
* IsEmpty takes a NODEPTR as its first
* argument, which is top.  It determines 
* if the stack is empty and returns 1 (true) 
* if the stack is empty and 0 (false) if it
* is not empty.
******************/ 
int IsEmpty (NODEPTR head);


/******************
* PrintStack takes a NODEPTR as an argument
* which is initially the top.  The stack is 
* traversed and the value of the data member 
* of each item is printed.
******************/ 
void PrintStack (NODEPTR curr);


/******************
* CreateNode mallocs the space needed to
* hold a struct of type node, initializes
* the members, and returns a pointer to
* the new node.
******************/ 
NODEPTR CreateNode (void);


/******************
* SetData sets the value passed in into the 
* data member of the node pointed to by the 
* NODEPTR it receives as an argument.
******************/ 
void SetData (NODEPTR temp, int value);

#endif