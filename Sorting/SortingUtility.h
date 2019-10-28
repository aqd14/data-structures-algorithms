//
// Created by Quoc Anh Do on 10/24/19.
//

#pragma once

#include <iostream>
#include <vector>

class SortingUtility {
protected:

public:
    static bool IsSorted(const std::vector<int> &);
    static void PrintVector(const std::vector<int> &);
    static void Swap(std::vector<int> &, unsigned long, unsigned long);
    static std::vector<int> GenerateVectorInput(int, int);
};
