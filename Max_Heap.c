// Max Heap implemented as an unsorted array

typedef struct heap *Heap;
struct heap {
    int *values; // note: values start from index 1 (0 is empty)
    int maxSize;
    int currSize;
}

Heap newHeap(int maxSize) {
    Heap new = malloc(sizeof(struct heap));
    new->values = malloc(sizeof(int) * (maxSize + 1));
    new->maxSize = maxSize;
    new->currSize = 0;
}

// O(log n)
bool insert(Heap h, int n) {
    if (h->currSize == h->maxSize) {
        return false;
    }

    h->values[currSize + 1] = n;

    // heapify bottom-up
    while (n > 1 && (h->values[n/2] < h->values[n])) {
        // swap parent with child
        int tmp = h->values[n];
        h->values[n] = h->values[n/2];
        h->values[n/2] = tmp;

        n /= 2;
    }

    h->currSize++;
    return true;
}

// O(log n)
int deleteMax(Heap h) {
    assert(h->currSize < h->maxSize);

    int max = h->values[1];
    h->currSize--;

    // replace root with last node in heap
    h->values[1] = h->values[h->currSize + 1];

    // heapify top-down
    int currIndex = 1;
    int childIndex = 2 * currIndex;
    while (childIndex <= h->currSize) {
        if (childIndex+1 <= h->currSize
            && h->values[childIndex] < h->values[childIndex + 1]) {
            childIndex++; // childIndex is the larger of the two children
        }

        if (h->values[currIndex] > h->values[childIndex]) {
            break;
        }

        // swap parent with child
        int tmp = h->values[currIndex];
        h->values[childIndex] = h->values[currIndex];
        h->values[currIndex] = tmp;

        currIndex = childIndex;
        childIndex = 2 * currIndex;
    }

    return max;
}