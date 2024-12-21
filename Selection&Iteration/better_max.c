#include <stdio.h>

int main(int argc, char *argv[]) {

  int a,b,c,d;

  scanf("%d %d %d", &a, &b, &c); 

  d = a;
  if (d < b) { 
    d = b;
  }
  if (d < c) { 
    d = c; 
  }

  printf("%d\n", d);

}
