//
// Created by Quoc Anh Do on 11/11/19.
//

#include <iostream>
#include <vector>
#include "HashTable.h"
//#include "Bucket.h"

/**
 * Constructs an empty HashMap with the default initial capacity (16)
 * @tparam K
 * @tparam V
 */
template<typename K, typename V>
HashTable<K, V>::HashTable() {
//    std::cout << "Default constructor...\n";
    _size = 0;
    _capacity = 16;
    _buckets = new Bucket<K, V> *[_capacity]; // array of HashNode pointers
    for (int i = 0; i < _capacity; ++i) _buckets[i] = new Bucket<K, V>;
}

/**
 * Constructs an empty HashMap with the specified initial capacity
 * @tparam K
 * @tparam V
 */
template<typename K, typename V>
HashTable<K, V>::HashTable(int capacity)
        :_capacity(capacity), _size(0) {
    _buckets = new HashNode<K, V> *[_capacity]();
    for (int i = 0; i < _capacity; ++i) _buckets[i] = new Bucket<K, V>;
}

/**
 * Delete memories allocated for all the buckets
 * @tparam K
 * @tparam V
 */
template<typename K, typename V>
HashTable<K, V>::~HashTable() {
    clear();
}

/**
 * Returns the number of key-value mappings in the hash table.
 * @tparam K
 * @tparam V
 * @return the number of key-value mappings in the hash table
 */
template<typename K, typename V>
int HashTable<K, V>::size() const {
    return _size;
}

/**
 * The current capacity of the hash table
 * @tparam K
 * @tparam V
 * @return current capacity
 */
template<typename K, typename V>
int HashTable<K, V>::capacity() const {
    return _capacity;
}

/**
 * Returns true if this map contains no key-value mappings.
 * @tparam K
 * @tparam V
 * @return true if this map contains no key-value mappings
 */
template<typename K, typename V>
bool HashTable<K, V>::isEmpty() const {
    return _size == 0;
}

//template <typename K, typename V>
//bool HashTable<K, V>::isFull() const {
//    return _size == _capacity;
//}

template<typename K, typename V>
void HashTable<K, V>::put(const K &key, const V &value) {
    int index = hash(key);
    HashNode<K, V> *node = _buckets[index]->findKey(key);
    if (node == nullptr) {
        _buckets[index]->insert(key, value);
        _size++;
    } else node->setValue(value);
}

/**
 * Get the value associates with given key in the hash table.
 * @tparam K
 * @tparam V
 * @param key
 * @return @code{value} of the key in the hash table. Returns @code{nullptr} if the key does not exist.
 */
template<typename K, typename V>
V HashTable<K, V>::get(const K &key) const {
    int index = hash(key);
    HashNode<K, V> *node = _buckets[index]->findKey(key);
    return node == nullptr ? "" : node->getValue();
}

template<typename K, typename V>
bool HashTable<K, V>::containsKey(const K &key) const {
    int index = hash(key);
    return _buckets[index]->findKey(key);
}

template<typename K, typename V>
bool HashTable<K, V>::containsValue(const V &value) const {
    int index = hash(value);
    return _buckets[index]->findValue(value);
}

template<typename K, typename V>
void HashTable<K, V>::remove(const K &key) {
    int index = hash(key);
    bool removable = _buckets[index]->remove(key);
    if (removable) _size--;
}

template<typename K, typename V>
void HashTable<K, V>::clear() {
    for (int i = 0; i < _capacity; ++i) {
        _buckets[i]->clear(); // just deallocate all the nodes in the buckets, not release the buckets themselves.
    }
    _size = 0;
}

/**
 * Simple hash function to calculate the index of given key.
 * @tparam K
 * @tparam V
 * @return the index of given key
 */
template<typename K, typename V>
int HashTable<K, V>::hash(const K &key) const {
    return std::hash<K>()(key) % _capacity; // using std::hash function to generate hash value
}

/**
 * Collect all the keys from the buckets
 * @tparam K
 * @tparam V
 * @return
 */
template<typename K, typename V>
std::vector<K> HashTable<K, V>::keys() {
    std::vector<K> out;
    for (int i = 0; i < _capacity; ++i) {
        std::vector<K> vKeys = _buckets[i]->keys();
        out.insert(out.end(), vKeys.begin(), vKeys.end());
    }
    return out;
}

/**
 * Collect all the values from the buckets
 * @tparam K
 * @tparam V
 * @return
 */
template<typename K, typename V>
std::vector<V> HashTable<K, V>::values() {
    std::vector<V> out;
    for (int i = 0; i < _capacity; ++i) {
        std::vector<V> vValues = _buckets[i]->values();
        out.insert(out.end(), vValues.begin(), vValues.end());
    }
    return out;
}

int main() {
    HashTable<std::string, std::string> map;
    map.put("daddy", "Quoc Anh Do");
    map.put("mommy", "Van Anh Nguyen");
    map.put("cutie", "Anna Truc Anh");

    assert(map.size() == 3);
//    HashTable<std::string, int> map;
//    map.put("One", 1);
//    map.put("Two", 2);
//    map.put("Three", 3);

//    std::cout << std::boolalpha << map.containsKey("daddy") << std::endl;
    assert(map.containsKey("daddy"));

    for (auto const &key : map.keys()) std::cout << key << ", ";
    std::cout << "\n";
    for (auto const &value : map.values()) std::cout << value << ", ";

    // assert get
    assert(map.get("daddy") == "Quoc Anh Do");
    assert(map.get("mommy") == "Van Anh Nguyen");
    assert(map.get("cutie") == "Anna Truc Anh");

    // assert value replacement for the same key
    map.put("cutie", "Anna Do");
    assert(map.get("cutie") == "Anna Do");

    // assert remove
    map.remove("daddy");
    assert(map.get("daddy").empty());
    assert(map.size() == 2);

    map.remove("mommy");
    assert(map.get("mommy").empty());

    map.clear();
    assert(map.size() == 0);
    return 0;
}