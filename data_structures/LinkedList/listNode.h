#pragma once
#include <iostream>

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

// Prints a linked list.
template <class T>
void displayLinkedList(ListNode<T> *head) {
    ListNode<T> *temp = head;
    while (temp != nullptr) {
        std::cout << temp -> getData() << " ";
        temp = temp -> getNext();
    }
}

// Creates a linked list from an array of elements.
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