#include <stdio.h>

int a=0,b=0,c=0;

void f(int b) {
  int a,d;
  a=b--; 
  c=a*b; 
  d=c-1;
  printf("f: a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
}

int main() {
  int c=1,d=1;
  
  c=a+b; 
  b=b+1;
  printf("main: a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
  f(c);
  printf("main: a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
  c=a+b; 
  b=b+1;
  f(a);
  printf("main: a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
}
