/*********************************
 ** File dynPhonebook.c
 ** Author: P. Lampsas
 ** Date: 10/11/2023
 ** E-Mail: plampsas@uth.gr
 **
 ** dynPhonebook.c implements a 
 ** phonebook as a dynamic array 
 ** of structs
**********************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <inttypes.h>

typedef struct entry {
    char name[64]; 
    char phone[11];
} Entry;

/* initializes data structure and number of entries */
void phonebook_init(Entry **db, uint32_t *numEntries) {
    *db = NULL; 
    *numEntries = 0;
}

/* removes a record */
void phonebook_rmv(Entry **db, const Entry record, uint32_t *numEntries) {

    uint32_t i;

    if (*numEntries == 0) {
        printf("Phonebook DB is empty!\n");
        return;
    } 

    for (i = 0; (i < *numEntries) && (strcmp((*db)[i].name, record.name)); i++)
        ;
    if (i < *numEntries) {
        memcpy(&(db[i]), &(db[*numEntries-1]), sizeof(Entry));
        (*numEntries)--;
        *db = (Entry *) realloc(*db, *numEntries*sizeof(Entry));
        if (*db == NULL && *numEntries > 0) {
            printf("In phonebook_rmv: Cannot reallocate space!\n");
            exit(EXIT_FAILURE);
        }
        printf("Record removed succesfully!\n");
    }
}

/* adds a record or updates an existing one */
long int pnbk_add_update(Entry **db, const Entry record, uint32_t *numEntries) {

    uint32_t i;

    for (i = 0; (i < *numEntries) && (strcmp((*db)[i].name, record.name)); i++)
        ;

    if (i < *numEntries) {
        strcpy((*db)[i].phone, record.phone); 
        return(-1);  /* update done */
    }		
    printf("Adding...%s %s\n", record.name, record.phone);
    (*numEntries)++; 

    *db = (Entry *) realloc(*db, *numEntries*sizeof(Entry));
    if (*db == NULL) {
        printf("In pnbk_add_update: Cannot realloc DB!\n");
        exit(EXIT_FAILURE);
    }
    memcpy(&((*db)[*numEntries-1]), &record, sizeof(Entry));

    return(1); /* add done */
}

/* finds record position of an entry given the name */
long int phonebook_find(const Entry *db, Entry record, const uint32_t numEntries) {
    
    uint32_t i;

    if (numEntries == 0) {
        printf("Phonebook DB is empty!\n");
        return(-2);
    }

    for (i = 0; (i < numEntries) && (strcmp(db[i].name, record.name)); i++)
        ;
    if (i < numEntries) {
        return((long int)i); //position of record
    }
    else {
        return(-1); //record not found
    }
}

/* prints phonebook contents */
void phonebook_print(const Entry *db, const uint32_t numEntries) {

    uint32_t i;

    if (numEntries == 0) {
        printf("Phonebook DB is empty!\n");
        return;
    } 

    printf("Phonebook entries are: \n");
    for (i=0; i<numEntries; i++) {
        printf("Name %s, phone %s \n", db[i].name, db[i].phone);
    }

}

/* frees dynamic array and sets number of entries to zero */
void phonebook_exit(Entry **db, uint32_t *numEntries) {
    *db = (Entry *) realloc(*db, 0);
    *numEntries = 0;
}


int main(void) {

    long int res; 
    Entry record;
    Entry *db; 
    uint32_t s, numEntries;

    phonebook_init(&db, &numEntries);
    
    while (1) {
        printf("1. Add\n"); 
        printf("2. Remove\n");
        printf("3. Find\n"); 
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("> "); 
        scanf("%u", &s);

        switch (s) {
            case 1: {
                printf("Add record or update phone number: \n");
                printf("(To update a phone number enter an already existing name.) \n");
                printf("Enter name to add: ");
                scanf(" %63[^\n]", record.name);
                printf("Enter phone to add: ");
                scanf(" %11[^\n]", record.phone);
                res = pnbk_add_update(&db, record, &numEntries); 
                if (res==1) {
                    printf("Contact inserted succesfully!\n");
                }
                else {
                    printf("Phone for %s updated succesfully! \n", record.phone);
                }
            break;
            }
            case 2: {
                printf("Name: "); 
                scanf(" %63[^\n]", record.name);
                phonebook_rmv(&db, record, &numEntries);
                break;
            }
            case 3: {
                printf("Name:"); 
                scanf(" %63[^\n]", record.name);
                res=phonebook_find(db, record, numEntries); 
                if (res >= 0) { 
                    printf("Phone: %s\n", db[res].phone); 
                }
                else {
                    printf("Name %s does not exist in phonebook.\n", record.name);
                }
            break;
            }
            case 4: {
                phonebook_print(db, numEntries);
            break;
            }
            case 5: {
                printf("Exiting... Entries are erased! \n");
                phonebook_exit(&db, &numEntries);
                exit(EXIT_SUCCESS);
            }
            default: 
            printf("Give an entry between 1 and 5 \n");
        }
    }
}