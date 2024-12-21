#include <stdio.h>

int main(void) {

int i;

	i = 11;
	while (--i > 0);        /*** Λάθος ***/
		printf("T minus %d and counting\n", i);

}