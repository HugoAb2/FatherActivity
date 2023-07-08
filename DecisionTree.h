#ifndef FATHERACTIVITY_DECISIONTREE_H
#define FATHERACTIVITY_DECISIONTREE_H

#include "Node.h"
#include "Disease.h"

using namespace std;

class DecisionTree {

private:
    Node* root;
    Node* buildRecTree(vector<string>& vetor, int& indice);
    void printRecTree(Node* node, int nivel);


public:

    void buildTree(vector<string>& vetor);

    void runTree(vector<Disease>* dataset);

    void runNode(Node *node, vector<struct Disease> *pVector);

    void printTree();

};

#endif