//
// Created by tomas on 2018-03-11.
//

#ifndef ASSIGNMENT4_GRAPH_HPP
#define ASSIGNMENT4_GRAPH_HPP
#include "Edge.hpp"
#include "Node.hpp"
#include "BaseNode.hpp"
#include <vector>

class Graph{
public:
    Graph(); // Default Constructor
    Graph(bool directed); // Constructor with direction
    Graph(unsigned int count, unsigned int edgeCount, vector<BaseNode*> nodes, vector<string> types, vector<Edge*> edges, bool directed); // Constructor with parameters
    Graph(const Graph &g); // Copy Constructor
    ~Graph(); // Destructor
    bool isDirected(); // Checks if the graph is a directed one
    void setDirected(bool directed); // Sets if the graph is directed or not
    int getNodeCount(); // Returns the number of nodes
    int getEdgeCount(); // Returns the number of edges
    void addNode(BaseNode* node); // Adds a node
    void removeNode(BaseNode* node); // Removes the indicated node and shifts the others
    void addEdge(Edge* e); // Adds an edge
    void removeEdge(Edge* e); // Removes the indicated edge and shifts the others
    void printUnconnectedNodes(); // Print every unconnected nodes
    void printNode(BaseNode* n); // Print the value of a specific node
    void print(); // Print the graph information
    void printPathFromNode(BaseNode* n); // Print the possible paths from a specific node
    bool edgeExists(Edge* e); // Tests if an edge is part of the graph
    bool nodeExists(BaseNode* n); // Tests if a node if part of the graph
    template<typename T> bool valueContained(T value, BaseNode::Types type){ // Tests if a certain value if contained
        for(size_t i = 0; i < nodeCount; i++){
            if(type == nodes[i]->getType()){
                if(static_cast<Node<T>*>(nodes[i])->getValue() == value){
                    return true;
                }
            }
        }
        return false;
    }
private:
    unsigned int nodeCount; // Keeps the number of nodes
    unsigned int edgeCount; // Keeps the number of edges
    vector<BaseNode*> nodes;
    vector<string> types;
    vector<Edge*> edges; // Keeps all the edges
    bool directed; // States if the graph is directed or not
};



/*
class Graph {
public:
    Graph();
    virtual ~Graph();
    //add in one vertex; bool returns if its added successfully

    virtual bool addVertex(Vertex& v)=0;
    //bonus: add in a set of vertices; bool returns if its added
    //virtual bool addVertices(Vertex* vArray)=0;
    //the edges that have connection with this vertex need to be removed;
    virtual bool removeVertex()=0;
    //remove an edge; as a result, some node may remain as orphan.
    virtual bool addEdge(Edge& e)=0;
    //Bonus: remove a set of edge; as a result, some node may remain as orphan.
    //virtual bool addEdges(Edge* eArray)=0;
    //remove the edge.
    //return bool if a vertex exists in a graph;
    virtual bool searchVertex(const Vertex& v)=0;
    //return bool if an edge exists in a graph;
    virtual bool searchEdge(const Edge& e)=0;
    //display the path that contains the vertex;
    virtual void display(Vertex& v) const = 0;
    //display the path that contains the edge;
    virtual void display(Edge& e) const=0;
    //display the whole graph with your own defined format
    virtual void display() const=0;
    /*convert the whole graph to a string such as 1-2-4-5,
     * 1-3-5; each path is separated by ';'  .
     * define your own format of a string representation of the graph
     * */
/*
    virtual string toString() const = 0;
    //remove all the vertices and edges;
    virtual bool clean() = 0;

};
*/


#endif //ASSIGNMENT4_GRAPH_HPP
