#ifndef FATHERACTIVITY_DECISIONTREE_H
#define FATHERACTIVITY_DECISIONTREE_H

#include "Node.h"
#include "Disease.h"

using namespace std;

class DecisionTree {

private:
    Node* root;
    Node* buildRecTree(vector<string>& symptomsNames, vector<Disease> dataset,int& indice);
    vector<Disease> updateDataset(bool choice, vector<Disease> dataset, int sIndicator);
    void runNode(Node *node, vector<Disease> &pVector, int sIndicator);
    void printRecTree(Node* node, int level);


public:

    void buildTree(vector<string>& symptomsNames, vector<Disease>& dataset);

    void runTree(vector<Disease>& dataset);

    void printTree();

};

#endif