
#ifndef _IO_H_
#define _IO_H_

#include "student.h"
#include <stdio.h>

/* Student IO */
int  student_read_txt(PC *s, FILE *in);
int  student_read_bin(PC *s, FILE *in);
void student_write_bin(PC *s, FILE *out);
void student_print(PC *s);

#endif
