#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    #define SIZE 10
    double A[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}, b[SIZE]; 

    /* Αποθήκευση του Α στο αρχείο test.bin */
    FILE * fp = fopen("test.bin", "wb");
    fwrite(A, sizeof(double), SIZE, fp);
    fclose (fp);

    fp = fopen("test.bin", "r");
    const size_t ret_code = fread(b, sizeof b[0], SIZE, fp); 

    if (ret_code == SIZE)  {
        printf("Array at %p read successfully, contents:\n", (void *)&b);
        for (int n = 0; n != SIZE; ++n)
            printf("%.2f ", b[n]);
        putchar('\n');
    }
    else  { /* χειρισμός λαθών */
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else if (ferror(fp))
            perror("Error reading test.bin");
    }
}
