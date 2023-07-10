#include "DecisionTree.h"
#include <iostream>

void DecisionTree::buildTree(vector<string>& symptomsNames) {
    int indice = 0;
    root = buildRecTree(symptomsNames, indice);
}

Node* DecisionTree::buildRecTree(vector<string>& symptomsNames, int& indice) {
    if (indice >= symptomsNames.size()) {
        return nullptr;
    }

    Node* node = new Node(symptomsNames[indice]);

    while (indice + 1 < symptomsNames.size() && symptomsNames[indice + 1] != node->getSymptom()) {
        indice++;
        Node* trueChild = buildRecTree(symptomsNames, indice);
        if (trueChild != nullptr) {
            node->addTrueChild(trueChild);
            Node* falseChild = new Node(symptomsNames[indice]);
            node->addFalseChild(falseChild);
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

    cout << node->symptomMessage();
    bool answer;
    cin >> answer;

    if (answer) {
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
