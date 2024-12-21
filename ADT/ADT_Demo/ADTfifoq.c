/* ADTfifoq.c – Δήλωση τύπου δεδομένων που χρησιμοποιήθηκε ως 
ημιτελής και υλοποίηση συναρτήσεων με τις λειτουργίες της ουράς */
#include "ADTfifoq.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

struct fifo_queue {
  char buf[N];  /* πίνακας για αποθήκευση χαρακτήρων */
  int in;       /* θέση για τοποθέτηση */
  int out;      /* θέση για απομάκρυνση */
  int occupied; /* πλήθος χαρακτήρων που έχουν τοποθετηθεί στον πίνακα */
};

FIFO_Queue *ADTfifoq_init(void) {
    FIFO_Queue *q;
    
    q = (FIFO_Queue *)malloc(sizeof(FIFO_Queue));
    if (q == NULL) {
        printf("Cannot allocate space for FIFO_Queue\n");
        exit(EXIT_FAILURE);
    }
    q->in=0; 
    q->out=0; 
    q->occupied=0;
    return q;
}

int ADTfifoq_put(FIFO_Queue *q, char c) {
    
    if (q->occupied == N) {
        return(0);
    }
    q->buf[q->in]=c; 
    q->in=(q->in+1)%N; 
    q->occupied++;
    return(1);
}

bool ADTfifoq_empty(const FIFO_Queue *q) {
    return(q->occupied==0);
}

char ADTfifoq_get(FIFO_Queue *q) {
    char c;
    c=q->buf[q->out]; 
    q->out=(q->out+1)%N; 
    q->occupied--;
    return(c);
}

void ADTfifoq_destroy(FIFO_Queue *q) {
    free(q);
}