// First element geq x (left bin search)
int search(int *arr, int x, int l, int r) {
    int m;
    while (l < r) {
        m = (l + r) / 2;
        if (arr[m] >= x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}


void binInsertion(int *arr, int n) {
    int k;
    for(int i = 1; i < n; i++) {
        k = search(arr, arr[i], 0, i);
        for (int j = i - 1; j >= k; j--) {
            std::swap(arr[j], arr[j + 1]);
        }
    }
}
