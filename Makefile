Calendar: main.o DoubleLinkedList.o Node.o ReadWrite.o
	g++ -std=c++11 -g -Wall main.o DoubleLinkedList.o Node.o ReadWrite.o -o Calendar

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DoubleLinkedList.o: DoubleLinkedList.h DoubleLinkedList.cpp
	g++ -std=c++11 -g -Wall -c DoubleLinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

ReadWrite.o: ReadWrite.h ReadWrite.cpp
	g++ -std=c++11 -g -Wall -c ReadWrite.cpp

clean:
	rm *.o Calendar
	echo Clean done
