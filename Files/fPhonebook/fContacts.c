#include "fContacts.h"

int main(void) {
    int s, res; 
    char name[64], phone[64];

    contact_init();
    do {
        printf("1. Add/Update\n"); 
        printf("2. Remove\n");
        printf("3. Find\n"); 
        printf("4. Print contacts\n");
        printf("5. Save and Exit\n");
        printf("> "); 
        scanf("%d",&s);
        
        switch (s) {
            case 1: {
                printf("name & phone:");
                scanf("%63s %63s", name, phone);
                res=contact_add_or_repl(name, phone); 
                if (res==1) {
                    printf("Contact added succesfully!\n");
                }
                else if (res==-1) {
                    printf("%s's phone updated succesfully\n", name);
                }
                else {
                    printf("Storage exhausted! Contact will not be added.\n");
                }
                break;
            }
            case 2: {
                printf("name:");
                scanf("%63s", name);
                contact_rmv(name);
                break;
            }
            case 3: {
                printf("name:"); 
                scanf("%63s", name);
                res=contact_find(name, phone); 
                printf("res=%d\n",res);
                if (res) { 
                    printf("phone: %s\n", phone); 
                }
                break;
            }
            case 4: {
                print_mfcontacts();
                break;
            }
            case 5: {
                printf("Saving contacts in file fContacts...\n");
                save_on_exit();
                break;
            }
            default: {
                printf("Valid choices: 1-5\n");
                break;
            }
        }
    } while (s!=5);
}

void contact_init() {
    unsigned int i;
    FILE *fp;

    for (i=0; i<N; i++) { 
        entries[i].used=0; 
    }

    if ((fp = fopen("fContacts", "rb")) == NULL) { // No entries in file
        printf("Cannot open file fContacts!\n");
        exit(EXIT_FAILURE);
    }

    else { //read entries from file
        i = 0;
        while (1) {
            if (fread(&entries[i], sizeof(struct entry), 1, fp) != 1) {
                if (feof(fp)) {
                    break;
                }
                else {
                    printf("Error in reading contacts from fContacts file. Aborting...\n");
                    exit(EXIT_FAILURE);
                }
            }
            i++;
        }
    }

    fclose(fp);
}

long internal_find(const char name[]) {
    long i;

    for (i=0; (i<N) && ((!entries[i].used) || (strcmp(entries[i].name,name))); i++)
        ;
    return i;
}

int contact_find(const char name[], char phone[]) {
    long i;
    
    i=internal_find(name);
    
    if (i==N) { //name not found
        return 0;
    }
    else { //return phone
        strcpy(phone, entries[i].phone);
        return 1;
    }
}

void contact_rmv(const char name[]) {
    long i;
    
    i=internal_find(name);
    if (i<N) {
        entries[i].used=0;
        printf("Entry %ld removed", i);
    }
    else 
        printf("Name %s not found!\n", name);
}

int contact_add_or_repl(const char name[], const char phone[]) {
    long i;
    
    i=internal_find(name);
    
    if (i<N) { //replace
        strcpy(entries[i].phone, phone);
        return -1;
    }
    
    for (i=0; (i<N) && (entries[i].used); i++)
        ;
    
    if (i==N) { //no free space
        return 0;
    }
    
    strcpy(entries[i].name, name);
    strcpy(entries[i].phone, phone);
    entries[i].used=1;
    
    return 1;
} 
    
void save_on_exit() {
    unsigned int i;
    FILE *fp;

    if ((fp = fopen("fContacts", "wb")) == NULL) {
        perror("Error in fopen:");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<N; i++) {
        if (entries[i].used == 1) {
            if (fwrite(&entries[i], sizeof(struct entry), 1, fp) != 1) {
                printf("Error in writing record %d to disk. Aborting...\n", i);
                exit(EXIT_FAILURE);
            }
        }
    }
    fflush(fp);
    fclose(fp);
}

void print_mfcontacts() {
    FILE *fp;
    struct entry record;
    
    printf("Printing memory contacts...\n");
    for (unsigned int i=0; i<N; i++) {
        if (entries[i].used == 1) {
            printf("Name %s, Phone %s\n", entries[i].name, entries[i].phone);
        }
    }
    printf("Printing file contacts...\n");
    if ((fp = fopen("fContacts", "rb")) == NULL) {
        perror("fContacts open error: ");
        exit(EXIT_FAILURE);
    }
    while (1) {
        if (fread(&record, sizeof(struct entry), 1, fp) != 1) {
            if (feof(fp)) {
                break;
            }
            else {
                printf("Error in reading contacts from fContacts file. Aborting...\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("Entry: Name %s, Phone: %s\n", record.name, record.phone);
    }
    fclose(fp);
}
