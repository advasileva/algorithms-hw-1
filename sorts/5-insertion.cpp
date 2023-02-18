void insertion(int *arr, int n) {
    int curr;
    for(int i = 1; i < n; i++) {
        curr = arr[i];
        for (int j = i - 1; j >= 0 && arr[j] > curr; j--) {
            arr[j + 1] = arr[j];
        }
        arr[i + 1] = curr;
    }
}