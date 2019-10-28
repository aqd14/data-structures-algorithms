cmake_minimum_required(VERSION 3.15)
project(DSA)

set(CMAKE_CXX_STANDARD 11)

add_executable(CircularQueue Queue/CircularQueue.cpp)
add_executable(BinarySearch BST/BinarySearch.cpp)
add_executable(BST2MinHeap BST/BST2MinHeap.cpp)
add_executable(MergeSort Sorting/SortingUtility.cpp Sorting/MergeSort.cpp)
add_executable(BubbleSort Sorting/SortingUtility.cpp Sorting/BubbleSort.cpp)
add_executable(InsertionSort Sorting/SortingUtility.cpp Sorting/InsertionSort.cpp)
add_executable(SelectionSort Sorting/SortingUtility.cpp Sorting/SelectionSort.cpp)
add_executable(ShellSort Sorting/SortingUtility.cpp Sorting/ShellSort.cpp)
add_executable(CoutingSort Sorting/SortingUtility.cpp Sorting/CoutingSort.cpp)