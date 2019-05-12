//
//  VertexAL.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef VertexAL_h
#define VertexAL_h

#include "Edge.h"

template<typename E>
class VertexAL {
    
    int number;
    E element;
    List<Edge> neighbours;
    
public:
    
    VertexAL() { }
    
    VertexAL(int number) :
    number(number) { }
    
    VertexAL(int number, E element) :
    number(number),
    element(element) { }
    
    ~VertexAL() { }
    
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
    
    List<Edge> getNeighbours() const {
        return neighbours;
    }
    
    bool isNeighbour(Edge edge) {
        return neighbours.isPresent(edge);
    }
    
    /*
     *  Adds new edge if not present
     */
    void addEdge(Edge edge) {
        if(!neighbours.isPresent(edge))
            neighbours.pushBack(edge);
    }
    
    /*
     *  Removes edge if present
     */
    void removeEdge(Edge edge) {
        neighbours.remove(edge);
    }
    
    void printVertex() {
        std::cout << "Vertex nr: " << number << ", element: " << element << ", " << neighbours;
    }
    
};


#endif /* VertexAL_h */
