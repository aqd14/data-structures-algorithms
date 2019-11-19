#include "HashNode.h"

template<typename K, typename V>
HashNode<K, V>::HashNode(const K &key, const V &value)
        : _key(key), _value(value), _next(nullptr) {
}

template<typename K, typename V>
void HashNode<K, V>::setKey(K key) {
    _key = key;
}

template<typename K, typename V>
void HashNode<K, V>::setValue(V value) {
    _value = value;
}

template<typename K, typename V>
K HashNode<K, V>::getKey() const {
    return _key;
}

template<typename K, typename V>
V HashNode<K, V>::getValue() const {
    return _value;
}

template<typename K, typename V>
void HashNode<K, V>::setNext(HashNode<K, V> *node) {
    this->_next = node;
}

template<typename K, typename V>
HashNode<K, V> *HashNode<K, V>::getNext() const {
    return _next;
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const HashNode<K, V> &node) {
//    out << "Hello World\n";
    return out;
}
