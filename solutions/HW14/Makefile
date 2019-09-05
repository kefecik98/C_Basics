TARGET = hw14
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw14.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log


TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_MERGE -DTEST_SORT -DLINKEDLIST

hw14: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw14

testmemory: $(TARGET)
	$(VALGRIND) ./hw14 inputs/test1.txt

testall: test1 test2

test1: hw14
	./hw14 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
test2: hw14
	./hw14 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt


.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
