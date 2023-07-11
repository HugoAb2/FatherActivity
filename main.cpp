#include <iostream>
#include "DocumentReceiver.h"
#include "Disease.h"
#include "DecisionTree.h"
#include <algorithm>

using namespace std;

int main() {
    // CodDic        Dia         turno            Nome              matricula
    // QXD0010 | terca-quarta  | manha | Hugo Rodrigues Amadeu    | 422631
    // QXD0010 | segunda-terca | tarde | Elienai Ribeiro da Silva | 416808

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
    tree.buildTree(symptomsN, dataset);
    vector<int> answers;
    tree.runTree(dataset, answers);

    //verificando e printando resultados em dataset
    if (answers.empty()) cout << "No diseases match" << endl;
    else{
        vector<string> diagnostics;
        for(int code : answers){
            string answer = diseasesN[code-1];
            if (find(diagnostics.begin(), diagnostics.end(), answer) == diagnostics.end()) {
                diagnostics.push_back(answer);
            }
        }
        for(const string& diagnostic: diagnostics){
            cout<< diagnostic << endl;
        }
    }


}
