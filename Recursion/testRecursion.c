/*********************************
 ** File testRecursion.c
 ** Author: P. Lampsas
 ** Date: 6/9/23
 ** E-Mail: plampsas@uth.gr
 **
 ** This file demonstrates recursive 
 ** calls of a function
*******************************/
#include <stdio.h>

void f(int x) {
if (x>1)  
    f(x-1);
printf("%d ", x);
}

int main(void) {
    f(9);
    printf("\n");
    return 0;
}
