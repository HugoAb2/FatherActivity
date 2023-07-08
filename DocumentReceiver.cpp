#include <sstream>
#include "DocumentReceiver.h"
#include "iostream"


DocumentReceiver::DocumentReceiver(string name) {
    document.open(name);
    getCounts();
}

void DocumentReceiver::readDocumentTxt() {
    if (document.is_open()){
        string line;
        while (getline(document,line)){
            cout<<line<<endl;
        }
        document.close();
    } else cout << "Document not found"<<endl;
}

void DocumentReceiver::getCounts() {
    if (document.is_open()){
        string line;
        getline(document, line);
        istringstream iss(line);
        iss >> countD >> countS;
    }
}

void DocumentReceiver::getDiseases(vector<string>* diseases) {
    if (document.is_open()){
        string line;
        int i=0;
        while (i < countD){
            getline(document, line);
            diseases->push_back(line);
            i++;
        }
    }
}

void DocumentReceiver::getSymptons(vector<string>* symptoms) {
    if (document.is_open()){
        string line;
        int i=0;
        while (i < countS){
            getline(document, line);
            symptoms->push_back(line);
            i++;
        }
    }
}

bool DocumentReceiver::getValues(Disease* currentD) {
    if (document.is_open()){
        string line;
        //fechando documento ao final do percurso
        if(!getline(document, line)){
            document.close();
            return false;
        }else {
            vector<bool> data;
            int code;
            bool value;
            istringstream iss(line);
            iss >> code;
            while (iss >> value) {
                data.push_back(value);
            }
            currentD->setCode(code);
            currentD->setSymptoms(data);
            return true;
        }
    }
}



