/*********************************
 ** File testAssert.c
 ** Author: IBM (https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-assert-verify-condition)
 **
 ** This file demonstrates use of
 ** assert macro for testing input 
 ** values of a function: string 
 ** must not be NULL or empty and 
 ** length argument must be positive
*******************************/

#include <stdio.h>
#include <assert.h>

void analyze(char *, int);
int main(void) {
    char *string1 = "ABC";
    char *string2 = "";
    int length = 3;

    analyze(string1, length);
    printf("string1 %s is not null or empty, "
          "and has length %d \n", string1, length);
    analyze(string2, length);
    printf("string2 %s is not null or empty,"
          "and has length %d\n", string2, length);
}

void analyze(char *string, int length) {
   assert(string != NULL);     /* cannot be NULL */
   assert(*string != '\0');    /* cannot be empty */
   assert(length > 0);         /* must be positive */
}