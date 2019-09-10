#include <stdio.h>
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
	SUITE_ADD_TEST(suite,Test_little_endian);
	return suite;
}

void Run_All_Tests(){
	CuSuite* suite=CuSuiteNew();
	CuString* output=CuStringNew();
	CuSuiteAddSuite(suite,Little_endian_getsuite());
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
	int number=2;
	F(number);
	Run_All_Tests();
}
