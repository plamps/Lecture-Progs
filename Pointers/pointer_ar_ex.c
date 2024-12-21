/*Stores 2, 4, 6, 8, 10 in an array using pointer arithmetic */
#include <stdio.h>
#define N 10

int main(void) {
    unsigned short int a[N]={0}, i, *p=&a[0];

	for (i = 2; i <= N; i+=2)
        *p++=i;
    for (i=0; i<N; i++) 
        printf("a[%d] = %d\n", i, a[i]);

}