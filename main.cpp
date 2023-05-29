#include <iostream>

#include "data_structures/LinkedList/listNode.h"

int main() {
    ListNode<int> *head = new ListNode<int>(10);
    head -> setNext(new ListNode<int>(12));
    head -> getNext() -> setNext(new ListNode<int>(14));
    head -> getNext() -> getNext() -> setNext(new ListNode<int>(16));

    for (auto i = head; i != NULL; i = i -> getNext()) {
        std::cout << i -> getData() << " ";
    } std::cout << std::endl;
}