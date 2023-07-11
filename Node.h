#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Disease.h"

using namespace std;

class Node {

private:
    string symptom;
    vector<Disease> dataset;
    Node* trueChild;
    Node* falseChild;
    vector<int> results;

public:
    Node(string& symptom, vector<Disease> dataset);

    void addResultsVector(vector<int> resultVec);

    vector<int> getResults();

    void addResult(int dCode);

    vector<Disease> getDataset();

    void addTrueChild(Node* child);

    void addFalseChild(Node* child);

    string getSymptom();

    string symptomMessage();

    Node* getTrueChild();

    Node* getFalseChild();

};

#endif  // NODE_H
