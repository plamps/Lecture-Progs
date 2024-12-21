/* Σύγκριση Συμβολοσειρών με δείκτες */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 32

void my_strcpy(char *dest, const char *src) {
	while(*dest++ = *src++)
        ;
}

int main(void) {
    char *src, *dest;

    src = malloc(sizeof(char)*SIZE);
    dest = malloc(sizeof(char)*SIZE);
    printf("Enter string to copy: ");
    scanf("%31s", src);

    my_strcpy(dest, src);
    
    printf("%s\n", dest);
}