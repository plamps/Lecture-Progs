/* Tests [ conversion specification for strings */

#include<stdio.h>

int main(void) {
    char str[50];

    scanf("%[^\n]", str);
    printf("You gave: %s", str);
}