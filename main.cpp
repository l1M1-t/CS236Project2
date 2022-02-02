#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <istream>
#include "Token.h"
#include "Scanner.h"
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[]) {

    int tokenAmount = 0;

    if (argc != 2)
        return 1;

    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }

    string accumulator = "";

    char currChar;
    while ((currChar = input.peek())) {
        if (currChar == EOF)
            break;
        input.get(currChar);
        accumulator += currChar;
    }

    Scanner s(accumulator);

    Token currToken = s.scanToken();
    tokenAmount++;
    Token temp = currToken;

    vector<Token> tokens;
    while (currToken.getType() != EOF_TOKEN) {
        tokenAmount++;
        tokens.push_back(currToken);
        currToken = s.scanToken();
    }
    tokens.push_back(currToken);

    Parser p(tokens);
    p.scheme();

    //loop through the token vector
    vector<Token>::iterator it;
    for (it = tokens.begin(); it != tokens.end(); it++) {

    }

    /*for (int i = 0; i < tokens.size(); i++) {
        tokens[i].toString();
    }*/


    cout << "Total Token = " << tokenAmount << endl;

    return 0;
}

/*vector<Token> tokens = {
        Token(ID, "Ned", 2),
        //Token(LEFT_PAREN, "(", 2),
        Token(ID, "Ted", 2),
        Token(COMMA, ",", 2),
        Token(ID, "Zed", 2),
        Token(RIGHT_PAREN, ")", 2),
};

Parser p = Parser(tokens);
p.scheme();*/