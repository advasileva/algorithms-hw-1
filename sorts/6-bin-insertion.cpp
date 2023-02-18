int search(int *arr, int x, int l, int r) {
    int m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (arr[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    if (x - arr[l] <= arr[r] - x) {
        return l;
    }
    return r;
}


void binInsertion(int *arr, int n) {
    int k;
    for(int i = 1; i < n; i++) {
        k = search(arr, arr[i], 0, i - 1);
        for (int j = i - 1; j >= k; j--) {
            std::swap(arr[j], arr[j + 1]);
        }
    }
}
