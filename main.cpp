#include <iostream>
#include "DocumentReceiver.h"
#include "Disease.h"
#include "DecisionTree.h"

using namespace std;

int main() {
    //recebendo o documento e armazenando para manipulacao em c++
    string path = R"(C:\Users\hugoc\Documents\Software Engenier\ED\FatherActivity\)";
    string docName = "SintomasMenor.txt";
    DocumentReceiver file(path + docName);
    vector<string> diseasesN, symptomsN;
    file.getDiseases(&diseasesN);
    file.getSymptons(&symptomsN);
    vector<Disease> dataset;
    Disease currentD;
    while(file.getValues(&currentD)){
        dataset.push_back(currentD);
    }

    DecisionTree tree;
    tree.buildTree(symptomsN);
    tree.runTree(dataset);

}
