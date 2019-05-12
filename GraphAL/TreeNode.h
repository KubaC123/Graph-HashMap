//
//  TreeNode.h
//  GraphAL
//
//  Created by Jakub Cichy on 11/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

class TreeNode {
    
    TreeNode *next;
    int vertex, cost;
    
public:
    
    TreeNode() { }
    
    ~TreeNode() { }
    
    TreeNode* getNext() const {
        return next;
    }
    
    void setNext(TreeNode *next) {
        this->next = next;
    }
    
    int getVertex() const {
        return vertex;
    }
    
    void setVertex(int vertex) {
        this->vertex = vertex;
    }
    
    int getCost() const {
        return cost;
    }
    
    void setCost(int cost) {
        this->cost = cost;
    }
};

#endif /* TreeNode_h */
