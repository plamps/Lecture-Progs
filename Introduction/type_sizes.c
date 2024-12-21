/* εκτύπωση μεγέθους βασικών τύπων 
    %ld is used to print long int values*/

#include <stdio.h>

int main(void) {

  printf("Size of char = %lld bytes\n", sizeof(char));
  printf("Size of short = %lld bytes\n", sizeof(short));
  printf("Size of int = %lld bytes\n", sizeof(int));
  printf("Size of long = %lld bytes\n", sizeof(long));
  printf("Size of long long = %lld bytes\n", sizeof(long long));
  printf("Size of float = %lld bytes\n", sizeof(float));
  printf("Size of double = %lld bytes\n", sizeof(double));
  printf("Size of long double = %lld bytes\n", sizeof (long double));
  
}