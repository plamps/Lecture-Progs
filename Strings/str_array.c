#include <stdio.h>
#include <string.h>
int main(void)
{
char str[] = "noteasy";
printf("%s\n", str+(*(str+3)-1)-str[strlen(str+3)]);
return 0;
}