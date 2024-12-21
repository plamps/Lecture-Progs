
#include <stdio.h>

int main(int argc, char *argv[]) {

  int a,b,c,d;

  scanf("%d %d %d", &a, &b, &c); 

  if (a > b) {
    if (a > c) { 
        d = a; 
    }
    else { /* a <= c */ 
        d = c; 
    }
  }
  else { /* a <= b */ 
    if (b > c) { 
        d = b; 
    }
    else { /* b <= c */ 
        d = c; 
    }
  }

  printf("%d\n", d);

}
