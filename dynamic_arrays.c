#include <stdlib.h>
#include <stdio.h>

char *t;
int tlen;

void init_array() {
  t=NULL; tlen=0;
}

void trim_array(int len) {
  t=(char*)realloc(t,len*sizeof(char)); tlen=len;
}

void write_array(int pos, char v) {
  if (pos >= tlen) { trim_array(pos+1); }
  t[pos]=v;
}

char read_array(int pos) {
  return(t[pos]);
}

void destroy_array() {
  trim_array(0); t=NULL;
}

int main(int argc, char *argv[]) {
  char s;  int i;

  init_array(); i = 0;

  do {
    scanf("%c",&s);
    write_array(i,s);
    fflush(stdin);
    i++;
  } while (s!='0');
  i--;
  for (; i>=0; i--) {
    printf("\ni=%d\n", i);
    s = read_array(i);
    printf("%c\n",s);
    //free(p);
  }

  destroy_array();

}
