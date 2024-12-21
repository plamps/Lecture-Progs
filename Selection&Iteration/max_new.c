#include <stdio.h>

int i, j, k, day, max=0;
int main() {

scanf("%d%d%d", i,j,k);

	if (i > j) {
	  if (i > k) {
	    max = i;
	  } else {
	    max = k;
	  }
	} else {
	  if (j > k) {
	    max = j;
	  } else {
	    max = k;
	  }
	}
}
