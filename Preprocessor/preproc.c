#include <stdio.h>
#define SQUARE(a) ((a)*(a)) 

int main(int argc, char *argv[]) {
  int i,j;

  scanf("%d",&i);
  j=SQUARE(++i);
  printf("%d\n",j);
}