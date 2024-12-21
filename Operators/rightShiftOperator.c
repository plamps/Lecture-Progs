#include <stdio.h>
    
void showbits( unsigned int x )
{
    short int i=0;
    for (i = (sizeof(short int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

int main( void )
{
    short int j = 57;
    printf("%d in binary \t\t ", j);
    showbits(j);

    /* the loop for right shift operation */
    for (int m = 0; m <= 5; m++)
    {
        int n = j >> m;
        printf("%d right shift %d gives\t ", j, m);
        showbits(n);
    }
    return 0;
}