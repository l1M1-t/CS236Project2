#ifndef LAB2_PREDICATE_H
#define LAB2_PREDICATE_H

#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate {
private:
    string id;
    vector<Parameter> params;
public:
    void snap();
    void HasSameAddress();
};

#endif //LAB2_PREDICATE_H
