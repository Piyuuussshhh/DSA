#pragma once
#include <iostream>

template <class T>
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

template <class T>
ListNode<T>::ListNode(T d) : data(d) {}

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