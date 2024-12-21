/***********************************************
 * Makes argv[i] point to the beginning of each
 * token in the line given as input.
 * 
 * Skips blank characters, marks start of each 
 * token and then skips token characters till 
 * next token is found.
************************************************/

#include "readline.h"

void parse(char *line, char **token) {
    
    while (*line != '\0') {
        while (*line == ' ' || *line == '\t' || *line == '\n') { // skip whites, advance line to first non-white char  
            line++; 
        } 
        *token++=line; //token starts here
        while (*line != '\t' && *line != ' ' && *line != '\0') { // token started, advance to the end of token
            line++; 
        }
        *line++='\0'; // marks end of token
    }
    *token=NULL; // no token past this point...
}