TARGET = hw10
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw10.c bmpimage.c bmpfunc.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC

hw10: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw10

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw10

testall: test1 test2 test3 test4

test1: hw10
	./hw10 exampleImages/CondProb.bmp outputImages/CondProbGray.bmp
	diff expectedImages/expectedCondProb.bmp outputImages/CondProbGray.bmp
test2: hw10
	./hw10 exampleImages/RV.bmp outputImages/RVGray.bmp
	diff expectedImages/expectedRV.bmp outputImages/RVGray.bmp
test3: hw10
	./hw10 exampleImages/RV2.bmp outputImages/RV2Gray.bmp
	diff expectedImages/expectedRV2.bmp outputImages/RV2Gray.bmp
test4: hw10
	./hw10 exampleImages/RV2Small.bmp outputImages/RV2SmallGray.bmp
	diff expectedImages/expectedRV2Small.bmp outputImages/RV2SmallGray.bmp

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
