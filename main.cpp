#include <iostream>
#include "DocumentReceiver.h"
#include "Disease.h"
#include "DecisionTree.h"
#include <algorithm>

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

    //criando arvore, percorrendo e atualizando resultados em dataset
    DecisionTree tree;
    tree.buildTree(symptomsN);
    tree.runTree(dataset);

    //verificando e printando resultados em dataset
    if (dataset.empty()) cout << "No diseases match" << endl;
    else{
        vector<string> diagnostics;
        for(Disease disease : dataset){
            string answer = diseasesN[disease.getCode() - 1];
            if (find(diagnostics.begin(), diagnostics.end(), answer) == diagnostics.end()) {
                diagnostics.push_back(answer);
            }
        }
        for(string diagnostic: diagnostics){
            cout<< diagnostic << endl;
        }
    }


}
