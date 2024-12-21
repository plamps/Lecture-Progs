#include <stdio.h>
#include <stddef.h>
 
struct S {
    char c;
    double d;
};

int main(void) {

printf("The first element is at offset %zu\n", offsetof(struct S, c));
printf("The double is at offset %zu\n", offsetof(struct S, d));

}