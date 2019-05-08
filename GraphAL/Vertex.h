//
//  Vertex.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include "Edge.h"

template<typename E>
class Vertex {
    
    int number;
    E element;
    List<Edge> neighbours;
    
public:
    
    Vertex() { }
    
    Vertex(int number) :
    number(number) { }
    
    Vertex(int number, E element) :
    number(number),
    element(element) { }
    
    ~Vertex() { }
    
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


#endif /* Vertex_h */
