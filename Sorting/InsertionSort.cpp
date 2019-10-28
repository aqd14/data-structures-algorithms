//
// Created by Quoc Anh Do on 10/26/19.
// Implementation of insertion sort

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class InsertionSort {
public:
    static void Sort(std::vector<int> &inputs) {
        for (unsigned long i = 1; i < inputs.size(); i++) {
            int current = inputs[i];
            unsigned long j = i;
            while (j > 0 && current < inputs[j - 1]) {
//                SortingUtility::Swap(inputs, j , j-1);
//                j--;
                inputs[j] = inputs[j - 1]; // Cutting down element access to half by not swapping every time.
                j--;
            }
            inputs[j] = current;
        }
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> inputs = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(inputs);

    InsertionSort::Sort(inputs);
    assert(SortingUtility::IsSorted(inputs));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(inputs);
    return 0;
}