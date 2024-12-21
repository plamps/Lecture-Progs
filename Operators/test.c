#include <stdio.h>

int main() {
    int i, *p, *q;
   
	p = &i;
    q = p;
    i = 10;
    printf("%p, %p, %d, %d \n", p, q, *p, *q);
}