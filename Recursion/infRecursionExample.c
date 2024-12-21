#include <stdio.h>

void infRec(int n) {
    // This condition is never met here
    if (n == 0)
        return;

    // Print the current value of N
    printf("n = %d \n", n);

    // Call itself recursively
    infRec(n);
}

int main() {

    int n = 5;

    // Call the recursive function
    infRec(n);
    return 0;
}