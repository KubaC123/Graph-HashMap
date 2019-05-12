//
//  Menu.h
//  GraphAL
//
//  Created by Jakub Cichy on 12/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "GraphAL.h"
#include "GraphAM.h"
#include "RandomDataGenerator.h"

#define FILENAME "graph_data.txt"

template<typename E>
class Menu {
    
    GraphAL<E> readGraphALFromFile(int givenNumberOfVertices) {
        int numberOfVertices, numberOfEdges, vertexNr, vertexElement, startVertexNr, endVertexNr, edgeCost;
        GraphAL<E> graphAL(givenNumberOfVertices);
        std::string line;
        std::string s;
        std::ifstream data(FILENAME);
        if(data.is_open()) {
            data >> numberOfVertices >> numberOfEdges;
            std::cout << "Readed nov: " << numberOfVertices << " noe: " << numberOfEdges << std::endl;
            while(s != "vertices:") data >> s;
            for(int i=0; i<numberOfVertices; i++) {
                data >> vertexNr >> vertexElement;
                graphAL.insertElementToVertex(vertexNr, vertexElement);
            }
            
            while(s != "edges:") data >> s;
            for(int i=0; i<numberOfEdges; i++) {
                data >> startVertexNr >> endVertexNr >> edgeCost;
                graphAL.addEdge(startVertexNr, endVertexNr, edgeCost);
            }
        }
        data.close();
        return graphAL;
    }
    
    GraphAM<E> readGraphAMFromFile(int givenNumberOfVertices) {
        int numberOfVertices, numberOfEdges, vertexNr, vertexElement, startVertexNr, endVertexNr, edgeCost;
        GraphAM<E> graphAM(givenNumberOfVertices);
        std::string line;
        std::string s;
        std::ifstream data(FILENAME);
        if(data.is_open()) {
            data >> numberOfVertices >> numberOfEdges;
            std::cout << "Readed nov: " << numberOfVertices << " noe: " << numberOfEdges << std::endl;
            while(s != "vertices:") data >> s;
            for(int i=0; i<numberOfVertices; i++) {
                data >> vertexNr >> vertexElement;
                graphAM.insertElementToVertex(vertexNr, vertexElement);
            }
            
            while(s != "edges:") data >> s;
            for(int i=0; i<numberOfEdges; i++) {
                data >> startVertexNr >> endVertexNr >> edgeCost;
                graphAM.addEdge(startVertexNr, endVertexNr, edgeCost);
            }
        }
        data.close();
        return graphAM;
    }
    
    void testGraphAL() {
        int choice = 0;
        int numberOfVertices, numberOfEdges;
        std::cout << "Create graph from random data (1) or enter yourself (2)?: ";
        std::cin >> choice;
        if(choice == 1) {
            std::cout << "Enter number of vertices: ";
            std::cin >> numberOfVertices;
            std::cout << "Enter number of edges: ";
            std::cin >> numberOfEdges;
            generateRandomGraphData(numberOfVertices, numberOfEdges, FILENAME);
            std::cout << "Random data has been generated" << std::endl;
            GraphAL<E> graphAL = readGraphALFromFile(numberOfVertices);
            graphALMenu(graphAL);
        } else if(choice == 2) {
            std::cout << "Enter number of vertices: ";
            std::cin >> numberOfVertices;
            GraphAL<E> graphAL(numberOfVertices);
            graphALMenu(graphAL);
        } else {
            std::cout << "Please choose 1 or 2" << std::endl;
            exit(1);
        }
    }
    
    void testGraphAM() {
        int choice = 0;
        int numberOfVertices, numberOfEdges;
        std::cout << "Create graph from random data (1) or enter yourself (2)?: ";
        std::cin >> choice;
        if(choice == 1) {
            std::cout << "Enter number of vertices: ";
            std::cin >> numberOfVertices;
            std::cout << "Enter number of edges: ";
            std::cin >> numberOfEdges;
            generateRandomGraphData(numberOfVertices, numberOfEdges, FILENAME);
            std::cout << "Random data has been generated" << std::endl;
            GraphAM<E> graphAM = readGraphAMFromFile(numberOfVertices);
            graphAMMenu(graphAM);
        } else if(choice == 2) {
            std::cout << "Enter number of vertices: ";
            std::cin >> numberOfVertices;
            GraphAL<E> graphAL(numberOfVertices);
            graphALMenu(graphAL);
        } else {
            std::cout << "Please choose 1 or 2" << std::endl;
            exit(1);
        }
    }
    
