/*
 * -> O(nlog(n))
 */
void shellCiura(int *arr, int n) {
    int ciura[] = {1 , 4, 10, 23, 57, 132, 301, 701, 1750};
    for (int i : ciura) {
        for (int j = i; j < n; ++j) {
            for (int k = j; k >= i && arr[k] < arr[k - i]; k -= i) {
                std::swap(arr[k], arr[k - i]);
            }
        }
    }
}