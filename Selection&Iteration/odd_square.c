/* Prints a table of squares using an odd method */

#include <stdio.h>

int main(void) 
{
  int i, n, odd, square;
  
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  for (square = 1, i=1, odd=3; i <= n; i++, square+=odd, odd += 2) {
    printf("%10d%10d\n", i, square);
  }

  return 0;
}