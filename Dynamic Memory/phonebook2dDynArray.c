/*********************************
 ** File phonebookDynArray.c
 ** Author: S. Lalis
 ** Modified by P. Lampsas
 ** Date: 7/9/23
 ** E-Mail: plampsas@uth.gr
 **
 ** This file creates a phonebook
 ** implementation as a dynamic array 
 ** of structs
*******************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct {
    char name[64];
    char phone[64];
} Entry;

Entry **entries; int n;

void phonebook_init() {
    entries=NULL; 
    n=0;
}

int internal_find(const char name[]) {
    int i; 
    for (i=0; (i<n) && (strcmp(entries[i]->name,name)); i++)
        ;
    return(i);
}

int phonebook_find(const char name[], char phone[]) {
    int i;
    i=internal_find(name);
    if (i == n) { 
        return(0); 
    }
    else { 
        strcpy(phone,entries[i]->phone); 
        return(1); 
    }
}

void phonebook_rmv(const char name[]) {
    int i;
    i=internal_find(name);
    if (i < n) {
        free(entries[i]); 
        entries[i] = entries[n-1];
        n--;
        entries=(Entry **) realloc(entries,n*sizeof(Entry *));
    }
}

int phonebook_add(const char name[], const char phone[]) {
    int i; 

    i=internal_find(name);

    if (i < n) {
        strcpy(entries[i]->phone,phone); 
        return(-1);  /* replace */
    }		

    n++; 
    entries=(Entry **) realloc(entries,n*sizeof(Entry *));
    
    entries[n-1] = (Entry *) malloc(sizeof(Entry));
    strcpy(entries[n-1]->name,name);	
    strcpy(entries[n-1]->phone,phone);	
    return(1); /* done */

}

void phonebook_print() {
    int i;

    for (i=0; i<n; i++) {
        printf("Name %s, phone %s \n", entries[i]->name, entries[i]->phone);
    }

}

int main(int argc, char *argv[]) {
    int s,res; char name[64],phone[64];
    phonebook_init();
    do {
        printf("1. Add\n"); printf("2. Remove\n");
        printf("3. Find\n"); printf("4. Print\n");
        printf("5. Exit\n");
        printf("> "); scanf("%d",&s);
        switch (s) {
            case 1: {
                printf("name & phone:"); scanf("%63s %63s",name,phone);
                res=phonebook_add(name,phone); printf("res=%d\n",res);
            break;
            }
            case 2: {
                printf("name:"); scanf("%63s",name);
                phonebook_rmv(name);
                break;
            }
            case 3: {
                printf("name:"); scanf("%63s",name);
                res=phonebook_find(name,phone); printf("res=%d\n",res);
                if (res) { 
                    printf("phone: %s\n",phone); 
                }
            break;
            }
            case 4: {
                printf("Phonebook entries are: \n");
                phonebook_print();
            break;
            }
        }
    } while (s!=5);
}