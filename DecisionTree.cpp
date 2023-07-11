#include "DecisionTree.h"
#include <iostream>

void DecisionTree::buildTree(vector<string>& symptomsNames, vector<Disease>& dataset) {
    int indice = 0;
    root = buildRecTree(symptomsNames, dataset,indice);
}

Node* DecisionTree::buildRecTree(vector<string>& symptomsNames, vector<Disease> dataset,int indice) {
    if (indice > symptomsNames.size()) {
        return nullptr;
    }

    if (indice==symptomsNames.size()){
        string resCode = "Result";
        Node* node = new Node(resCode, dataset);
        vector<int> resultVector;
        node->addResultsVector(resultVector);
        for (Disease disease : dataset) {
            node->addResult(disease.getCode());
        }
        return node;
    }

    Node* node = new Node(symptomsNames[indice], dataset);

    Node* trueChild = buildRecTree(symptomsNames, updateDataset(true, dataset, indice),indice+1);
    if (trueChild != nullptr) node->addTrueChild(trueChild);

    Node* falseChild = buildRecTree(symptomsNames, updateDataset(false, dataset, indice),indice+1);
    if (falseChild != nullptr) node->addFalseChild(falseChild);


    return node;
}

vector<Disease> DecisionTree::updateDataset(bool choice, vector<Disease> dataset, int sIndicator) {
    if (choice) {
        for (int i=dataset.size()-1;i>=0;i--) {
            if (!dataset.at(i).getSymptoms()[sIndicator]){
                dataset.erase(dataset.begin() +i);
            }
        }
    } else {
        for (int i=dataset.size()-1;i>=0;i--) {
            if (dataset.at(i).getSymptoms()[sIndicator]){
                dataset.erase(dataset.begin() +i);
            }
        }
    }
    return dataset;
}

Node* DecisionTree :: runTree(vector<Disease>& dataset){
    return runNode(root, dataset, 0);
}

Node* DecisionTree :: runNode(Node* node, vector<Disease> dataset, int sIndicator){
    if (node->getSymptom() == "Result") {
        return node;
    }

    cout << node->symptomMessage();
    bool answer;
    cin >> answer;

    if (answer) {
        runNode(node->getTrueChild(), node->getDataset(), sIndicator + 1);
    } else {
        runNode(node->getFalseChild(), node->getDataset(), sIndicator + 1);
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

    while (node->getTrueChild()) {
        printRecTree(node->getTrueChild(), level + 1);
    }
}
