TARGET = hw18
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw18.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file=valgrind.log


TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_DIST -DTEST_MIN

hw18: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o hw18

testmemory: $(TARGET)
	$(VALGRIND) ./hw18 inputs/test1.txt

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

test1: hw18
	./hw18 inputs/test1.txt > output1.txt
	diff -i -w output1.txt expected/expected1.txt
test2: hw18
	./hw18 inputs/test2.txt > output2.txt
	diff -i -w output2.txt expected/expected2.txt
test3: hw18
	./hw18 inputs/test3.txt > output3.txt
	diff -i -w output3.txt expected/expected3.txt
test4: hw18
	./hw18 inputs/test4.txt > output4.txt
	diff -i -w output4.txt expected/expected4.txt
test5: hw18
	./hw18 inputs/test5.txt > output5.txt
	diff -i -w output5.txt expected/expected5.txt
test6: hw18
	./hw18 inputs/test6.txt > output6.txt
	diff -i -w output6.txt expected/expected6.txt
test7: hw18
	./hw18 inputs/test7.txt > output7.txt
	diff -i -w output7.txt expected/expected7.txt
test8: hw18
	./hw18 inputs/test8.txt > output8.txt
	diff -i -w output8.txt expected/expected8.txt
test9: hw18
	./hw18 inputs/test9.txt > output9.txt
	diff -i -w output9.txt expected/expected9.txt
test10: hw18
	./hw18 inputs/test10.txt > output10.txt
	diff -i -w output10.txt expected/expected10.txt

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
