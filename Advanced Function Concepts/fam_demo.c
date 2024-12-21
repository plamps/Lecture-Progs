/* Πρόγραμμα επίδειξης του τρόπου χρήσης των Flexible 
Array Members (FAM) σε structs */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Δομή που αποθηκεύει πληροφορίες για φοιτητές
struct student {
    int id;
    int struct_size;
    char std_name[]; /*Flexible Array Member (FAM)
    Ο πίνακας μεταβλητού μεγέθους πρέπει να είναι
    το τελευταίο πεδίο της δομής */
};

/* Δυναμική ανάθεση μνήμης και γέμισμα δομής με τιμές */
struct student* createStudent(int id, char name[]) {
    /* Ανάθεση μνήμης για τη δομή και τον πίνακα FAM */
    struct student *s = malloc(sizeof(*s) + 
                    sizeof(char) * (strlen(name) + 1)); 

    if (s == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    s->id = id;
    /* Υπολογισμός του συνολικού μεγέθους του *s */
    s->struct_size = sizeof(s->id) + 
            sizeof(char)*(strlen(name)+1);
    strcpy(s->std_name, name); /* Αντιγραφή ονόματος, 
    το std_name έχει πλέον χώρο για να αποθηκεύσει 
    συμβολοσειρά */

    return s;
}

// Εμφάνιση δεδομένων φοιτητή
void printStudent(struct student* s) {
    printf("Student_id : %d\n"
        "Student name : %s\n"
        "Name_Length: %lld\n"
        "Initially Allocated struct size: %llu\n"
        "Total size of struct for student %s is %d\n\n",
        s->id, s->std_name, strlen(s->std_name),
        sizeof *s, s->std_name, s->struct_size);
}

/* Πρόγραμμα επίδειξης λειτουργιών FAM */
int main() {
    struct student* s1 = createStudent(123, "Petros");
    struct student* s2 = createStudent(345, "Helen");

    printStudent(s1);
    printStudent(s2);

    printf("Size of Struct pointer: %llu\n", sizeof s1);

    // Απελευθέρωση δεσμευμένης μνήμης
    free(s1);
    free(s2);

    return 0;
}