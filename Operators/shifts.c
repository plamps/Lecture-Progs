#include <stdio.h>

int main() {
    short int v, i;
    
    printf("Give the exponent: ");

    scanf("%d", &i);
    v = 1<<i;
    printf("2 to the %d is %d\n", i, v);

    v=5;
    v=v<<i;
    printf("v (int) is %d, v (hex) is: %x", v, v);
}
