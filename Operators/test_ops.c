/* tests various operators... */

#include<stdio.h>
int main( void ) {
int x=17;
int y=24;
int p=(x & y);
int r=(x | y);
int s=(x ^ y);
int t=(y >> 2);
int v=(x << 3);
printf( "%d\n", p );
printf( "%d\n", r );
printf( "%d\n", s );
printf( "%d\n", t );
printf( "%d\n", v );
return 0;
} /* end main */
