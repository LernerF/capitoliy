#ifndef LW_LIST_H
#define LW_LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode *head;
} List;

List* list_create();
void list_print(List* list);
void list_insert_to_begin(int data, List* list);
void list_insert_to_end(int data, List* list);
void list_delete_begin(List* list);
void list_delete_end(List* list);
int list_size(List* list);
void list_reverse(List* list);
void list_destroy(List* list);

#endif // LW_LIST_H
