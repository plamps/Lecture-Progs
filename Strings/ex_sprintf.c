#include <stdio.h>

int main(void) {

    char buffer[50];
    int i, j;
    double fp;
    char *s = "Larissa";
    char c;

    c = 'l';
    i = 35;
    fp = 1.7320508;
    
    /* Format and print various data */
    j = sprintf(buffer, "%s\n", s);
    j += sprintf(buffer+j, "%c\n", c);
    j += sprintf(buffer+j, "%d\n", i);
    j += sprintf(buffer+j, "%.7f\n", fp);
    printf("string:\n%s\ncharacter count = %d\n", buffer, j);
}