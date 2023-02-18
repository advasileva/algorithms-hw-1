#include <random>

int SIZE = 4100;

int* copy(int *arr, int n) {
    int *copy = new int[SIZE];
    for (int i = 0; i < n; ++i) {
        copy[i] = arr[i];
    }
    return copy;
}

int* small() {
    int *arr = new int[SIZE];
    srand((unsigned) time(NULL));
    int min = 0, max = 5;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = min + (rand() % static_cast<int>(max - min + 1));
    }
    return arr;
}

int* big() {
    int *arr = new int[SIZE];
    srand((unsigned) time(NULL));
    int min = 0, max = 4000;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = min + (rand() % static_cast<int>(max - min + 1));
    }
    return arr;
}
