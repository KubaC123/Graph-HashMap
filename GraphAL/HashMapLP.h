//
//  HashMapLP.h
//  GraphAL
//
//  Created by Jakub Cichy on 13/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef HashMapLP_h
#define HashMapLP_h

#include "HashNode.h"

#define REMOVED -1

template<typename K, typename V>
class HashMapLP {
  
    HashNode<K, V> **array;
    int capacity;
    int currentSize;
    HashNode<K,V> *removedMark;
    
    int hashCode(K key) {
        return key % capacity;
    }
    
public:
    
    HashMapLP(int capacity) :
    capacity(capacity),
    currentSize(0) {
        array = new HashNode<K,V>*[capacity];
        for(int i=0; i<capacity; i++) {
            array[i] = nullptr;
        }
        removedMark = new HashNode<K,V>(REMOVED, REMOVED);
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
    
    void put(K key, V value) {
        if(currentSize == capacity) {
            std::cout << "Map is full" << std::endl;
        }
        int counter = 0;
        HashNode<K,V> *nodeToAdd = new HashNode<K,V>(key, value);
        int hash = hashCode(key);
        while(array[hash] != nullptr && array[hash]->getKey() != key && array[hash]->getKey() != REMOVED) {
            counter++;
            hash++;
            hash %= capacity;
        }
        if(array[hash] == nullptr || array[hash]->getKey() == REMOVED) {
            currentSize++;
            std::cout << "Looped " << counter << " times during put" << std::endl;
        }
        array[hash] = nodeToAdd;
    }
    
    V get(K key) {
        int hash = hashCode(key);
        int counter = 0;
        while(array[hash] != nullptr) {
            if(counter++ > capacity)
                return REMOVED;
            if(array[hash]->getKey() == key) {
                std::cout << "Looped " << counter << " times during get" << std::endl;
                return array[hash]->getValue();
            }
            hash++;
            hash %= capacity;
        }
        return REMOVED;
    }
    
    void remove(K key) {
        int hash = hashCode(key);
        int counter = 0;
        while(array[hash] != nullptr) {
            counter++;
            if(array[hash]->getKey() == key) {
                array[hash] = removedMark;
                currentSize--;
                std::cout << "Looped " << counter << " times during remove" << std::endl;
                return;
            }
            hash++;
            hash %= capacity;
        }
    }
    
    void print() {
        for(int i=0; i<capacity; i++) {
            std::cout << "|" << i << "|:";
            if(array[i] != nullptr && array[i]->getKey() != REMOVED) {
                std::cout << " (key:" << array[i]->getKey() << ",value:" << array[i]->getValue() << ") ";
            }
            std::cout << std::endl;
        }
    }
    
};

#endif /* HashMapLP_h */
