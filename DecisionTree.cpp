#include "DecisionTree.h"
#include <iostream>

void DecisionTree::buildTree(vector<string>& vetor) {
    int indice = 0;
    root = buildRecTree(vetor, indice);
}

Node* DecisionTree::buildRecTree(vector<string>& vetor, int& indice) {
    if (indice >= vetor.size()) {
        return nullptr;
    }

    Node* node = new Node(vetor[indice]);

    while (indice + 1 < vetor.size() && vetor[indice + 1] != node->getSymptom()) {
        indice++;
        Node* child = buildRecTree(vetor, indice);
        if (child != nullptr) {
            node->addChild(child);
        }
    }

    return node;
}

void DecisionTree :: runTree(vector<Disease>* dataset){
    runNode(root, dataset);
}

void DecisionTree :: runNode(Node* node, vector<Disease>* dataset){
    if (node == nullptr) {
        return;
    }

    cout << node->getSymptom() << " (s/n): ";
    char resposta;
    cin >> resposta;

    if (resposta == 's') {
        //for (int i=0;i<dataset->size();i++) {
        //    if (dataset->at(i).getSymptoms()[i]){
        //        cout << i <<" ";
        //    }
        //}
        runNode(node->getChildren()[0], nullptr);
    } else {
        runNode(node->getChildren()[0], nullptr);
    }
}


void DecisionTree::printTree(){
    printRecTree(root, 0);
}

void DecisionTree::printRecTree(Node* node, int nivel){
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < nivel; i++) {
        std::cout << "  ";
    }

    std::cout << node->getSymptom() << std::endl;

    for (Node* child : node->getChildren()) {
        printRecTree(child, nivel + 1);
    }
}
