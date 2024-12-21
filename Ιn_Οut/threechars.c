#include <stdio.h>

int main(int argc, char* argv[]) {
  char c1, c2, c3;

  putchar('3'); 
  putchar(' '); 
  putchar('c');
  putchar('h'); 
  putchar('a'); 
  putchar('r');
  putchar('s'); 
  putchar(':'); 
  putchar('\n');
  
  c1=getchar(); 
  c2=getchar(); 
  c3=getchar();

  putchar(c1); 
  putchar(c2); 
  putchar(c3);
  putchar('\n');
}