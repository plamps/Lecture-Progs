/* Βρίσκει το ελάχιστο στοιχείο πίνακα δύο διαστάσεων με χρήση δείκτη */

#include <stdio.h>

#define ROWS 3
#define COLS 4

int find_min(const int a[], int n) {
	int i, min;

    min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
	return min;
}

int main() {
    int i, j, arr[ROWS][COLS], *p;
    
    for (i=0;i<ROWS;i++)
        for (j=0; j<COLS; j++) 
            scanf("%d", &arr[i][j]);

    p = arr[0]; /* Ο p δείχνει στο πρώτο στοιχείο της γραμμής 0 */
    printf("Min is %d\n", find_min(p, ROWS*COLS)); /* Ισοδύναμα: 
    printf("Min is %d\n", find_min(arr[0], ROWS*COLS)); */

}
