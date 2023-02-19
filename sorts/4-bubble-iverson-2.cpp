#include <algorithm>

/*
 * O(n^2)
 */
void bubbleIverson2(int *arr, int n) {
    int lastSwap = n, prevSwap;
    bool flag = true;
    for(int i = 0; flag; i++) {
        flag = false;
        for (int j = 0; j < lastSwap; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
                prevSwap = j;
            }
        }
        lastSwap = prevSwap;
    }
}