//
//  GraphAM.h
//  GraphAL
//
//  Created by Jakub Cichy on 12/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef GraphAM_h
#define GraphAM_h

#include "List.h"
#include "VertexAM.h"
#include "Edge.h"

#define NO_EDGE -1

template<typename E>
class GraphAM {
    
    int** adjacencyMatrix;
    VertexAM<E>* vertices;
    int numberOfVertices;
    int numberOfEdges;
    
public:
    
    GraphAM(int numberOfVertices) :
    numberOfVertices(numberOfVertices),
    numberOfEdges(0) {
        adjacencyMatrix = new int*[numberOfVertices];
        for(int i=0; i<numberOfVertices; i++) {
            adjacencyMatrix[i] = new int[numberOfVertices];
        }
        
        for(int i=0; i<numberOfVertices; i++) {
            for(int j=0; j<numberOfVertices; j++) {
                adjacencyMatrix[i][j] = NO_EDGE;
            }
        }
        
        vertices = new VertexAM<E>[numberOfVertices];
        for(int i=0; i<numberOfVertices; i++) {
            vertices[i].setNumber(i);
        }
    }
    
    ~GraphAM() {
        delete [] vertices;
        for(int i=0; i<numberOfVertices; i++) {
            delete [] adjacencyMatrix[i];
        }
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
            adjacencyMatrix[firstVertexNr][secondVertexNr] = cost;
            adjacencyMatrix[secondVertexNr][firstVertexNr] = cost;
            numberOfEdges++;
        }
    }
    
    void removeEdge(int firstVertexNr, int secondVertexNr) {
        if(vertexExists(firstVertexNr) && vertexExists(secondVertexNr)) {
            adjacencyMatrix[firstVertexNr][secondVertexNr] = NO_EDGE;
            adjacencyMatrix[secondVertexNr][firstVertexNr] = NO_EDGE;
            numberOfEdges--;
        }
    }
    
    bool areAdjacent(int firstVertexNr, int secondVertexNr) {
        if(!vertexExists(firstVertexNr) || !vertexExists(secondVertexNr)) {
            return false;
        }
        return adjacencyMatrix[firstVertexNr][secondVertexNr] != NO_EDGE && adjacencyMatrix[secondVertexNr][firstVertexNr] != NO_EDGE;
        
    }
    
    void printVertices() {
        for(int i=0; i<numberOfVertices; i++) {
            vertices[i].printVertex();
            for(int j=0; j<numberOfVertices; j++) {
                if(adjacencyMatrix[i][j] != NO_EDGE)
                    std::cout << "(" << i << "->" << j << ",cost:" << adjacencyMatrix[i][j] << ")" << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void printVertex(int vertexNr) {
        vertices[vertexNr].printVertex();
        for(int j=0; j<numberOfVertices; j++) {
            if(adjacencyMatrix[vertexNr][j] != NO_EDGE)
                std::cout << "(" << vertexNr << "->" << j << ",cost:" << adjacencyMatrix[vertexNr][j] << ")" << std::endl;
        }
    }
    
    void printAdjacencyMatrix() {
        for(int i=0; i<numberOfVertices; i++) std::cout << i << " ";
        std::cout << std::endl;
        for(int i=0; i<numberOfVertices; i++) {
            std::cout << i  << "| ";
            for(int j=0; j<numberOfVertices; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    bool vertexExists(int vertexNr) {
        bool exist = vertexNr < numberOfVertices;
        if(!exist)
            std::cerr << "Vertex number " << vertexNr << " doesn't exist!" << std::endl;
        return exist;
    }
    
};


#endif /* GraphAM_h */
