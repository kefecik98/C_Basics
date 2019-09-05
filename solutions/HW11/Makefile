TARGET = hw11
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw11.c bmpimage.c bmpfunc.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log


TESTFLAGS = -DTEST_MAIN -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_ADAPTIVETHRESHOLDING -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_WRITEFUNC -DTEST_BMPFREEFUNC

hw11: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw11

testmemory: $(TARGET)
	$(VALGRIND) ./hw11 exampleImages/RV2.bmp outputImages/outputRV2.bmp 3 2

testall: test1 test2 test3 test4

test1: hw11
	./hw11 exampleImages/CondProb.bmp outputImages/adaptiveCondProb.bmp 1 2
	diff expectedImages/expectedCondProb.bmp outputImages/adaptiveCondProb.bmp
test2: hw11
	./hw11 exampleImages/RV.bmp outputImages/adaptiveRV.bmp 5 2
	diff expectedImages/expectedRV.bmp outputImages/adaptiveRV.bmp
test3: hw11
	./hw11 exampleImages/RV2.bmp outputImages/adaptiveRV2.bmp 3 2
	diff expectedImages/expectedRV2.bmp outputImages/adaptiveRV2.bmp
test4: hw11
	./hw11 exampleImages/RV2Small.bmp outputImages/adaptiveRV2Small.bmp 11 2
	diff expectedImages/expectedRV2Small.bmp outputImages/adaptiveRV2Small.bmp

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
