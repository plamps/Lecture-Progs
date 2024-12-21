/* μετατροπή ενός μονοψήφιου αριθμού της μορφής 
*  number={whitechar}digit{whitechar} που δίνεται 
*  είσοδος ως χαρακτήρας στον ισοδύναμό του ακέραιο  
*/

#include <stdio.h>

int main(void) {

  char c;
  int v;
  printf("Give a non-negative number: ");
  do {
    c = getchar();
  } while ((c == ' ') || (c == '\n') || (c == '\t'));
  
  v = 0; 
  v = v + c-'0';
  
  do {
    c = getchar();
  } while (c != '\n');

  printf("%d\n", v);
}