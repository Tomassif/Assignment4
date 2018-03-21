//
// Created by tomas on 2018-03-11.
//

#include "Graph.hpp"
#include "BaseNode.hpp"
#include <iomanip>
//luca was here
Graph::Graph(){
    edgeCount = 0;
    nodeCount = 0;
    directed = false;
}
Graph::Graph(bool directed){
    edgeCount = 0;
    nodeCount = 0;
    this->directed = directed;
}
Graph::Graph(unsigned int nodeCount, unsigned int edgeCount, vector<BaseNode*> nodes, vector<string> types, vector<Edge*> edges, bool directed){
    this->nodeCount = nodeCount;
    this->edgeCount = edgeCount;
    for(size_t i = 0; i < nodeCount; i++){
        this->nodes[i] = nodes[i];
        this->types[i] = types[i];
    }
    for(size_t i = 0; i < edgeCount; i++){
        this->edges[i] = edges[i];
    }
    this->directed = directed;
}
Graph::Graph(const Graph &g){
    this->nodeCount = g.nodeCount;
    this->edgeCount = g.edgeCount;
    for(size_t i = 0; i < nodeCount; i++){
        nodes[i] = g.nodes[i];
        types[i] = g.types[i];
    }
    for(size_t i = 0; i < edgeCount; i++){
        edges[i] = g.edges[i];
    }
    directed = g.directed;
}
Graph::~Graph(){
    for(size_t i = 0; i < nodeCount; i++){
        delete nodes[i];
    }
}
bool Graph::isDirected(){
    return directed;
}
void Graph::setDirected(bool directed){
    // If goes from directed to undirected, deletes every edges connecting two same nodes since direction doesn't matter in undirected graph
    if(!directed && this->directed){
        this->directed = directed; // Sets it after the verification in order for the function addEdge to behave properly
        for(size_t i = 0; i < edgeCount-1; i++){
            for(size_t j = i+1; j < edgeCount; j++){
                if(edges[i] == edges[j]){
                    removeEdge(edges[j]);
                    j--;
                }
            }
        }
        // If goes from undirected to directed, makes a copy of every edge in the opposite direction to connect both nodes back and forth
    }else if(directed && !this->directed){
        this->directed = directed; // Sets it after the verification in order for the function addEdge to behave properly
        size_t temp = edgeCount;
        for(size_t i = 0; i < temp; i++){
            cout << "caca" << endl;
            addEdge(new Edge(!edges[i]->getDirection(), edges[i]->getNode1(), edges[i]->getNode2()));
        }
    }else{
        return;
    }
}
int Graph::getNodeCount(){
    return nodeCount;
}
int Graph::getEdgeCount(){
    return edgeCount;
}
void Graph::addNode(BaseNode* node){
    nodes.push_back(node);
    nodeCount++;
}
void Graph::addEdge(Edge* edge){
    bool add1 = true, add2 = true;
    // tests if the nodes of that edge are in the graph
    for(size_t i = 0; i < nodeCount; i++){
        if(edge->getNode1() == nodes[i]){
            add1 = false;
        }
        if(edge->getNode2() == nodes[i]){
            add2 = false;
        }
    }
    for(size_t i = 0; i < edgeCount; i++){
        if(edges[i]->getNode1() == edge->getNode1() && edges[i]->getNode2() == edge->getNode2()){
            if(!directed || edges[i]->getDirection() == edge->getDirection()){
                return;
            }
        }else if(edges[i]->getNode1() == edge->getNode2() && edges[i]->getNode2() == edge->getNode1()){
            if(!directed || edges[i]->getDirection() != edge->getDirection()){
                return;
            }
        }
    }
    // If one or two of the nodes of the edge are not part of the graph, add them in it
    if(add1){
        addNode(edge->getNode1());
    }
    if(add2){
        addNode(edge->getNode2());
    }
    edges.push_back(edge);
    edgeCount++;
}
void Graph::removeNode(BaseNode* node){
    for(size_t i = 0; i < nodeCount; i++){
        if(node == nodes[i]){
            // Removes every edge associated with that node
            for(size_t j = 0; j < edgeCount; j++){
                if(edges[j]->getNode1() == node || edges[j]->getNode2() == node){
                    removeEdge(edges[j]);
                    j--;
                }
            }
            nodes.erase(nodes.begin()+i);
        }
    }
    nodeCount--;
}
void Graph::removeEdge(Edge* edge){
    for(size_t i = 0; i < nodeCount; i++){
        if(edge == edges[i]){
            edges.erase(edges.begin()+i);
        }
    }
    edgeCount--;
}
void Graph::printNode(BaseNode* n){
    switch(n->getType()){
        // Casts according to the type of the node
        case BaseNode::st:
            cout << *static_cast<Node<string>*>(n);
            break;
        case BaseNode::i:
            cout << *static_cast<Node<int>*>(n);
            break;
        case BaseNode::d:
            cout << *static_cast<Node<double>*>(n);
            break;
        case BaseNode::b:
            cout << *static_cast<Node<bool>*>(n);
            break;
        case BaseNode::f:
            cout << *static_cast<Node<float>*>(n);
            break;
        case BaseNode::l:
            cout << *static_cast<Node<long>*>(n);
            break;
        case BaseNode::s:
            cout << *static_cast<Node<short>*>(n);
            break;
        case BaseNode::c:
            cout << *static_cast<Node<char>*>(n);
            break;
        case BaseNode::g:
            cout << "Graph: " << *static_cast<Node<Graph*>*>(n);
            break;
        case BaseNode::e:
            cout << "Edge: " << *static_cast<Node<Edge*>*>(n);
            break;
        case BaseNode::bN:
            cout << "BaseNode: " << *static_cast<Node<BaseNode*>*>(n);
            break;
        case BaseNode::nSt:
            cout << "Node<string>: " << *static_cast<Node<Node<string>*>*>(n);
            break;
        case BaseNode::nI:
            cout << "Node<int>: " << *static_cast<Node<Node<int>*>*>(n);
            break;
        case BaseNode::nD:
            cout << "Node<double>: " << *static_cast<Node<Node<double>*>*>(n);
            break;
        case BaseNode::nB:
            cout << "Node<bool>: " << *static_cast<Node<Node<bool>*>*>(n);
            break;
        case BaseNode::nF:
            cout << "Node<float>: " << *static_cast<Node<Node<float>*>*>(n);
            break;
        case BaseNode::nL:
            cout << "Node<long>: " << *static_cast<Node<Node<long>*>*>(n);
            break;
        case BaseNode::nS:
            cout << "Node<short>: " << *static_cast<Node<Node<short>*>*>(n);
            break;
        case BaseNode::nC:
            cout << "Node<char>: " << *static_cast<Node<Node<char>*>*>(n);
            break;
        case BaseNode::nG:
            cout << "Node<Graph>: " << *static_cast<Node<Node<Graph*>*>*>(n);
            break;
        case BaseNode::nE:
            cout << "Node<Edge>: " << *static_cast<Node<Node<Edge*>*>*>(n);
            break;
        case BaseNode::nBn:
            cout << "Node<BaseNode>: " << *static_cast<Node<Node<BaseNode*>*>*>(n);
            break;
    }
}
void Graph::printUnconnectedNodes(){
    for(size_t i = 0; i < nodeCount; i++){
        bool unconnected = true;
        for(size_t j = 0; j < edgeCount; j++){
            if(edges[j]->getNode1() == nodes[i] || edges[j]->getNode2() == nodes[i]){
                unconnected = false;
            }
        }
        if(unconnected){
            printNode(nodes[i]);
            cout << endl;
        }
    }
}
void Graph::print(){
    if(nodeCount == 0){
        cout << "Empty graph" << endl;
    }else{
        cout << "N = {";
        for(size_t i = 0; i < nodeCount; i++){
            printNode(nodes[i]);
            if(i != nodeCount - 1){
                cout << ", ";
            }
        }
        cout << "}" << endl;
        cout << "E = {";
        for(size_t i = 0; i < edgeCount; i++){
            cout << "(";
            printNode(edges[i]->getNode1());
            cout << ",";
            printNode(edges[i]->getNode2());
            cout << ")";
            if(i != edgeCount - 1){
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}
void Graph::printPathFromNode(BaseNode* n){
    static bool printTabs = true;
    if(!nodeExists(n)){
        cout << "Node not in graph, printing graph info: " << endl;
        print();
    }else if(!directed){
        cout << "Undirected, printing graph info: " << endl;
        print();
    }else{
        bool printed = false;
        for(size_t i = 0; i < edgeCount; i++){
            if(edges[i]->getDirection() && edges[i]->getNode1()==n){
                if(!edges[i]->getNode2()->isShown() && edges[i]->getNode2()!=n){
                    // Prints tabs if on new line
                    if(printTabs){
                        size_t tabs = 0;
                        for(size_t i = 0; i < nodeCount; i++){
                            if(nodes[i]->isShown()){
                                tabs++;
                            }
                        }
                        for(size_t i = 0; i < tabs; i++){
                            if(i != tabs-1){
                                cout << setw(15 + 4 * (tabs-1));
                            }else{
                                cout << setw(15);
                            }
                            cout << "";
                            if(tabs == 1 || i != 0){
                                cout << " |> ";
                            }
                        }
                        printTabs = false;
                    }
                    cout << setw(15) << left;
                    printNode(n);
                    printed = true;
                    cout << " -> ";
                    n->setShown(true);
                    printPathFromNode(edges[i]->getNode2());
                    n->setShown(false);
                }
            }else if(!edges[i]->getDirection() && edges[i]->getNode2()==n){
                if(!edges[i]->getNode1()->isShown() && edges[i]->getNode1()!=n){
                    // Prints tabs if on new line
                    if(printTabs){
                        size_t tabs = 0;
                        for(size_t i = 0; i < nodeCount; i++){
                            if(nodes[i]->isShown()){
                                tabs++;
                            }
                        }
                        for(size_t i = 0; i < tabs; i++){
                            if(i != tabs-1){
                                cout << setw(15 + 4 * (tabs-1));
                            }else{
                                cout << setw(15);
                            }
                            cout << "";
                            if(tabs == 1 || i != 0){
                                cout << " |> ";
                            }
                        }
                        printTabs = false;
                    }
                    printNode(n);
                    printed = true;
                    cout << " -> ";
                    n->setShown(true);
                    printPathFromNode(edges[i]->getNode1());
                    n->setShown(false);
                }
            }
        }
        if(!printed){
            printNode(n);
            cout << endl;
            printTabs = true;
        }
    }
}
bool Graph::edgeExists(Edge* e){
    for(size_t i = 0; i < edgeCount; i++){
        if(directed){
            if(e->getDirection() == edges[i]->getDirection() && e->getNode1() == edges[i]->getNode1() && e->getNode2() == edges[i]->getNode2()){
                return true;
            }else if(e->getDirection() != edges[i]->getDirection() && e->getNode1() == edges[i]->getNode2() && e->getNode2() == edges[i]->getNode1()){
                return true;
            }
        }else{
            if(e == edges[i]){
                return true;
            }
        }
    }
    return false;
}
bool Graph::nodeExists(BaseNode* n){
    for(size_t i = 0; i < nodeCount; i++){
        if(nodes[i] == n){
            return true;
        }
    }
    return false;
}
