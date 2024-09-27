#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_RECORDS 10

typedef struct {
    char owner[50];
    int cores;
    char cpu_type[20];
    int frequency;
    char gpu_type[20];
    int gpu_memory;
    char storage_type[20];
    int storage_capacity;
    int ram;
    int usb_ports;
    int other_ports;
    char os[50];
} Computer;

const char* cpu_types[] = {"single-core", "dual-core", "quad-core", "hexa-core", "octa-core"};
const char* gpu_types[] = {"integrated", "external", "AGP", "PCI"};
const char* storage_types[] = {"SATA", "ATA", "SCSI", "IDE"};
const char* os_types[] = {"Windows10", "Ubuntu20.04", "MacOS", "Fedora34", "Windows11", "LinuxMint", "CentOS8", "Debian10", "FreeBSD", "NULL"};

int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_owner_name(char* name) {
    const char* surnames[] = {"Ivanov", "Smith", "Johnson", "Garcia", "Chen", "Kim", "Martinez", "Brown", "Lee", "Nguyen"};
    int index = random_range(0, 9);
    strcpy(name, surnames[index]);
}

Computer generate_computer() {
    Computer comp;

    generate_owner_name(comp.owner);
    comp.cores = random_range(1, 8);
    strcpy(comp.cpu_type, cpu_types[random_range(0, 4)]);
    comp.frequency = random_range(90, 250);
    strcpy(comp.gpu_type, comp.cores % 2 ? gpu_types[random_range(0, 3)] : "NULL");
    comp.gpu_memory = comp.cores % 2 ? random_range(4, 64) : 0;
    strcpy(comp.storage_type, storage_types[random_range(0, 3)]);
    comp.storage_capacity = comp.cores % 3 ? random_range(128, 1024) : 0;
    comp.ram = random_range(2, 8) * 256;
    comp.usb_ports = random_range(2, 6);
    comp.other_ports = comp.cores % 2 ? random_range(3, 7) : 0;
    strcpy(comp.os, os_types[random_range(0, 9)]);

    return comp;
}

void write_computer(FILE* file, Computer* comp) {
    fprintf(file, "%s %d %s %d %s %d %s %d %d %d %d %s\n",
        comp->owner,
        comp->cores,
        comp->cpu_type,
        comp->frequency,
        comp->gpu_type,
        comp->gpu_memory,
        comp->storage_type,
        comp->storage_capacity,
        comp->ram,
        comp->usb_ports,
        comp->other_ports,
        comp->os
    );
}

int main() {
    srand((unsigned int)time(NULL));
    FILE* out = fopen("computers.txt", "w");
    if (!out) {
        printf("Ошибка при открытии файла для записи.\n");
        return 1;
    }

    int num_records = MAX_RECORDS;
    for (int i = 0; i < num_records; i++) {
        Computer comp = generate_computer();
        write_computer(out, &comp);
    }

    fclose(out);
    printf("Файл успешно создан.\n");
    return 0;
}