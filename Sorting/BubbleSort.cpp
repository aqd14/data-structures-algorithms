//
// Created by Quoc Anh Do on 10/24/19.
// Implementation of bubble sort

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class BubbleSorting {
public:
    static void Sort(std::vector<int> &values) {

        auto n = values.size() - 1;

        while (n > 0) {
            unsigned long wall = 0; // subarray [wall, values.size()-1] has been sorted. No need to check and swap next time
            for (unsigned long i = 0; i < n; i++) {
                if (values[i] > values[i+1]) {
                    SortingUtility::Swap(values, i, i+1);
                    wall = i;
                }
            }
            n = wall;
        }
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> values = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(values);
    BubbleSorting::Sort(values);
    assert(SortingUtility::IsSorted(values));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(values);
    return 0;
}
