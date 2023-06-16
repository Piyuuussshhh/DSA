#pragma once
#include <iostream>

// * Declaration

template <class T>
class DoubleListNode {
private:
    DoubleListNode<T> *prev;
    T data;
    DoubleListNode<T> *next;
public:
    DoubleListNode(T);
    DoubleListNode(T, DoubleListNode<T>*, DoubleListNode<T>*);
    ~DoubleListNode();
    DoubleListNode<T>* getPrev();
    T getData();
    DoubleListNode<T>* getNext();

    void setPrev(DoubleListNode<T>*);
    void setData(T);
    void setNext(DoubleListNode<T>*);
};

// * Implementation

template <class T>
DoubleListNode<T>::DoubleListNode(T element)
    : data(element), prev(nullptr), next(nullptr) {}

template <class T>
DoubleListNode<T>::DoubleListNode(T element, DoubleListNode<T> *p, DoubleListNode<T> *n)
    : data(element), prev(p), next(n) {}

template <class T>
DoubleListNode<T>::~DoubleListNode() {}

template <class T>
DoubleListNode<T>* DoubleListNode<T>::getPrev() {
    return this -> prev;
}

template <class T>
T DoubleListNode<T>::getData() {
    return this -> data;
}

template <class T>
DoubleListNode<T>* DoubleListNode<T>::getNext() {
    return this -> next;
}

template <class T>
void DoubleListNode<T>::setPrev(DoubleListNode<T> *node) {
    this -> prev = node;
}

template <class T>
void DoubleListNode<T>::setData(T element) {
    this -> data = element;
}

template <class T>
void DoubleListNode<T>::setNext(DoubleListNode<T> *node) {
    this -> next = node;
}

// * Doubly Linked List Functions

// Prints a doubly linked list iteratively.
template <class T>
void displayDoublyLinkedList(DoubleListNode<T> *head) {
    DoubleListNode<T> *temp = head;
    while (temp) {
        std::cout << temp -> getData() << " ";
        temp = temp -> getNext();
    } std::cout << std::endl;
}

// Creates a doubly linked list from an array.
template <class T>
DoubleListNode<T>* createDoublyLinkedListFromArray(T arr[], int size) {
    DoubleListNode<T> *head = new DoubleListNode(arr[0]);
    DoubleListNode<T> *temp, *last;
    last = head;

    for (int i = 1; i < size; i++) {
        temp = new DoubleListNode<T>(arr[i]);
        last -> setNext(temp);
        temp -> setPrev(last);
        last = temp;
    }

    return head;
}

// Counts the number of nodes in a doubly linked list.
template <class T>
int _countNodes(DoubleListNode<T> *head) {
    int count = 0;

    DoubleListNode<T> *temp = head;
    while (temp) {
        count++;
        temp = temp -> getNext();
    }

    return count;
}

// Inserts an element in a doubly linked list.
template <class T>
void insert(DoubleListNode<T> *&head, T element, int index = -1) {
    DoubleListNode<T> *newNode = new DoubleListNode<T>(element);

    if ((index < 0 && index != -1) || index > _countNodes(head)) {
        std::cout << "[ERROR] Invalid index! position" << std::endl;
        return;
    }

    if (index == 0) {
        newNode -> setNext(head);
        head -> setPrev(newNode);
        head = newNode;
        return;
    } else if (index == -1) {
        DoubleListNode<T> *temp = head;
        while (temp -> getNext()) {
            temp = temp -> getNext();
        }

        temp -> setNext(newNode);
        newNode -> setPrev(temp);
        return;
    }

    DoubleListNode<T> *temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp -> getNext();
    }

    newNode -> setPrev(temp);
    newNode -> setNext(temp -> getNext());

    if (temp -> getNext()) {
        temp -> getNext() -> setPrev(newNode);
    }
    temp -> setNext(newNode);

    return;
}

// Deletes an element in a doubly linked list by index.
template <class T>
void deleteByIndex(DoubleListNode<T> *&head, int index) {
    if (index < 0 || index > _countNodes<T>(head)) {
        std::cout << "[ERROR] Invalid Index!" << std::endl;
        return;
    }

    DoubleListNode<T> *temp = head;
    if (index == 1) {
        head = head -> getNext();
        if (head) {
            head -> setPrev(nullptr);
        }
        std::cout << "Deleted " << temp -> getData() << std::endl;
        delete temp;
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        temp = temp -> getNext();
    }

    if (temp -> getNext()) {
        temp -> getPrev() -> setNext(temp -> getNext());
    } else {
        temp -> getPrev() -> setNext(nullptr);
        std::cout << "Deleted " << temp -> getData() << std::endl;
        delete temp;
        return;
    }

    temp -> getNext() -> setPrev(temp -> getPrev());
    std::cout << "Deleted " << temp -> getData() << std::endl;
    delete temp;
    return;
}

// Reverses a doubly linked list by swapping links.
template <class T>
void reverse(DoubleListNode<T> *&head) {
    DoubleListNode<T> *temp = head, *swap = nullptr;

    while (temp) {
        swap = temp -> getNext();
        temp -> setNext(temp -> getPrev());
        temp -> setPrev(swap);

        temp = temp -> getPrev();

        if (temp && !temp -> getNext()) {
            head = temp;
        }
    }
}

// Creates a circular doubly linked list.
template <class T>
DoubleListNode<T>* makeCircularDoublyLinkedList(T arr[], int size) {
    DoubleListNode<T> *head = createDoublyLinkedListFromArray<T>(arr, size);

    DoubleListNode<T> *temp = head;
    while (temp -> getNext()) {
        temp = temp -> getNext();
    }

    temp -> setNext(head);
    head -> setPrev(temp);

    return head;
}

// Makes a doubly linked list circular.
template <class T>
void makeDoublyLinkedListCircular(DoubleListNode<T> *&head) {
    DoubleListNode<T> *temp = head;
    while (temp -> getNext()) {
        temp = temp -> getNext();
    }

    temp -> setNext(head);
    head -> setPrev(temp);
}

// Returns the middle element of the linked list.
template <class T>
DoubleListNode<T>* middleNode(DoubleListNode<T> *head) {
    DoubleListNode<T> *last = head, *middle = head;

    while (last) {
        middle = middle -> getNext();

        last = last -> getNext();
        last = last -> getNext();
    }

    return middle;
}