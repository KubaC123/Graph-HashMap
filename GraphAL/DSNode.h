//
//  DSNode.h
//  GraphAL
//
//  Created by Jakub Cichy on 11/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef DSNode_h
#define DSNode_h

class DSNode {
    
    int up, rank;
    
public:
    
    DSNode() { }
    
    DSNode(int up, int rank) :
    up(up),
    rank(rank) { }
    
    ~DSNode() { }
    
    int getUp() const {
        return up;
    }
    
    void setUp(int up) {
        this->up = up;
    }
    
    int getRank() const {
        return rank;
    }
    
    void setRank(int rank) {
        this->rank = rank;
    }
    
};


#endif /* DSNode_h */
