#include <stdio.h>

void reverse(char *str) {
    char *begin = str; // Κρατάμε έναν δείκτη στην αρχή του str
    char *rev_str = str;
    char temp;

    while (*str)
        str++; // Βρισκόμαστε στο τέλος του str
    --str; // Πηγαίνουμε ένα βήμα πίσω για να αποφύγουμε τον τελευταίο χαρακτήρα

    while (rev_str < str) {
        temp = *rev_str;
        *rev_str = *str;
        *str = temp;
        rev_str++;
        str--;
    }

    printf("Αντίστροφο μήνυμα: %s\n", begin);
}

int main(void) {
    char message[] = "Madam, I am Adam";
    reverse(message);
    return 0;
}