/* Tests \n at scanf format string */

#include<stdio.h>

int main(void) {
    int i;

    scanf("%d\n", &i);
    printf("You gave: %d", i);
}