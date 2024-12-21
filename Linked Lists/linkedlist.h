/********************************************************\
* Filename:  linkedlist.h                                *
* Author:    Sue Bogar                                   *
* Written:   11/17/98                                    *
* Last Modification: 9/27/05                             *
* Section:   201staff                                    *
* Email:     bogar@cs.umbc.edu                           *
*                                                        *
* This file contains the structure definition of a node, *
* and typedefs of the types NODE and NODEPTR.  It also   *
* contains the function prototypes for the functions     *
* defined in linkedlist.c, which are the linked list     *
* implementation of a list abstract data type.           *
\********************************************************/

#ifndef _linkedlist_h
#define _linkedlist_h

/* NODEPTR is defined as an alias for
** "struct node *" so it can be used within
** the structure before it is completely defined
*/

typedef struct node * NODEPTR;


/* A NODE is a structure that allows us to build a linked
** list since it has both a data portion and a NODEPTR as
** its members.  The NODEPTR called next is known as the
** link.
*/
typedef struct node
{
    int     data;
    NODEPTR next;    /* OR struct node *next; */
}NODE;


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
NODEPTR CreateNode (void);


/**************************************
** Function: SetData
** Input:    a pointer to a node (NODEPTR), and
**           the value to be placed into the node
** Output:   the data member of the node pointed to 
**           is populated with the value passed in
**
**************************************/ 
void    SetData    (NODEPTR temp, int data);


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
void    Insert     (NODEPTR* headPtr, NODEPTR temp);


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
int     Delete     (NODEPTR* headPtr, int data);


/**************************************
* Function: IsEmpty
* Input:    a pointer to the head of the linked list
* Output:   returns 1 (true) if the list is empty
*           returns 0 (false) if the list is not empty
*********************************************/
int     IsEmpty    (NODEPTR head);


/**************************************
* Function: PrintList
* Input:    a pointer to the head of the list
* Ouput:    each node in the list is printed according
*             to the format specified in this code
**************************************/ 
void    PrintList  (NODEPTR head);

#endif
