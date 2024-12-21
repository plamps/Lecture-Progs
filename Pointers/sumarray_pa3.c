/*sums array elements using pointer arithmetic simplified version*/
#include <stdio.h>
#define N 10

int main(void) {
    int a[N]={0, 1 , 5, 78, 9};
    int sum=0, *p=&a[0];

    while (p < a+N)
	  sum += *p++;

    printf("Sum is %d\n", sum);
}