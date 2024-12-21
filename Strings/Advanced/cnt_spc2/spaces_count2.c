#include "readline.h"

#define SIZE 32

int main(void) {
    char *s;
    int count = 0;

    s = (char *) malloc(sizeof(char)*SIZE);

    printf("Give string to count spaces: \n");
    readline(s, SIZE-1);

	for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;

    printf("Number of spaces in string %s is %d\n", s, count);
}
