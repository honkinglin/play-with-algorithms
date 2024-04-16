#ifndef PLAY_WITH_ALGORITHMS_SELECTIONSORT_H
#define PLAY_WITH_ALGORITHMS_SELECTIONSORT_H

namespace SelectionSort {
    template<typename T>
    void selectionSort(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            // find the minimum element in arr[i...n)
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
} // SelectionSort

#endif //PLAY_WITH_ALGORITHMS_SELECTIONSORT_H
