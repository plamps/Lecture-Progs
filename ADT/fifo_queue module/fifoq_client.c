#include <stdio.h>
#include "fifoq_arr.h"

int main() {
  char c; 
  FIFO_Queue q;
 
  fifoq_init(&q); 
  
  while ((c=getchar()) != '\n') { 
    fifoq_put(&q, c); 
  }

  while (!fifoq_empty(&q)) {
    c = fifoq_get(&q);
    putchar(c);
  }
  putchar('\n');

}
