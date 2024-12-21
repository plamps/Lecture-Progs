/* υπολογισμός μέγιστης τιμής 2 ακεραίων */

#include <stdio.h>

int max2(int x, int y) {
    int z;

    if (x > y) {
        z = x;
    }
    else {
        z = y; 
    }
    return(z);
}

int main(void) {
    int a,b,c;

    printf("enter 2 int: ");
    scanf("%d %d", &a, &b);
    c = max2(a,b);
    printf("%d\n", c);

}
