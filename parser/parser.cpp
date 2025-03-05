#include "parser.h"

std::vector<Token> Parser::tokenize(std::string line) {
    // TODO: Handle floats

    std::vector<Token> result;
    for (int i = 0; i < int(line.size()); i++) {
        if (line[i] == '(') result.push_back({LEFT_PARENTHESIS, "(", i});
        else if (line[i] == ')') result.push_back({RIGHT_PARENTHESIS, ")", i});
        else if (line[i] == '+') result.push_back({PLUS, "+", i});
        else if (line[i] == '-') result.push_back({MINUS, "-", i});
        else if (line[i] == '*') result.push_back({STAR, "*", i});
        else if (line[i] == '/') result.push_back({SLASH, "/", i});
        else if (line[i] == '^') result.push_back({CIRCUMFLEX, "^", i});
        else if (isalpha(line[i])) {
            int j = i + 1;
            while (j < int(line.size()) && isalpha(line[j])) j++;
            result.push_back({IDENTIFIER, line.substr(i, j - i), i});
        } else if (isdigit(line[i])) {
            int j = i + 1;
            while (j < int(line.size()) && isdigit(line[j])) j++;
            result.push_back({IDENTIFIER, line.substr(i, j - i), i});
        } else if (isblank(line[i])) continue;
        else {
            std::cout << "Error in column " << i << ": couldn't recognize token" << std::endl;
            // TODO: Error handling
        }
    }

    result.push_back({EOL, "", int(result.size())});

    return result;
}