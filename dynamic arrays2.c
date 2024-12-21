#include <stdlib.h>

void **t;
int tlen;

void init_array() {
  t=NULL; tlen=0;
}

void trim_array(int len) {
  t=(void**)realloc(t,len*sizeof(void*)); tlen=len;
}

void write_array(int pos, void *v) {
  if (pos >= tlen) { trim_array(pos+1); }
  t[pos]=v;
}

void *read_array(int pos) {
  return(t[pos]);
}

void destroy_array() {
  trim_array(0); t=NULL;
}

int main(int argc, char *argv[]) {
  char s[256],*p; int i;

  init_array(); i = 0;

  do {
    scanf("%255s",s);
    write_array(i,(void*)strdup(s));
    i++;
  } while (strcmp(s,"end"));
  i--;
  for (; i>=0; i--) {
    printf("in for with i=%d...\n", i);
    p = (char*)read_array(i);
    printf("%s\n",p);
    free(p);
  }

  destroy_array();

}
