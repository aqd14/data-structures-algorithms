/**
 * Implementation of the node in the buckets of hash table
 * Support "Separate Chaining" using Singly Linked List
 */

#pragma once

#include <iostream>

template<typename K, typename V>
class HashNode {
private:
    K _key;
    V _value;
    HashNode *_next;

public:
    HashNode() = default;

    HashNode(const K &, const V &);

    void setKey(K);

    void setValue(V);

    K getKey() const;

    V getValue() const;

    HashNode *getNext() const;

    void setNext(HashNode *);

    friend std::ostream &operator<<(std::ostream &out, const HashNode &node);

    HashNode(const HashNode &) = default;

    HashNode &operator=(const HashNode &) = default;
};

#include "HashNode.cpp"