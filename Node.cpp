#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(string& symptom) : symptom(symptom){
    children = nullptr;
}

void Node::addChild(Node* child) {
    this->children = child;
}

string Node::getSymptom(){
    return symptom;
}

string Node::symptomMessage(){
    return "Are you feeling " + symptom + "? ";
}

Node* Node::getChildren() {
    if (children != nullptr) return children;
    else return nullptr;
}

#endif