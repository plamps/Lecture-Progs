/* Program 3.1 from PTRTUT10.HTM   6/13/97 */
#include <stdio.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80] = "012345678901234567890123456789012345678901234567890123456789";

int main(void) {    
    char *pA;
    char *pB;
    puts(strA);
    pA = strA;
    puts(pA);
    pB = strB;
    int i;
    putchar('\n');
    while(*pA != '\0') {
        *pB++ = *pA++;
    }    
    *pB = '\0';
    puts(strB);
    i=0;
    while (i<80) {
        putchar(strB[i]);
        i++;
    }
    return 0;
}