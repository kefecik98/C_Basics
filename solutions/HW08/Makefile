# Makefile

TARGET = shuf
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

#declare test flags, for example: TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV
TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV

SRCS =  main.c utility.c shuffle.c

OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --verbose --log-file
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

#val:
#	$(VALGRIND)=./logfile ./shuf

testmemory: $(TARGET)
	$(VAL) ./shuf 4

testall: test1 test2 test3

test1: shuf
	./shuf 4 | sort > output1.txt
	diff output1.txt expected/expected1.txt

test2: shuf
	./shuf 8 | sort > output2.txt
	diff output2.txt expected/expected2.txt

test3: shuf
	./shuf 11 | sort > output3.txt
	diff output3.txt expected/expected3.txt

clean:
	rm -f $(OBJS) $(TARGET)
