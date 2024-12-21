/*********************************
 ** File 2darray.c
 ** Author: S. Evans
 ** Modified by P. Lampsas
 ** Date: 6/9/23
 ** E-Mail: plampsas@uth.gr
 **
 ** This file demonstrates dynamic memory
 ** allocation of a 2 dimensional array
 ** of integers
*******************************/

#include <stdio.h>
#include <stdlib.h>

int **GetTwoDSpace(int rows, int cols);
void  FreeTwoDSpace(int **array, int rows);

int main() {
    int **array, i, j, rows, cols;
    printf("This program dynamically allocates the space needed\n");
    printf("for a two-dimensional array of ints\n\n");

    /* How big would you like the array to be ? */
    printf("How many rows : ");
    scanf("%d", &rows);
    printf("How many columns : ");
    scanf("%d", &cols);
    printf("\n");

   /* Get the space for the array */
    array = GetTwoDSpace(rows, cols);

   /* Load the array with some values */
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            array[i][j] = i * j;
        }
    }                                                                           

   /* Print out what the array holds */
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
        printf("%5d", array[i][j]);
        }
        printf("\n");
    }

   /* Free the space that was dynamically allocated */
    FreeTwoDSpace(array, rows);
    
    return 0;
}

/***************
** Function: GetTwoDSpace()
**
** GetTwoDSpace() gets the memory space needed to hold the 2 dimensional
** array of ints and returns the pointer which will become the name of
** the array.
**
** Inputs: Number of rows to be in the array
**         Number of columns to be in the array
** Output: The pointer to the memory
********************************/
int **GetTwoDSpace(int rows, int cols) {
   int **array, i;

   /* Get the space for the array of pointers to int */
   array = (int**)malloc(rows * sizeof(int*));
    if(array == NULL) {
        printf("Error getting space for 2-d array of ints\n");
        exit(EXIT_FAILURE);
    }

   /* Get the space for all of the one dimensional arrays of ints */
    for(i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if(array[i] == NULL) {
            printf("Error getting space for 2-d array of ints\n");
            exit(EXIT_FAILURE);
        }
    }

    return array;
}

/***************
** Function: FreeTwoDSpace()
**
** FreeTwoDSpace() frees the memory space of a 2 dimensional
** array of ints.
**
** Inputs: Number array to be freed
**         Number of rows in the array
** Output: None
********************************/
void  FreeTwoDSpace(int **array, int rows) {
    int i;
                                                                            
    for(i = 0; i < rows; i++) {
        free(array[i]);
    }
    
    free(array);
}