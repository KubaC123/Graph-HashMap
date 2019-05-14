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
#include "HashMapLP.h"
#include "HashMapUtil.h"
#include "HashMapDH.h"
#include "HashMapL.h"
#include "List.h"

#define FILENAME "graph_data.txt"

template<typename E, typename K, typename V>
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
        printBasicGraphMenu();
        do {
            std::cin >> choice;
            if(choice == 7)
                exit(1);
            else {
                switch (choice) {
                    case 1:
                        graphAM.printVertices();
                        printBasicGraphMenu();
                        break;
                        
                    case 2:
                        std::cout << "Enter vertex nr: ";
                        std::cin >> vertexNr;
                        std::cout << "Enter element to insert: ";
                        std::cin >> element;
                        graphAM.insertElementToVertex(vertexNr, element);
                        printBasicGraphMenu();
                        break;
                        
                    case 3:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        std::cout << "Enter cost: ";
                        std::cin >> edgeCost;
                        graphAM.addEdge(startVertexNr, endVertexNr, edgeCost);
                        printBasicGraphMenu();
                        break;
                        
                    case 4:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        graphAM.removeEdge(startVertexNr, endVertexNr);
                        printBasicGraphMenu();
                        break;
                        
                    case 5:
                        graphAM.printAdjacencyMatrix();
                        printBasicGraphMenu();
                        break;
                        
                    case 6:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        if(graphAM.areAdjacent(startVertexNr, endVertexNr)) {
                            std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are adjacent" << std::endl;
                        } else std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are not adjacent" << std::endl;
                        printBasicGraphMenu();
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
        printBasicGraphMenu();
        do {
            std::cin >> choice;
            if(choice == 7)
                exit(1);
            else {
                switch (choice) {
                    case 1:
                        graphAL.printVertices();
                        printBasicGraphMenu();
                        break;
                        
                    case 2:
                        std::cout << "Enter vertex nr: ";
                        std::cin >> vertexNr;
                        std::cout << "Enter element to insert: ";
                        std::cin >> element;
                        graphAL.insertElementToVertex(vertexNr, element);
                        printBasicGraphMenu();
                        break;
                        
                    case 3:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        std::cout << "Enter cost: ";
                        std::cin >> edgeCost;
                        graphAL.addEdge(startVertexNr, endVertexNr, edgeCost);
                        printBasicGraphMenu();
                        break;
                        
                    case 4:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        graphAL.removeEdge(startVertexNr, endVertexNr);
                        printBasicGraphMenu();
                        break;
                        
                    case 5:
                        graphAL.printEdges();
                        printBasicGraphMenu();
                        break;
                        
                    case 6:
                        std::cout << "Enter first vertex nr: ";
                        std::cin >> startVertexNr;
                        std::cout << "Enter second vertex nr: ";
                        std::cin >> endVertexNr;
                        if(graphAL.areAdjacent(startVertexNr, endVertexNr)) {
                            std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are adjacent" << std::endl;
                        } else std::cout << "Vertex " << startVertexNr << " and " << endVertexNr << " are not adjacent" << std::endl;
                        printBasicGraphMenu();
                        break;
                        
                    case 7:
                        exit(1);
                        break;
         
                    default:
                        printBasicHashMapMenu();
                        break;
                }
            }
        } while(choice != 7);
    }
    
    void printBasicGraphMenu() {
        std::cout << "What you want to do?" << std::endl;
        std::cout << "1 - print vertices" << std::endl;
        std::cout << "2 - insert element to vertex" << std::endl;
        std::cout << "3 - add edge" << std::endl;
        std::cout << "4 - remove edge" << std::endl;
        std::cout << "5 - print edges/adjacencyMatrix" << std::endl;
        std::cout << "6 - check if vertices are adjacent" << std::endl;
        std::cout << "7 - exit" << std::endl;
    }
    
    void testHashMapLP() {
        HashMapUtil hashMapUtil;
        int capacity = 0;
        while(1) {
            std::cout << "Enter map capacity (it must be a prime number) or 0 to exit: ";
            std::cin >> capacity;
            if(hashMapUtil.isPrime(capacity))
                break;
            else if(capacity == 0)
                exit(1);
            else
                std::cout << capacity << " is not a prime number" << std::endl;
        }
        HashMapLP<int, int> hashMapLP(capacity);
        hashMapLPMenu(hashMapLP);
    }
    
    void testHashMapDH() {
        HashMapUtil hashMapUtil;
        int capacity = 0;
        while(1) {
            std::cout << "Enter map capacity (it must be a prime number) or 0 to exit: ";
            std::cin >> capacity;
            if(hashMapUtil.isPrime(capacity))
                break;
            else if(capacity == 0)
                exit(1);
            else
                std::cout << capacity << " is not a prime number" << std::endl;
        }
        HashMapDH<int, int> hashMapDH(capacity);
        hashMapDHMenu(hashMapDH);
    }
    
    void testHashMapL() {
        HashMapUtil hashMapUtil;
        int capacity = 0;
        while(1) {
            std::cout << "Enter map capacity (it must be a prime number) or 0 to exit: ";
            std::cin >> capacity;
            if(hashMapUtil.isPrime(capacity))
                break;
            else if(capacity == 0)
                exit(1);
            else
                std::cout << capacity << " is not a prime number" << std::endl;
        }
        HashMapL<int, int> hashMapL(capacity);
        hashMapLMenu(hashMapL);
    }
    
    void hashMapDHMenu(HashMapDH<K,V> hashMapDH) {
        std::cout << "Filling half of the hash map with random values..." << std::endl;
        int mapCapacity = hashMapDH.getCapacity();
        int insertedValues[mapCapacity];
        int insertedKeys[mapCapacity];

        for(int i=0; i<mapCapacity/2; i++) {
            insertedKeys[i] = -1;
            insertedValues[i] = -1;
        }

        for(int i=0; i<mapCapacity/2; i++) {
            int key, value;
            do {
                key = rand() % mapCapacity;
            } while(insertedKeys[key] != -1);
            do {
                value = rand() % mapCapacity;
            } while(insertedValues[value] != -1);
            std::cout << "Inserting (" << key << "," << value << ") pair..." << std::endl;
            hashMapDH.put(key, value);

            insertedKeys[key] = 1;
            insertedValues[value] = 1;
        }
        std::cout << " --------------------------- " << std::endl;
        int choice = 0;
        printBasicHashMapMenu();
        do {
            std::cin >> choice;
            switch(choice) {
                case 1:
                    hashMapDH.print();
                    printBasicHashMapMenu();
                    break;
                case 2:
                    int key, value;
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    hashMapDH.put(key, value);
                    printBasicHashMapMenu();
                    break;
                    
                case 3:
                    int keyToRemove;
                    std::cout << "Insert key to remove: ";
                    std::cin >> keyToRemove;
                    if(hashMapDH.get(keyToRemove) == -1) {
                        std::cout << "No such key in map" << std::endl;
                    } else {
                        hashMapDH.remove(keyToRemove);
                        std::cout << "Removed" << std::endl;
                    }
                    printBasicHashMapMenu();
                    break;
                    
                case 4: {
                    int keyToGet;
                    std::cout << "Enter key to get value ";
                    std::cin >> keyToGet;
                    int returnValue = hashMapDH.get(keyToGet);
                    if(returnValue == -1) {
                        std::cout << "No such key in map" << std::endl;
                    } else {
                        std::cout << "Found value: " << returnValue << std::endl;
                    }
                    printBasicHashMapMenu();
                    break;
                }
                    
                case 5: {
                    exit(1);
                    break;
                }
                    
                default: {
                    printBasicHashMapMenu();
                    break;
                }
            }
            
        } while (1);
    }
    
    void hashMapLMenu(HashMapL<K,V> hashMapL) {
        std::cout << "Filling half of the hash map with random values..." << std::endl;
        int mapCapacity = hashMapL.getCapacity();
        List<int> insertedValues;
        List<int> insertedKeys;
        
        for(int i=0; i<mapCapacity/2; i++) {
            int key, value;
            do {
                key = rand() % mapCapacity*2;
            } while(insertedKeys.isPresent(key));
            do {
                value = rand() % mapCapacity*2;
            } while(insertedValues.isPresent(value));
            std::cout << "Inserting (" << key << "," << value << ") pair..." << std::endl;
            hashMapL.put(key, value);
            
            insertedKeys.pushBack(key);
            insertedValues.pushBack(value);
        }
        std::cout << " --------------------------- " << std::endl;
        int choice = 0;
        printBasicHashMapMenu();
        do {
            std::cin >> choice;
            switch(choice) {
                case 1:
                    hashMapL.print();
                    printBasicHashMapMenu();
                    break;
                case 2:
                    int key, value;
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    hashMapL.put(key, value);
                    printBasicHashMapMenu();
                    break;
                    
                case 3:
                    int keyToRemove;
                    std::cout << "Insert key to remove: ";
                    std::cin >> keyToRemove;
                    if(hashMapL.get(keyToRemove) == -1) {
                        std::cout << "No such key in map" << std::endl;
                    } else {
                        hashMapL.remove(keyToRemove);
                        std::cout << "Removed" << std::endl;
                    }
                    printBasicHashMapMenu();
                    break;
                    
                case 4: {
                    int keyToGet;
                    std::cout << "Enter key to get value ";
                    std::cin >> keyToGet;
                    int returnValue = hashMapL.get(keyToGet);
                    if(returnValue == -1) {
                        std::cout << "No such key in map" << std::endl;
                    } else {
                        std::cout << "Found value: " << returnValue << std::endl;
                    }
                    printBasicHashMapMenu();
                    break;
                }
                    
                case 5: {
                    exit(1);
                    break;
                }
                    
                default: {
                    printBasicHashMapMenu();
                    break;
                }
            }
            
        } while (1);
    }
    
    void hashMapLPMenu(HashMapLP<K,V> hashMapLP) {
        std::cout << "Filling half of the hash map with random values..." << std::endl;
        int mapCapacity = hashMapLP.getCapacity();
        int insertedValues[mapCapacity];
        int insertedKeys[mapCapacity];

        for(int i=0; i<mapCapacity/2; i++) {
            insertedKeys[i] = -1;
            insertedValues[i] = -1;
        }

        for(int i=0; i<mapCapacity/2; i++) {
            int key, value;
            do {
                key = rand() % mapCapacity;
            } while(insertedKeys[key] != -1);
            do {
                value = rand() % mapCapacity;
            } while(insertedValues[value] != -1);
            std::cout << "Inserting (" << key << "," << value << ") pair..." << std::endl;
            hashMapLP.put(key, value);

            insertedKeys[key] = 1;
            insertedValues[value] = 1;
        }
        std::cout << " --------------------------- " << std::endl;
        int choice = 0;
        printBasicHashMapMenu();
        do {
            std::cin >> choice;
            switch(choice) {
                case 1:
                    hashMapLP.print();
                    printBasicHashMapMenu();
                    break;
                case 2:
                    int key, value;
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    hashMapLP.put(key, value);
                    printBasicHashMapMenu();
                    break;
                    
                case 3:
                    int keyToRemove;
                    std::cout << "Insert key to remove: ";
                    std::cin >> keyToRemove;
                    if(hashMapLP.get(keyToRemove) == -1) {
                        std::cout << "No such key in map" << std::endl;
                    } else {
                        hashMapLP.remove(keyToRemove);
                        std::cout << "Removed" << std::endl;
                    }
                    printBasicHashMapMenu();
                    break;
                    
                case 4: {
                    int keyToGet;
                    std::cout << "Enter key to get value ";
                    std::cin >> keyToGet;
                    int returnValue = hashMapLP.get(keyToGet);
                    if(returnValue == -1) {
                        std::cout << "No such key in map" << std::endl;
                    } else {
                        std::cout << "Found value: " << returnValue << std::endl;
                    }
                    printBasicHashMapMenu();
                    break;
                }
                    
                case 5: {
                    exit(1);
                    break;
                }
                    
                default: {
                    printBasicHashMapMenu();
                    break;
                }
            }
            
        } while (1);
    }
    
    void printBasicHashMapMenu() {
        std::cout << "What you want to do?" << std::endl;
        std::cout << "1 - print (key, value) pairs" << std::endl;
        std::cout << "2 - insert pair to map" << std::endl;
        std::cout << "3 - remove pair with given key" << std::endl;
        std::cout << "4 - get value from given key" << std::endl;
        std::cout << "5 - exit" << std::endl;
    }
    
    void generateRandomGraphData(int numberOfVertices, int numberOfEdges, std::string fileName) {
        RandomDataGenerator randomDataGenerator;
        randomDataGenerator.generateGraphData(numberOfVertices, numberOfEdges, fileName);
    }
    
    void printFirstMenu() {
        std::cout << "What you want to do?" << std::endl;
        std::cout << "1 - test graph AL" << std::endl;
        std::cout << "2 - test graph AM" << std::endl;
        std::cout << "3 - test hash map with linear probing" << std::endl;
        std::cout << "4 - test hash map with double hashing" << std::endl;
        std::cout << "5 - test hash map with linking" << std::endl;
        std::cout << "6 - exit" << std::endl;
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
                testHashMapLP();
                break;
            case 4:
                testHashMapDH();
                break;
            case 5:
                testHashMapL();
                break;
            case 6:
                exit(1);
            default:
                break;
        }
    }
};

#endif /* Menu_h */
