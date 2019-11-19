//
// Created by Quoc Anh Do on 11/12/19.
//

#include "Bucket.h"

template<typename K, typename V>
Bucket<K, V>::Bucket() = default;

template<typename K, typename V>
Bucket<K, V>::~Bucket() {
    clear();
}

/**
 * Insert a node into the bucket
 * @tparam K
 * @tparam V
 * @param node
 */
template<typename K, typename V>
void Bucket<K, V>::insert(HashNode<K, V> &node) {
    insert(node.getKey(), node.getValue());
}

/**
 * Insert a new node to the bucket
 * Replace the value by new value if key already exist
 * @tparam K
 * @tparam V
 * @param key
 * @param value
 */
template<typename K, typename V>
void Bucket<K, V>::insert(const K &key, const V &value) {
    insertFirst(key, value);
}

/**
 * Insert a new node into the end of the bucket.
 * @tparam K
 * @tparam V
 * @param key
 * @param value
 */
template<typename K, typename V>
void Bucket<K, V>::insertLast(const K &key, const V &value) {
    if (_head == nullptr) {
        _head = new HashNode<K, V>(key, value);
        return;
    }
    HashNode<K, V> *temp = _head;
    while (temp->getNext() != nullptr) temp = temp->getNext();
    temp->setNext(new HashNode<K, V>(key, value));
}

/**
 * Insert a new node into the beginning of the bucket
 * @tparam K
 * @tparam V
 * @param key
 * @param value
 */
template<typename K, typename V>
void Bucket<K, V>::insertFirst(const K &key, const V &value) {
    if (_head == nullptr) {
        _head = new HashNode<K, V>(key, value);
        return;
    }

    auto *node = new HashNode<K, V>(key, value);
    node->setNext(_head);
    _head = node;
}

/**
 * Find a node in the list with the key matching given the node's key.
 * @tparam K
 * @tparam V
 * @param key
 * @return the value of the node matched given key. return nullptr if key not found.
 */
template<typename K, typename V>
HashNode<K, V> *Bucket<K, V>::find(const HashNode<K, V> *node) {
    if (node == nullptr) return nullptr;
    return findKey(node->getKey());
}

/**
 * Find a node in the list given the input key.
 * @tparam K
 * @tparam V
 * @param key
 * @return the node matched given key. return nullptr if key not found.
 */
template<typename K, typename V>
HashNode<K, V> *Bucket<K, V>::findKey(const K &key) {
    HashNode<K, V> *temp = _head;
    while (temp != nullptr && temp->getKey() != key) temp = temp->getNext();
    return temp;
}

/**
 * Find a node in the list given the input value.
 * @tparam K
 * @tparam V
 * @param key
 * @return the node matched given value. return nullptr if value not found.
 */
template<typename K, typename V>
HashNode<K, V> *Bucket<K, V>::findValue(const V &value) {
    HashNode<K, V> *temp = _head;
    while (temp != nullptr && temp->getValue() != value) temp = temp->getNext();
    return temp;
}

/**
 * Deallocate all the nodes in the bucket
 * @tparam K
 * @tparam V
 */
template<typename K, typename V>
void Bucket<K, V>::clear() {
//    HashNode<K, V> *temp = _head;
////    while (temp) {
////        HashNode<K, V> *current = temp;
////        temp = temp->getNext();
////        delete current;
////        current = nullptr;
////    }

    HashNode<K, V> *temp;
    while (_head != nullptr) {
        temp = _head;
        _head = _head->getNext();
        delete temp;
    }
}

/**
 * Remove the node in the bucket with the key matches input key
 * @tparam K
 * @tparam V
 * @param key
 * @return @code{true} if the key exist and gets deleted successfully. Otherwise, returns false
 */
template<typename K, typename V>
bool Bucket<K, V>::remove(const K &key) {
    HashNode<K, V> *pre = nullptr;
    HashNode<K, V> *temp = _head;
    while (temp != nullptr) {
        if (temp->getKey() == key) {
            if (pre == nullptr) { // deleting node is the head
                _head = _head->getNext();
            } else {
                pre->setNext(temp->getNext());
            }
            delete temp;
            return true;
        }
        pre = temp;
        temp = temp->getNext();
    }
    return false; // couldn't find the deleting key
}

template<typename K, typename V>
void Bucket<K, V>::print() const {
    HashNode<K, V> *temp = _head;
    while (temp != nullptr) {
        std::cout << "key = " << temp->getKey() << ", value = " << temp->getValue() << std::endl;
        temp = temp->getNext();
    }
}

/**
 * Retrieve all keys in the bucket and store in a vector.
 * @tparam K
 * @tparam V
 * @return a vector containing all keys.
 */
template<typename K, typename V>
std::vector<K> Bucket<K, V>::keys() {
    std::vector<K> vKeys;
    HashNode<K, V> *temp = _head;
    while (temp != nullptr) {
        vKeys.push_back(temp->getKey());
        temp = temp->getNext();
    }
    return vKeys;
}

/**
 * Retrieve all keys in the bucket and store in a vector.
 * @tparam K
 * @tparam V
 * @return a vector containing all keys.
 */
template<typename K, typename V>
std::vector<V> Bucket<K, V>::values() {
    std::vector<V> vValues;
    HashNode<K, V> *temp = _head;
    while (temp != nullptr) {
        vValues.push_back(temp->getValue());
        temp = temp->getNext();
    }
    return vValues;
}
