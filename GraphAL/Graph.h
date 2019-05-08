//
//  Graph.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include "List.h"
#include "Vertex.h"
#include "Edge.h"

#define SIZE 10

template<typename E>
class Graph {
    
    Vertex<E>* vertices[SIZE];
    
public:
    
    Graph() {
        for(int i=0; i<SIZE; i++) {
            vertices[i] = new Vertex<E>(i);
        }
    }
    
    ~Graph() {
        for(int i=0; i<SIZE; i++) {
            if(vertices[i] != nullptr)
                delete vertices[i];
        }
    }
    
    void insertElementToVertex(int vertexNr, E element) {
        if(vertexExists(vertexNr))
            vertices[vertexNr]->setElement(element);
    }
    
    void removeVertex(int vertexNr) {
        vertices[vertexNr] = nullptr;
    }
    
    void addEdge(int firstVertexNr, int secondVertexNr, int cost) {
        if(vertexExists(firstVertexNr) && vertexExists(secondVertexNr)) {
            vertices[firstVertexNr]->addEdge(Edge(firstVertexNr, secondVertexNr, cost));
            vertices[secondVertexNr]->addEdge(Edge(firstVertexNr, secondVertexNr, cost));
        }
    }
    
    void removeEdge(int firstVertexNr, int secondVertexNr) {
        if(vertexExists(firstVertexNr) && vertexExists(secondVertexNr)) {
            vertices[firstVertexNr]->removeEdge(Edge(firstVertexNr, secondVertexNr));
            vertices[secondVertexNr]->removeEdge(Edge(firstVertexNr, secondVertexNr));
            std::cout << "Removed edge beetwen vertex number " << firstVertexNr << " and " << secondVertexNr << std::endl;
        }
    }
    
    bool areAdjacent(int firstVertexNr, int secondVertexNr) {
        if(!vertexExists(firstVertexNr) || !vertexExists(secondVertexNr)) {
            return false;
        }
        return vertices[firstVertexNr]->isNeighbour(Edge(firstVertexNr, secondVertexNr)) && vertices[secondVertexNr]->isNeighbour(Edge(firstVertexNr, secondVertexNr));
        
    }
    
    void printVertices() {
        for(int i=0; i<SIZE; i++) {
            if(vertices[i] != nullptr)
                vertices[i]->printVertex();
        }
    }
    
    void printVertex(int vertexNr) {
        if(vertices[vertexNr] != nullptr)
            vertices[vertexNr]->printVertex();
    }
    
    bool vertexExists(int vertexNr) {
        bool exist = vertexNr < SIZE && vertices[vertexNr] != nullptr;
        if(!exist)
            std::cerr << "Vertex number " << vertexNr << " doesn't exist!" << std::endl;
        return exist;
    }
    
};

#endif /* Graph_h */
