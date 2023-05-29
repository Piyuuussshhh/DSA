all: final

final: listNode.o main.o
	@echo "Linking and producing build file..."
	g++ main.o listNode.o -o final

main.o: main.cpp data_structures/LinkedList/listNode.h
	@echo "Compiling main..."
	g++ -c main.cpp

listNode.o: data_structures/LinkedList/listNode.cpp data_structures/LinkedList/listNode.h
	@echo "Compiling listNode..."
	g++ -c data_structures\LinkedList\listNode.cpp

clean:
	@echo "Cleaning build files..."
	del main.o
	del listNode.o
	del final.exe