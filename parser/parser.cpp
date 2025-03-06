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
            result.push_back({LITERAL, line.substr(i, j - i), i});
        } else if (isblank(line[i])) continue;
        else {
            std::cout << "Error in column " << i << ": couldn't recognize token" << std::endl;
            // TODO: Error handling
        }
    }

    result.push_back({EOL, "", int(result.size())});

    return result;
}

Expression *Parser::parse(std::vector<Token> &tokens) {
    // TODO: Error handling
    int index = 0;
    return expression(tokens, index);
}

Expression *Parser::expression(std::vector<Token> &tokens, int &index) {
    return term(tokens, index);
}

Expression *Parser::term(std::vector<Token> &tokens, int &index) {
    Expression *left = factor(tokens, index);

    while (tokens[index].tokenType == PLUS || tokens[index].tokenType == MINUS) {
        bool sum = tokens[index].tokenType == PLUS;
        Expression *right = factor(tokens, ++index);

        if (sum) left = new Sum(left, right);
        else left = new Subtraction(left, right);
    }

    return left;
}

Expression *Parser::factor(std::vector<Token> &tokens, int &index) {
    Expression *left = unary(tokens, index);

    while (tokens[index].tokenType == STAR || tokens[index].tokenType == SLASH) {
        bool multiplication = tokens[index].tokenType == STAR;
        Expression *right = unary(tokens, ++index);

        if (multiplication) left = new Multiplication(left, right);
        else left = new Division(left, right);
    }

    return left;
}

Expression *Parser::unary(std::vector<Token> &tokens, int &index) {
    if (tokens[index].tokenType == MINUS) {
        Expression *right = primary(tokens, ++index);
        return new Subtraction(new Integer(0), right);
    }

    return primary(tokens, index);
}

Expression *Parser::primary(std::vector<Token> &tokens, int &index) {
    if (tokens[index].tokenType == LEFT_PARENTHESIS) {
        Expression *inner = expression(tokens, ++index);

        if (tokens[index].tokenType != RIGHT_PARENTHESIS) {
            // Todo: raise error
            std::cout << "Error in column " << tokens[index].column << ": expected a \")\"" << std::endl;
        }
        index++;

        return inner;
    }
    if (tokens[index].tokenType == LITERAL) {
        int value = std::stoi(tokens[index].lexeme);
        index++;
        return new Integer(value);
    }

    // TODO: Raise error
    std::cout << "Error in column " << tokens[index].column << ": expected an expression" << std::endl;
    std::cout << tokens[index].tokenType << std::endl;
    return nullptr;
}