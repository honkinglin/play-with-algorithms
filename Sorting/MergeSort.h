#ifndef PLAY_WITH_ALGORITHMS_MERGESORT_H
#define PLAY_WITH_ALGORITHMS_MERGESORT_H

namespace MergeSort {
    // merge arr[l...mid] and arr[mid+1...r]
    template<typename T>
    void __merge(T arr[], int l, int mid, int r) {
        // create a temporary array to store the elements of arr[l...r]
        T aux[r - l + 1];
        // copy the elements of arr[l...r] to aux
        for (int i = l; i <= r; i++) {
            aux[i - l] = arr[i];
        }

        // merge the two sorted arrays
        int i = l, j = mid + 1;
        // merge arr[l...mid] and arr[mid+1...r]
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }
    }

    // merge sort arr[l...r]
    template<typename T>
    void __mergeSort(T arr[], int l, int r) {
        if (l >= r) {
            return;
        }

        // prevent overflow
        int mid = (r - l) / 2 + l;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        __merge(arr, l, mid, r);
    }

    template<typename T>
    void mergeSort(T arr[], int n) {
        __mergeSort(arr, 0, n - 1);
    }
}

namespace MergeSortBU {
    // merge arr[l...mid] and arr[mid+1...r]
    template<typename T>
    void __merge(T arr[], int l, int mid, int r) {
        // create a temporary array to store the elements of arr[l...r]
        T aux[r - l + 1];
        // copy the elements of arr[l...r] to aux
        for (int i = l; i <= r; i++) {
            aux[i - l] = arr[i];
        }

        // merge the two sorted arrays
        int i = l, j = mid + 1;
        // merge arr[l...mid] and arr[mid+1...r]
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }
    }

    // merge sort arr[l...r]
    template<typename T>
    void mergeSortBU(T arr[], int n) {
        for (int size = 1; size <= n; size += size) {
            for (int i = 0; i + size < n; i += size + size) {
                // merge arr[i...i+size-1] and arr[i+size...i+2*size-1]
                __merge(arr, i, i + size - 1, min(i + size + size - 1, n - 1));
            }
        }
    }
}

#endif //PLAY_WITH_ALGORITHMS_MERGESORT_H
