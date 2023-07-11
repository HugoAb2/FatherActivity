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

void DecisionTree :: runTree(vector<Disease>& dataset, vector<int>& answers){
    runNode(root, 0, answers);

}

Node* DecisionTree :: runNode(Node* node, int sIndicator, vector<int>& answers){
    if (node->getSymptom() == "Result") {
        for (int dCode : node->getResults()) {
            answers.push_back(dCode);
        }
        return node;
    }

    cout << node->symptomMessage();
    bool answer;
    cin >> answer;

    if (answer) {
        runNode(node->getTrueChild(), sIndicator + 1, answers);
    } else {
        runNode(node->getFalseChild(), sIndicator + 1, answers);
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
