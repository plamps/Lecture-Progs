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
    int i, j, arr[ROWS][COLS];
    
    for (i=0;i<ROWS;i++)
        for (j=0; j<COLS; j++) 
            scanf("%d", &arr[i][j]);

    for (i=0;i<ROWS;i++)
        for (j=0; j<COLS; j++) 
            printf("%d ", arr[i][j]);

    printf("Min is %d\n", find_min(arr[0], ROWS*COLS));

}
