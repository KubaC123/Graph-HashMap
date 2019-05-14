//
//  HashNodeL.h
//  GraphAL
//
//  Created by Jakub Cichy on 14/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef HashNodeL_h
#define HashNodeL_h

template<typename K, typename V>
class HashNodeL {
    
    K key;
    V value;
    HashNodeL *next;
    
public:
    
    HashNodeL(const K& key, const V& value) :
    key(key),
    value(value),
    next(nullptr) { }
    
    HashNodeL(const K& key, const V& value, HashNodeL *next) :
    key(key),
    value(value),
    next(nullptr) { }
    
    ~HashNodeL() { }
    
    K getKey() const {
        return key;
    }
    
    void setKey(K key) {
        this->key = key;
    }
    
    V getValue() const {
        return value;
    }
    
    void setValue(V value) {
        this->value = value;
    }
    
    HashNodeL* getNext() const {
        return this->next;
    }
    
    void setNext(HashNodeL *next) {
        this->next = next;
    }
};

#endif /* HashNodeL_h */
