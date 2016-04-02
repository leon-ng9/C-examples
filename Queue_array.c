// Queue implemented as an array

typedef struct queue *Queue;
struct queue {
    int *values;
    int maxSize;
    int currSize;
    int firstIndex;
    int lastIndex;
};

Queue newQueue(int maxSize) {
    Queue new = malloc(sizeof(struct queue));
    if (new == NULL) {
        exit(EXIT_FAILURE);
    }
    new->values = malloc(sizeof(int) * maxSize);
    if (new->values == NULL) {
        exit(EXIT_FAILURE);
    }
    new->maxSize = maxSize;
    new->currSize = 0;
    new->firstIndex = -1;
    new->lastIndex = -1;
}

bool insert(Queue q, int n) {
    if (q->currSize == q->maxSize) {
        return false;
    }

    if (q->currSize == 0) {
        q->values[0] = n;
        q->currSize++;
        q->firstIndex = 0;
        q->lastIndex = 0;
    } else {
        int insertIndex = (q->lastIndex + 1) % q->maxSize;
        q->values[insertIndex] = n;
        q->currSize++;
        q->lastIndex = insertIndex;
    }

    return true;
}

bool dequeue(Queue q) {
    if (q->currSize == 0) {
        return false;
    }

    if (q->currSize == 1) {
        q->currSize--;
        q->firstIndex = -1;
        q->lastIndex = -1;
    } else {
        q->currSize--;
        q->firstIndex = (q->firstIndex + 1) % q->maxSize;
    }

    return true;
}
