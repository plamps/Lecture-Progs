/* type cast demo */

#include <stdio.h>
#include <limits.h>

int main(void) {
    int i;
    unsigned int j=UINT_MAX;
    float x=10.6;

    i = (int)x;
    printf("i is now: %d\n", i);
    i = (int)j;
    printf("i is now: %d\n", i);
}