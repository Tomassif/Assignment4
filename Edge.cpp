//
// Created by tomas on 2018-03-11.
//

#include "Edge.hpp"
#include "BaseNode.hpp"

//testing 123 github here
//luca was here
Edge::Edge(){ 
    direction = false;
    node1 = NULL;
    node2 = NULL;
}
Edge::Edge(BaseNode* node1, BaseNode* node2){
    direction = false;
    this->node1 = node1;
    this->node2 = node2;
}
Edge::Edge(bool direction, BaseNode* node1, BaseNode* node2){
    this->direction = direction;
    this->node1 = node1;
    this->node2 = node2;
}
Edge::Edge(const Edge &e){
    direction = e.direction;
    node1 = e.node1;
    node2 = e.node2;
}
Edge::~Edge(){
    cout << "Edge Destroyed" << endl;
}
bool Edge::operator ==(const Edge& rhs){
    if((node1 == rhs.node1 && node2 == rhs.node2) || (node1 == rhs.node2 && node2 == rhs.node2)){
        return true;
    }
    return false;
}
bool Edge::getDirection(){
    return direction;
}
void Edge::setDirection(bool direction){
    this->direction = direction;
}
void Edge::setNode1(BaseNode* node1){
    this->node1 = node1;
}
void Edge::setNode2(BaseNode* node2){
    this->node2 = node2;
}
BaseNode* Edge::getNode1(){
    return node1;
}
BaseNode* Edge::getNode2(){
    return node2;
}
