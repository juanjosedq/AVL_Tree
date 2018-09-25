#Compiler
CC = g++

#Compiler flags
CFLAGS = -Wall -g -std=c++14 --pedantic

#Include directory
IDIR = -I ../include/data_structures

#SRC directory
SRCDIR = ../src/

#SRC targets
SRC = avl_tree

TESTDIR = ../test/
TEST1 = main_nodo_10
TEST2 = main_nodo_100
TEST3 = main_nodo_1000
TEST4 = main_nodo_5000
TEST5 = main_nodo_10000

UNIT1 = positive_unit_test1
UNIT2 = positive_unit_test2
UNIT3 = negative_unit_test1

all:
	$(CC) $(CFLAGS) $(IDIR) -c $(SRCDIR)$(SRC).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(TEST1).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(TEST2).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(TEST3).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(TEST4).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(TEST5).cpp
	$(CC) $(CFLAGS) $(IDIR) -o $(TEST1).out $(SRC).o $(TEST1).o
	$(CC) $(CFLAGS) $(IDIR) -o $(TEST2).out $(SRC).o $(TEST2).o
	$(CC) $(CFLAGS) $(IDIR) -o $(TEST3).out $(SRC).o $(TEST3).o
	$(CC) $(CFLAGS) $(IDIR) -o $(TEST4).out $(SRC).o $(TEST4).o
	$(CC) $(CFLAGS) $(IDIR) -o $(TEST5).out $(SRC).o $(TEST5).o

run:
	./$(TEST1).out
	./$(TEST2).out
	./$(TEST3).out
	./$(TEST4).out
	./$(TEST5).out

run_debug:
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST2).out

unittest:
	$(CC) $(CFLAGS) $(IDIR) -c $(SRCDIR)$(SRC).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(UNIT1).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(UNIT2).cpp
	$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$(UNIT3).cpp
	$(CC) $(CFLAGS) $(IDIR) -o $(UNIT1).out $(SRC).o $(UNIT1).o
	$(CC) $(CFLAGS) $(IDIR) -o $(UNIT2).out $(SRC).o $(UNIT2).o
	$(CC) $(CFLAGS) $(IDIR) -o $(UNIT3).out $(SRC).o $(UNIT3).o

run_unittest:
	./$(UNIT1).out
	./$(UNIT2).out
	./$(UNIT3).out

clean:
	rm -f *.o *out
