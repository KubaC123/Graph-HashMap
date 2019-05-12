//
//  GraphAL.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef GraphAL_h
#define GraphAL_h

#include "List.h"
#include "VertexAL.h"
#include "Edge.h"

#define SIZE 10

template<typename E>
class GraphAL {
    
    VertexAL<E>* vertices;
    List<Edge> edges;
    int numberOfVertices;
    int numberOfEdges;
    
public:
    
    GraphAL() { }
    
    GraphAL(int numberOfVertices) :
    numberOfVertices(numberOfVertices),
    numberOfEdges(0) {
        vertices = new VertexAL<E>[numberOfVertices];
        for(int i=0; i<numberOfVertices; i++) {
            vertices[i].setNumber(i);
            vertices[i].setElement(0);
        }
    }
    
    ~GraphAL() {
        delete [] vertices;
    }
    
    int getNumberOfVertices() const {
        return numberOfVertices;
    }
    
    int getNumberOfEdges() const {
        return numberOfEdges;
    }
    
    void insertElementToVertex(int vertexNr, E element) {
        if(vertexExists(vertexNr))
            vertices[vertexNr].setElement(element);
    }
    
    void addEdge(int firstVertexNr, int secondVertexNr, int cost) {
        if(vertexExists(firstVertexNr) && vertexExists(secondVertexNr)) {
            vertices[firstVertexNr].addEdge(Edge(firstVertexNr, secondVertexNr, cost));
            vertices[secondVertexNr].addEdge(Edge(firstVertexNr, secondVertexNr, cost));
            edges.pushFront(Edge(firstVertexNr, secondVertexNr, cost));
            numberOfEdges++;
        }
    }
    
    void removeEdge(int firstVertexNr, int secondVertexNr) {
        if(vertexExists(firstVertexNr) && vertexExists(secondVertexNr)) {
            vertices[firstVertexNr].removeEdge(Edge(firstVertexNr, secondVertexNr));
            vertices[secondVertexNr].removeEdge(Edge(firstVertexNr, secondVertexNr));
            edges.remove(Edge(firstVertexNr, secondVertexNr));
            numberOfEdges--;
        }
    }
    
    bool areAdjacent(int firstVertexNr, int secondVertexNr) {
        if(!vertexExists(firstVertexNr) || !vertexExists(secondVertexNr)) {
            return false;
        }
        return vertices[firstVertexNr].isNeighbour(Edge(firstVertexNr, secondVertexNr)) && vertices[secondVertexNr].isNeighbour(Edge(firstVertexNr, secondVertexNr));
        
    }
    
    void printVertices() {
        for(int i=0; i<numberOfVertices; i++) {
            vertices[i].printVertex();
        }
    }
    
    void printVertex(int vertexNr) {
        vertices[vertexNr].printVertex();
    }
    
    bool vertexExists(int vertexNr) {
        bool exist = vertexNr < numberOfVertices;
        if(!exist)
            std::cerr << "Vertex number " << vertexNr << " doesn't exist!" << std::endl;
        return exist;
    }
    
    void printEdges() {
        std::cout << edges;
    }
    
};

#endif /* GraphAL_h */
