//
//  HashNode.h
//  GraphAL
//
//  Created by Jakub Cichy on 14/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

template<typename K, typename V>
class HashNode {
  
    K key;
    V value;
    
public:
    
    HashNode(K key, V value) :
    key(key),
    value(value) { }
    
    ~HashNode() { }
    
    K getKey() const {
        return key;
    }
    
    V getValue() const {
        return value;
    }
    
    void setValue(V value) {
        this->value = value;
    }
};

#endif /* HashNode_h */
