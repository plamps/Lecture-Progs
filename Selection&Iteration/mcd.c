/* υπολογισμός του μέγιστου κοινού διαιρέτη x,y */

#include <stdio.h>

int main(void) {

  int x,x1,y,y1;

  scanf("%d %d", &x, &y);

  x1 = x; y1 = y;	
  
  while (x1 != y1) {
    if (x1 > y1) { 
        x1 = x1-y1; 
    }
    else {      /* x1 <= y1 */ 
        y1 = y1-x1; 
    }
  }
  
  printf("%d\n", x1);

}
