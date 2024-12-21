/* επανειλημμένη αποτίμηση παραμέτρων ... */
#include <stdio.h>
#define SQUARE(a) ((a)*(a)) 

int main() {
  int i,j;

  scanf("%d",&i);
  j=SQUARE(++i);
  printf("%d\n",j);
}
