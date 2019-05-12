//
//  List.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef List_h
#define List_h

#include "Node.h"

template<typename V>
class List {
    
    int size;
    Node<V> *head;
    Node<V> *tail;
    
public:
    
    List() : head(nullptr), tail(nullptr), size(0) { }
    
    bool isEmpty() const {
        return head == nullptr;
    }
    
    ~List() {
        if(size == 0) {
            return;
        } else if(size == 1) {
            delete head;
        } else {
            for(Node<V> *node; !isEmpty(); ) {
                node = head->getNext();
                delete head;
                head = node;
            }
        }
    }
    
    Node<V>* getHead() const {
        return head;
    }
    
    Node<V>* getTail() const {
        return tail;
    }
    
    int getSize() const {
        return size;
    }
    
    void pushFront(V value) {
        if(head == nullptr) {
            head = tail = new Node<V>(value);
        } else {
            head = new Node<V>(value, head, nullptr);
            head->getNext()->setPrev(head);
        }
        size++;
    }
    
    void pushBack(V value) {
        if(tail == nullptr) {
            head = tail = new Node<V>(value);
        } else {
            tail = new Node<V>(value, nullptr, tail);
            tail->getPrev()->setNext(tail);
        }
        size++;
    }
    
    void popBack() {
        if(size == 0) {
            std::cout << "List is empty!" << std::endl;
        } else if(size == 1) {
            delete head;
            size--;
        } else {
            tail = tail->getPrev();
            tail->setNext(nullptr);
            size--;
        }
    }
    
    void popFront() {
        if(size == 0) {
            std::cout << "List is empty!" << std::endl;
        } else if(size == 1) {
            delete head;
            size--;
        } else {
            head = head->getNext();
            head->setPrev(nullptr);
            size--;
        }
    }
    
    V front() const {
        if(size == 0) {
            std::cout << "List is empty!" << std::endl;
            exit(1);
        }
        return head->getValue();
    }
    
    V back() const {
        if(size == 0) {
            std::cout << "List is empty!" << std::endl;
            return nullptr;
        }
        return tail->getValue();
    }
    
    V get(int nodeNr) {
        Node<V> *current = head;
        int count = 0;
        while(current != nullptr) {
            if(count == nodeNr)
                return current->getValue();
            count++;
            current = current->getNext();
        }
        assert(0);
    }
    
    bool isPresent(V value) {
        Node<V> *tmp = head;
        while(tmp != nullptr) {
            if(tmp->getValue() == value) {
                return true;
            }
            tmp = tmp->getNext();
        }
        return false;
    }
    
    void remove(V value) {
        Node<V> *tmp = head;
        Node<V> *prev = nullptr;
        
        while(tmp != nullptr && tmp->getValue() == value) {
            head = tmp->getNext();
            free(tmp);
            tmp = head;
        }
        
        while(tmp != nullptr) {
            while(tmp != nullptr && tmp->getValue() != value) {
                prev = tmp;
                tmp = tmp->getNext();
            }
            if(tmp == nullptr)
                return;
            
            prev->setNext(tmp->getNext());
            free(tmp);
            tmp = prev->getNext();
        }
    }
    
};

template<typename V>
std::ostream& operator << (std::ostream &os, const List<V>& list) {
    Node<V> *tmp = list.getHead();
    while(tmp != nullptr) {
        os << tmp->getValue() << " ";
        tmp = tmp->getNext();
    }
    std::cout << std::endl;
    return os;
}

#endif /* List_h */
