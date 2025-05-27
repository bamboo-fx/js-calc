#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum TokenType {NUMBER, PLUS, MINUS, TIMES, DIVIDE}

struct Token {
    TokenType type;
    string value;
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
        }

        for (Token t : tokens) {
            cout << "Type: " << t.type << ", Value: " << t.value << endl;
        }
    }

    return 0;
}

struct ASTNode() {
    string value;
    ASTNode* left = nullptr
    ASTNode* right = nullptr

    ASTNode(string value) : value(val); {}
}

