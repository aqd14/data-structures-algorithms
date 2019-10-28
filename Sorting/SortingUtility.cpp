//
// Created by Quoc Anh Do on 10/24/19.
//

#include <random>
#include "SortingUtility.h"

/**
 * Check if the given vector is sorted
 * @param values
 * @return
 */
bool SortingUtility::IsSorted(const std::vector<int> &values) {
    for (int i = 0; i < values.size() - 1; ++i) {
        if (values[i] > values[i+1]) return false;
    }
    return true;
}

/**
 * Print all elements of given vector
 * @param values vector
 */
void SortingUtility::PrintVector(const std::vector<int> &values) {
    for (auto v : values) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

void SortingUtility::Swap(std::vector<int> &values, unsigned long i, unsigned long j) {
    if (i == j) return;
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
}

std::vector<int> SortingUtility::GenerateVectorInput(const int SIZE, const int MAX_VALUE) {
    std::vector<int> values;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> distribution(0,MAX_VALUE);

    values.reserve(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        values.push_back(distribution(rng));
    }

    return values;
}
