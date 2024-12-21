#include <stdio.h>
#include "contacts.h"

void contact_init(); 
/* αρχικοποιεί τις καθολικές μεταβλητές 
   ή/και δομές δεδομένων του προγράμματος */

int contact_find(const char name[], char phone[]);
/* δέχεται σαν πρώτη παράμετρο ένα αλφαριθμητικό όνομα και
   αποθηκεύει στην δεύτερη παράμετρο το αντίστοιχο τηλέφωνο,
   επιστρέφοντας 1 για επιτυχία και 0 για αποτυχία */

void contact_rmv(const char name[]);
/* δέχεται σαν παράμετρο ένα αλφαριθμητικό όνομα και
   "απομακρύνει" την αντίστοιχη εγγραφή, αν υπάρχει */

int contact_add_or_repl(const char name[], const char phone[]);
/* επιχειρεί να εισάγει μια νέα εγγραφή με το όνομα και
   τηλέφωνο που δίνονται σαν παράμετροι, και επιστρέφει
   1 για επιτυχία, 0 για αποτυχία λόγω έλλειψης χώρου 
   και -1 για αντικατάσταση υπάρχουσας εγγραφής */

int main(void) {
    int s,res; 
    char name[64],phone[64];
    
    contact_init();
    
    do {
        printf("1. Add\n"); 
        printf("2. Remove\n");
        printf("3. Find\n"); 
        printf("4. Exit\n");
        printf("> "); 
        scanf("%d",&s);
        
        switch (s) {
            case 1: {
                printf("name & phone:");
                scanf("%63s %63s",name,phone);
                res=contact_add_or_repl(name,phone); 
                printf("res=%d\n",res);
                break;
            }
            case 2: {
                printf("name:");
                scanf("%63s",name);
                contact_rmv(name);
                break;
            }
            case 3: {
                printf("name:"); 
                scanf("%63s",name);
                res=contact_find(name,phone); 
                printf("res=%d\n",res);
                if (res) { 
                    printf("phone: %s\n",phone); 
                }
                break;
            }
        }
    } while (s!=4);
}