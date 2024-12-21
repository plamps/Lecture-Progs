/* Εμφάνιση φυσικών αριθμών στο διάστημα [0...n] */ 
#include <stdio.h>
#include <inttypes.h>

void printInts(uint8_t from, uint8_t to) {
  if (from <= to) {
    printf(" %" PRIu8, from);
    printInts(from+1, to);
  }
}

int main() {
  uint8_t n; 	

  printf("Enter int: ");
  scanf("%" SCNu8, &n);
  printInts(0, n);
}  
