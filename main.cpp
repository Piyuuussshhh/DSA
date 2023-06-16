#include <iostream>

#include "data_structures/LinkedList/listNode.h"
#include "utility_functions.h"

// class InvalidOptionException {};

int main() {
    const int choice = mainMenu();
    const int dataTypeChoice = chooseDataType();
    char repeat = 'y';
    do {
        switch (choice) {
            case 1: {
                linkedList(dataTypeChoice);
                break;
            }
            case 2: {
                doublyLinkedList(dataTypeChoice);
                break;
            }

            default: {
                // throw InvalidOptionException();
                std::cout << "[ERROR] Invalid option!" << std::endl;
                exit(0);
            }
        }

        std::cout << "Do you want to repeat (y/n): ";
        std::cin >> repeat;
        std::cout << "------------------------------------------------------" << std::endl;
    } while (repeat == 'y' || repeat == 'Y');

}