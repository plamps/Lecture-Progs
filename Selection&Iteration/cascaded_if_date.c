/* εκτύπωση ονόματος ημέρας με τον κωδικό day */

#include <stdio.h>

int main(int argc, char *argv[]) {

  int day;

  scanf("%d", &day);

  if (day == 1) 
    printf("Mon\n");
  else if (day == 2) 
    printf("Tue\n");
  else if (day == 3) 
    printf("Wed\n");
  else if (day == 4) 
    printf("Thu\n");
  else if (day == 5) 
    printf("Fri\n");
  else if (day == 6) 
    printf("Sat\n");
  else if (day == 7) 
    printf("Sun\n");
  else 
    printf("wrong code %d\n",day);

  return 0;
}