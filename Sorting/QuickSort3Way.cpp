//
// Created by Quoc Anh Do on 10/29/19.
//

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class QuickSort3Way {
public:
    static void Sort(std::vector<int> &inputs) {
        Sort(inputs, 0, inputs.size()-1);
    }

    /**
     * Partition the vector into three sub-arrays, less than, equals, and greater than the pivot.
     *
     * Define 3 indices to mark the boundary of three regions.
     * + [low, lt): all the elements less than the pivot
     * + [lt, i): all the elements equals to the pivot
     * + [gt+1, high]: all the element that are greater than the pivot
     * + [i, gt] not yet examined
     *
     * @param inputs input vector
     * @param low   left most index of examining vector
     * @param high right most index of examining vector
     */
    static void Sort(std::vector<int> &inputs, int low, int high) {
        if (high <= low) return;

        int pivot = inputs[low];
        int lt = low; // initialized as nothing less than the pivot
        int gt = high; // initialized as nothing greater than the pivot
        int i = low+1; // +1 because we have examined the pivot as the first element

        while (i <= gt) {
            if (inputs[i] < pivot) SortingUtility::Swap(inputs, lt++, i++);
            else if (inputs[i] > pivot) SortingUtility::Swap(inputs, i, gt--); // the new i'th element need to be examined after swapping
            else i++;
        }
        Sort(inputs, low, lt-1);
        Sort(inputs, gt+1, high);
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> values = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(values);
    QuickSort3Way::Sort(values);
    assert(SortingUtility::IsSorted(values));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(values);
    return 0;
}