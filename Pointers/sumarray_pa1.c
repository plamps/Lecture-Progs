/*sums array elements using pointer arithmetic 1st version*/
#include <stdio.h>
#define N 10

int main(void) {
    int a[N]={0, 1 , 5, 78, 9};
    int sum, *p;

	sum = 0;
	for (p = &a[0]; p < &a[N]; p++)
	  sum += *p;

    printf("Sum is %d\n", sum);
}