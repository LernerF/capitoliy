#include <string.h> 
#include <stdio.h> 
#include <stdbool.h>
#include "lib.h"
#include <stdlib.h>

// Функция для проверки монотонного убывания ширины уровней
bool is_monotonically_decreasing_width(BNode *root) {
    if (root == NULL) return true;

    int prev_width = -1;
    Queue *q = create_queue();  // предполагается, что такая функция существует
    enqueue(q, root);
    while (!is_empty(q)) {
        int level_size = queue_size(q);  // размер текущего уровня
        if (prev_width != -1 && level_size >= prev_width) {
            return false;
        }
        prev_width = level_size;

        for (int i = 0; i < level_size; i++) {
            BNode *node = dequeue(q);
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
    return true;
}

int main(void) { 
    char chr[15]; 
    BNode *node = NULL; 
    printf("Type 'help' to take info\n\n "); 
    while (1) { 
        printf("tree> "); 
        scanf("%s", chr); 
        if (!strcmp(chr, "check")) { 
            if (node == NULL || !is_monotonically_decreasing_width(node)) 
                printf(" NO\n\n"); 
            else 
                printf(" YES\n\n"); 
            printf(" "); 
        } 
        // Остальная часть кода остаётся без изменений
        // ... (Оставляю без изменений для краткости)
    }
}
