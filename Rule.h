#ifndef LAB2_RULE_H
#define LAB2_RULE_H

#include <vector>
#include "Predicate.h"

using namespace std;

class Rule {
private:
    Predicate headPred;
    vector<Predicate> body;
public:
    void HasSameAddress();
};

#endif //LAB2_RULE_H
