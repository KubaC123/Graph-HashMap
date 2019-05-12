//
//  MinimalSpanningTree.h
//  GraphAL
//
//  Created by Jakub Cichy on 11/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef MinimalSpanningTree_h
#define MinimalSpanningTree_h

#include "TreeNode.h"
#include "Edge.h"

class MinimalSpanningTree {
    
    TreeNode** list;
    int listLenght;
    int weight;
    
public:
    
    MinimalSpanningTree(int size) :
    listLenght(size-1),
    weight(0) {
        list = new TreeNode*[size];
        for(int i=0; i<size; i++) {
            list[i] = nullptr;
        }
    }
    
    ~MinimalSpanningTree() {
        TreeNode *tmp1, *tmp2;
        for(int i=0; i<=listLenght; i++) {
            tmp1 = list[i];
            while(tmp1) {
                tmp2 = tmp1;
                tmp1 = tmp1->getNext();
                delete tmp2;
            }
        }
        delete [] list;
    }
    
    void addEdge(Edge edge) {
        TreeNode *newNode;
        
        weight += edge.getCost();
        newNode = new TreeNode;
        newNode->setVertex(edge.getSecondVertexNr());
        newNode->setCost(edge.getCost());
        newNode->setNext(list[edge.getFirstVertexNr()]);
        list[edge.getFirstVertexNr()] = newNode;
        
        newNode = new TreeNode;
        newNode->setVertex(edge.getFirstVertexNr());
        newNode->setCost(edge.getCost());
        newNode->setNext(list[edge.getSecondVertexNr()]);
        list[edge.getSecondVertexNr()] = newNode;
    }
    
    void print() {
        TreeNode *tmp;
        
        std::cout << std::endl;
        for(int i=0; i<=listLenght; i++)
        {
            std::cout << "Vertex " << i << " - ";
            for(tmp = list[i]; tmp; tmp = tmp->getNext()){
                std::cout << tmp->getVertex() << ":" << tmp->getCost() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl << "Minimal Spanning Tree Weight = " << weight << std::endl << std::endl;
    }
};

#endif /* MinimalSpanningTree_h */
