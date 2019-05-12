//
//  Kruskal.h
//  GraphAL
//
//  Created by Jakub Cichy on 11/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Kruskal_h
#define Kruskal_h

#include "GraphAL.h"
#include "DSStructure.h"
#include "MinimalSpanningTree.h"
#include "EdgeQueue.h"

template<typename E>
class Kruskal {
    
    GraphAL<E> graph;
    
public:
    
    Kruskal(GraphAL<E> graph) :
    graph(graph) { }
    
    ~Kruskal() { }
    
    MinimalSpanningTree run() {
        int numberOfVertices = graph.getNumberOfVertices();
        int numberOfEdges = graph.getNumberOfEdges();
        Edge edge;
        DSStructure dSStructure(numberOfVertices);
        EdgeQueue queue(graph.getNumberOfEdges());
        MinimalSpanningTree minimalSpanningTree(numberOfEdges);
        
        for(int vertexNr=0; vertexNr<numberOfVertices; vertexNr++)
            dSStructure.makeSet(vertexNr);
        
        List<Edge> edges = graph.getEdges();
        for(int edgeNr=0; edgeNr<numberOfEdges; edgeNr++)
            queue.push(edges.get(edgeNr));
        
        for(int i=1; i<numberOfVertices-1; i++) {
            do {
                edge = queue.front();
                queue.pop();
            } while(dSStructure.findSet(edge.getFirstVertexNr()) == dSStructure.findSet(edge.getSecondVertexNr()));
            minimalSpanningTree.addEdge(edge);
            dSStructure.unionSets(edge);
        }
        return minimalSpanningTree;
    }
};

#endif /* Kruskal_h */
