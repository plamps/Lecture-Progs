/* υπολογισμός μέγιστης τιμής 2 ακεραίων */

#include <stdio.h>

int max2(int x, int y) {
    if (x > y) {
      x=y;
        return(x);
    }
    return(y);
}

int main(void) {
  int x,y,c;

  printf("enter 2 ints: ");
  scanf("%d %d", &x, &y);
  c = max2(x,y);
  printf("x = %d, Max of two ints is %d\n", x, c);

}
