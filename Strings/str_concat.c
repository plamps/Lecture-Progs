/* σύνδεση δύο συμβολοσειρών σε μια (string concatenation) */

#include <stdio.h> 
#define N 32

int main(void) {
  int i,j; char s1[N],s2[N],s3[2*N-1];

  printf("enter string:"); scanf("%31s", s1);
  printf("enter string:"); scanf("%31s", s2);

  /* αντέγραψε το s1 στο s3 */
  for (i=0; s1[i]!='\0'; i++) { s3[i] = s1[i]; }

  /* αντέγραψε το s2 στο s3 */
  for (j=0; s2[j]!='\0'; j++,i++) { s3[i] = s2[j]; }
  
  s3[i]='\0'; /* τερμάτισε το s3 */
  
  printf("%s + %s = %s\n", s1, s2, s3);
}
