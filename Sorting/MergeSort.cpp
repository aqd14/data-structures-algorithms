//
// Created by Quoc Anh Do on 10/24/19.
// Implementation of merge sort
//

#include <iostream>
#include <vector>
#include "SortingUtility.h"

class MergeSort {
private:
    /**
     *
     * @param inputs
     * @param aux temporary vector used before merging two sorted array into the original vector
     * @param low
     * @param mid
     * @param high
     */
    static void Merge(std::vector<int> &inputs, std::vector<int> &aux, unsigned long low, unsigned long mid, unsigned long high) {
        // copy to aux vector
        for (unsigned long i = 0; i < inputs.size(); ++i) {
            aux[i] = inputs[i];
        }

        unsigned long i = low, j = mid+1;

        for (unsigned long k = low; k <= high; k++) {
            if (i > mid) inputs[k] = aux[j++];
            else if (j > high) inputs[k] = aux[i++];
            else if (aux[i] < aux[j]) inputs[k] = aux[i++];
            else inputs[k] = aux[j++];
        }
    }

    /**
     *
     * @param inputs
     * @param aux
     * @param low
     * @param high
     */
    static void Sort(std::vector<int> &inputs, std::vector<int> &aux, unsigned long low, unsigned long high) {
        if (low >= high) return;

        unsigned long mid = low + (high - low) / 2;

        Sort(inputs, aux, low, mid);
        Sort(inputs, aux, mid + 1, high);

        Merge(inputs, aux, low, mid, high);
    }
public:
    static void Sort(std::vector<int> &inputs) {
        std::vector<int> aux(inputs.size());
        Sort(inputs, aux, 0, inputs.size() - 1);
    }
};

int main() {
    int max_value = 100;
    int size = 100;
    std::vector<int> inputs = SortingUtility::GenerateVectorInput(size, max_value);
    std::cout << "\nOriginal Vector...\n";
    SortingUtility::PrintVector(inputs);

    MergeSort::Sort(inputs);
    assert(SortingUtility::IsSorted(inputs));
    std::cout << "\nSorted Vector...\n";
    SortingUtility::PrintVector(inputs);
    return 0;
}
