TARGET = hw12
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw12.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log


TESTFLAGS = -DLINKEDLIST -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_JOSEPHUS

hw11: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw12

testmemory: $(TARGET)
	$(VALGRIND) ./hw12 10 3 1

testall: test1 test2 test3 test4 test5 test6

test1: hw12
	./hw12 10 3 1 > expected1.txt
	diff expected/expected1.txt expected1.txt
test2: hw12
	./hw12 10 4 2 > expected2.txt
	diff expected/expected2.txt expected2.txt
test3: hw12
	./hw12 8 5 3 > expected3.txt
	diff expected/expected3.txt expected3.txt
test4: hw12
	./hw12 8 9 1 > expected4.txt
	diff expected/expected4.txt expected4.txt
test5: hw12
	./hw12 41 3 1 > expected5.txt
	diff expected/expected5.txt expected5.txt
test6: hw12
	./hw12 100 3 20 > expected6.txt
	diff expected/expected6.txt expected6.txt


.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
