#ifndef LAB2_DATALOG_H
#define LAB2_DATALOG_H

#include <vector>
#include <set>
#include "Predicate.h"
#include "Rule.h"

using namespace std;

class dataLog{
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;
    set<Parameter> domains;
public:

};

#endif //LAB2_DATALOG_H
