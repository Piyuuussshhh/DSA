#pragma once
#include <iostream>

#include "data_structures/LinkedList/listNode.h"

// ! Improve code readability with enums for cases, instead of numbers.
// ! Utitity functions only for linked list as of now, make them generic.

int chooseDataType() {
    int choice;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Choose data type for data structure: " << std::endl;
    std::cout << "1. int" << std::endl
              << "2. float" << std::endl
              << "3. double" << std::endl
              << "4. string" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    return choice;
}

int mainMenu() {
    std::cout << "---------------------------MENU---------------------------" << std::endl;
    std::cout << "1. Linked List" << std::endl;

    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    return choice;
}

int listCreationMenu() {
    int listCreationChoice;
    std::cout << "---------------------------LINKED LIST---------------------------" << std::endl;
    std::cout << "1. Create linked list with array." << std::endl
              << "2. Create linked list element-wise." << std:: endl;
    std::cout << "Enter choice: ";
    std::cin >> listCreationChoice;

    return listCreationChoice;
}

int linkedListSearchMenu() {
    std::cout << "1. Perform linear search." << std::endl;
    std::cout << "2. Perform optimised linear search." << std::endl;

    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    return choice;
}

template <class T>
ListNode<T>* createLinkedListManually() {
    int numOfElems;
    std::cout << "Enter number of elements: ";
    std::cin >> numOfElems;

    T element;
    std::cout << "Enter element 1: ";
    std::cin >> element;

    ListNode<T> *head = new ListNode<T>(element);
    for (int i = 1; i < numOfElems; i++) {
        T temp;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> temp;
        insert(head, temp);
    }

    return head;
}

