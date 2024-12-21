/* s=1+2+…+n */
#include <stdio.h>

int main(int argc, char *argv[]) {

  int n,s,i;

  scanf("%d", &n);
	
  for (s=0, i=1; i<=n; s+=i++) { }

  printf("%d\n", s);

}
