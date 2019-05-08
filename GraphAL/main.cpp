//
//  main.cpp
//  GraphAL
//
//  Created by Jakub Cichy on 05/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {
    
    Graph<int> graph;
    for(int i=0; i<10; i++) {
        graph.insertElementToVertex(i, i*10);
    }
    graph.insertElementToVertex(100, 33);
    graph.removeVertex(0);
    graph.insertElementToVertex(0, 33);
    graph.addEdge(3, 4, 69);
    graph.addEdge(3, 5, 639);
    graph.addEdge(3, 7, 3);
    graph.addEdge(3, 8, 9);
    graph.printVertices();
    graph.removeEdge(3, 4);
    graph.removeEdge(3, 5);
    graph.removeEdge(3, 7);
    graph.removeEdge(3, 8);
    std::cout << graph.areAdjacent(3, 4) << std::endl;
    std::cout << graph.areAdjacent(3, 5) << std::endl;
    std::cout << graph.areAdjacent(3, 7) << std::endl;
    std::cout << graph.areAdjacent(3, 8) << std::endl;
    graph.printVertices();
    return 0;
}
