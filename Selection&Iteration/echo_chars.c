/* αντιγραφή χαρακτήρων από είσοδο σε έξοδο 
   μέχρι να διαβαστεί ο χαρακτήρας ‘~’ */

#include <stdio.h>

int main(int argc, char *argv[]) {

  char c;
	
  do {
    c = getchar();
    putchar(c);
  } while (c != '~');

}
