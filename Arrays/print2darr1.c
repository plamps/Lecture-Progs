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
  
  int i, *p = &arr[0][0];
  
  // print the elements of the array via pointer ptr
  for (i = 0; i < ROWS*COLS; i++) {

        printf("%d ", *p++);
    }

  return 0;
}