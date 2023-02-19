#include <math.h>

int digit(int x, int pos, int *pows) {
    int k = 256;
    return (x / pows[pos - 1]) % k;
}

void radixSort(int *a, int n, int *pows) {
    int d, tmp, count, m = 11, k = 256;
    int *b = new int[n];
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
    }
    int *c = new int[k];
    for (int i = 0; i < k; ++i) {
        c[i] = 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < k; j++) {
            c[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            d = digit(a[j], i, pows);
            c[d]++;
        }
        count = 0;
        for (int j = 0; j < k; j++) {
            tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; j++) {
            d = digit(a[j], i, pows);
            b[c[d]] = a[j];
            c[d]++;
        }
        for (int j = 0; j < n; j++) {
            a[j] = b[j];
        }
    }
}

void radix(int *arr, int n) {
    int *pows = new int[11];
    for (int i = 0; i < 11; ++i) {
        pows[i] = 0;
    }
    for (int i = 0; i < 10; ++i) {
        pows[i] = int(pow(256, i));
    }
    radixSort(arr, n, pows);
}