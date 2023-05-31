#include <iostream>

#include "data_structures/LinkedList/listNode.h"

int main() {
    // ListNode<int> *head = new ListNode<int>(10);
    // head -> setNext(new ListNode<int>(12));
    // head -> getNext() -> setNext(new ListNode<int>(14));
    // head -> getNext() -> getNext() -> setNext(new ListNode<int>(16));

    // for (auto i = head; i != NULL; i = i -> getNext()) {
    //     std::cout << i -> getData() << " ";
    // } std::cout << std::endl;

    std::cout << "---------------------------MENU---------------------------" << std::endl;
    std::cout << "1. Linked List" << std::endl;

    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cout << std::endl;

    switch (choice) {
    case 1: {
        int listCreationChoice;
        std::cout << "---------------------------LINKED LIST---------------------------" << std::endl;
        std::cout << "1. Create linked list with array." << std::endl
                  << "2. Create linked list element-wise." << std:: endl;
        std::cout << "Enter choice: ";
        std::cin >> listCreationChoice;

        switch (listCreationChoice) {
        case 1: {
            int sizeOfArray;
            std::cout << "Enter array size: ";
            std::cin >> sizeOfArray;

            int *arr = new int[sizeOfArray];

            for (int i = 0; i < sizeOfArray; i++) {
                std::cout << "Enter element " << i + 1 << ": ";
                std::cin >> arr[i];
            }

            ListNode<int> *head = createLinkedListFromArray<int>(arr, sizeOfArray);
            displayLinkedList<int>(head); std::cout << std::endl;
            recursiveDisplayLL<int>(head); std::cout << std::endl;

            break;
        }

        default:
            break;
        }

        break;
    }

    default:
        break;
    }
}