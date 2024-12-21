/* Εμφάνιση επιτυχίας ή αποτυχίας με βάση το βαθμό και 
υπολογισμός πλήθους επιτυχόντων */

#include <stdio.h>

int main(void) {

    int grade, num_pass=0, num_fail=0;

    printf("Enter grade, -1 to exit: ");
    scanf("%d", &grade);
    
    while (grade != -1) {
        switch (grade) {
            case 10: case 9: case 8: case 7: case 6: case 5: {
                num_pass++;
                printf("Pass\n");
                break;
            }
            case 4: case 3: case 2: case 1: case 0: {
                num_fail++;
                printf("Fail\n");
                break;
            }
            default: {
                printf("Illegal grade\n");
                break;
            }
        }
        printf("Enter next grade, -1 to exit: ");
        scanf("%d", &grade);
    }
    printf("Number of students passed: %d\n", num_pass);
    printf("Number of students failed: %d\n", num_fail);
    return 0;

}