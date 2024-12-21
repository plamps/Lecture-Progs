/* ταξινόμηση αλφαριθμητικών με ευρετήριο */

#include <stdio.h>
#include <string.h>

#define N 7
#define MAXNAMELEN 7

int main(void) {

    char names[N][MAXNAMELEN],*idx[N],*tmp; 
    int i,j;
    
    for (i=0; i<N; i++) {
        printf("enter name: ");
        scanf("%6s", names[i]);
    }

    for (i=0; i<N; i++) { 
        idx[i] = names[i]; 
    }

    for (i=0; i<N; i++) {
        for (j=i; j<N; j++) {
            if (strcmp(idx[i],idx[j])>0) {
                tmp = idx[i]; 
                idx[i] = idx[j]; 
                idx[j] = tmp;
            }
        }
    }

    for(i=0; i<N; i++) { 
        printf("%s\n", idx[i]); 
    }
}