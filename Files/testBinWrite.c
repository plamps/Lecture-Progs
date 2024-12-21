#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *f;
  int j;

  f = fopen("test_bin","w"); /* ανοίγει το αρχείο test_bin (το δημιουργεί αν δεν υπάρχει) */

  if (f==NULL) {
    printf("Error in opening file: test_bin\n");
    exit(EXIT_FAILURE);
  }

  j=1000000000;

  fwrite((void*)&j, sizeof(int), 1, f);

  fflush(f); 
  fclose(f);
}