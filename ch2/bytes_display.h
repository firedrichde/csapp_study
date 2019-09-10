#ifndef __BYTES_DISPLAY_H
#define __BYTES_DISPALY_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int32_t show_int(long x,unsigned char* dst);

int is_little_endian();


#endif
