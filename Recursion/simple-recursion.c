#include <stdio.h>
#include <stdint.h>

void f(int x) { 
    if (!x) 
        return;
    f(x-1);
    printf("%d ", x); 
}

int main(void) { 
    uint64_t n;
    n=9;
    f(n);
    printf("\n");
    return 0; 
}
