#include <stdio.h>
#include <string.h>

void αντίστροφο_μηνύματος(char μήνυμα[]) {
int μήκος = strlen(μήνυμα);

for (int δείκτης = μήκος - 1; δείκτης >=0; δείκτης--){
printf("%c",*(μήνυμα + δείκτης));
}
}
int main () {
char μήνυμα[100];
printf("Εισάγετε ένα μήνυμα:");
fgets(μήνυμα,sizeof(μήνυμα),stdin);

αντίστροφο_μηνύματος(μήνυμα);
return 0;
}