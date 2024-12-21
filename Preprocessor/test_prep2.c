#include <stdio.h>
#define PLUSONE(x) (x+1)   

int main() {
  int i,j;

  scanf("%d",&i);
  j=PLUSONE(i)*2;
  printf("%d\n",j);
}
