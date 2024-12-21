/* υπολογισμός μέγιστης τιμής 2 ακεραίων */

#include <stdio.h>

int max2(int x, int y) {
    if (x > y) {
        return(x);
    }
    else { 
        return(y);
    }
}

int main(void) {
    int a,b,c;

    printf("enter 2 ints: ");
    scanf("%d %d", &a, &b);
    c = max2(a,b);
    printf("Max of two ints is %d\n", c);

}