// Priority queue implemented as an (unsorted) array

typedef struct PQueue *PQueue;

struct PQueue {
    int *values;
    int maxSize;
    int currSize;
};

PQueue newPQueue(int maxSize) {
    PQueue new = malloc(sizeof(struct PQueue));
    if (new == NULL) {
        return exit(EXIT_FAILURE);
    }
    new->values = malloc(sizeof(int) * MAX_QUEUE_SIZE)
    if (new == NULL) {
        return exit(EXIT_FAILURE);
    }
    new->maxSize = maxSize;
    new->currSize = 0;
}

/* Unsorted array implementation */

// O(1)
bool insert(PQueue pq, int n) {
    if (pq->currSize == pq->maxSize) {
        return false;
    }

    pq->values[pq->currSize] = n;
    pq->currSize++;
    return true;
}

// O(n)
int deleteMax(PQueue pq) {
    assert(pq->currSize > 0);

    int indexOfMax = 0;
    int i;
    for (i = 1; i < pq->currSize; i++) {
        if (pq->values[i] > pq->values[indexOfMax]) {
            indexOfMax = i;
        }
    }

    int max = pq->values[indexOfMax];

    // replace max with last item in array
    pq->values[indexOfMax] = pq->values[pq->currSize - 1];

    pq->currSize--;
    return max;
}

/* Sorted array implementation */

// O(n)
bool insert(PQueue pq, int n) {
    if (pq->currSize == pq->maxSize) {
        return false;
    }

    int indexToInsert = 0;
    while (indexToInsert < pq->currSize && pq->values[indexToInsert] < n) {
        indexToInsert++;
    }    

    // shift upper array
    int i;
    for (i = pq->currSize - 1; i > indexToInsert; i--) {
        pq->values[i] = pq->values[i-1];
    }

    pq->values[indexToInsert] = n;
    pq->currSize++;
    return true;
}

// O(1)
int deleteMax(PQueue pq) {
    assert(pq->currSize > 0);

    pq->currSize--;
    return pq->values[currSize];
}