CC=gcc
CFLAGS=-g -Wall
CFLAGSm32=-g -m32 -Wall
CuTestLib = CuTest
CuTest32Lib = CuTestm32

all:allTests allTests_m32

allTests:allTests.o bytes_utils.o
	$(CC) -o allTests allTests.o bytes_utils.o -L. -l$(CuTestLib)

allTests.o:allTests.c
	$(CC) $(CFLAGS) -c allTests.c

bytes_utils.o:bytes_utils.c
	$(CC) $(CFLAGS) -c bytes_utils.c


allTests_m32:allTests_m32.o bytes_utils_m32.o
	$(CC) $(CFLAGSm32) -o allTests_m32 allTests_m32.o bytes_utils_m32.o -L. -l$(CuTest32Lib)

allTests_m32.o:allTests.c
	$(CC) $(CFLAGSm32) -c allTests.c -o allTests_m32.o

bytes_utils_m32.o:bytes_utils.c
	$(CC) $(CFLAGSm32) -c bytes_utils.c -o bytes_utils_m32.o

.PHONY: clean
clean:
	-rm allTests allTests.o bytes_utils.o \
		allTests_m32 allTests_m32.o bytes_utils_m32.o


	
