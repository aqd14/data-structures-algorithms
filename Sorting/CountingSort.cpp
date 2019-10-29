//
// Created by Quoc Anh Do on 10/28/19.
// Implementation of Counting Sort

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class CountingSort {
public:
    static void Sort(std::vector<int> &inputs) {
        int N = inputs.size();
        int max = *std::max_element(inputs.begin(), inputs.end());

        int* counts = new int[max + 1];

        // counting element x at index x;
        for (int item : inputs) {
            counts[item]++;
        }

        // find the index where element i starts
        int index = 0;
        int temp;
        for (int i = 0; i <= max; i++) {
            temp = counts[i];
            counts[i] = index;
            index += temp;
        }

        std::vector<int> copy(inputs);
        for (int item : copy) {
            inputs[counts[item]] = item;
            counts[item]++;
        }
    }

    // Counting sort without storing cumulative indices
    static void Sort2(std::vector<int> &inputs) {
        int N = inputs.size();
        int max = *std::max_element(inputs.begin(), inputs.end());

        int* counts = new int[max + 1];

        // counting element x at index x;
        for (int item : inputs) {
            counts[item]++;
        }

        int index = 0;
        for (int i = 0; i <= max; i++) {
//            int cur = i;
            while (counts[i] > 0) {
                inputs[index++] = i;
                counts[i]--;
            }
        }
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> input = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(input);

    CountingSort::Sort2(input);
    assert(SortingUtility::IsSorted(input));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(input);
    return 0;
}