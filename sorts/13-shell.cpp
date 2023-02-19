/*
 * O(n^2)
 */
void shell(int *arr, int n) {
    for (int i = n / 2; i > 0 ; i /= 2) {
        for (int j = i; j < n; ++j) {
            for (int k = j; k >= i && arr[k] < arr[k - i]; k -= i) {
                std::swap(arr[k], arr[k - i]);
            }
        }
    }
}