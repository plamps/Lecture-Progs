#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    typedef struct tNode{//κόμβος μιας δομής δεδομένων με τύπο δένδρο
        int value; 
        struct tNode *left;
        struct tNode *right;
} Node;

Node *node = (Node *) calloc(1, sizeof(Node));
node->left = (Node *) calloc(1, sizeof(Node));

node->value = 5;
printf("Node value is %d\n", node->value);

free(node); /* Διαρροή μνήμης! δεν θα απελευθερωθεί η μνήμη που έχει ανατεθεί στο node->left! */
}