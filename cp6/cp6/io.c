#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "io.h"

#define STR_SIZE 50
/* Student IO */
int student_read_txt(PC *s, FILE *in)
{
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", s->processors_count);
    fscanf(in, "%s", s->processors_type);
    fscanf(in, "%s", s->volume);
    fscanf(in, "%s", s->gpu_type);
    fscanf(in, "%s", s->gpu_volume);
    fscanf(in, "%s", s->type);
    fscanf(in, "%s", s->venture_count);
    fscanf(in, "%s", s->venture_capacity);
    fscanf(in, "%s", s->integrated_controller_count);
    fscanf(in, "%s", s->peripheral_device_count);
    fscanf(in, "%s", s->os);

    return !feof(in);
}

int student_read_bin(PC *s, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->processors_count, sizeof(char), STR_SIZE, in);
    fread(s->processors_type, sizeof(char), STR_SIZE, in);
    fread(s->volume, sizeof(char), STR_SIZE, in);
    fread(s->gpu_type, sizeof(char), STR_SIZE, in);
    fread(s->gpu_volume, sizeof(char), STR_SIZE, in);
    fread(s->type, sizeof(char), STR_SIZE, in);
    fread(s->venture_count, sizeof(char), STR_SIZE, in);
    fread(s->venture_capacity, sizeof(char), STR_SIZE, in);
    fread(s->integrated_controller_count, sizeof(char), STR_SIZE, in);
    fread(s->peripheral_device_count, sizeof(char), STR_SIZE, in);
    fread(s->os, sizeof(char), STR_SIZE, in);

    return !feof(in);
}


void student_write_bin(PC *s, FILE *out)
{

    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->processors_count, sizeof(char), STR_SIZE, out);
    fwrite(s->processors_type, sizeof(char), STR_SIZE, out);
    fwrite(s->volume, sizeof(char), STR_SIZE, out);
    fwrite(s->gpu_type, sizeof(char), STR_SIZE, out);
    fwrite(s->gpu_volume, sizeof(char), STR_SIZE, out);
    fwrite(s->type, sizeof(char), STR_SIZE, out);
    fwrite(s->venture_count, sizeof(char), STR_SIZE, out);
    fwrite(s->venture_capacity, sizeof(char), STR_SIZE, out);
    fwrite(s->integrated_controller_count, sizeof(char), STR_SIZE, out);
    fwrite(s->peripheral_device_count, sizeof(char), STR_SIZE, out);
    fwrite(s->os, sizeof(char), STR_SIZE, out);
}


void student_print(PC *s)
{
    
    printf("%10s", s->surname);
    printf("%12s", s->processors_count);
    printf("%14s", s->processors_type);
    printf("%8s", s->volume);
    printf("%12s", s->gpu_type);
    printf("%10s", s->gpu_volume);
    printf("%8s", s->type);
    printf("%14s", s->venture_count);
    printf("%18s", s->venture_capacity);
    printf("%18s", s->integrated_controller_count);
    printf("%18s", s->peripheral_device_count);
    printf("%16s", s->os);
    printf("\n");
}