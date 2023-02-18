#include <algorithm>

/*
 * O(n^2)
 */
void bubbleIverson1(int *arr, int n) {
    bool flag = true;
    for(int i = 0; flag; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
    }
}