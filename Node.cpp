#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(string& value) : symptom(value){

}

void Node::addChild(Node* child) {
    children.push_back(child);
}

string Node::getSymptom(){
    return "Are you feeling " + symptom + "?";
}

vector<Node*>& Node::getChildren() {
    return children;
}

#endif