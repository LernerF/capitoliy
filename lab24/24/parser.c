#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

Token* tokenize(const char* str) {
    Token* tokens = malloc((strlen(str) + 1) * sizeof(Token));
    if (!tokens) {
        perror("Failed to allocate memory for tokens");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while (*str) {
        if (isspace(*str)) {
            str++;
            continue;
        }

        if (isdigit(*str) || (*str == '.' && isdigit(*(str + 1)))) {
            tokens[count++] = makeNumberToken(&str);
        } else if (isalpha(*str)) {
            tokens[count++] = makeVariableToken(&str);
        } else if (isOperator(*str)) {
            tokens[count++] = makeOperatorToken(&str);
        }
    }
    tokens[count].type = TOKEN_END;
    return tokens;
}

Token makeNumberToken(const char** str) {
    Token token;
    token.type = TOKEN_NUMBER;
    token.data.value = strtod(*str, (char**)str);
    return token;
}

Token makeOperatorToken(const char** str) {
    Token token;
    token.type = TOKEN_OPERATOR;
    token.data.op = **str;
    (*str)++;
    return token;
}

Token makeVariableToken(const char** str) {
    Token token;
    token.type = TOKEN_VARIABLE;
    int i = 0;
    while (isalnum(**str)) {
        token.data.var[i++] = **str;
        (*str)++;
    }
    token.data.var[i] = '\0';
    return token;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

Node* parseExpression(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    Node* node = parseTerm(currentToken);
    while (*currentToken && (*currentToken)->type == TOKEN_OPERATOR &&
           getPrecedence((*currentToken)->data.op) <= 1) {
        Token op = *(*currentToken)++;
        Node* right = parseTerm(currentToken);
        Node* new_node = createNode(op);
        new_node->left = node;
        new_node->right = right;
        node = new_node;
    }
    return node;
}

Node* parseTerm(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    Node* node = parseExponent(currentToken);
    while (*currentToken && (*currentToken)->type == TOKEN_OPERATOR &&
           getPrecedence((*currentToken)->data.op) == 2) {
        Token op = *(*currentToken)++;
        Node* right = parseExponent(currentToken);
        Node* new_node = createNode(op);
        new_node->left = node;
        new_node->right = right;
        node = new_node;
    }
    return node;
}

Node* parseExponent(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    Node* node = parseFactor(currentToken);
    while (*currentToken && (*currentToken)->type == TOKEN_OPERATOR &&
           getPrecedence((*currentToken)->data.op) == 3) {
        Token op = *(*currentToken)++;
        Node* right = parseFactor(currentToken);
        Node* new_node = createNode(op);
        new_node->left = node;
        new_node->right = right;
        node = new_node;
    }
    return node;
}

Node* parseFactor(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    if ((*currentToken)->type == TOKEN_NUMBER || (*currentToken)->type == TOKEN_VARIABLE) {
        Node* node = createNode(*(*currentToken)++);
        return node;
    }
    return NULL; // Invalid expression
}

Node* createNode(Token token) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for a new node");
        exit(EXIT_FAILURE);
    }
    newNode->token = token;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTree(const Node* node) {
    if (node == NULL) return;

    if (node->left != NULL && node->right != NULL) {
        printf("(");
    }

    printTree(node->left);

    switch (node->token.type) {
        case TOKEN_NUMBER:
            printf("%f", node->token.data.value);
            break;
        case TOKEN_VARIABLE:
            printf("%s", node->token.data.var);
            break;
        case TOKEN_OPERATOR:
            printf(" %c ", node->token.data.op);
            break;
        default:
            break;
    }

    printTree(node->right);

    if (node->left != NULL && node->right != NULL) {
        printf(")");
    }
}

void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

