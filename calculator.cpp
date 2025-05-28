#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum TokenType {NUMBER, PLUS, MINUS, TIMES, DIVIDE};

struct Token {
    TokenType type;
    string value;
};

struct ASTNode() {
    string value;
    ASTNode* left = nullptr;
    ASTNode* right = nullptr;

    ASTNode(string value) : value(val); {}
};

int main() {
    while (true) {
        string input;
        cout << "> ";
        getline(cin, input);

        if (input == "exit") break;

        vector<Token> tokens;

        for (int i = 0; i < input.length(); i++) {
            char current = input[i];

            if (isdigit(current)) {
                string number(1, current);
                while (i + 1 < input.length() && isdigit(input[i + 1])) {
                    number += input[i + 1];
                    i++;
                }
                tokens.push_back({NUMBER, number});
            }
            else if (current == '+') {
                tokens.push_back({PLUS, "+"});
            }
            else if (current == '-') {
                tokens.push_back({MINUS, "-"});
            }
            else if (current == '/') {
                tokens.push_back({DIVIDE, "/"})
            }
            else if (current = '*') {
                tokens.push_back({TIMES, "*"})
            }
        }

        for (Token t : tokens) {
            cout << "Type: " << t.type << ", Value: " << t.value << endl;
        }
    }

    return 0;
}


int current = 0;

Token peek(vector<Token>& tokens) {
    return current < tokens.size() ? tokens[current] : Token{NUMBER, ""};
}

Token advance(vector<Token>& tokens) {
    return tokens[current++];
}

bool match(vector<Token>& tokens, TokenType type) {
    if (peek(tokens).type == type) {
        advance(tokens);
        return true;
    }
    return false;
}

ASTNode* parseNumbers(vector<Token>& tokens) {
    if (match(tokens, NUMBER)) {
        return new ASTNode(tokens[current - 1].value);
    }

    cout << "Unexpected token: " << peek(tokens).value << endl;
    exit(1);
}

ASTNode* parseMD(vector<Token>& tokens) {
    ASTNode* node = parseFactor(tokens);

    while (match(tokens, TIMES) || match(tokens, DIVIDE)) {
        string op = tokens[current - 1].value;
        ASTNode* right = parseFactor(tokens);
        ASTNode* newNode = new ASTNode(op);
        newNode->left = node;
        newNode->right = right;
        node = newNode;
    }

    return node;
}

ASTNode* parseAS(vector<Token>& tokens) {
    ASTNode* node = parseTerm(tokens);

    while (match(tokens, PLUS) || match(tokens, MINUS)) {
        string op = tokens[current - 1].value;
        ASTNode* right = parseTerm(tokens);
        ASTNode* newNode = new ASTNode(op);
        newNode->left = node;
        newNode->right = right;
        node = newNode;
    }

    return node;
}
