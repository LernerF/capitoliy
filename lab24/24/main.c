#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "transform.h"

int main() {
    char input[256];
    printf("Enter an expression: ");
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = 0;

        Token* tokens = tokenize(input);
        Token* currentToken = tokens;
        Node* root = parseExpression(&currentToken);

        printf("Original expression: ");
        printTree(root);
        printf("\n");

        Node* transformedRoot = transformTree(root);
        printf("Transformed expression: ");
        printTree(transformedRoot);
        printf("\n");

        freeTree(transformedRoot); // Free the transformed tree
        free(tokens); // Free the tokens
    }
    return 0;
}
