#include "bytes_utils.h"

//typedef unsigned char *byte_pointer;
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

int int_shifts_are_arithmetic(){
	int x=~0;
	int shift_val = (sizeof(int) <<3) -1;
	int mask =  1 << shift_val;
	return !!((x>>1)&mask);

}


/**
 * if x==y return 1
 * else return 0
 * 
**/
int equals(int x,int y){
	return !(x^y);
}


unsigned srl(unsigned x,int k){
	unsigned xsra = (int)x >> k;
	int int_size = 8*sizeof(int);
	int right_shift_val = int_size-k;
	int mask = (1<<right_shift_val)-1;
	return xsra & mask;
}


int sra(int x,int k){
	int xsrl = (unsigned int)x >> k;
	int int_size = 8*sizeof(int);
	int right_shift_val = int_size-1;
	int mask = 1<<right_shift_val;
	int mask_val = !!(x&mask);
	int ret = xsrl;
	mask_val && (ret= xsrl|~((1<<(int_size-k))-1));
	return ret;
}

int any_odd_one(unsigned int x){
	int mask = 0xaaaaaaaa; 
	return !!(mask&x);
}

int odd_ones(unsigned int x){
	x ^= x>>16;
	x ^= x>>8;
	x ^= x>>4;
	x ^= x>>2;
	x ^= x>>1;
	return (x&0x1);
}


int leftmost_one(unsigned int x){
	x |= x>>16;
	x |= x>>8;
	x |= x>>4;
	x |= x>>2;
	x |= x>>1;
	return x^(x>>1);
}
