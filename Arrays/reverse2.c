/* ανάποδη εκτύπωση εισόδου – ως 80 χαρακτήρες ή '\n' */
#include <stdio.h>
#define N 80
	
int main(void) {
  char buf[N];  /* πίνακας χαρακτήρων */ 
  int n;        /* θέση τελευταίου έγκυρου στοιχείου */
  char c;       /* βοηθητική μεταβλητή */

  n=0; 
  do {
    c = (char) getchar(); 
    buf[n] = c; 
    n++; 
  } while ((n < N) && (c != '\n'));
 
  n--;
  while (n >= 0) {
    putchar(buf[n]); 
    n--;
  }
  putchar('\n');
}