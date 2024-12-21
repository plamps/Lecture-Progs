#include "contacts.h"

struct entry entries[N];

void contact_init() {
    int i;
    for (i=0; i<N; i++) { 
        entries[i].used=0; 
    }
}
/* internal_find returns N if name does not exist in the database or the element id 
*  of the entry that matches name 
*/
int internal_find(const char name[]) {
    int i;
    for (i=0; (i<N) && ((!entries[i].used) || (strcmp(entries[i].name,name))); i++)
        ;
    return(i);
}

int contact_find(const char name[], char phone[]) {
    int i;
    
    i=internal_find(name);
    
    if (i==N) {
        return(0);
    }
    else { 
        strcpy(phone,entries[i].phone); 
        return(1);
    }
}

void contact_rmv(const char name[]) {
    int i;
    
    i=internal_find(name);
    if (i<N) {
        entries[i].used=0;
    }
}

int contact_add_or_repl(const char name[], const char phone[]) {
    int i;
    
    i=internal_find(name);
    
    if (i<N) { //replace
        strcpy(entries[i].phone,phone);
        return(-1);  
    }
    
    for (i=0; (i<N) && (entries[i].used); i++)
        ;
    
    if (i==N) { //no free space
        return(0);
    }
    
    strcpy(entries[i].name,name);
    strcpy(entries[i].phone,phone);
    entries[i].used=1;
    return(1); /* done */

}