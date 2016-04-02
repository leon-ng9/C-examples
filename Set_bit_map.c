// Set implemented as a bit map

#define NUM_SECTIONS 10
#define NUM_BITS (sizeof(int)*NUM_SECTIONS) // range of values in Set is restricted 
                                            // between 0..(NUM_BITS-1)
typedef int bits[NUM_SECTIONS] bitMap;

void setBit(bitMap b, int n) {
    assert(n < NUM_BITS);

    int section = i / NUM_SECTIONS;
    int positionInSection = i % 32;

    b[section] |= (1 << (31 - positionInSection));
}

void unsetBit(bitMap b, int n) {
    assert(n < NUM_BITS);

    int section = i / NUM_SECTIONS;
    int positionInSection = i % 32;

    b[section] &= ~(1 << (31 - positionInSection));
}