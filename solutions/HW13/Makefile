TARGET = hw13
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw13.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log


TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_DIV -DLINKEDLIST

hw11: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw13

testmemory: $(TARGET)
	$(VALGRIND) ./hw13 inputs/test1.txt

testall: test1 test2 test3 test4

test1: hw13
	./hw13 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
test2: hw13
	./hw13 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt
test3: hw13
	./hw13 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt
test4: hw13
	./hw13 inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt


.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
