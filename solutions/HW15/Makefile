TARGET = hw15
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw15.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log


TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_REMOVED -DLINKEDLIST

hw15: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw15

testmemory: $(TARGET)
	$(VALGRIND) ./hw15 inputs/test1.txt

testall: test1 test2

test1: hw15
	./hw15 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
test2: hw15
	./hw15 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt
test3: hw15
	./hw15 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt
test4: hw15
	./hw15 inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt


.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
