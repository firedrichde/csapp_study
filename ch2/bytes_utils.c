#include "bytes_utils.h"

typedef unsigned char *byte_pointer;
int32_t show_bytes(byte_pointer start,size_t len,unsigned char* dst){
	if(dst==NULL|| (dst+len-1)==NULL)
		return -1;
	size_t i;
	for(i=0;i<len;i++){
		*(dst+i) = *(start+i);
	}
	return 0;

}

int32_t show_int(long x,unsigned char* dst){
	return show_bytes((byte_pointer)(&x),sizeof(long),dst);
}

int is_little_endian(){
	int x=1;
	byte_pointer p = (byte_pointer)&x;
	if(0 == (x & (*p)))
		return 0;
	else
		return 1;
}


void print_bytes(byte_pointer x,size_t len){
	if(NULL==x)
		return ;
	for(size_t i=0;i<len;i++){
		printf("%.2x ",*(x+i));
	}
}
