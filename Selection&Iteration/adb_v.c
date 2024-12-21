#include <stdio.h>

int main(void) {

  int a,b;

  scanf("%d", &a);

  if (a >= 0) {
    b = a; 
  }
  else {   /* a < 0 */
    b = -a; 
  }

  printf("%d\n", b);

}