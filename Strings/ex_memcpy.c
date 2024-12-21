#include <string.h>
#include <stdio.h>
 
#define MAX_LEN 80
 
char source[MAX_LEN] = "This is the source string";
char target[MAX_LEN] = "This is the target string";
 
int main(void) {
    
    printf( "Before memcpy, target is: \"%s\"\n", target );
    memcpy( target, source, sizeof(source));
    printf( "After memcpy, target becomes: \"%s\"\n", target );
}