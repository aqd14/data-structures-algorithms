/**
 * Simple implementation of hash table using separate chaining.
 * The hash table support different types of key value
 */

#pragma once

#include "HashNode.h"
#include "Bucket.h"

template<typename K, typename V>
class HashTable {
private:
    int _capacity = 16;
    int _size;
    Bucket<K, V> **_buckets;

    int hash(const K &) const;

    bool isKeyValid(const K &) const;
//    int loadFactor;

public:
    HashTable();

    explicit HashTable(int);

    ~HashTable();

    // Returns the number of key-value mappings in this map.
    int size() const;

    int capacity() const;

    bool isEmpty() const;

    V get(const K &) const;

    bool containsKey(const K &) const;

    bool containsValue(const V &) const;

    std::vector<K> keys();

    std::vector<V> values();

    void put(const K &, const V &);

    void remove(const K &);

    void clear();
};
