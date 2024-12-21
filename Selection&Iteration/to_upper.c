/* Convert a lowecase char to uppercase, print every other char */
#include <stdio.h>

int main(void) {

    char c;
    
    do {
        c = getchar();
        if ((c >= 'a') && (c <= 'z')) { 
            c = c-32; 
        }
        putchar(c);
    } while (c != '\n');
}