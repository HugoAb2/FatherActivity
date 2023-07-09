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

void DecisionTree :: runTree(vector<Disease>& dataset){
    runNode(root, dataset, 0);
}

void DecisionTree :: runNode(Node* node, vector<Disease>& dataset, int sIndicator){
    if (node == nullptr) {
        return;
    }

    cout << node->getSymptom() << " (s/n): ";
    char answer;
    cin >> answer;

    if (answer == 's') {
        for (int i=dataset.size()-1;i>=0;i--) {
            if (!dataset.at(i).getSymptoms()[sIndicator]){
                dataset.erase(dataset.begin() +i);
            }
        }
        runNode(node->getChildren(), dataset, sIndicator+1);
    } else {
        for (int i=dataset.size()-1;i>=0;i--) {
            if (dataset.at(i).getSymptoms()[sIndicator]){
                dataset.erase(dataset.begin() +i);
            }
        }
        runNode(node->getChildren(), dataset, sIndicator+1);
    }
}


void DecisionTree::printTree(){
    printRecTree(root, 0);
}

void DecisionTree::printRecTree(Node* node, int level){
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < level; i++) {
        std::cout << "  ";
    }

    std::cout << node->getSymptom() << std::endl;

    while (node->getChildren()) {
        printRecTree(node->getChildren(), level + 1);
    }
}
