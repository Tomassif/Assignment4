//
// Created by tomas on 2018-03-21.
//

#include "BaseNode.hpp"


BaseNode::BaseNode(){
    type = s;
    shown = false;
}
BaseNode::BaseNode(Types type){
    this->type = type;
    shown = false;
}
BaseNode::BaseNode(const BaseNode &b){
    type = b.type;
    shown = b.shown;
}
BaseNode::~BaseNode(){

}
BaseNode::Types BaseNode::getType(){
    return type;
}
void BaseNode::setShown(bool shown){
    this->shown = shown;
}
bool BaseNode::isShown(){
    return shown;
}
