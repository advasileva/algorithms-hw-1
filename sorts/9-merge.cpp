void merge(int *arr, int l, int r) {
    int currL = 0, currR = 0, curr = 0;
    int *left = new int[l];
    for (int i = 0; i < l; ++i) {
        left[i] = arr[i];
    }
    int *right = new int[r];
    for (int i = 0; i < r; ++i) {
        right[i] = arr[l + i];
    }
    while (currL < l || currR < r) {
        if (currL < l && (currR == r || left[currL] < right[currR])) {
            arr[curr] = left[currL];
            currL++;
        } else {
            arr[curr] = right[currR];
            currR++;
        }
        curr++;
    }
}


void mergeSort(int *arr, int n) {
    if (n < 2) {
        return;
    }
    int m = n / 2;
    mergeSort(arr, m);
    mergeSort(&arr[m], n - m);
    merge(arr, m, n - m);
}