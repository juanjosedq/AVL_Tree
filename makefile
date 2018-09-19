#Compiler
CC = g++

#Compiler flags
CFLAGS = -Wall -g -std=c++14

#Include directory
IDIR = -I include/avl_tree.hpp

#SRC directory
SRCDIR = src/

#SRC targets
SRC = avl_tree

$(SRC):
	$(CC) $(CFLAGS) -c $(SRCDIR)$@.cpp

clean:
	rm *.o *out
