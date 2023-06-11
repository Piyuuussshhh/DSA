#include <iostream>

#include "data_structures/LinkedList/listNode.h"
#include "functions.h"

class InvalidOptionException {};

int main() {
    const int choice = mainMenu();
    const int dataTypeChoice = chooseDataType();
    char repeat = 'y';
    do {
        switch (choice) {
            case 1: {
                switch (dataTypeChoice) {
                    case 1: {
                        const int &listChoice = listCreationMenu();
                        ListNode<int> *head = createLinkedList<int>(listChoice);
                        const int &operation = linkedListMenu();
                        linkedListOperations<int>(operation, head);
                        break;
                    }
                    case 2: {
                        const int &listChoice = listCreationMenu();
                        ListNode<float> *head = createLinkedList<float>(listChoice);
                        const int &operation = linkedListMenu();
                        linkedListOperations<float>(operation, head);
                        break;
                    }
                    case 3: {
                        const int &listChoice = listCreationMenu();
                        ListNode<double> *head = createLinkedList<double>(listChoice);
                        const int &operation = linkedListMenu();
                        linkedListOperations<double>(operation, head);
                        break;
                    }
                    case 4: {
                        const int &listChoice = listCreationMenu();
                        ListNode<std::string> *head = createLinkedList<std::string>(listChoice);
                        const int &operation = linkedListMenu();
                        linkedListOperations<std::string>(operation, head);
                        break;
                    }
                    default:
                        // throw InvalidOptionException();
                        std::cout << "[ERROR] Invalid option!" << std::endl;
                        break;
                }
            break;
            }

            default: {
                // throw InvalidOptionException();
                std::cout << "[ERROR] Invalid option!" << std::endl;
                break;
            }
        }

        std::cout << "Do you want to repeat (y/n): ";
        std::cin >> repeat;
        std::cout << "------------------------------------------------------" << std::endl;
    } while (repeat == 'y' || repeat == 'Y');

}