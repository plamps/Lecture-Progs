/* n_sum, calculates 0+1+2+...+n */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;	
  int i;	
  int s;	
  scanf("%d", &n);

  i = 1; s = 0;

  while (i <= n) {
    s = s+i;
    i++;
  }

  printf("%d\n", s);
}
