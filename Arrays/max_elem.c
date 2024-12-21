/* ανάγνωση 10 ακεραίων και εκτύπωση μέγιστης τιμής */
#include <stdio.h>
#define N 10 /* όπου "Ν" αντικατέστησε με "10" */ 

int main(void) {
  int v[N];  /* πίνακας Ν ακεραίων */
  int maxp;  /* θέση μεγαλύτερου στοιχείου */
  int i;     /* μετρητής βρόχου for */ 
	
  for (i=0; i<N; i++) {
    printf("enter %d int: ", i+1);
    scanf("%d", &v[i]);
  }

  maxp = 0;
  for (i=1; i<N; i++) {
    if (v[maxp] < v[i]) { 
        maxp = i; 
    }
  }

  printf("Maximum element is %d\n", v[maxp]); 
}
