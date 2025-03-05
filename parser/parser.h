#ifndef _parser_h_
#define _parser_h_

#include "../elements/elements.h"
#include <string>
#include <vector>
#include <iostream>

enum TokenType {
    LEFT_PARENTHESIS, RIGHT_PARENTHESIS,
    PLUS, MINUS, STAR, SLASH, CIRCUMFLEX,
    LITERAL, IDENTIFIER,
    EOL
};

struct Token {
    TokenType tokenType;
    std::string lexeme;
    int column;
};

class Parser {
    public:
    static std::vector<Token> tokenize(std::string line);
    static Expression *parse(std::vector<Token> &tokens);

    private:
    static Expression *expression(std::vector<Token> &tokens, int &index);
    static Expression *term(std::vector<Token> &tokens, int &index);
    static Expression *factor(std::vector<Token> &tokens, int &index);
    static Expression *unary(std::vector<Token> &tokens, int &index);
    static Expression *primary(std::vector<Token> &tokens, int &index);
};

#endif
