//
//  Edge.h
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

class Edge {
    
    int firstVertexNr, secondVertexNr, cost;
    
public:
    
    Edge() { }
    
    Edge(int firstVertexNr, int secondVertexNr) :
    firstVertexNr(firstVertexNr),
    secondVertexNr(secondVertexNr) { }
    
    Edge(int firstVertexNr, int secondVertexNr, int cost) :
    firstVertexNr(firstVertexNr),
    secondVertexNr(secondVertexNr),
    cost(cost) { }
    
    ~Edge() { }
    
    int getFisrtVertexNr() const {
        return firstVertexNr;
    }
    
    void setFisrtVertex(int firstVertexNr) {
        this->firstVertexNr = firstVertexNr;
    }
    
    int getSecondVertexNr() const {
        return secondVertexNr;
    }
    
    void setSecondVertex(int secondVertexNr) {
        this->secondVertexNr = secondVertexNr;
    }
    
    int getCost() const {
        return cost;
    }
    
    void setCost(int cost) {
        this->cost = cost;
    }
    
    bool operator == (const Edge& edge) {
        return
        (this->firstVertexNr == edge.getFisrtVertexNr() && this->secondVertexNr == edge.getSecondVertexNr()) ||
        (this->firstVertexNr == edge.getSecondVertexNr() && this->secondVertexNr == edge.getFisrtVertexNr());
    }
    
    bool operator != (const Edge& edge) {
        return this->firstVertexNr != edge.getFisrtVertexNr() || this->secondVertexNr != edge.getSecondVertexNr();
    }
    
};

std::ostream& operator << (std::ostream &os, const Edge& edge) {
    os << "(" << edge.getFisrtVertexNr() << "->" << edge.getSecondVertexNr() << ",cost:" << edge.getCost() << ") ";
    return os;
}


#endif /* Edge_h */
