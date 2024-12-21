#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <stdbool.h>

#define BITS_PER_LONG (sizeof(long)*CHAR_BIT)

static inline uint8_t bits_per_long(void);
static inline unsigned long testBit(unsigned long, unsigned long);
static inline bool testBit1(unsigned long, unsigned long);
static inline unsigned long setBit(unsigned long, unsigned long);
static inline unsigned long deleteBit(unsigned long, unsigned long);
static inline unsigned long changeBit(unsigned long, unsigned long);
static inline unsigned long lowestBit(unsigned long);

int main() {
    printf("bits per long are : %" PRIu8 "\n", bits_per_long());
    printf("bits per long are : %lld\n", BITS_PER_LONG);
    printf("Has bit 3 value 1 in hex 8? %lu \n", testBit(0x8, 3)); // 8: 01000
    printf("Has bit 2 value 1 in hex 10? %d \n", testBit1(0x10, 2)); //10: 10000
    printf("Set bit 2 to 1 in hex 10: %lu \n", setBit(0x10, 2)); // γίνεται 10100
    printf("Set bit 2 to 0 in hex 10: %lu \n", deleteBit(0x10, 2)); //γίνεται 10000
    printf("Toggle value of bit 2 in hex 10: %lu \n", changeBit(0x10, 2)); //γίνεται 10100
    printf("Only lowest bit set of 0x15: %lu\n", lowestBit(0x15));

}

static inline uint8_t bits_per_long(void) {
    //Επιστρέφει το πλήθος των bits του τύπου unsigned long
    int count = 0;
    unsigned int value = ULONG_MAX;

    while (value != 0) {
        if ((value & 0x1) == 0x1) {
            count++;
        }
        value >>= 1;
    }

    printf("Number of bits in the value: %d\n", count);
    return count;
}

static inline unsigned long testBit(unsigned long x, unsigned long i) {
    // Επιστρέφει 0 αν το bit i είναι 0
    // αλλιώς επιστρέφει μια λέξη με το bit i 1
    return ( x & (1UL << i));
}

static inline bool testBit1(unsigned long x, unsigned long i) {
    // Επιστρέφει 1 αν το bit i είναι 1, αλλιώς 0
    return ( 0 != testBit(x, i));
}

static inline unsigned long setBit(unsigned long x, unsigned long i) {
    // Επιστρέφει το x με το bit i 1
    return (x | (1UL << i));
}

static inline unsigned long deleteBit(unsigned long x, unsigned long i) {
    // Επιστρέφει το x με το bit i 0
    return (x & ~(1UL << i));
}

static inline unsigned long changeBit(unsigned long x, unsigned long i) {
    // Επιστρέφει το x με το bit i αντεστραμμένο (toggled)
    return(x ^ (1UL << i));
}

static inline unsigned long lowestBit(unsigned long x) {
    // Επιστρέφει τον ακέραιο όπου μόνο το χαμηλότερο από τα bits που είναι 1 παραμένει 1
    // Επιστρέφει 0 αν δεν υπάρχει κάποιο bit 1
    return x & -x;
}
