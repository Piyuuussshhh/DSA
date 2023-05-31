#pragma once
#include <iostream>
#include <limits>

// * Declaration
template <class T = int>
class ListNode {
private:
    T data;
    ListNode* next = NULL;
public:
    ListNode(T d);
    ~ListNode();
    T getData();
    ListNode* getNext();
    void setNext(ListNode *node);
};

// * Implementation

template <class T>
ListNode<T>::ListNode(T d) : data(d), next(NULL) {}

template <class T>
ListNode<T>::~ListNode() {}

template <class T>
T ListNode<T>::getData() {
    return this -> data;
}

template <class T>
ListNode<T>* ListNode<T>::getNext() {
    return this -> next;
}

template <class T>
void ListNode<T>::setNext(ListNode *node) {
    this -> next = node;
}

// * Linked List Functions

// Prints a linked list iteratively.                           Time Complexity: O(n), Space Complexity: O(1).
template <class T>
void displayLinkedList(ListNode<T> *head) {
    ListNode<T> *temp = head;
    while (temp != nullptr) {
        std::cout << temp -> getData() << " ";
        temp = temp -> getNext();
    }
}

// Prints a linked list recursively.                           Time Complexity: O(n), Space Complexity: -
template <class T>
void recursiveDisplayLL(ListNode<T> *node) {
    std::cout << node -> getData() << " ";
    if (!node -> getNext()) {
        return;
    }
    recursiveDisplayLL(node -> getNext());
}

// Prints a linked list in reverse recursively.                Time Complexity: O(n), Space Complexity: -
template <class T>
void recursiveReverseDisplayLL(ListNode<T> *node) {
    if (!node) {
        return;
    }
    recursiveDisplayLL(node -> getNext());
    std::cout << node -> getData() << " ";
}

// Creates a linked list from an array of elements.            Time Complexity: O(n), Space Complexity: O(n).
template <class T>
ListNode<T>* createLinkedListFromArray(T arr[], int size) {
    ListNode<T> *head = new ListNode<T>(arr[0]);
    ListNode<T> *temp, *last;
    last = head;

    for (int i = 1; i < size; i++) {
        temp = new ListNode<T>(arr[i]);
        last -> setNext(temp);
        last = temp;
    }

    return head;
};

// Counts the number of nodes in a linked list.                Time Complexity: O(n), Space Complexity: O(1).
template <class T>
int countNodes(ListNode<T> *head) {
    int count = 0;

    ListNode<T> *temp = head;
    while (temp) {
        count++;
        temp = temp -> getNext();
    }

    return count;
}

// Returns sum of elements if data type is int, float or double.    Time Complexity: O(n), Space Complexity: O(1).
template <class T>
T sumOfData(ListNode<T> *head) {
    T sum;
    ListNode<T> *temp = head;
    while (temp) {
        sum += temp -> getData();
        temp = temp -> getNext();
    }

    return sum;
}

template<>
int sumOfData<int>(ListNode<int> *head) {
    int sum = 0;
    ListNode<int> *temp = head;
    while (temp) {
        sum += temp -> getData();
        temp = temp -> getNext();
    }

    return sum;
}

template<>
float sumOfData<float>(ListNode<float> *head) {
    float sum = 0.0f;
    ListNode<float> *temp = head;
    while (temp) {
        sum += temp -> getData();
        temp = temp -> getNext();
    }

    return sum;
}

template<>
double sumOfData<double>(ListNode<double> *head) {
    double sum = 0.0f;
    ListNode<double> *temp = head;
    while (temp) {
        sum += temp -> getData();
        temp = temp -> getNext();
    }

    return sum;
}

// Returns the maximum element in a linked list.               Time Complexity: O(n), Space Complexity: O(1).
template <class T>
T maxElement(ListNode<T> *head) {
    T maxElement = head -> getData();
    ListNode<T> *temp = head;

    while (temp) {
        if (temp -> getData() > maxElement) {
            maxElement = temp -> getData();
        }
        temp = temp -> getNext();
    }

    return maxElement;
}

template <>
int maxElement<int>(ListNode<int> *head) {
    int maxElement = INT_MIN;
    ListNode<int> *temp = head;

    while (temp) {
        if (temp -> getData() > maxElement) {
            maxElement = temp -> getData();
        }
        temp = temp -> getNext();
    }

    return maxElement;
}

template <>
float maxElement<float>(ListNode<float> *head) {
    float maxElement = std::numeric_limits<float>::min();
    ListNode<float> *temp = head;

    while (temp) {
        if (temp -> getData() > maxElement) {
            maxElement = temp -> getData();
        }
        temp = temp -> getNext();
    }

    return maxElement;
}

template <>
double maxElement<double>(ListNode<double> *head) {
    double maxElement = std::numeric_limits<double>::min();
    ListNode<double> *temp = head;

    while (temp) {
        if (temp -> getData() > maxElement) {
            maxElement = temp -> getData();
        }
        temp = temp -> getNext();
    }

    return maxElement;
}

// Searches for a value in the linked list and returns its address if found, else returns NULL.     Time Complexity: O(n), Space Complexity: O(1).
template <class T>
ListNode<T>* searchLinkedListFor(T element, ListNode<T> *head) {
    ListNode<T> *temp = head;

    while (temp) {
        if (temp -> getData() == element) {
            return temp;
        }
        temp = temp - getNext();
    }

    return nullptr;
}

// Optimised Move to Head search algorithm implementation for linked list.
// ? If you search for an element twice, the time complexity to search it becomes O(1). This is done
// ? by replacing the placing the element at the head of the linked list, so accessing it takes constant time.
template<class T>
ListNode<T>* optimisedSearch(T element, ListNode<T> *head) {
    ListNode<T> *temp = head, *prev = nullptr;

    while (temp -> getData() != element) {
        prev = temp;
        temp = temp -> next;
    }

    prev -> setNext(temp -> setNext());
    temp -> setNext(head);
    head = temp;

    return temp;
}