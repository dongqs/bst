all: run
	./run

run: run.o bst.o
	g++ -o run run.o bst.o

run.o: run.cpp
	g++ -c -o run.o run.cpp

bst.o: bst.h bst.cpp
	g++ -c -o bst.o bst.cpp


