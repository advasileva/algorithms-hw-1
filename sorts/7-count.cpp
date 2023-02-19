int MAX = 4101;

void counting(int *arr, int n) {
    int *counter = new int[MAX];
    for (int i = 0; i < MAX; ++i) {
        counter[i] = 0;
    }
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        counter[arr[i]]++;
    }
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < counter[i]; ++j) {
            arr[curr] = i;
            curr++;
        }
    }
    delete[] counter;
}