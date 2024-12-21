#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define LINE_LEN 128
#define ARGS 32

int readline (char str[], int n);
void parse (char *line, char **token);