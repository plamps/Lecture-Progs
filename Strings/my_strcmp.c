/* Σύγκριση Συμβολοσειρών με δείκτες */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 32

int main(void) {
    char *s1, *s2;
    s1 = malloc(sizeof(char)*SIZE);
    s2 = malloc(sizeof(char)*SIZE);
    printf("Enter strings to compare: ");
    scanf("%31s %31s", s1, s2);
    
    while(*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    printf("%d",*s1 - *s2);
}