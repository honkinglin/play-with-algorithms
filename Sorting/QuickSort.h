#ifndef PLAY_WITH_ALGORITHMS_QUICKSORT_H
#define PLAY_WITH_ALGORITHMS_QUICKSORT_H

namespace QuickSort {
    // partition the array arr[l...r] and return the index p
    // such that arr[l...p-1] < arr[p] and arr[p+1...r] > arr[p]
    template<typename T>
    int __partition(T arr[], int l, int r) {
        // choose the first element as the pivot
        T v = arr[l];
        // arr[l+1...j] < v, arr[j+1...i) > v
        int j = l;
        for (int i = l + 1; i <= r; i++) {
            if (arr[i] < v) {
                swap(arr[j + 1], arr[i]);
                j++;
            }
        }
        swap(arr[l], arr[j]);
        return j;
    }

    // quick sort the array arr[l...r]
    template<typename T>
    void __quickSort(T arr[], int l, int r) {
        if (l >= r) {
            return;
        }

        int p = __partition(arr, l, r);
        __quickSort(arr, l, p - 1);
        __quickSort(arr, p + 1, r);
    }

    template<typename T>
    void quickSort(T arr[], int n) {
        __quickSort(arr, 0, n - 1);
    }
} // QuickSort

#endif //PLAY_WITH_ALGORITHMS_QUICKSORT_H
