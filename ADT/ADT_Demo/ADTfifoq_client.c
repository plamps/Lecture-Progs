/* ADT_fifoq_client.c – Κώδικας πελάτη για την πρόσβαση 
στον ΑΤΔ FIFO αποθήκη χαρακτήρων */
#include <stdio.h>
#include "ADTfifoq.h"

int main() {
    char c; 
    FIFO_Queue *q;
 
    q = ADTfifoq_init(); 
  
    printf("Give input: ");
    while ((c = getchar()) != '\n') { 
        ADTfifoq_put(q, c); 
    }

    ADTfifoq_put(q, 'a');
    ADTfifoq_put(q, 'c');
    
    c = ADTfifoq_get(q);
    putchar(c); 
    c = ADTfifoq_get(q);
    putchar(c); 

    printf("FIFO buffer contents: ");
    while (!ADTfifoq_empty(q)) {
        c = ADTfifoq_get(q);
        putchar(c);
    }
    putchar('\n');

    ADTfifoq_destroy(q);

}