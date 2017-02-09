# C++ Data Structures Makefile

#  File: Makefile
#  Type: Makefile
#  Date: January 31, 2017
#
#  Description:
#  This makefile compiles the data structures project in C++.

CC=g++
CFLAGS=-Wall
DIR_SRC=src/
DIR_BIN=bin/

.PHONY: clean refresh default

default: $(DIR_BIN)Test_Driver.exe

$(DIR_BIN)Test_Driver.exe: $(DIR_SRC)Test_Driver.cpp $(DIR_SRC)Linked_List.h $(DIR_SRC)Linked_List_Node.h
	$(CC) $(CFLAGS) $(DIR_SRC)Test_Driver.cpp -o $(DIR_BIN)Test_Driver.exe

#################################################################

clean:
	rm $(DIR_BIN)Test_Driver.exe

refresh:
	make clean
	make
