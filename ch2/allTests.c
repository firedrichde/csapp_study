#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CuTest.h"
#include "bytes_utils.h"


void Test_little_endian(CuTest* ct){
	int expected_value = 1;
	int actual_value = is_little_endian();
	CuAssertIntEquals(ct,expected_value,actual_value);	
}

CuSuite *Little_endian_getsuite(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite,Test_little_endian);
	return suite;
}

void Test_equals(CuTest* ct){
	int x=10;
	int y=20;
	int expected_value = (x==y);
	int actual_value = equals(x,y);
	CuAssertIntEquals(ct,expected_value,actual_value);
}


CuSuite *Suite_equals(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite,Test_equals);
	return suite;
}


void Test_int_shifts_are_arithmetic(CuTest* ct){
	int expected_value = 1;
	int actual_value = int_shifts_are_arithmetic();
	CuAssertIntEquals(ct,expected_value,actual_value);
}


CuSuite *Suite_int_shifts_are_arithmetic(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite,Test_int_shifts_are_arithmetic);
	return suite;
}


void Test_srl(CuTest* ct){
	unsigned int x=~0;
	int k=4;
	char msg[128];
	memset(msg,'\0',128);
	unsigned int expected_value = x>>k;
	unsigned int actual_value = srl(x,k);
	sprintf(msg,"val=%x,%x",expected_value,actual_value);
	CuAssertIntEquals_Msg(ct,msg,expected_value,actual_value);
}


void Test_sra(CuTest* ct){
	int x=~0;
	int k=4;
	char msg[128];
	memset(msg,'\0',128);
	int expected_value = (x>>k);
	int actual_value = sra(x,k);
	sprintf(msg,"val=%x,%x",expected_value,actual_value);
	CuAssertIntEquals_Msg(ct,msg,expected_value,actual_value);
}


void Test_odd_ones(CuTest* ct){
	unsigned int x=0xfe;
	int expected_value = 1;
	int actual_value = odd_ones(x);
	CuAssertIntEquals(ct,expected_value,actual_value);
}

void Test_leftmost_one(CuTest* ct){
	unsigned int x = 0xffff;
	int expected_value = 0x8000;
	int actual_value = leftmost_one(x);
	CuAssertIntEquals(ct,expected_value,actual_value);
}
CuSuite *Suite_bit_operations(){
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite,Test_srl);
	SUITE_ADD_TEST(suite,Test_sra);
	SUITE_ADD_TEST(suite,Test_odd_ones);
	SUITE_ADD_TEST(suite,Test_leftmost_one);
	return suite;
}

void Run_All_Tests(){
	CuSuite* suite=CuSuiteNew();
	CuString* output=CuStringNew();
	CuSuiteAddSuite(suite,Little_endian_getsuite());
	CuSuiteAddSuite(suite,Suite_equals());
	CuSuiteAddSuite(suite,Suite_int_shifts_are_arithmetic());
	CuSuiteAddSuite(suite,Suite_bit_operations());
	CuSuiteRun(suite);
	CuSuiteSummary(suite,output);
	CuSuiteDetails(suite,output);
	printf("%s\n",output->buffer);
}

#define F(x) f(#x,x)

void f(const char* name,int x){
	printf("%s=%d\n",name,x);
}

int main(){
	int x= 1;
	int word_size = sizeof(&x)<<3;
	F(word_size);
	Run_All_Tests();
}
