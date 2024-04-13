#ifndef PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
#define PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper {

    // generate a random array with n elements, each element is between [rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        // seed
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    // print the array
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // check if the array is sorted
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // test the sort algorithm
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
        return;
    }

    // copy the array
    template<typename T>
    T* copyArray(T arr[], int n) {
        T *arrCopy = new T[n];
        copy(arr, arr + n, arrCopy);
        return arrCopy;
    }

    // generate nearly ordered array
    int* generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }
};


#endif //PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
