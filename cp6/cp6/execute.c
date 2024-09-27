#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Функция для чтения информации о компьютере из файла. Возвращает 0 при достижении конца файла.
int read_pc(FILE* file, PC* pc) {
    return fscanf(file, "%49s %9s %19s %9s %19s %9s %9s %9s %9s %9s %9s %19s",
                  pc->surname, pc->processors_count, pc->processors_type, pc->volume,
                  pc->gpu_type, pc->gpu_volume, pc->type, pc->venture_count,
                  pc->venture_capacity, pc->integrated_controller_count,
                  pc->peripheral_device_count, pc->os) == 12;
}

// Функция для печати информации о серверах и рабочих станциях
void print_pc_info(const PC* pc) {
    if (strcmp(pc->type, "Server") == 0 || strcmp(pc->type, "Workstation") == 0) {
        printf("Surname: %s\n", pc->surname);
        printf("Processors Count: %s\n", pc->processors_count);
        printf("Processors Type: %s\n", pc->processors_type);
        printf("Volume: %s\n", pc->volume);
        printf("GPU Type: %s\n", pc->gpu_type);
        printf("GPU Volume: %s\n", pc->gpu_volume);
        printf("Type: %s\n", pc->type);
        printf("Venture Count: %s\n", pc->venture_count);
        printf("Venture Capacity: %s\n", pc->venture_capacity);
        printf("Integrated Controller Count: %s\n", pc->integrated_controller_count);
        printf("Peripheral Device Count: %s\n", pc->peripheral_device_count);
        printf("OS: %s\n\n", pc->os);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    PC pc;
    while (read_pc(file, &pc)) {
        print_pc_info(&pc);
    }

    fclose(file);
    return EXIT_SUCCESS;
}