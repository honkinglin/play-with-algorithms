cmake_minimum_required(VERSION 3.27)
project(play_with_algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(play_with_algorithms main.cpp
        Sorting/MergeSort.h
        Sorting/SelectionSort.h
        Sorting/InsertionSort.h
        Sorting/QuickSort.h)
