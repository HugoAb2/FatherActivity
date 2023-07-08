#ifndef FATHERACTIVITY_DISEASE_H
#define FATHERACTIVITY_DISEASE_H

#include "string"
#include "vector"
using namespace std;

class Disease {
private:
    int code;
    vector<bool> symptoms;

public:
    Disease(int code, const vector<bool> &symptoms);

    Disease();

    int getCode() const;

    void setCode(int code);

    const vector<bool> &getSymptoms() const;

    void setSymptoms(const vector<bool> &symptoms);
};


#endif //FATHERACTIVITY_DISEASE_H
