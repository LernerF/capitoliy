#include "iterator.h"

Iterator* iter_create(const List* list) {
    Iterator* iter = (Iterator*)malloc(sizeof(Iterator));
    if (!iter) {
        printf("Memory allocation error\n");
        exit(1);
    }
    iter->node = list->head;
    return iter;
}

void next(Iterator* iter) {
    if (iter->node) {
        iter->node = iter->node->next;
    }
}
