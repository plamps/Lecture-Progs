/****************************************** 
* reads up to n characters from stin and 
*  stores them in str 
********************************************/

#include "readline.h"

int readline(char str[], int n) {
    int ch;
    int i;
    
    printf("In readline...\n");
    i = 0;
    ch = getchar ();
    
    while(ch!='\n') {
        if (i<n) {
            str[i] = ch;
            i++;
            ch = getchar();
        }
    }
    
    str[i] ='\0';
    printf("Entered string is: %s\n", str);
    return i;
}