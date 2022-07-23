CFLAGS=-std=c++11 -g

all: Lab6

Lab6: main.cpp LinkedList.h LinkedListInterface.h
	g++ $(CFLAGS) main.cpp -o Lab6