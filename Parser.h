#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include "Token.h"
#include "DataLog.h"
using namespace std;

class Parser {
private:
   vector<Token> tokens;
   dataLog datalog;

public:
   Parser(const vector<Token>& tokens) : tokens(tokens) {}

   TokenType tokenType() const {
      return tokens[0].getType();
   }

   void advanceToken() {
      tokens.erase(tokens.begin());
   }

   void throwError() {
      cout << "error" << endl;
   }

   void match(TokenType t) {
      cout << "match: " << t << endl;
      if (tokenType() ==  t)
         advanceToken();
      else
         throwError();
   }

   void idList() {
      if (tokenType() == COMMA) {
         match(COMMA);
         match(ID);
         idList();
      } else {
         // lambda
      }
   }

   void scheme() {
      if (tokenType() == SCHEMES) {

      } else {
         throwError();
      }
   }
};

#endif
