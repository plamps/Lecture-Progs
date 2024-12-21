#include <stdio.h>

struct entry {
  char used;      /* 1 υπό χρήση, 0 ελεύθερο */
  char name[64];  /* όνομα ως συμβολοσειρά */
  char phone[64]; /* τηλέφωνο ως συμβολοσειρά */
};

int main(void) {
    struct entry e;
    
    printf("size of struct entry is %d\n",sizeof(struct entry));
    
    printf("size of variable e is %d\n",sizeof(e));

}