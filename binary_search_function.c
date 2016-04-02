// O(log n)

// recursive
int binarySearch(int a[], int low, int high, int n) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    if (a[mid] < n) {
        return binarySearch(a, mid+1, high, n);
    } else if (a[mid] > n) {
        return binarySearch(a, low, mid - 1, n);
    } else {
        return mid;
    }
}

// iterative
int binarySearch(int a[], int size, int n) {
	int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        } else {
            return mid;
        }

        return -1;
    }
}