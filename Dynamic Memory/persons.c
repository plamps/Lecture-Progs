/* Program that allocates consecutive space for structs, 
reads values in them and displays struct member values */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    float weight;
    char name[30];
} person;

int main() {

    person *ptr;
    int i, n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    // allocate memory for n consecutive struct(s) person
    ptr = (person *) malloc(n * sizeof(person));
        
    /* Read values in structs using pointer arithmetic */
    for (i = 0; i < n; ++i) {
        printf("Enter name of person %d and age respectively: ", i);
        scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
    }

    printf("Displaying person information: \n");
    for (i = 0; i < n; ++i)
        printf("Name: %s\tAge: %d\n", ptr[i].name, ptr[i].age);
    
    free(ptr);
    return 0;
}