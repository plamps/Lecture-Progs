/* μήκος string s, pointer arithmetic */

#include <stdio.h>
#include <stdlib.h>
#define N 32

int main(void) {
    char *str;
    const char *p;
    
    printf("enter string: ");
    str = malloc(sizeof(char)*N);
    scanf("%31s", str);
    p=str;

    while (*str)
        str++;
    printf("length of %s is %zu\n", p, str-p);
}
