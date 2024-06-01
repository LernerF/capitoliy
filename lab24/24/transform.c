#include <stdio.h>
#include <stdlib.h>
#include "transform.h"

Node* transformTree(Node* node) {
    if (!node) return NULL;

    node->left = transformTree(node->left);
    node->right = transformTree(node->right);

    if (node->token.type == TOKEN_OPERATOR && node->token.data.op == '-' &&
        node->left && node->left->token.type == TOKEN_OPERATOR && node->left->token.data.op == '^' &&
        node->left->right && node->left->right->token.type == TOKEN_NUMBER && node->left->right->token.data.value == 3 &&
        node->right && node->right->token.type == TOKEN_OPERATOR && node->right->token.data.op == '^' &&
        node->right->right && node->right->right->token.type == TOKEN_NUMBER && node->right->right->token.data.value == 3) {

        Token plusToken = {TOKEN_OPERATOR, {.op = '+'}};
        Token minusToken = {TOKEN_OPERATOR, {.op = '-'}};
        Token multToken = {TOKEN_OPERATOR, {.op = '*'}};

        Node* a = node->left->left;
        Node* b = node->right->left;

        // Create (a - b)
        Node* minusNode = createNode(minusToken);
        minusNode->left = a;
        minusNode->right = b;

        // Create (a^2 + ab + b^2)
        Node* a2 = createNode(node->left->token); // a^2
        Node* b2 = createNode(node->right->token); // b^2

        Node* ab = createNode(multToken); // ab
       

 ab->left = a;
        ab->right = b;

        Node* plus_ab = createNode(plusToken); // ab + b^2
plus_ab->left = ab;
        plus_ab->right = b2;

        Node* plus_a2_ab_b2 = createNode(plusToken); // a^2 + (ab + b^2)
        plus_a2_ab_b2->left = a2;
        plus_a2_ab_b2->right = plus_ab;

        // Create final node (a - b) * (a^2 + ab + b^2)
        Node* multNode = createNode(multToken);
        multNode->left = minusNode;
        multNode->right = plus_a2_ab_b2;

        // Free the nodes that are no longer used
        freeTree(node->left->right);
        freeTree(node->left);
        freeTree(node->right->right);
        freeTree(node->right);

        free(node); // Free the current node
        return multNode;
    }

    return node;
}
