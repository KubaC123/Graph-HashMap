//
//  HashMapL.h
//  GraphAL
//
//  Created by Jakub Cichy on 14/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef HashMapL_h
#define HashMapL_h

#include "HashNodeL.h"

#define REMOVED -1

template<typename K, typename V>
class HashMapL {
    
    HashNodeL<K, V> **array;
    int capacity;
    int currentSize;
    HashNodeL<K, V> *removedMark;
    
    int hashCode(K key) {
        return key % capacity;
    }
    
public:
    
    HashMapL(int capacity) :
    capacity(capacity),
    currentSize(0) {
        array = new HashNodeL<K,V> *[capacity]();
        for(int i=0; i<capacity; i++) {
            array[i] = nullptr;
        }
        removedMark = new HashNodeL<K,V>(REMOVED, REMOVED, nullptr);
    }
    
    ~HashMapL() {
        for (int i = 0; i < capacity; ++i) {
            HashNodeL<K, V> *entry = array[i];
            while (entry != NULL) {
                HashNodeL<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            array[i] = NULL;
        }
        delete [] array;
    }
    
    int getCapacity() const {
        return capacity;
    }
    
    int getCurrentSize() const {
        return currentSize;
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == capacity;
    }
    
    void put(const K& key, const V& value) {
        if(isFull()) {
            std::cout << "Map is full" << std::endl;
            return;
        }
        
        int hash = hashCode(key);
        HashNodeL<K,V> *prev = NULL;
        HashNodeL<K,V> *entry = array[hash];
        
        while(entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }
        
        if(entry == NULL) {
            entry = new HashNodeL<K,V>(key, value);
            if(prev == NULL) {
                array[hash] = entry;
                currentSize++;
            } else {
                prev->setNext(entry);
            }
        } else {
            entry->setValue(value);
        }
    }
    
    V get(const K& key) {
        int hash = hashCode(key);
        HashNodeL<K,V> *entry = array[hash];
        
        while(entry != NULL && entry->getKey() != REMOVED) {
            if(entry->getKey() == key) {
                return entry->getValue();
            }
            entry = entry->getNext();
        }
        return removedMark->getValue();
    }
    
    void remove(const K& key) {
        int hash = hashCode(key);
        HashNodeL<K,V> *prev = NULL;
        HashNodeL<K,V> *entry = array[hash];
        
        while(entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }
        
        if(entry == nullptr) {
            return;
        } else {
            if(prev == nullptr) {
                array[hash] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            entry->setKey(REMOVED); // mark as removed
            currentSize--;
        }
    }
    
    void print() {
        std::cout << "Size:" << currentSize << std::endl;
        for(int i=0; i<capacity; i++) {
            std::cout << "|" << i << "|:";
            HashNodeL<K, V> *entry = array[i];
            while(entry != nullptr) {
                if(entry->getKey() != REMOVED) {
                    std::cout << " (key:" << entry->getKey() << ",value:" << entry->getValue() << ") ";
                }
                entry = entry->getNext();
            }
            std::cout << std::endl;
        }
    }
};


#endif /* HashMapL_h */
