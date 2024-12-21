#include <stdio.h>

#define ROWS 3
#define COLS 4
/* Θέτει στα στοιχεία της στήλης i του πίνακα a την τιμή j
με χρήση δείκτη σε πίνακα μιας διάστασης */
void set_col(int (*a)[COLS], int i, int j) {
	
    int (*p)[COLS];

    for (p = a; p < a + ROWS; p++)
        (*p)[i] = j;

}

int main() {
    int i, j, arr[ROWS][COLS];
    
    for (i=0;i<ROWS;i++)
        for (j=0; j<COLS; j++) 
            scanf("%d", &arr[i][j]);
    
    set_col(arr, 0, 0);

    for (i=0;i<ROWS;i++) {
        for (j=0; j<COLS; j++) 
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
