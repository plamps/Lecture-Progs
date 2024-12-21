#include "readline.h"

#define SIZE 32

int main(void) {
    char s[SIZE];
    int count = 0, i;
    
    printf("Give string to count spaces: \n");
    readline(s, SIZE-1);

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
            count++;

    printf("Number of spaces in string %s is %d\n", s, count);
}
