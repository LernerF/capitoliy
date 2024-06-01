#ifndef LW_ITERATOR_H
#define LW_ITERATOR_H

#include "list.h"

typedef struct Iterator {
    ListNode* node;
} Iterator;

Iterator* iter_create(const List* list);
void next(Iterator* iter);

#endif // LW_ITERATOR_H
