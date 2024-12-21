/* 
*  Επισκέπτεται τα στοιχεία του πίνακα matrix 
*  ανά γραμμή και θέτει στα  στοιχεία που 
*  βρίσκονται στη διαγώνιο την τιμή 1,5 και 
*  στα υπόλοιπα την τιμή 0 
*/
#include <stdio.h>
#define N 10

int main() {

    double matrix[N][N];
    int row, col;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (row == col) {
                matrix[row][col] = 1.5;
            }
            else {
                matrix[row][col] = 0;
            }
            printf("%.2lf ", matrix[row][col]);
        }
        printf("\n");
    }
}