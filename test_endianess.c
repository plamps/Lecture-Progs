#include <unistd.h>
#include <inttypes.h>
int main()
{
uint32_t i = 0x33323130; // "3210"
write(1, &i, sizeof(uint32_t));
return 0;
}
