/* εκτύπωση ονόματος ημέρας με τον κωδικό day */

#include <stdio.h>

int main(int argc, char *argv[]) {

  int day;

  scanf("%d", &day);
	
  switch (day) {
    case 1: { printf("Monday\n"); break; }
    case 2: { printf("Thuesday\n"); break; }
    case 3: { printf("Wednesday\n"); break; }
    case 4: { printf("Thursday\n"); break; }
    case 5: { printf("Friday\n"); break; }
    case 6: { printf("Saturday\n"); break; }
    case 7: { printf("Sunday\n"); break; }
    default:{ printf("wrong day code %d\n",day); }
  }
  return 0;
}
