#ifndef HashMap_H
#define HashMap_H

#include <cstddef>

template <typename Hash, typename T>
class HashMap
{
private:
    size_t capacity;
    size_t size;
    float loadFactor;
    int resizeThreshold;

    T* array;
    size_t* hashTable;

    void rehash(size_t newSize);
    void hashFunction(Hash key);
    void append(T& e);
public:
    HashMap(size_t capacity, float loadFactor);
    ~HashMap();
    
};

template <typename Hash, typename T>
HashMap<Hash, T>::HashMap(size_t capacity, float loadFactor)
: capacity(capacity), loadFactor(loadFactor), size(0)
{
    array = new T[capacity];
    hashTable = new size_t[capacity];
    // Fill hash table will invalid positions
    std::fill(hashTable, hashTable + capacity, static_cast<size_t>(-1));
}

template <typename Hash, typename T>
HashMap<Hash, T>::~HashMap()
{
}

template <typename Hash, typename T>
inline void HashMap<Hash, T>::rehash(size_t newSize)
{
}

template <typename Hash, typename T>
inline void HashMap<Hash, T>::hashFunction(Hash key)
{
}

template <typename Hash, typename T>
inline void HashMap<Hash, T>::append(T &e)
{
}

#endif /*HashMap_H*/