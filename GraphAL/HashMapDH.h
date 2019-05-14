//
//  HashMapDH.h
//  GraphAL
//
//  Created by Jakub Cichy on 14/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef HashMapDH_h
#define HashMapDH_h

#include "HashNode.h"

#define PRIME 7
#define REMOVED -1

template<typename K, typename V>
class HashMapDH {
  
    HashNode<K,V> **array;
    int capacity;
    int currentSize;
    HashNode<K,V> *removedMark;
    
    int hashCode1(K key) {
        return key % capacity;
    }
    
    int hashCode2(int key) {
        return (PRIME - (key % PRIME));
    }
    
public:
    
    HashMapDH(int capacity) :
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
            return;
        }
        int hash1 = hashCode1(key);
        int hash2 = hashCode2(key);
        int counter = 0;
        HashNode<K,V> *nodeToAdd = new HashNode<K,V>(key, value);
        if(array[hash1] != nullptr && array[hash1]->getKey() != REMOVED) {
            int i = 1;
            while(1) {
                int hash = (hash1 + i*hash2) % capacity;
                if(array[hash] == nullptr || array[hash]->getKey() == REMOVED) {
                    array[hash] = nodeToAdd;
                    break;
                }
                i++;
                counter++;
            }
        } else {
            array[hash1] = nodeToAdd;
        }
        std::cout << "Looped " << counter << " times during put" << std::endl;
        currentSize++;
    }
    
    V get(K key) {
        int hash1 = hashCode1(key);
        int hash2 = hashCode2(key);
        
        if(array[hash1] != nullptr && array[hash1]->getKey() == key) {
            return array[hash1]->getValue();
        } else {
            int maxTry = 40, i = 1, counter = 0, hash = -1;
            while(i <= maxTry) {
                counter++;
                hash = (hash1 + i*hash2) % capacity;
                if(array[hash] != nullptr && array[hash]->getKey() == key) {
                    std::cout << "Looped " << counter << " times during get" << std::endl;
                    return array[hash]->getValue();
                }
                i++;
            }
        }
        return removedMark->getValue();
    }
    
    void remove(K key) {
        int hash1 = hashCode1(key);
        int hash2 = hashCode2(key);
        
        if(array[hash1] != nullptr && array[hash1]->getKey() == key) {
            array[hash1] = removedMark;
        } else {
            int maxTry = 40, i = 1, counter = 0, hash = -1;
            while(i <= maxTry) {
                counter++;
                hash = (hash1 + i*hash2) % capacity;
                if(array[hash] != nullptr && array[hash]->getKey() == key) {
                    std::cout << "Looped " << counter << " times during remove" << std::endl;
                    array[hash] = removedMark;
                }
                i++;
            }
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

#endif /* HashMapDH_h */
