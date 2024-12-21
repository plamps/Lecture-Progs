/* πολλαπλασιασμός με πρόσθεση z=x*y, y>=0 */

#include <stdio.h>

int main(void) {

  int x,y,z,i;
  printf("Enter two ints x, y to calculate x*y by adding:");  
  scanf("%d %d", &x, &y);
	
  z =0;
  for (i=0; i<y; i++) {
    z = z+x;
  }

  printf("%d\n", z);

}
