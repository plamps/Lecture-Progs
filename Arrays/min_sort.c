/* ταξινόμηση πίνακα σε αύξουσα σειρά*/
#include<stdio.h>
#define N 10

int main(void) {
    
    int t[N];  /* πίνακας με Ν ακεραίους */
    int i,j;   /* μετρητές βρόχων */
    int k;     /* θέση τοποθέτησης μικρότερου στοιχείου */
    int tmp;   /* βοηθητική μεταβλητή για ανταλλαγή θέσης */

    /* Δώσε τα στοιχεία του πίνακα t, ένα σε κάθε γραμμή */
    printf("Insert %d ints to be sorted, one per line\n", N);
    for (i=0; i<N; i++) {
        scanf("%d", &t[i]);
    } 	

    for (i=0; i<N; i++) {
        k = i;
        for (j=i+1; j<N; j++) {
            if (t[j] < t[k]) { 
                k = j; 
            }
        }
        if (k != i) {
            tmp = t[i]; 
            t[i] = t[k]; 
            t[k] = tmp;
        }
    }
    printf("Sorted ints: ");
    for (i=0; i<N; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}