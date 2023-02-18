#include <algorithm>

/*
 * O(n^2)
 */
void selection(int *arr, int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}