#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int years[10];
int months[10];
int days[10];

int main() {
	
	unsigned int i=0, year, month, day;
	char sel[4] = "yes";
	
	for (i=0; i<10; i++) {
		years[i]=0;
		months[i]=0;
		days[i]=0;
	}	
	
	i=0;
	printf("Dwse xronies\n");
	while (i<10) {
		scanf("%d", &years[i]);
		i++;
	}
	i=0;
	printf("Dwse mines\n");
	while (i<10) {
		scanf("%d", &months[i]);
		i++;
	}
	
	i=0;
	printf("Dwse meres\n");
	while (i<10) {
		scanf("%d", &days[i]);
		i++;
	}
// Από εδώ και κάτω βρίσκουμε τις ημερομηνίες μετά από μια ημερομηνία

	printf("Dates are: ");
	for (i=0; i<10; i++) 
		printf("%d.%d.%d \t", days[i], months[i], years[i]);

while (strcmp(sel, "yes") == 0) {
	
	printf("\nYear? ");
	scanf("%d", &year);
	
	printf("Month? ");
	scanf("%d", &month);
	
	printf("Day? ");
	scanf("%d", &day);
	
	printf("Date: %d.%d.%d :\n", day, month, year);
	
	for (i=0; i<10; i++) {
		if (years[i] > year) //σίγουρα μεταγενέστερη ημερομηνία
			printf("Date: %d.%d.%d\n ", days[i], months[i], years[i]);
		else if (years[i] == year) {
			if (months[i] > month) {
				printf("Date: %d.%d.%d\n ", days[i], months[i], years[i]);
			}
			else if (months[i] == month) {
				if (days[i] > day) {
				printf("Date: %d.%d.%d\n ", days[i], months[i], years[i]);
				}
			}	
		}
	}
printf("Continue: (yes/no): ");
scanf("%s", sel);
}
}
