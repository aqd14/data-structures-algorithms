//
// Created by Quoc Anh Do on 10/23/19.
//

#include <iostream>
#include <vector>

#define SIZE_TYPE std::vector<int>::size_type

int RecursiveBSTHelper(const std::vector<int> &values, int low, int high, int key) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    int midElement = values.at(mid);
    if (midElement == key) return mid;
    else if (midElement > key) return RecursiveBSTHelper(values, low, high-1, key);
    else return RecursiveBSTHelper(values, mid+1, high, key);
}

int RecursiveBST(const std::vector<int> &values, int key) {
    return RecursiveBSTHelper(values, 0, values.size() - 1, key);
}

// Returns the index of the specified key in the specified array.
int IndexOf(const std::vector<int> &values, int key) {
    auto low = 0;
    auto high = values.size() - 1;
    while (low <= high) {
        auto mid = low + (high - low) / 2;
        if (key < values.at(mid)) high = mid - 1;
        else if (key > values.at(mid)) low = mid + 1;
        else return mid;
    }
    return -1;
}

/**
 * Find the left most element that matches the key
 * @param values vector of integers
 * @param key key to be searched
 * @return index of left most matching element. If not found, returns -1
 */
unsigned long IndexOfOuterMost(const std::vector<int> &values, int key, bool searchLeftMost) {
    unsigned long index = -1;

    unsigned long low = 0;
    unsigned long high = values.size() - 1;

    while (low <= high) {
        unsigned long mid = low + (high - low) / 2;
        unsigned long midElement = values.at(mid);
        if (midElement == key) {
            index = mid;
            if (searchLeftMost) high = mid - 1;
            else low = mid + 1;
        } else if (midElement > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return index;
}

int LeftMostIndex(const std::vector<int> &values, int key) {
    unsigned long low = 0, high = values.size() - 1;

    while (low <= high) {
        unsigned long mid = low + (high - low) / 2;
        if (values.at(mid) < key) low = mid + 1;
        else high = mid - 1;
    }
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
    int key = 11;
    std::cout << "Key location = " << RecursiveBST(values, key) << std::endl;
}