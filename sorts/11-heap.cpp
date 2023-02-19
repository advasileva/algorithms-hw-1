#include <algorithm>

void heapify(int *arr, int i, int n) {
    if (i >= n) {
        return;
    }
    int left = 2 * i + 1, right = left + 1, largest = i;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void heap(int *arr, int n) {
    for (int i = n / 2; i >= 0; --i) {
        heapify(arr, i, n);
    }
    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}