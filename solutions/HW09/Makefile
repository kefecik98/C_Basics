TARGET = shuf
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = main.c utility.c shuffle.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV -DTEST_RSHUF

shuf: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o shuf

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./shuf

test1: shuf
	./shuf 2 2 | sort > output1
	diff output1 expected/expected1

test2: shuf
	./shuf 4 3 | sort > output2
	diff output2 expected/expected2

test3: shuf
	./shuf 7 2 | sort > output3
	diff output3 expected/expected3

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
