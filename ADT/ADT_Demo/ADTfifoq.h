/* Αρχείο επικεφαλίδας ADTfifoq.h 
Προγραμματιστική διεπαφή για ΑΔΤ FIFO αποθήκη χαρακτήρων */

#ifndef FIFOQ_H
#define FIFOQ_H

#include <stdbool.h>

typedef struct fifo_queue FIFO_Queue;

/* αρχικοποιεί την ουρά */
FIFO_Queue *ADTfifoq_init(void);

/* αν η ουρά έχει χώρο, τοποθετεί την τιμή c  
   και επιστρέφει 1, διαφορετικά επιστρέφει 0 */
int ADTfifoq_put(FIFO_Queue *q, char c);

/* επιστρέφει 1 αν η ουρά είναι άδεια,
διαφορετικά επιστρέφει 0 */
bool ADTfifoq_empty(const FIFO_Queue *q);

/* ορίζεται μόνο όταν η ουρά δεν είναι κενή!
απομακρύνει και επιστρέφει την επόμενη τιμή
που βρίσκεται αποθηκευμένη στην ουρά */
char ADTfifoq_get(FIFO_Queue *q);

/* απελευθερώνει το χώρο που δεσμεύτηκε για την ουρά */
void ADTfifoq_destroy(FIFO_Queue *q);

#endif