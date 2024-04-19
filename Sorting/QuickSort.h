#ifndef PLAY_WITH_ALGORITHMS_QUICKSORT_H
#define PLAY_WITH_ALGORITHMS_QUICKSORT_H

//#include "InsertionSort.h"

namespace QuickSort {
    // partition the array arr[l...r] and return the index p
    // such that arr[l...p-1] < arr[p] and arr[p+1...r] > arr[p]
    template<typename T>
    int __partition(T arr[], int l, int r) {
        // optimization: choose a random element as the pivot
        swap(arr[l], arr[rand() % (r - l + 1) + l]);

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
//        if (l >= r) {
//            return;
//        }

        // optimization: use insertion sort for small arrays
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr + l, r - l + 1);
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

namespace QuickSort2Ways {
    // partition the array arr[l...r] and return the index p
    // such that arr[l...p-1] <= arr[p] and arr[p+1...r] >= arr[p]
    template<typename T>
    int __partition2Ways(T arr[], int l, int r) {
        // optimization: choose a random element as the pivot
        swap(arr[l], arr[rand() % (r - l + 1) + l]);

        // choose the first element as the pivot
        T v = arr[l];
        // arr[l+1...i) <= v, arr(j...r] >= v
        int i = l + 1, j = r;
        while (true) {
            while (i <= r && arr[i] < v) i++;
            while (j >= l + 1 && arr[j] > v) j--;

            if (i > j) break;

            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        swap(arr[l], arr[j]);
        return j;
    }

    // quick sort the array arr[l...r]
    template<typename T>
    void __quickSort2Ways(T arr[], int l, int r) {
        // optimization: use insertion sort for small arrays
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr + l, r - l + 1);
            return;
        }

        int p = __partition2Ways(arr, l, r);
        __quickSort2Ways(arr, l, p - 1);
        __quickSort2Ways(arr, p + 1, r);
    }

    template<typename T>
    void quickSort2Ways(T arr[], int n) {
        __quickSort2Ways(arr, 0, n - 1);
    }
}

namespace QuickSort3Ways {
    // partition the array arr[l...r] and return the index p
    // such that arr[l...lt] < arr[p], arr[lt+1...i) == arr[p], arr[gt...r] > arr[p]
    template<typename T>
    void __partition3Ways(T arr[], int l, int r, int &lt, int &gt) {
        // optimization: choose a random element as the pivot
        swap(arr[l], arr[rand() % (r - l + 1) + l]);

        T v = arr[l];
        // arr[l+1...lt] < v, arr[lt+1...i) == v, arr[gt...r] > v
        lt = l, gt = r + 1;
        for (int i = l + 1; i < gt;) {
            if (arr[i] < v) {
                swap(arr[i], arr[lt + 1]);
                lt++;
                i++;
            } else if (arr[i] > v) {
                swap(arr[i], arr[gt - 1]);
                gt--;
            } else {
                i++;
            }
        }
        swap(arr[l], arr[lt]);
        lt--;
    }

    // quick sort the array arr[l...r]
    template<typename T>
    void __quickSort3Ways(T arr[], int l, int r) {
        // optimization: use insertion sort for small arrays
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr + l, r - l + 1);
            return;
        }

        int lt, gt;
        __partition3Ways(arr, l, r, lt, gt);
        __quickSort3Ways(arr, l, lt);
        __quickSort3Ways(arr, gt, r);
    }

    template<typename T>
    void quickSort3Ways(T arr[], int n) {
        __quickSort3Ways(arr, 0, n - 1);
    }

}

#endif //PLAY_WITH_ALGORITHMS_QUICKSORT_H
