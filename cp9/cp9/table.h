#ifndef _TABLE_H_
#define _TABLE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define STR_SIZE 256
#define MAX_THREADS 2

typedef struct {
    char data[50][STR_SIZE];
    int size;
} Table;

void CreateTable(Table* t);
bool ReadTable(FILE* in, Table* t);
int SizeTable(Table* t);
void PrintLine(void);
void PrintTable(Table* t);
int SearchByKey(Table* t, const char* key);
Table* Copy(Table *t);
void Merge(Table* t1, Table* t2);
Table* SortTable(Table* t);
void ReverseTable(Table* t);
void ClearTable(Table*t);
void ClearLine(Table* t, int i);
void MixRandom(Table* t);
void SwapLineTable(Table* t, int ln1, int ln2);
void DeleteTable(Table* t);

#endif
