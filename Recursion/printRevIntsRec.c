/* Εμφάνιση φυσικών αριθμών στο διάστημα [0...n] με 
αντίστροφη σειρά */ 
#include <stdio.h>
#include <inttypes.h>

void printIntsRev(uint8_t from, uint8_t to) {
  if (from <= to) {
    printIntsRev(from+1, to);
    printf(" %" PRIu8, from);
  }
}

int main() {
  uint8_t n; 	

  printf("Enter int: ");
  scanf("%" SCNu8, &n);
  printIntsRev(0, n);
}  