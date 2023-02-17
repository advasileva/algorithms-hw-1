int SIZE = 4100;

int* copy(int *arr, int n) {
    int *copy = new int[SIZE];
    for (int i = 0; i < n; ++i) {
        copy[i] = arr[i];
    }
    return copy;
}

int* stupid() {
    int *arr = new int[SIZE];
    arr[0] = 3;
    arr[1] = 1;
    arr[2] = 2;
    return arr;
}