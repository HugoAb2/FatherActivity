#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

class Node {

private:
    string symptom;
    Node* trueChild;
    Node* falseChild;

public:
    Node(string& symptom);

    void addTrueChild(Node* child);

    void addFalseChild(Node* child);

    string getSymptom();

    string symptomMessage();

    Node* getChildren();

};

#endif  // NODE_H
