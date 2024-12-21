#include <stdio.h>
#include <string.h>
#define N 60

int main(void) {
    char message[N];
    FILE *fp;
    
    printf("Enter message to write to file \n");
    fgets(message, N, stdin);

    fp = fopen("testFseekText", "w");
    /* Εγγραφή δύο γραμμών σε ένα αρχείο */ 
    fprintf(fp, "Line 1: %s", message); 
    fprintf(fp, "Line 2: %s", message);
    
    fflush(fp);
    fclose(fp);

    fp = fopen("testFseekText", "r");

    fgets(message, N, fp); /* Ανάγνωση της πρώτης γραμμής (στο message τοποθετείται και η αλλαγή γραμμής) */
    printf("Message is: %s\n", message);
    printf("File position now is: %ld\n", ftell(fp)); /* Εμφάνιση της θέσης αρχείου */
    fseek(fp, 0, SEEK_END); /* Η θέση αρχείου μετακινείται στο τέλος αρχείου */ 
    long pos = ftell(fp); /* Ενημέρωση της pos με την τρέχουσα θέση αρχείου */
    printf("File position now is: %ld\n", pos); 
    
    fseek(fp, pos-(strlen(message))-1, SEEK_SET); /* Μετακίνηση της θέσης αρχείου στην αρχή της δεύτερης γραμμής */
    printf("File position now is: %ld\n", ftell(fp)); 
    fgets(message, N, fp); /* Ανάγνωση της δεύτερης γραμμής */
    printf("Message is: %s\n", message);

}