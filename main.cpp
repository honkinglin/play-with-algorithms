#include <iostream>
#include "SortTestHelper.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/MergeSort.h"
#include "Sorting/InsertionSort.h"

using namespace std;

int main() {
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("Selection Sort", SelectionSort::selectionSort, arr, n);
    SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr, n);
    SortTestHelper::testSort("Merge Sort BU", MergeSortBU::mergeSortBU, arr, n);
    SortTestHelper::testSort("Insertion Sort", InsertionSort::insertionSort, arr, n);

    delete[] arr;

    return 0;
}
