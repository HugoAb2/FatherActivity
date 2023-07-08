#ifndef FATHERACTIVITY_DOCUMENTRECEIVER_H
#define FATHERACTIVITY_DOCUMENTRECEIVER_H

#include <vector>
#include"fstream"
#include "string"
#include "Disease.h"

using namespace std;

class DocumentReceiver {
private:
    ifstream document;
    int countD, countS;

public:
    DocumentReceiver(string name);

    void readDocumentTxt();

    void getCounts();

    void getDiseases(vector<string>* diseases);

    void getSymptons(vector<string>* symptoms);

    bool getValues(Disease* disease);
};

#endif