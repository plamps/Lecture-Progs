#include <stdio.h>
#include <stdlib.h>

char *strAppend(const char *s1, const char *s2) {
  int i,j,len1,len2; char *s3;

    for (len1=0; s1[len1]!='\0'; len1++)
        ;
    for (len2=0; s2[len2]!='\0'; len2++)
        ;
    
    s3=(char *)malloc((len1+len2+1)*sizeof(char));

    for (i=0; i<len1; i++) { 
        s3[i]=s1[i];
    }

    for (j=0; j<len2; j++,i++) { 
        s3[i]=s2[j]; 
    } 
        s3[i]='\0';
        return(s3);
}

int main(int argc, char *argv[]) {
    char s1[64],s2[64],*s3;

    scanf("%63s %63s", s1, s2); 
    s3=strAppend(s1,s2);
    printf("%s plus %s is %s\n", s1, s2, s3);
    free(s3);
}
