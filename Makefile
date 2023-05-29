all: final

final: main.o
	@echo "Linking and producing build file..."
	g++ main.o -o final

main.o: main.cpp data_structures/LinkedList/listNode.h
	@echo "Compiling main..."
	g++ -c main.cpp

clean:
	@echo "Cleaning build files..."
	del main.o
	del final.exe