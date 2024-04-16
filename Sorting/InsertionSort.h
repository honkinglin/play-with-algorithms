#ifndef PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
#define PLAY_WITH_ALGORITHMS_INSERTIONSORT_H

namespace InsertionSort {
    template<typename T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; i++) {
            // find the right position to insert arr[i]
            for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
} // InsertionSort

#endif //PLAY_WITH_ALGORITHMS_INSERTIONSORT_H
