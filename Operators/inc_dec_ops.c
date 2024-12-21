#include <stdio.h>

int main()
{
    int i;

    i = 0;
    i = (++i) + (++i);
    
    //i = (++i) + (i++);
    //i = (i++) + (++i);
    
    printf("%d\n", i); 

}