#ifndef PARSER_H
#define PARSER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_VARIABLE,
    TOKEN_OPERATOR,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    union {
        double value; // Used only for numbers (int or float)
        char op;      // Used only for operators
        char var[256]; // Used only for variables
    } data;
} Token;

typedef struct Node {
    Token token;
    struct Node* left;
    struct Node* right;
} Node;

Token* tokenize(const char* str);
Node* parseExpression(Token** currentToken);
void printTree(const Node* node);
void freeTree(Node* node);

#endif // PARSER_H
