#pragma once
#include <iostream>
#include <limits>

#include "../LinkedList/listNode.h"

#define GARBAGE_INT_VALUE INT_MIN
#define GARBAGE_FLOAT_VALUE std::numeric_limits<float>::min()
#define GARBAGE_DOUBLE_VALUE std::numeric_limits<double>::min()
#define GARBAGE_STRING_VALUE "12344555567899999"

// * Declaration

template <class T>
class Stack {
private:
    int size = INT_MIN;
    ListNode<T> *bottom;
    ListNode<T> *top;
public:
    Stack();
    Stack(int);
    void push(T);
    T pop();
    int getSize();
    T peek(int);
    bool isEmpty();
    bool isFull();
};

// *Implementation

// Constructor
template <>
Stack<int>::Stack() {
    this -> bottom = new ListNode<int>(GARBAGE_INT_VALUE);
    this -> top = this -> bottom;
}

// Takes an integer to set the size of the stack.
template <>
Stack<int>::Stack(int sizeOfStack) : size(sizeOfStack) {
    this -> bottom = new ListNode<int>(GARBAGE_INT_VALUE);
    this -> top = this -> bottom;
}

template <>
Stack<float>::Stack() {
    this -> bottom = new ListNode<float>(GARBAGE_FLOAT_VALUE);
    this -> top = this -> bottom;
}

// Takes an integer to set the size of the stack.
template <>
Stack<float>::Stack(int sizeOfStack) : size(sizeOfStack) {
    this -> bottom = new ListNode<float>(GARBAGE_FLOAT_VALUE);
    this -> top = this -> bottom;
}

template <>
Stack<double>::Stack() {
    this -> bottom = new ListNode<double>(GARBAGE_DOUBLE_VALUE);
    this -> top = this -> bottom;
}

// Takes an integer to set the size of the stack.
template <>
Stack<double>::Stack(int sizeOfStack) : size(sizeOfStack) {
    this -> bottom = new ListNode<double>(GARBAGE_DOUBLE_VALUE);
    this -> top = this -> bottom;
}

template <>
Stack<std::string>::Stack() {
    this -> bottom = new ListNode<std::string>(GARBAGE_STRING_VALUE);
    this -> top = this -> bottom;
}

// Takes an integer to set the size of the stack.
template <>
Stack<std::string>::Stack(int sizeOfStack) : size(sizeOfStack) {
    this -> bottom = new ListNode<std::string>(GARBAGE_STRING_VALUE);
    this -> top = this -> bottom;
}

// Pushes a new element to the bottom of the stack.    Time Complexity: O(1), Space Complexity: O(n).
template <>
void Stack<int>::push(int element) {
    if (this -> bottom -> getData() == GARBAGE_INT_VALUE) {
        this -> bottom -> setData(element);
        return;
    }

    if (size != INT_MIN && this -> getSize() >= this -> size) {
        std::cout << "[ERROR] Stack full!" << std::endl;
        return;
    }

    ListNode<int> *newTop = new ListNode<int>(element);
    this -> top -> setNext(newTop);
    this -> top = newTop;
}

template <>
void Stack<float>::push(float element) {
    if (this -> bottom -> getData() == GARBAGE_FLOAT_VALUE) {
        this -> bottom -> setData(element);
        return;
    }

    if (size != INT_MIN && this -> getSize() >= this -> size) {
        std::cout << "[ERROR] Stack full!" << std::endl;
        return;
    }

    ListNode<float> *newTop = new ListNode<float>(element);
    this -> top -> setNext(newTop);
    this -> top = newTop;
}

template <>
void Stack<double>::push(double element) {
    if (this -> bottom -> getData() == GARBAGE_DOUBLE_VALUE) {
        this -> bottom -> setData(element);
        return;
    }

    if (size != INT_MIN && this -> getSize() >= this -> size) {
        std::cout << "[ERROR] Stack full!" << std::endl;
        return;
    }

    ListNode<double> *newTop = new ListNode<double>(element);
    this -> top -> setNext(newTop);
    this -> top = newTop;
}

template <>
void Stack<std::string>::push(std::string element) {
    if (this -> bottom -> getData() == GARBAGE_STRING_VALUE) {
        this -> bottom -> setData(element);
        return;
    }

    if (size != INT_MIN && this -> getSize() >= this -> size) {
        std::cout << "[ERROR] Stack full!" << std::endl;
        return;
    }

    ListNode<std::string> *newTop = new ListNode<std::string>(element);
    this -> top -> setNext(newTop);
    this -> top = newTop;
}

// Pops an element off the bottom of the stack. Time Complexity: O(1), Space Complexity: O(1).
template <class T>
T Stack<T>::pop() {
    if (this -> isEmpty()) {
        // ! throw ERROR.
    }

    T data = top -> getData();

    // deletes the topmost element.
    deleteByIndex<T>(this -> bottom);

    ListNode<T> *temp = bottom;
    while (temp -> getNext()) {
        temp = temp -> getNext();
    }
    this -> top = temp;

    return data;
}

// Returns the getSize of the stack. Time Complexity: O(n), Space Complexity: O(1).
template <class T>
int Stack<T>::getSize() {
    return countNodes(this -> bottom);
}

// Returns the value of the element at index passed as argument.
template <class T>
T Stack<T>::peek(int indexFromLast) {
    if (indexFromLast > this -> getSize() || index < 0) {
        std::cout << "[ERROR] Invalid index!" << std::endl;
        // return;
        // ! NEED TO THROW ERROR.
    }
    if (indexFromLast == 0) {
        return this -> bottom -> getData();
    }

    int index = this -> getSize() - indexFromLast;
    ListNode<T> *temp = this -> bottom;
    for (int i = 0; i < index - 1; i++) {
        temp = temp -> getNext();
    }

    return temp -> getData();
}

// Returns true if the stack is empty.  Time Complexity: O(1), Space Complexity: O(1).
template <class T>
bool Stack<T>::isEmpty() {
    if (this -> top -> getData() == GARBAGE_INT_VALUE ||
        this -> top -> getData() == GARBAGE_FLOAT_VALUE ||
        this -> top -> getData() == GARBAGE_DOUBLE_VALUE ||
        this -> top -> getData() == GARBAGE_STRING_VALUE) {
        return true;
    }
    return false;
}

// Returns true if the stack is full.   Time Complexity: O(n), Space Complexity: O(1).
template <class T>
bool Stack<T>::isFull() {
    if (this -> size == INT_MIN || this -> getSize() < this -> size) {
        return false;
    }
    return true;
}