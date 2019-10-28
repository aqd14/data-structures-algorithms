//
// Created by Quoc Anh Do on 10/27/19.
// Implementation of shell sort. Extension of insertion sort but swapping element from far distance

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class ShellSort {
public:
    static void Sort(std::vector<int> &inputs) {
        int GAP = 3;
        int N = inputs.size();
        int h = 1;
        while (h < N/GAP) h = GAP*h + 1;

        while (h >= 1) {
            for (int i = h; i < N; i++) {
                for (int j = i; j >= h && inputs[j] < inputs[j - h]; j -= h) {
                    SortingUtility::Swap(inputs, j, j - h);
                }
            }
            h = h/GAP;
        }
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> inputs = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(inputs);

    ShellSort::Sort(inputs);
    assert(SortingUtility::IsSorted(inputs));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(inputs);
    return 0;
}