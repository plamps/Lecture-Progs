#include<stdio.h>

int main(void) {
  //int x=1;
  char str[4];
  int x=1;

  printf("enter string:");
  scanf("%s",str);
  printf("you entered %s\n", str);

  printf("enter string:");
  scanf("%3s",str);
  printf("you entered %s\n", str);
  printf("and x=%d\n", x);
}
