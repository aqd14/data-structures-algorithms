//
// Created by Quoc Anh Do on 10/28/19.
// Implementation of Quick Sort

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class QuickSort {
public:

    static void Sort(std::vector<int> &inputs) {
        Sort(inputs, 0, inputs.size()-1);
    }

    static void Sort(std::vector<int> &inputs, int low, int high) {
        if (low >= high) return;
//        std::cout << "Inside quick sort..." << std::endl;
        unsigned long pivot = partition(inputs, low, high);
        Sort(inputs, low, pivot-1);
        Sort(inputs, pivot+1, high);
    }

    /**
     * Partition the vector by the pivot. Choose the pivot to be the last element in the range, i.e., low
     * Every element on left of the pivot is less than or equal than it. Every element on the right is greater than the pivot
     * @param inputs input vector
     * @param low lower bound of the examining vector
     * @param high upper bound of the examining vector
     * @return the new index of the pivot
     */
    static unsigned long partitionLomuto(std::vector<int> &inputs, int low, int high) {
        int pivot = inputs[high]; // Choose the pivot to be the last element in the range [low, high]
//        std::cout << "pivot = " << pivot << std::endl;
        // elements from low to i-1 (inclusive) are equal or less than the pivot
        // and the element from i to j (inclusive) are greater than the pivot
        int i = low;
        int j = low;
        for (; j < high; j++) {
            if (inputs[j] <= pivot) {
                SortingUtility::Swap(inputs, i, j);
                i++;
            }
        }
        SortingUtility::Swap(inputs, i, high);
        return i;
    }

    /**
    * Sedgewick and Wayne's Implementation.
    *
    * First, choose inputs[low] to be the pivot. Next, scan from the left end of the vector
    * until we find the element greater than the pivot, scan from the right end to find the element
    * less than or equal to the pivot. Exchange these two elements to maintain the pivot property.
    * Make sure the 'left' index doesn't exceed the 'high' and the 'right' index doesn't pass the 'low'
    * When the 'left' and 'right' cross, we just need to swap the pivot with the element at the 'right' index,
    * which is the rightmost entry of the left subarray and returns index 'right'
    *
    * @param inputs input vector
    * @param low lower bound of the examining vector
    * @param high upper bound of the examining vector
    * @return the new index of the pivot
    */
    static int partition(std::vector<int> &inputs, int low, int high) {
        int left = low;
        int right = high+1;
//        int mid = low + (high - low) / 2;
        int pivot = inputs[low]; //inputs[low + (high - low) / 2];

        while (true) {
            while (inputs[++left] < pivot) {
                if (left == high) break;
            }

            while (inputs[--right] > pivot) {
                if (right == low) break;
            }

            if (left >= right) break;
            SortingUtility::Swap(inputs, left, right);
        }
        SortingUtility::Swap(inputs, low, right);
        return right;
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> inputs = SortingUtility::GenerateVectorInput(size, max_value);// {45, 59, 30, 70, 21, 11, 31, 14, 5, 35};
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(inputs);

    QuickSort::Sort(inputs);
    assert(SortingUtility::IsSorted(inputs));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(inputs);
    return 0;
}