    void graphAMMenu(GraphAM<E> graphAM) {
        int choice, vertexNr, element, startVertexNr, endVertexNr, edgeCost;
        printBasicMenu();
        do {
            std::cin >> choice;
            if(choice == 7)
                exit(1);
            else {
                switch (choice) {
                    case 1:
                        graphAM.printVertices();
                        printBasicMenu();
                        break;
                        
                    case 2:
                        std::cout << "Enter vertex nr: ";
                        std::cin >> vertexNr;
                        std::cout << "Enter element to insert: ";
                        std::cin >> element;
                        graphAM.insertElementToVertex(vertexNr, element);
                        printBasicMenu();
                        break;
                        
                    case 3:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        std::cout << "Enter cost: ";
                        std::cin >> edgeCost;
                        graphAM.addEdge(startVertexNr, endVertexNr, edgeCost);
                        printBasicMenu();
                        break;
                        
                    case 4:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        graphAM.removeEdge(startVertexNr, endVertexNr);
                        printBasicMenu();
                        break;
                        
                    case 5:
                        graphAM.printAdjacencyMatrix();
                        printBasicMenu();
                        break;
                        
                    case 6:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        if(graphAM.areAdjacent(startVertexNr, endVertexNr)) {
                            std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are adjacent" << std::endl;
                        } else std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are not adjacent" << std::endl;
                        printBasicMenu();
                        break;
                        
                    case 7:
                        exit(1);
                        break;
                        
                    default:
                        break;
                }
            }
        } while(choice != 7);
    }
    
    void graphALMenu(GraphAL<E> graphAL) {
        int choice, vertexNr, element, startVertexNr, endVertexNr, edgeCost;
        printBasicMenu();
        do {
            std::cin >> choice;
            if(choice == 7)
                exit(1);
            else {
                switch (choice) {
                    case 1:
                        graphAL.printVertices();
                        printBasicMenu();
                        break;
                        
                    case 2:
                        std::cout << "Enter vertex nr: ";
                        std::cin >> vertexNr;
                        std::cout << "Enter element to insert: ";
                        std::cin >> element;
                        graphAL.insertElementToVertex(vertexNr, element);
                        printBasicMenu();
                        break;
                        
                    case 3:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        std::cout << "Enter cost: ";
                        std::cin >> edgeCost;
                        graphAL.addEdge(startVertexNr, endVertexNr, edgeCost);
                        printBasicMenu();
                        break;
                        
                    case 4:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        graphAL.removeEdge(startVertexNr, endVertexNr);
                        printBasicMenu();
                        break;
                        
                    case 5:
                        graphAL.printEdges();
                        printBasicMenu();
                        break;
                        
                    case 6:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        if(graphAL.areAdjacent(startVertexNr, endVertexNr)) {
                            std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are adjacent" << std::endl;
                        } else std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are not adjacent" << std::endl;
                        printBasicMenu();
                        break;
                        
                    case 7:
                        exit(1);
                        break;
         
                    default:
                        break;
                }
            }
        } while(choice != 7);
    }
    
    void printBasicMenu() {
        std::cout << "What you want to do?" << std::endl;
        std::cout << "1 - print vertices" << std::endl;
        std::cout << "2 - insert element to vertex" << std::endl;
        std::cout << "3 - add edge" << std::endl;
        std::cout << "4 - remove edge" << std::endl;
        std::cout << "5 - print edges/adjacencyMatrix" << std::endl;
        std::cout << "6 - check if vertices are adjacent" << std::endl;
        std::cout << "7 - exit" << std::endl;
    }
    
    void generateRandomGraphData(int numberOfVertices, int numberOfEdges, std::string fileName) {
        RandomDataGenerator randomDataGenerator;
        randomDataGenerator.generateGraphData(numberOfVertices, numberOfEdges, fileName);
    }
    
    void printFirstMenu() {
        std::cout << "What you want to do?" << std::endl;
        std::cout << "1 - test graph AL" << std::endl;
        std::cout << "2 - test graph AM" << std::endl;
        std::cout << "3 - test hash map" << std::endl;
        std::cout << "4 - exit" << std::endl;
    }
    
public:
    
    Menu() { }
    
    void start() {
        int choice;
        printFirstMenu();
        std::cin >> choice;
        switch(choice) {
            case 1:
                testGraphAL();
                break;
            case 2:
                testGraphAM();
                break;
            case 3:
                exit(1);
                break;
            case 4:
                exit(1);
            default:
                break;
        }
    }
};

#endif /* Menu_h */
