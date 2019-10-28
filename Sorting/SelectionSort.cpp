//
// Created by Quoc Anh Do on 10/26/19.
// Implementation of Selection Sort

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class SelectionSort {
public:
    static void Sort(std::vector<int> &inputs) {
        for (unsigned long i = 0; i < inputs.size(); ++i) {
            unsigned long min = i;
            for (unsigned long j = i + 1; j < inputs.size(); ++j) {
                if (inputs[j] < inputs[min]) {
                    min = j;
                }
            }
            SortingUtility::Swap(inputs, i, min);
        }
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> inputs = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(inputs);

    SelectionSort::Sort(inputs);
    assert(SortingUtility::IsSorted(inputs));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(inputs);
    return 0;
}

