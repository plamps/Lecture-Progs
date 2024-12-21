#include <inttypes.h>
#include <stdio.h>
 
int main(void) {

    int8_t a;

    printf("%zu\n", sizeof(int64_t));
    printf("%s\n", PRId64);
    printf("%+" PRId64 "\n", INT64_MIN);
    printf("%+" PRId64 "\n", INT64_MAX);
    scanf("%" SCNd8, &a);
    printf("%" PRId8, a);
}
