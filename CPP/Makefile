# C++ Data Structures Makefile

#  File: Makefile
#  Type: Makefile
#  Date: January 31, 2017
#
#  Description:
#  This makefile compiles the data structures project in C++.

CC=g++
CFLAGS=-Wall

.PHONY: clean refresh default

default: Test_Driver.exe

Test_Driver.exe: Test_Driver.cpp Linked_List.h Linked_List_Node.h
	$(CC) $(CFLAGS) Test_Driver.cpp -o Test_Driver.exe

#################################################################

clean:
	rm Test_Driver.exe

refresh:
	make clean
	make
