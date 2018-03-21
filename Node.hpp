//
// Created by tomas on 2018-03-11.
//

#ifndef ASSIGNMENT4_VERTEX_HPP
#define ASSIGNMENT4_VERTEX_HPP

#include "Graph.hpp"
#include "BaseNode.h"

using namespace std;

template<typename T>

class Node: public BaseNode{
public:
    Node():BaseNode(){ // Default Constructor

    }
    Node(Types type, T value): BaseNode(type){ // Constructor with parameters
        this->value = value;
    }
    Node(const Node &node){ // Copy Constructor
        this->value = node.value;
    }
    ~Node(){ // Destructor
        cout << "Node destroyed" << endl;
    }
    friend ostream& operator <<(ostream& os, const Node<T>& s){ // cout operator
        os << s.value;
        return os;
    }
    T getValue(){ // Returns the value
        return value;
    }
    void setValue(T value){ // Sets the value
        this->value = value;
    }
private:
    T value; // Information/label of the node
};



#endif /* NODE_H_ */


#endif //ASSIGNMENT4_VERTEX_HPP
