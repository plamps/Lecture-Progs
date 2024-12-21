#include <stdio.h>
#include <stdlib.h>

/* δεσμεύει δυναμικά μνήμη για έναν ακέραιο, προσθέτει τα ορίσματα
και τα αποθηκεύει στη μνήμη που δεσμεύτηκε δυναμικά. Επιστρέφει τη
διεύθυνση της μνήμης που ανατέθηκε δυναμικά  */
int *add(int a, int b) { 
  int *c = (int *)malloc(sizeof(int));
  if (c == NULL) {
    printf("Cannot allocate memory...\n");
    exit(EXIT_FAILURE);
  }
  
  *c = a+b;
  return(c);
}

int main(int argc, char *argv[]) {
  int a,b,*c; /* η c έχει χώρο μόνο για να αποθηεύσει μια διεύθυνση μνήμης */

  printf("Give two ints to add: ");

  scanf("%d %d",&a,&b); 

  c = add(a,b);

  printf("%d\n",*c);

  free(c);
}
