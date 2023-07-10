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
    Node(string& symptom);

    void addChild(Node* child);

    string getSymptom();

    string symptomMessage();

    Node* getChildren();

};

#endif  // NODE_H
