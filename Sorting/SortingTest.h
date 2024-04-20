//
// Created by kyrielin on 2024-04-19.
//

#ifndef PLAY_WITH_ALGORITHMS_SORTINGTEST_H
#define PLAY_WITH_ALGORITHMS_SORTINGTEST_H

#include <iostream>
#include "../SortTestHelper.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

using namespace std;

namespace SortingTest {
    void test() {
        int n = 100000;
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        int *arr2 = SortTestHelper::copyArray(arr, n);
        int *arr3 = SortTestHelper::copyArray(arr, n);
        int *arr4 = SortTestHelper::copyArray(arr, n);
        int *arr5 = SortTestHelper::copyArray(arr, n);

        cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
        SortTestHelper::testSort("Selection Sort", SelectionSort::selectionSort, arr, n);
        SortTestHelper::testSort("Insertion Sort", InsertionSort::insertionSort, arr2, n);
        SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr3, n);
        SortTestHelper::testSort("Merge Sort BU", MergeSortBU::mergeSortBU, arr4, n);
        SortTestHelper::testSort("Quick Sort", QuickSort::quickSort, arr5, n);
        cout << endl;

        cout << "Test for nearly ordered array, size = " << n << ", random range [0, " << n << "]" << endl;
        int swapTimes = 100;
        arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
        arr2 = SortTestHelper::copyArray(arr, n);
        arr3 = SortTestHelper::copyArray(arr, n);

        SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr, n);
        SortTestHelper::testSort("Quick Sort", QuickSort::quickSort, arr2, n);
        SortTestHelper::testSort("Quick Sort 2 Ways", QuickSort2Ways::quickSort2Ways, arr3, n);
        cout << endl;

        // Test for same value array
        cout << "Test for same value array, size = " << n << ", random range [0, " << n << "]" << endl;
        arr = SortTestHelper::generateRandomArray(n,0,10);
        arr2 = SortTestHelper::copyArray(arr, n);
        arr3 = SortTestHelper::copyArray(arr, n);

        SortTestHelper::testSort("Quick Sort", QuickSort::quickSort, arr, n);
        SortTestHelper::testSort("Quick Sort 2 Ways", QuickSort2Ways::quickSort2Ways, arr2, n);
        SortTestHelper::testSort("Quick Sort 3 Ways", QuickSort3Ways::quickSort3Ways, arr3, n);
        cout << endl;

        delete[] arr;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;
    }
};


#endif //PLAY_WITH_ALGORITHMS_SORTINGTEST_H
