/* σειριακή αναζήτηση σε ταξινομημένο πίνακα */
#include<stdio.h>
#define N 10

int main(void) {
    
    int t[N];     /* πίνακας με Ν ακεραίους */
    int i,j;      /* μετρητές βρόχων */
    int k;        /* θέση τοποθέτησης μικρότερου στοιχείου */
    int v;        /* τιμή στοιχείου που αναζητούμε */
    int m;        /* θέση μεσαίου στοιχείου */
    int beg, end; /* όρια αναζήτησης */
    int tmp;      /* βοηθητική μεταβλητή για ανταλλαγή θέσης */

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
    
    printf("Give the value you want to search for: \n");
    scanf("%d", &v);    
    beg = 0; 
    end = N-1;
    while (beg <= end) {
        m = (beg+end)/2; 
        if (t[m] == v) { 
            break;
        }
        else if (t[m] < v) {
            beg = m+1;
        }
        else {   /* t[m] > v */
            end = m-1;
        }
    } 

    if (beg > end) { 
        printf("not found\n"); 
    }
    else { 
        printf("found at position %d\n", m); 
    }
}
