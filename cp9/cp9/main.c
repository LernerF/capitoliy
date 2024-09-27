#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Добавлено
#include <time.h>

#include "table.h"

int main(void){
    printf("Запуск программы...\n");
    char stat = 'e';
    bool flag_is_the_table_read = false;
    Table* tab = (Table*)malloc(sizeof(Table));
    CreateTable(tab);
    
    while ((stat != 'Q') && (stat != 'q')) {
        printf("\nN для считывания новой ASCII-графики,\nK для поиска по ключу,\nS для сортировки таблицы,\nR для реверса таблицы,\nM для перемешивания,\nC для подсчёта количества строк в ASCII-графике,\nP для печати ASCII-графики,\nQ для выхода.\n");
        scanf(" %c", &stat);
        
        switch(stat){
            
            case 'N':
            case 'n':
            {
                char name_file[STR_SIZE];
                ClearTable(tab);
                flag_is_the_table_read = false;
                printf("Введите название файла с ASCII-графикой: ");
                scanf("%s", &name_file[0]);
                FILE* in = fopen(name_file, "r");
                if (!in){
                    printf("I/O ERROR: ошибка открытия файла.\n");
                    break;
                }
                if (!ReadTable(in, tab)){
                    printf("I/O ERROR: ошибка чтения файла.\n");
                    fclose(in);
                    break;
                }
                flag_is_the_table_read = true;
                fclose(in);
            }
            break;
            
            case 'K':
            case 'k':
            {
                if (!flag_is_the_table_read){
                    printf("Не указан файл с ASCII-графикой.\n");
                    break;
                }
                tab = SortTable(tab);
                int64_t key;
                printf("Введите ключ: ");
                scanf("%I64d", &key); // Изменено
                int i = SearchByKey(tab, key);
                if (i == -1){
                    printf("Ключ отсутствует в таблице.\n");
                } else {
                    int index = 0;
                    while (isspace(tab->data[i][index])){ index++; }
                    while (isdigit(tab->data[i][index])){ index++; }
                    printf("Найденная строка: %s", &(tab->data[i][index]));
                }
            }
            break;
            
            case 'S':
            case 's':
            {
                if (!flag_is_the_table_read){
                    printf("Не указан файл с ASCII-графикой.\n");
                    break;
                }
                tab = SortTable(tab);
                PrintTable(tab);
            }
            break;
            
            case 'R':
            case 'r':
            {
                if (!flag_is_the_table_read){
                    printf("Не указан файл с ASCII-графикой.\n");
                    break;
                }
                ReverseTable(tab);
                PrintTable(tab);
                
            }
            break;
            
            case 'M':
            case 'm':
            {
                if (!flag_is_the_table_read){
                    printf("Не указан файл с ASCII-графикой.\n");
                    break;
                }
                MixRandom(tab);
                PrintTable(tab);
            }
            break;
            
            case 'C':
            case 'c':
            {
                if (!flag_is_the_table_read){
                    printf("Не указан файл с ASCII-графикой.\n");
                    break;
                }
                printf("В данном файле с ASCII-графикой %d строк.\n", SizeTable(tab));
            }
            break;
            
            case 'P':
            case 'p':
            {
                if (!flag_is_the_table_read){
                    printf("Не указан файл с ASCII-графикой.\n");
                    break;
                }
                PrintTable(tab);
            }
            break;
        }
    }
    
    DeleteTable(tab);
    printf("\nДо свидания!\n");
    
    return 0;
}