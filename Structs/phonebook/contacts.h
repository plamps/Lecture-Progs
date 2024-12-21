#include <stdio.h>
#include <string.h>

#define N 100

struct entry {
  char used;      /* 1 υπό χρήση, 0 ελεύθερο */
  char name[64];  /* όνομα ως αλφαριθμητικό */
  char phone[64]; /* τηλέφωνο ως αλφαριθμητικό */
};
