/* υπολογισμός y=x! */

#include <stdio.h>

int main(int argc, char *argv[]) {

  int x,y,i;

  scanf("%d", &x);
	
  y = 1; 
  i = 2;
  
  while (i <= x) {
    y = y*i; 
    i = i+1;
  }

  printf("%d\n", y);

}