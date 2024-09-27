#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "io.c"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage:\n\t./print DB_FILE\n");
        exit(0);
    }
    FILE *in = fopen(argv[1], "r");

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(0);
    }

    PC s;
    printf("%5s", "ID");
    printf("%10s", "Surname");
    printf("%12s", "Proc_count");
    printf("%14s", "Proc_type");
    printf("%8s", "Volume");
    printf("%12s", "GPU_type");
    printf("%10s", "GPU_vol");
    printf("%8s", "Type");
    printf("%14s", "Venture_count");
    printf("%18s", "Venture_capacity");
    printf("%18s", "Integrated_count");
    printf("%18s", "Peripheral_count");
    printf("%16s\n", "OS");
    for (int i = 0; i < 4; ++i) {
         printf("------------------------------------------");
    }
    printf("\n");
    int i = 1;
    while (student_read_bin(&s, in)) {
        printf("%5d", i);
        student_print(&s);
        i++;
    }

    fclose(in);

    return 0;
}
