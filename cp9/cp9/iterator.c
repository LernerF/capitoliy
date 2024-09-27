#include "iterator.h"
#include <stdlib.h>
#include <stdio.h>

Iterator* iter_create(Table* table) {
    Iterator* iter = (Iterator*)malloc(sizeof(Iterator));
    if (iter == NULL) {
        printf("MEMORY ALLOCATION ERROR\n");
        exit(1);
    }
    iter->table = table;
    iter->index = 0;
    return iter;
}

void iter_next(Iterator* iter) {
    if (iter->index < iter->table->size) {
        iter->index++;
    }
}

bool iter_has_next(Iterator* iter) {
    return iter->index < iter->table->size;
}

char* iter_current(Iterator* iter) {
    if (iter->index < iter->table->size) {
        return iter->table->data[iter->index];
    }
    return NULL;
}
