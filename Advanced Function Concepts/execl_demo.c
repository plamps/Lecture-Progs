/* Πρόγραμμα 15.3. exec_variation.c - Υλοποίηση
της execl(). Το πρόγραμμα εκτελείται σε Linix/Unix
ή WSL */ 
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define MAXargs 31

int _execl (const char *path, ...) {
  va_list Argp;
  char *array [MAXargs];
  int argno=0;
  va_start (Argp, path);
  while ((array[argno++] = va_arg(Argp, char *)) != (char *)NULL)
    ;
  va_end(Argp);

  return(execv(path, array));
}

int main(int argc, char **argv) {
  _execl("/usr/bin/echo", argv[0], "Test", "message", (char *)NULL);  
  /* To argv[0] απορρίπτεται */
}
