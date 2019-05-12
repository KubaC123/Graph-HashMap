//
//  DSStructure.h
//  GraphAL
//
//  Created by Jakub Cichy on 11/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef DSStructure_h
#define DSStructure_h

#include "DSNode.h"
#include "Edge.h"

class DSStructure {
    
    DSNode *sets;
    
public:
    
    DSStructure(int size) {
        sets = new DSNode[size];
    }
    
    ~DSStructure() {
        delete [] sets;
    }
    
    void makeSet(int v) {
        sets[v].setUp(v);
        sets[v].setRank(0);
    }
    
    int findSet(int v) {
        if(sets[v].getUp() != v) {
            int up = findSet(sets[v].getUp());
            sets[v].setUp(up);
        }
        return sets[v].getUp();
    }
    
    void unionSets(Edge edge) {
        int set1, set2;
        
        set1 = findSet(edge.getFirstVertexNr());
        set2 = findSet(edge.getSecondVertexNr());
        if(set1 != set2) {
            if(sets[set1].getRank() > sets[set2].getRank()) {
                sets[set2].setUp(set1);
            } else {
                sets[set1].setUp(set2);
                if(sets[set1].getRank() == sets[set2].getRank()) {
                    int rank = sets[set2].getRank();
                    sets[set2].setRank(rank+1);
                }
            }
        }
    }
};

#endif /* DSStructure_h */
