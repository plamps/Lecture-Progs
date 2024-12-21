#include <stdio.h>
#include <limits.h>

#define BITS_PER_LONG (sizeof(long)*CHAR_BIT)


long max(long x) {
    return x & ~( x >> (BITS_PER_LONG - 1));
}

int main() {
    long x;

    printf("Give a long as input: " );
    scanf("%ld", &x);
    printf("Output is %ld", max(x));
}