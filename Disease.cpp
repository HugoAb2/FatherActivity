#include "Disease.h"

Disease::Disease(int code, const vector<bool> &symptoms) : code(code), symptoms(symptoms) {}

Disease::Disease() {}

int Disease::getCode() const {
    return code;
}

void Disease::setCode(int code) {
    Disease::code = code;
}

const vector<bool> &Disease::getSymptoms() const {
    return symptoms;
}

void Disease::setSymptoms(const vector<bool> &symptoms) {
    Disease::symptoms = symptoms;
}
