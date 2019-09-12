#ifndef __BYTES_UTILS_H
#define __BYTES_UTILS_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char *byte_pointer;

int32_t show_int(long x,unsigned char* dst);

int is_little_endian();

void print_bytes(byte_pointer x,size_t len);

int equals(int x,int y);

int int_shifts_are_arithmetic();

unsigned int srl(unsigned x,int k);

int sra(int x,int k);

int any_odd_one(unsigned int x);

int odd_ones(unsigned int x);

int leftmost_one(unsigned int x);
#endif
