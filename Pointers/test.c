#include <stdio.h>
#include <string.h>

void remove_extra_spaces(char *str) {
int i = 0, j = 0;
int len = strlen(str);
int in_word = 0;


while (isspace(str[i])) {
i++;
}


while (i < len) {
if (!isspace(str[i])) {

str[j++] = str[i];
in_word = 1;
} else if (in_word) {

str[j++] = ' ';
in_word = 0;
}
i++;
}

if (j > 0 && str[j - 1] == ' ') {
j--;
}


str[j] = '\0';
}

int main() {
char str[81];

printf("Δώστε μια συμβολοσειρά (μέγιστο 80 χαρακτήρες): ");
fgets(str, sizeof(str), stdin);


str[strcspn(str, "\n")] = 0;

remove_extra_spaces(str);

printf("Συμβολοσειρά χωρίς επιπλέον κενά: \"%s\"\n", str);

return 0;
}