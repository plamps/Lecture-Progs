/* ανάγνωση και πρόσθεση δύο θετικών αριθμών, μέχρι να δοθεί 
   σε έναν από τους δύο μια τιμή μικρότερη από ή ίση με 0    */

#include <stdio.h>

int main(int argc, char *argv[]) {

  int a,b;

  while (1) {

    printf("enter 2 ints > 0 or 0 to stop: ");
    scanf("%d %d",&a, &b); 

    if ((a <= 0) || (b <= 0)) { 
        break; 
    }
    
    printf("%d plus %d is %d\n", a, b, a+b);
  
  }

}
