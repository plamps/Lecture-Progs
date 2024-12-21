/* συνδυασμοί <i,j> με i:[0,n) και j:[0,m) */

#include <stdio.h>

int main(void) {

  int n,m,i,j;
  printf("Give boundaries i j for combinations: ");
  scanf("%d %d", &n, &m);
	
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) {
      printf("%d,%d\t", i, j);
    }
    printf("\n");
  }

}
