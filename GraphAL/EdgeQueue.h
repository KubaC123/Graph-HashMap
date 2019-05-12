//
//  EdgeQueue.h
//  GraphAL
//
//  Created by Jakub Cichy on 11/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef EdgeQueue_h
#define EdgeQueue_h

#include "Edge.h"

class EdgeQueue {

    Edge *heap;
    int heapPosition;
    
public:
    
    EdgeQueue(int size) : heapPosition(0) {
        heap = new Edge[size];
    }
    
    ~EdgeQueue() {
        delete [] heap;
    }
    
    Edge front() {
        return heap[0];
    }
    
    void push(Edge edge) {
        int i = heapPosition++;
        int j = (i-1) >> 1;
        
        while(i && (heap[j].getCost() > edge.getCost())) {
            heap[i] = heap[j];
            i = j;
            j = (i-1) >> 1;
        }
        heap[i] = edge;
    }
    
    void pop() {
        int i, j;
        Edge edge;
        
        if(heapPosition) {
            edge = heap[--heapPosition];
            i = 0;
            j = 1;
            
            while(j < heapPosition) {
                if((j+1 < heapPosition) && (heap[j+1].getCost() < heap[j].getCost()))
                    j++;
                if(edge.getCost() <= heap[j].getCost())
                    break;
                heap[i] = heap[j];
                i = j;
                j = (j << 1) + 1;
            }
            heap[i] = edge;
        }
    }
};


#endif /* EdgeQueue_h */
