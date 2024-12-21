#include <stdio.h>
#include <limits.h>
    
void showbits( unsigned int x ) {
    short i=0;
    for (i = (sizeof(short) * 8) - 1; i >= 0; i--) {
       putchar(x & (1u << i) ? '1' : '0');
    }
}

int main( void ) {
    int n;
    short j;
    printf("Enter a short int in the range [-32.768, 32.767]: ");
    scanf("%hd", &j);

    printf("%hd in binary is: ", j);
    showbits(j);
    printf("\n\n");

    /* the loop for right shift operation */
    for (int m = 0; m <= 3; m++) {
        n = j >> m;
        printf("%d right shift %d gives %d decimal (Binary: ", j, m, n);
        showbits(n);
        printf(")\n");
    }
    showbits(~(1 << 3)); 
    printf("\n");
    showbits(n = (n & ~0x0038) | (5 << 3));
    return 0;
}