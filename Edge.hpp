//
// Created by tomas on 2018-03-11.
//

#ifndef ASSIGNMENT4_EDGE_HPP
#define ASSIGNMENT4_EDGE_HPP


#include "Graph.hpp"
#include "Node.hpp"
#include "BaseNode.hpp"
#include <iostream>

using namespace std;

class Edge{
public:
    Edge(); // Default Constructor
    Edge(BaseNode* node1, BaseNode* node2); // Constructor with nodes
    Edge(bool direction, BaseNode* node1, BaseNode* node2); // Constructor with nodes and direction
    Edge(const Edge &e); // Copy Constructor
    ~Edge(); // Destructor
    bool operator ==(const Edge& rhs); // Compare operator
    bool getDirection(); // Returns direction
    void setDirection(bool direction); // Sets direction
    void setNode1(BaseNode* node1); // Sets first node
    void setNode2(BaseNode* node2); // Sets second node
    BaseNode* getNode1(); // Returns first node
    BaseNode* getNode2(); // Returns second node
protected:
    bool direction; // true: node1->node2; false: node1<-node2
    BaseNode* node1;
    BaseNode* node2;
};

#endif //ASSIGNMENT4_EDGE_HPP
