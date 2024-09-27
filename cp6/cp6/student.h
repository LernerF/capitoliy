#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char surname[50];
    char processors_count[10];
    char processors_type[20];
    char volume[10];
    char gpu_type[20];
    char gpu_volume[10];
    char type[10];
    char venture_count[10];
    char venture_capacity[10];
    char integrated_controller_count[10];
    char peripheral_device_count[10];
    char os[20];
} PC;

#endif // STUDENT_H