#include <stdio.h>

int readline(char str[], int n) {
    int ch;
    int i;

    i = 0;
    ch = getchar();

    while(ch!='\n') {
        if (i<n-1) {
            str[i] = ch;
            i++;
        }
        ch = getchar();
    }
    str[i] ='\0';
    printf("You entered string: %s\n", str);
    return i;
}

int main() {
    char str[5];
    readline(str, 5);
    printf("%s", str);
}