template <class T>
ListNode<T>* createLinkedListByArray() {
    int sizeOfArray;
    std::cout << "Enter array size: ";
    std::cin >> sizeOfArray;

    T *arr = new T[sizeOfArray];

    for (int i = 0; i < sizeOfArray; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    ListNode<T> *head = createLinkedListFromArray<T>(arr, sizeOfArray);
    return head;
}

template <class T>
ListNode<T>* createLinkedList(const int choice) {
    switch (choice) {
    case 1: {
        return createLinkedListByArray<T>();
    }
    case 2: {
        return createLinkedListManually<T>();
    }

    default:
        // throw InvalidOptionException();
        std::cout << "[ERROR] Invalid option!" << std::endl;
        exit(0);
    }
}

template <class T>
void performSearch(ListNode<T>* head) {
    int searchChoice = linkedListSearchMenu();
    switch (searchChoice) {
    case 1: {
        T element;
        std::cout << "Enter element to be searched: ";
        std::cin >> element;

        head = searchLinkedListFor<T>(element, head);
        if (!head) {
            std::cout << "Element not found!" << std::endl;
            return;
        }
        break;
    }
    case 2: {
        T element;
        std::cout << "Enter element to be searched: ";
        std::cin >> element;

        head = optimisedSearch<T>(element, head);
        if (!head) {
            std::cout << "Element not found!" << std::endl;
            return;
        }

        displayLinkedList<T>(head);
        break;
    }
    default:
        // throw InvalidOptionException();
        std::cout << "[ERROR] Invalid option!" << std::endl;
        exit(0);
    }
}

int linkedListMenu() {
    std::cout << "---------------------------OPERATIONS ON THIS LINKED LIST---------------------------" << std::endl;
    std::cout << "1. Display linked list." << std::endl;
    std::cout << "2. Find total number of nodes." << std::endl;
    std::cout << "3. Find the sum of all elements. (preferably used with linked list of data types: int, float, double)" << std::endl;
    std::cout << "4. Search for an element." << std::endl;
    std::cout << "5. Insert an element" << std::endl;
    std::cout << "6. Sort linked list, and insert element in sorted order." << std::endl;
    std::cout << "7. Delete an element by index." << std::endl;
    std::cout << "8. Delete an element by value." << std::endl;
    std::cout << "9. Delete duplicates in a sorted linked list." << std::endl;

    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    return choice;
}

template <class T>
void linkedListOperations(const int &choice, ListNode<T>* head) {
    switch (choice) {
    case 1: {
        std::cout << "------------------------------------------------------" << std::endl;
        displayLinkedList<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 2: {
        std::cout << "------------------------------------------------------" << std::endl;
        int count = countNodes<T>(head);
        std::cout << "Total number of nodes: " << count << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 3: {
        std::cout << "------------------------------------------------------" << std::endl;
        T sum = sumOfData<T>(head);
        std::cout << "Sum of data: " << sum << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 4: {
        std::cout << "---------------------------SEARCH THE LINKED LIST---------------------------" << std::endl;
        performSearch<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 5: {
        std::cout << "------------------------------------------------------" << std::endl;
        T insertElement;
        std::cout << "Enter element to be inserted: ";
        std::cin >> insertElement;

        char toInsertInBetween;
        std::cout << "Do you want to insert the element in between the linked list (y/n): ";
        std::cin >> toInsertInBetween;

        if (toInsertInBetween == 'y') {
            int index;
            std::cout << "Enter the index at which to insert the entered element: ";
            std::cin >> index;

            insert<T>(head, insertElement, index);
        } else if (toInsertInBetween = 'n') {
            insert<T>(head, insertElement);
        }
        std::cout << "------------------------------------------------------" << std::endl;
        displayLinkedList<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 6: {
        sort<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;
        displayLinkedList<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;

        char toInsertElement;
        std::cout << "Do you want to insert an element into the sorted linked list (y/n): ";
        std::cin >> toInsertElement;

        if (toInsertElement == 'y' || toInsertElement == 'Y') {
            T insertElement;
            std::cout << "Enter element to be inserted: ";
            std::cin >> insertElement;

            insertInSortedLinkedList<T>(insertElement, head);
            displayLinkedList<T>(head);
            std::cout << "------------------------------------------------------" << std::endl;
        }
        break;
    }
    case 7: {
        std::cout << "------------------------------------------------------" << std::endl;
        int index;
        std::cout << "Enter index of element to delete: ";
        std::cin >> index;

        deleteByIndex<T>(head, index);
        displayLinkedList<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 8: {
        std::cout << "------------------------------------------------------" << std::endl;
        T element;
        std::cout << "Enter element to delete: ";
        std::cin >> element;

        deleteByValue<T>(head, element);
        displayLinkedList<T>(head);
        std::cout << "------------------------------------------------------" << std::endl;
        break;
    }
    case 9: {
        if (!isLinkedListSorted(head)) {
            std::cout << "[ERROR] Linked List is not sorted!" << std::endl;
            return;
        }
        deleteDuplicateElementsInSortedLL<T>(head);
        std::cout << "Deleted duplicate elements! The new linked list is: ";
        displayLinkedList<T>(head);
        break;
    }


    default:
        // throw InvalidOptionException();
        std::cout << "[ERROR] Invalid option!" << std::endl;
        exit(0);
    }
}

template <class T>
void performLinkedListOperations() {
    const int &listChoice = listCreationMenu();
    ListNode<int> *head = createLinkedList<int>(listChoice);
    const int &operation = linkedListMenu();
    linkedListOperations<int>(operation, head);
    delete head;
}

void linkedList(const int &dataTypeChoice) {
    switch (dataTypeChoice) {
        case 1: {
            performLinkedListOperations<int>();
            break;
        }
        case 2: {
            performLinkedListOperations<float>();
            break;
        }
        case 3: {
            performLinkedListOperations<double>();
            break;
        }
        case 4: {
            performLinkedListOperations<std::string>();
            break;
        }
        default: {
            // throw InvalidOptionException();
            std::cout << "[ERROR] Invalid option!" << std::endl;
            exit(0);
        }
    }
}