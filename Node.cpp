#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(string& value) : symptom(value){
    children = nullptr;
}

void Node::addChild(Node* child) {
    this->children = child;
}

string Node::getSymptom(){
    return "Are you feeling " + symptom + "?";
}

Node* Node::getChildren() {
    if (children != nullptr) return children;
    else return nullptr;
}

#endif