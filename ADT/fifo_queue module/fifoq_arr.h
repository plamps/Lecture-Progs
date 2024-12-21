/* Αρχείο επικεφαλίδας fifoq.h 
Προγραμματιστική διεπαφή για τη FIFO αποθήκη χαρακτήρων */

#ifndef FIFOQ_H
#define FIFOQ_H

#include <stdbool.h>

#define N 100

typedef struct {
  char buf[N];  /* πίνακας για αποθήκευση χαρακτήρων */
  int in;       /* θέση τοποθέτησης χαρακτήρα */
  int out;      /* θέση για απομάκρυνση χαρακτήρα */
  int occupied; /* αριθμός στοιχείων "υπό χρήση" */
} FIFO_Queue;


/* αρχικοποιεί την ουρά */
void fifoq_init(FIFO_Queue *q);

/* αν η ουρά έχει χώρο, τοποθετεί την τιμή c  
   και επιστρέφει 1, διαφορετικά επιστρέφει 0 */
int fifoq_put(FIFO_Queue *q, char c);

/* επιστρέφει 1 αν η ουρά είναι άδεια,
διαφορετικά επιστρέφει 0 */
bool fifoq_empty(const FIFO_Queue *q);

/* ορίζεται μόνο όταν η ουρά δεν είναι κενή!
απομακρύνει και επιστρέφει την επόμενη τιμή
που βρίσκεται αποθηκευμένη στην ουρά */
char fifoq_get(FIFO_Queue *q);

#endif