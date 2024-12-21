#include <stdlib.h>
#include <stdio.h>

char *t;   // θα χρησιμεύσει ως πίνακας χαρακτήρων
int tlen;  // το πλήθος των στοιχείων του πίνακα

/* αρχικοποιεί το δείκτη και το μέγεθος του πίνακα */
void init_array() { 
    t=NULL; 
    tlen=0;
}

/* αναπροσαρμόζει τον πίνακα σε len χαρακτήρες */
void rearrange_array(int len) {
    printf("In realloc...\n");
    t=(char *)realloc(t, len*sizeof(char));
    tlen=len;
}

/* γράφει στη θέση pos του πίνακα τον χαρακτήρα v, αν χρειάζεται επεκτείνει τον πίνακα */
void write_elem(int pos, char v) {
    if (pos >= tlen) {
        rearrange_array(pos+1);
    }
    t[pos]=v;
}
/* επιστρέφει το στοιχείο του πίνακα που βρίσκεται στη θέση pos */
char read_elem(int pos) { 
    return(t[pos]);
}
/* απελευθέρωση της μνήμης του πίνακα */
void destroy_array() { 
    rearrange_array(0);
    t=NULL;
}

int main() {
    char ch; 
    int i, j;

    init_array(); 
    i = 0;
    
    printf("Phrase to be stored in a dynamic array of chars: ");
    do { 
        ch = getchar();
        write_elem(i, ch);
        i++;
    } while (ch!='\n');

    printf("Contents of the dynamic array of chars: ");
    for (j=0; j<i; j++) {
        printf("%c", read_elem(j));
    }
    printf("\n");

    destroy_array();
}