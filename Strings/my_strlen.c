/* μήκος string s */

#include <stdio.h>
#define N 32

int main(void) {
  int i;
  char str[N];

  printf("enter string: ");
  scanf("%31s", str);

  for (i=0; str[i]!='\0'; i++)
    ;
  printf("length of %s is %d\n", str, i);
}
