#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *f;
  unsigned int j;

  f = fopen("test_ascii", "w"); /* ανοίγει το αρχείο test_ascii (το δημιουργεί αν δεν υπάρχει) */

  if (f==NULL) {
    printf("Error in opening file: test_ascii\n");
    exit(EXIT_FAILURE);
  }

  j=1000000000;

  fprintf(f, "%d", j);

  fflush(f); 
  fclose(f);
}