#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void **t;       //2d versatile dynamic array
size_t tlen;    //# of elements t holds

void init_array() {
    t=NULL; 
    tlen=0;
}

void trim_array(size_t len) {
    t=(void **) realloc(t, len*sizeof(void *));
    tlen=len;
}

void write_elem(size_t pos, void *v) {
    if (pos >= tlen) {
        trim_array(pos+1); 
    }
    t[pos]=v;
}

void *read_elem(size_t pos) {
    return(t[pos]);
}

void destroy_array() {
    trim_array(0); 
    t=NULL;
}

char *strdup(const char *src) {
    char *dst = malloc(strlen(src) + 1);   // Allocate space for string plus \0
    if (dst == NULL)        // No memory
        return NULL;        
    strcpy(dst, src);       // Copy the characters
    return dst;             // Return the new string
}

int main() {
    char s[256], *p; 
    size_t i, j;
    char ch;
    
    init_array(); 
    i = 0;
    
    do {
        printf("Give input (end terminates program): \n");
        scanf("%255s", s);
        if ((p=strdup(s)) == NULL) {
            printf("No space for string\n");
            exit(EXIT_FAILURE);
        }
        else {
            write_elem(i,(void *)p);
        }
        i++;
    } while (strcmp(s,"end"));
    
    printf("What is the type of the array elements?\n");
    printf("c: char, i: int, s: string\n");
    scanf(" %c", &ch);
    
    for (j=0; j<=i-2; j++) {
        switch (ch) {
            case 'c':
                printf("Char is: %c\n", *((char *)read_elem(j)));
                break;
            case 'i': 
                printf("%d\n", atoi((char *)read_elem(j)));
                break;
            case 's':
                printf("String is %s\n", (char *)read_elem(j));
                break;
            default: printf("Bye...\n");
        }
        free(read_elem(j)); /* Release memory occupied by each string */
    }
    destroy_array(); /* Release memory occupied by 1st level pointers */
}