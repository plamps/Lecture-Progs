#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void) {
  
  // 2d array
  int arr[ROWS][COLS] = {
    {1, 2,  3,  4},
    {5, 6,  7,  8},
    {9, 10, 11, 12}
  };
  
  int i, j, *ptr = &arr[0][0];
  
  // print the elements of the array via pointer ptr
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d ", *(ptr + (i * COLS + j)));
    }
    printf("\n");
  }
  
  return 0;
}