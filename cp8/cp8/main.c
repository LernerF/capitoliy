#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void help_command() {
    printf("\tins <value>  : add a new node to the tree\n");
    printf("\tdel <value>  : remove a node from the tree\n");
    printf("\tshow         : show tree structure in terminal\n");
    printf("\tget_min      : show the smallest node of the tree\n");
    printf("\tget_max      : show the largest node of the tree\n");
    printf("\tget_root     : show the root node of the tree\n");
    printf("\tclear        : clear the tree structure\n");
    printf("\tis_width_decreasing (iwd): check if the tree is width decreasing\n");
    printf("\trev          : reverse the list\n");
    printf("\texit         : close the program\n");
}

void invalid_command(char* command) {
    printf("%s: command not found\n", command);
    printf("Type 'help' to learn about commands\n\n");
}

void ins_command(List* list) {
    int data;
    scanf("%d", &data);
    list_insert_to_end(data, list);
    printf("%d was successfully inserted to the list\n", data);
}

void del_command(List* list) {
    list_delete_end(list);
    printf("Last element was successfully deleted from the list\n");
}

void show_command(List* list) {
    if (!list->head) {
        printf("The list is empty\n");
    } else {
        printf("\n");
        list_print(list);
        printf("\n");
    }
}

void clear_command(List* list) {
    if (!list->head) {
        printf("The list is empty\n");
    } else {
        printf("List clear visualization: \n\n");
        list_destroy(list);
        list->head = NULL;
        printf("The list is empty now\n");
    }
}

void rev_command(List* list) {
    list_reverse(list);
    printf("The list has been reversed\n");
}

int main(void) {
    List* list = list_create();
    char command[20];
    printf("Type 'help' to learn about commands\n\n");
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (!strcmp(command, "help")) {
            help_command();
        } else if (!strcmp(command, "ins")) {
            ins_command(list);
        } else if (!strcmp(command, "del")) {
            del_command(list);
        } else if (!strcmp(command, "show")) {
            show_command(list);
        } else if (!strcmp(command, "clear")) {
            clear_command(list);
        } else if (!strcmp(command, "rev")) {
            rev_command(list);
        } else if (!strcmp(command, "exit")) {
            clear_command(list);
            break;
        } else {
            invalid_command(command);
        }
    }
    free(list);
    return 0;
}
