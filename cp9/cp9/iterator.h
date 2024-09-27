#ifndef LW_ITERATOR_H
#define LW_ITERATOR_H

#include "table.h"

typedef struct Iterator {
  Table* table;
  int index;
} Iterator;

Iterator* iter_create(Table* table);
void iter_next(Iterator* iter);
bool iter_has_next(Iterator* iter);
char* iter_current(Iterator* iter);

#endif
