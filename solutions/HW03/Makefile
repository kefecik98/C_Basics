# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_JOSEPHUS

SRCS = main.c josephus.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o main

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12

test1: main
	./main 6 3 > output1
	diff output1 expected1

test2: main
	./main 6 4 > output2
	diff output2 expected2

test3: main
	./main 25 7 > output3
	diff output3 expected3

test4: main
	./main 6 2 > output4
	diff output4 expected4

test5: main
	./main 6 5 > output5
	diff output5 expected5

test6: main
	./main 6 6 > output6
	diff -w output6 expected6

test7: main
	./main 6 7 > output7
	diff output7 expected7

test8: main
	./main 6 8 > output8
	diff output8 expected8

test9: main
	./main 5 4 > output9
	diff output9 expected9

test10: main
	./main 5 5 > output10
	diff output10 expected10

test11: main
	./main 5 6 > output11
	diff output11 expected11

test12: main
	./main 5 7 > output12
	diff output12 expected12




clean: # remove all machine generated files
	rm -f main *.o output?


