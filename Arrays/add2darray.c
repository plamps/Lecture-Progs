#include <stdio.h>

#define ROWS 3
#define COLS 4

int add2darray(int arr[][COLS]);

int main(void) {
  
  // 2d array
  int arr[ROWS][COLS] = {
    {1, 2,  3,  4},
    {5, 6,  7,  8},
    {9, 10, 11, 12}
  };
  
  printf("Sum is: %d\n", add2darray(arr));
}  

int add2darray(int arr[][COLS]) {
    int i, j, sum=0;
    for (i=0; i<ROWS; i++)
        for (j=0; j<COLS; j++)
            sum += arr[i][j];
    return sum;
}