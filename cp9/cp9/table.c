#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "table.h"

void CreateTable(Table* t){
    t->size = 0;
}

bool ReadTable(FILE* in, Table* t){
    t->size = 0;
    while (fgets(t->data[t->size], sizeof(t->data[t->size]), in) != NULL){
        if (ferror(in)) {
            return false;
        }
        t->size++;
    }
    return true;
}

int SizeTable(Table* t){
    return t->size;
}

void PrintLine(void){
    for (int i = 0; i<180; i++){
        printf("-");
    }
    printf("\n");
}

void PrintTable(Table* t){
    printf("+-------+");
    PrintLine();
    printf("|  Ключ |                          Значение                                                \n");
    printf("+-------+");
    PrintLine();
    for (int i=0; i < t->size; i++){
        int index = 0;
        int64_t key;
        sscanf(&(t->data[i][0]), "%I64d", &key);
        while (isspace(t->data[i][index])){ index++; }
        while (isdigit(t->data[i][index])){ index++; }
        printf("| %5I64d |%s", key, &(t->data[i][index]));
    }
}

int SearchByKey(Table* t, int64_t key){
    int left = 0;
    int right = SizeTable(t) - 1;
    int mid;
    int64_t key_m;
    
    while (left <= right){
        mid = (left + right) / 2;
        sscanf(&(t->data[mid][0]), "%I64d", &key_m);
        if(key_m == key){
            return mid;
        } else if (key_m > key){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    } 
    return -1;
}

Table* Copy(Table *t){
    Table* res = (Table*)malloc(sizeof(Table));
    CreateTable(res);
    for(int i = 0; i < SizeTable(t); i++){
        strcpy(res->data[i], t->data[i]);
    }
    res->size = t->size;
    return res;
}

void Merge(Table* t1, Table* t2){
    Table* tab = Copy(t1);
    ClearTable(t1);
    int it = 0;
    int i2 = 0;
    int i1 = 0;
    int64_t keyt = 0, key2 = 0;
    while(it < SizeTable(tab) && i2 < SizeTable(t2)){
        sscanf(&(tab->data[it][0]), "%I64d", &keyt);
        sscanf(&(t2->data[i2][0]), "%I64d", &key2);
        if (keyt <= key2){
            strcpy(t1->data[i1], tab->data[it]);
            it++;
        } else {
            strcpy(t1->data[i1], t2->data[i2]);
            i2++;
        }
        i1++;
    }
    while(it < SizeTable(tab)){
        strcpy(t1->data[i1], tab->data[it]);
        it++;
        i1++;
    }
    while(i2 < SizeTable(t2)){
        strcpy(t1->data[i1], t2->data[i2]);
        i2++;
        i1++;
    }
    t1->size = SizeTable(tab) + SizeTable(t2);
    
    DeleteTable(tab);
    DeleteTable(t2);
}

Table* SortTable(Table* t){
    if(SizeTable(t) <= 1){
        return t;
    }
    
    Table* left = (Table*)malloc(sizeof(Table));
    Table* right = (Table*)malloc(sizeof(Table));
    CreateTable(left);
    CreateTable(right);
    int middle = SizeTable(t) / 2;
    
    for(int i=0; i<middle; i++){
        strcpy(left->data[i], t->data[i]);
    }
    left->size = middle;
    for(int i=middle; i < SizeTable(t); i++){
        strcpy(right->data[i-middle], t->data[i]);
    }
    right->size = SizeTable(t) - middle;
    
    left = SortTable(left);
    right = SortTable(right);
    Merge(left, right);
    
    DeleteTable(t);
    return left;
}

void ReverseTable(Table* t){
    int left = 0;
    int right = SizeTable(t) - 1;
    char bf[STR_SIZE];
    
    while (left < right){
        strcpy(bf, t->data[left]);
        ClearLine(t, left);
        strcpy(t->data[left], t->data[right]);
        ClearLine(t, right);
        strcpy(t->data[right], bf);
        for (int j = 0; j < STR_SIZE; j++){
            bf[j] = '\0';
        }
        right--;
        left++;
    }
}

void ClearTable(Table* t){
    for (int i = 0; i < t->size; i++){
        int len = strlen(t->data[i]);
        for (int j = 0; j < len; j++){
            t->data[i][j] = '\0';
        }
    }
    t->size = 0;
}

void ClearLine(Table* t, int i){
    int len = strlen(t->data[i]);
    for (int j = 0; j < len; j++){
        t->data[i][j] = '\0';
    }
}

void MixRandom(Table* t){
    int ln2;
    int s = SizeTable(t);
    srand(time(NULL));
    for (int ln1 = 0; ln1 < s; ln1++){
        ln2 = rand() % s;
        if (ln1 == ln2){
            continue;
        } else {
            SwapLineTable(t, ln1, ln2);
        }
    }
}

void SwapLineTable(Table* t, int ln1, int ln2){
    char bf[STR_SIZE];
    strcpy(bf, t->data[ln1]);
    ClearLine(t, ln1);
    strcpy(t->data[ln1], t->data[ln2]);
    ClearLine(t, ln2);
    strcpy(t->data[ln2], bf);
}

void DeleteTable(Table* t){
    free(t);
}

