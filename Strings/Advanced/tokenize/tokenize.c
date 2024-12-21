/*******************************************
 * Parses input line and creates tokens
 * Delimeter is every white space character
 * Each argv[i] points to a different token
 * 
 *******************************************/

#include "readline.h"

int main(void) {
    char line[LINE_LEN];
    char *token[ARGS];
    unsigned short i=0;

    printf("Enter line to parse: \n");
    readline(line, LINE_LEN-1);
    parse(line, token);
    if (strcmp(token[0], "exit") == 0) {
        printf("Program exits... bye! \n");
        exit(EXIT_FAILURE);
    }
    while (token[i] != NULL) {
        printf("Token %d is %s \n", i, token[i]);
        i++;
    }
    exit(EXIT_SUCCESS);
}