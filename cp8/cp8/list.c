#include "list.h"

List* list_create() {
    List* list = (List*)malloc(sizeof(List));
    if (!list) {
        printf("Memory allocation error\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void list_print(List* list) {
    if (!list || !list->head) return;
    ListNode* current = list->head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("(HEAD)\n");
}

void list_insert_to_begin(int data, List* list) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node) {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    if (!list->head) {
        new_node->next = new_node;
        list->head = new_node;
    } else {
        ListNode* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        new_node->next = list->head;
        list->head = new_node;
        tail->next = list->head;
    }
}

void list_insert_to_end(int data, List* list) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node) {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    if (!list->head) {
        new_node->next = new_node;
        list->head = new_node;
    } else {
        ListNode* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        new_node->next = list->head;
        tail->next = new_node;
    }
}

void list_delete_begin(List* list) {
    if (!list->head) return;
    ListNode* temp = list->head;
    if (list->head->next == list->head) {
        list->head = NULL;
    } else {
        ListNode* tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        list->head = list->head->next;
        tail->next = list->head;
    }
    free(temp);
}

void list_delete_end(List* list) {
    if (!list->head) return;
    ListNode* current = list->head;
    if (current->next == list->head) {
        free(current);
        list->head = NULL;
        return;
    }
    ListNode* prev = NULL;
    while (current->next != list->head) {
        prev = current;
        current = current->next;
    }
    prev->next = list->head;
    free(current);
}

int list_size(List* list) {
    if (!list->head) return 0;
    int size = 0;
    ListNode* current = list->head;
    do {
        size++;
        current = current->next;
    } while (current != list->head);
    return size;
}

void list_reverse(List* list) {
    if (!list->head || list->head->next == list->head) return;
    ListNode* prev = NULL;
    ListNode* current = list->head;
    ListNode* next = NULL;
    ListNode* tail = list->head;

    while (tail->next != list->head) {
        tail = tail->next;
    }

    do {
        next = current->next;
        current->next = prev ? prev : tail;
        prev = current;
        current = next;
    } while (current != list->head);

    list->head->next = prev;
    list->head = prev;
}

void list_destroy(List* list) {
    if (!list->head) return;
    ListNode* current = list->head;
    ListNode* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list->head);
    free(list);
}

