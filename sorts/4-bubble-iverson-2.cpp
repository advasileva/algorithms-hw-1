#include <algorithm>

/*
 * O(n^2)
 */
void bubbleIverson2(int *arr, int n) {
    int last = n;
    bool flag = true;
    for(int i = 0; flag; i++) {
        flag = false;
        // Incorrect
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
                last = j;
            }
        }
    }
}