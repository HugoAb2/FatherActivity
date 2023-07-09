#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

class Node {

private:
    string symptom;
    Node* children;

public:
    Node(string& value);

    void addChild(Node* child);

    string getSymptom();

    Node* getChildren();

};

#endif  // NODE_H
