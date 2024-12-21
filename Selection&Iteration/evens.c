/* Εμφάνιση άρτιων αριθμών στο διάστημα [1..n) */
#include <stdio.h>

int main(void) {
  int n,i;

  scanf("%d", &n);
	
  for (i=1; i<=n; i++) {
    if (i%2 != 0) { 
        continue; 
    }
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}
