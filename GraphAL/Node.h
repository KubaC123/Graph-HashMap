//
//  Node.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Node_h
#define Node_h

template<typename V>
class Node {
    
    V value;
    Node *next;
    Node *prev;
    
public:
    
    Node() { }
    
    Node(V value) :
    value(value),
    next(NULL),
    prev(NULL) { }
    
    Node(V value, Node *next, Node *prev) :
    value(value),
    next(next),
    prev(prev) { }
    
    ~Node() { }
    
    V getValue() const {
        return value;
    }
    
    void setValue(V value) {
        this->value = value;
    }
    
    Node* getNext() {
        return next;
    }
    
    void setNext(Node *next) {
        this->next = next;
    }
    
    Node* getPrev() {
        return prev;
    }
    
    void setPrev(Node *prev) {
        this->prev = prev;
    }
};

#endif /* Node_h */
