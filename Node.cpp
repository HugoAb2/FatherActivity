#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(string& symptom) : symptom(symptom){
    trueChild = nullptr;
    falseChild = nullptr;
}

void Node::addTrueChild(Node* child) {
    this->trueChild = child;
}

void Node::addFalseChild(Node* child) {
    this->falseChild = child;
}

string Node::getSymptom(){
    return symptom;
}

string Node::symptomMessage(){
    return "Are you feeling " + symptom + "? ";
}

Node* Node::getChildren() {
    if (trueChild != nullptr) return trueChild;
    else return nullptr;
}

#endif