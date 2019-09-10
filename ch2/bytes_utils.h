#ifndef __BYTES_UTILS_H
#define __BYTES_UTILS_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char *byte_pointer;

int32_t show_int(long x,unsigned char* dst);

int is_little_endian();

void print_bytes(byte_pointer x,size_t len);


#endif
