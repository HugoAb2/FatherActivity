#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(string& symptom, vector<Disease> dataset) : symptom(symptom), dataset(dataset){
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

Node* Node::getTrueChild() {
    if (trueChild != nullptr) return trueChild;
    else return nullptr;
}

Node* Node::getFalseChild() {
    if (falseChild != nullptr) return falseChild;
    else return nullptr;
}

#endif