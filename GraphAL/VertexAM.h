//
//  VertexAM.h
//  GraphAL
//
//  Created by Jakub Cichy on 12/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef VertexAM_h
#define VertexAM_h

template<typename E>
class VertexAM {
    
    int number;
    E element;
    
public:
    
    VertexAM() { }
    
    VertexAM(int number) :
    number(number) { }
    
    VertexAM(int number, E element) :
    number(number),
    element(element) { }
    
    ~VertexAM() { }
    
    int getNumber() const {
        return number;
    }
    
    void setNumber(int number) {
        this->number = number;
    }
    
    E getElement() const {
        return element;
    }
    
    void setElement(E element) {
        this->element = element;
    }
    
    void printVertex() {
        std::cout << "Vertex nr: " << number << ", element: " << element << " ";
    }
    
};


#endif /* VertexAM_h */
