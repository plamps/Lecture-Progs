#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], size_t);

/* Remove dulicate elements and store the result in
*  the same array
*  Works on a sorted array.
*/
int main() {
    
    size_t numEls = 0, i, x = 0, y = 0, elements = 0; 
    int *array = NULL;

    printf("Give number of elements: \n"); 
    scanf("%zu", &numEls);

    printf("Allocating space for %zu input elements...\n", numEls);
    array = (int *)realloc(array, numEls*sizeof(int));

    if (array == NULL) {
        printf("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    printf("Insert items, one in a row:\n");
    for (i=0; i<numEls; i++) {
        scanf("%d", &array[i]);
    }
    printArray(array, numEls);

    /* copy distinct elements to the beginning of the array */
    while (x < numEls) {
        array[elements] = array[x];
        elements++;
        y = x+1;
        /* advance y to the next different element */
        while ((y<numEls) && (array[x]==array[y])) { 
            y++;
        }
        x = y;
        printf("X, Y, Elements: %zu %zu %zu\n", x, y, elements);
    }
    printf("Shrinking array to %zu elements...\n", elements);
    array = (int *)realloc(array, elements*sizeof(int));
    if (array == NULL) {
        printf("Cannot shrink array\n");
        exit(EXIT_FAILURE);
    }
    printArray(array, elements);
    free(array);
}

/* 
* prints contents of size elements of array a 
*/
void printArray(int a[], size_t size) {
    size_t i;

    for (i=0; i<size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

