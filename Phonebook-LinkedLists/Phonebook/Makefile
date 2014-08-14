all: Main

Main: main.o
	g++-4.7 -std=c++11 main.o -o Main

main.o: main.cpp TemplateDoublyLinkedList.h Record.h
	g++-4.7 -std=c++11 -c main.cpp
clean:
	rm *.o Main
