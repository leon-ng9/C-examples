void merge (int a[], int low, int high) {
    int numItems = high - low + 1;
	int *tmpSorted = malloc(numItems * sizeof(int));

	int mid = (low + high) / 2;

	int i = low;
	int j = mid + 1; // keep consistent with mergeSort
	int k = 0;

	// scan bottom half and upper half
	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			tmpSorted[k++] = a[i++];
		} else {
			tmpSorted[k++] = a[j++];
		}
	}

	// copy remaining items from one half
	while (i <= mid) {
		tmpSorted[k++] = a[i++];
	}
	while (j <= high) {
		tmpSorted[k++] = a[j++];
	}

	// copy tmpSorted to main
	for (i = low, k = 0; i <= high; i++, k++) {
		a[i] = tmpSorted[k];
	}

	free(tmpSorted);
}

void mergeSort(int a[], int low, int high) {
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, high);
}