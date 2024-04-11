#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int L, int R) {
    int i = L + 1;
    int r = R;
    while (1) {
        while (arr[i] < arr[L]) {
            i++;
        }
        while (arr[r] > arr[L]) {
            r--;
        }
        if (i < r) {
            swap(&arr[i], &arr[r]);
            i++;
            r--;
        } else {
            swap(&arr[L], &arr[r]);
            return r;
        }
    }
}

void quickSort(int arr[], int p, int q) {
    if (p < q) {
        int x = partition(arr, p, q);
        quickSort(arr, p, x - 1);
        quickSort(arr, x + 1, q);
    }
}

int main() {
    int n;
    int arr[] = {12, 11, 13, 5, 6, 7};
    n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
