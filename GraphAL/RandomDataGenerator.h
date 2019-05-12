//
//  RandomDataGenerator.h
//  GraphAL
//
//  Created by Jakub Cichy on 12/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef RandomDataGenerator_h
#define RandomDataGenerator_h

#include "string"
#include <iostream>
#include <fstream>

class RandomDataGenerator {
    
public:
    
    RandomDataGenerator() { }
    
    ~RandomDataGenerator() { }
    
    void generateGraphData(int numberOfVertices, int numberOfEdges, std::string fileName) {
        std::ofstream output(fileName);
        
        output << numberOfVertices << " " << numberOfEdges << std::endl << std::endl;
        
        output << "vertices:" << std::endl;
        for(int i=0; i<numberOfVertices; i++) {
            output << i << " " << rand()%10000 << std::endl;
        }
        output << std::endl;
        output << "edges:" << std::endl;
        for(int i=0; i<numberOfEdges; i++) {
            int startVertex = rand()%numberOfVertices-13;
            int endVertex = startVertex + 13;
            output << rand()%numberOfVertices << " " << endVertex << " " << rand()%1000 << std::endl;
        }
        output.close();
    }
};

#endif /* RandomDataGenerator_h */
