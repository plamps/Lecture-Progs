#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], size_t);

/* Copy every distinct element of an array to a new array,
*  dynamically allocated and resized. 
*  Works on a sorted array
*/
int main() {
    
    size_t numEls = 0, t = 1;
    size_t i, cnt = 0, x = 0, y = 0, block; 
    int *array = NULL, *newarr=NULL;

    printf("Give number of elements: \n"); 
    scanf("%zu", &numEls);

    /* Create and populate array */
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

    block = (numEls/2)<=2 ? 3 : numEls/2; //Block of memory has size 3 or numEls/2 ints 
    printf("Block size = %zu\n", block);
    newarr = (int *) realloc(newarr, (t*block)*sizeof(int));
    t++;
    if (newarr == NULL) {
        printf("Cannot allocate space for second array\n");
        exit(EXIT_FAILURE);
    }

    while (x<numEls) {
    /* if newarr is exhausted, expand it by block size */    
        if ((cnt > 0) && (cnt%block == 0)) { 
            printf("Expanding target array...\n");
            newarr = (int *) realloc(newarr, (t*block)*sizeof(int));
            if (newarr == NULL) {
                printf("Cannot expand target array! Program terminates.\n");
                exit(EXIT_FAILURE);
            }
            t++;
        }

    /* copy distinct element from array to newarr, skip duplicates */
        newarr[cnt]=array[x]; 
        cnt++;

        y = x+1;
        while ((y<numEls) && (array[x]==array[y])) { 
            y++;
        }
        x = y;
    } 
    
    if ((t-1)*block>cnt) { //shrink newarr if need be
        printf("Shrinking target array...\n");
        newarr = (int *) realloc(newarr, cnt*sizeof(int));
    }
    if (newarr == NULL) {
        printf("Cannot reduce target array! Program terminates. \n");
        exit(EXIT_FAILURE);
    }
    printArray(newarr, cnt);
    free(array);
    free(newarr);
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