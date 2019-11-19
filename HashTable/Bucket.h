//
// Implementation of buckets in the hash table.
// Each bucket store a linked list of HashNode where the collision occur.
//

#pragma once

#include <iostream>
#include <vector>
#include "HashNode.h"

template<typename K, typename V>
class Bucket {
private:
    HashNode<K, V> *_head = nullptr;

    void insertLast(const K &, const V &);

    void insertFirst(const K &, const V &);

public:
    Bucket();

    ~Bucket();

    void insert(HashNode<K, V> &);

    void insert(const K &, const V &);

    HashNode<K, V> *find(const HashNode<K, V> *);

    HashNode<K, V> *findKey(const K &);

    HashNode<K, V> *findValue(const V &);

    std::vector<K> keys();

    std::vector<V> values();

    void clear();

    bool remove(const K &);

    void print() const;
};

#include "Bucket.cpp"
