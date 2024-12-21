/* ανάποδη αντιγραφή του s1 στο s2 */

#include <stdio.h>
#define N 32

int main(void) {
  int i,j; 
  char s1[N],s2[N];

  printf("enter string:");
  scanf("%31s", s1);

  /* βρες το τέλος του s1 */
  for (i=0; s1[i]!='\0'; i++)
    ;
  /* αντέγραψε ανάποδα στο s2 */
  for (j=0,i--; i>=0; j++,i--) { 
    s2[j] = s1[i]; 
  }
  s2[j] = '\0'; /* τερμάτισε το s2 */

  printf("%s in reverse is %s\n", s1, s2);
}
