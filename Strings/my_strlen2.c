/* μήκος string s, pointer arithmetic */

#include <stdio.h>
#include <stdlib.h>
#define N 32

int main(void) {
    char *str;
    int n=0;
    
    printf("enter string: ");
    str = malloc(sizeof(char)*N);
    scanf("%31s", str);
    
    while (*str++)
        n++;
    printf("length is %d\n", n);
}
