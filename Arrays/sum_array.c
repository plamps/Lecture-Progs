/* ανάγνωση 10 ακεραίων και εκτύπωση αθροίσματος */
#include <stdio.h>
#define N 10 /* όπου "Ν" αντικατέστησε με "10" */ 

int main(void) {
  int v[N];  /* πίνακας Ν ακεραίων */
  int sum;     /* άθροισμα στοιχείων */
  int i;     /* μετρητής βρόχου for */ 
	
  for (i=0; i<N; i++) {
    printf("enter %d int: ", i+1);
    scanf("%d", &v[i]);
  }

  sum = 0;
  for (i=0; i<N; i++) {
    sum = sum + v[i]; 
  }

  printf("Sum of array elements is: %d\n", sum); 
}