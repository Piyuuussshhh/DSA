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
    ListNode(T);
    ~ListNode();
    T getData();
    void setData(T);
    ListNode* getNext();
    void setNext(ListNode<T>*);
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
void ListNode<T>::setData(T element) {
    this -> data = element;
}

template <class T>
ListNode<T>* ListNode<T>::getNext() {
    return this -> next;
}

template <class T>
void ListNode<T>::setNext(ListNode<T> *node) {
    this -> next = node;
}

// * Linked List Functions

// Prints a linked list iteratively.                           Time Complexity: O(n), Space Complexity: O(1).
template <class T>
void displaySingleLinkedList(ListNode<T> *head) {
    ListNode<T> *temp = head;
    while (temp != nullptr) {
        std::cout << temp -> getData() << " ";
        temp = temp -> getNext();
    } std::cout << std::endl;
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

    int index = 0;
    while (temp) {
        if (temp -> getData() == element) {
            std::cout << "Element found at index " << index << "." << std::endl;
            return temp;
        }
        temp = temp -> getNext();
        index++;
    }

    return nullptr;
}

// Optimised Move to Head search algorithm implementation for linked list.      Time Complexity: O(n) && O(1) in some cases, Space Complexity: O(1).
// ? If you search for an element twice, the time complexity to search it becomes O(1). This is done
// ? by replacing the placing the element at the head of the linked list, so accessing it takes constant time.
template<class T>
ListNode<T>* optimisedSearch(T element, ListNode<T> *head) {
    ListNode<T> *temp = head, *prev = nullptr;

    int index = 0;
    while (temp) {
        if (temp -> getData() == element) {
            std::cout << "Element found at index " << index << "." << std::endl;
            prev -> setNext(temp -> getNext());
            temp -> setNext(head);
            head = temp;
            return head;
        }
        prev = temp;
        temp = temp -> getNext();
        index++;
    }

    if (!temp) {
        return nullptr;
    }

    return head;
}

// Inserts a new node into the linked list. By default, if no index is provided, inserts element at the end of the linked list.
// ? Inserting new node before head: Time Complexity: O(1), Space Complexity: O(1).
// ? Inserting new node in between head and last node: Time Complexity: O(n), Space Complexity: O(1).
// ? Inserting new node after last node: Time Complexity: O(1), Space Complexity: O(1).
template <class T>
void insert(ListNode<T> *&head, T element, int index = -1) {
    ListNode<T> *newNode = new ListNode<T>(element);

    if ((index < 0 && index != -1) || index > countNodes(head)) {
        std::cout << "[ERROR] Incorrect index position!" << std::endl;
        return;
    }

    if (index == 0) {
        newNode -> setNext(head);
        head = newNode;
    } else if (index == -1) {
        ListNode<T> *prev = head;

        while (prev -> getNext()) {
            prev = prev -> getNext();
        }

        prev -> setNext(newNode);
    } else {
        ListNode<T> *prev = head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev -> getNext();
        }

        newNode -> setNext(prev -> getNext());
        prev -> setNext(newNode);
    }
}

// Sorts a linked list.                                             Time Complexity: O(n^2), Space Complexity: O(1).
template <class T>
void sort(ListNode<T>* head) {
    for (auto i = head; i; i = i -> getNext()) {
        for (auto j = i -> getNext(); j; j = j -> getNext()) {
            if (i -> getData() > j -> getData()) {
                auto temp = i -> getData();
                i -> setData(j -> getData());
                j -> setData(temp);
            }
        }
    }
}

// Inserts an element in the right place in a sorted Linked List.   Time Complexity: O(n) {best case O(1)}, Space Complexity: O(1).
template <class T>
void insertInSortedLinkedList(T element, ListNode<T> *&head) {
    ListNode<T> *newNode = new ListNode<T>(element);
    ListNode<T> *temp = head, *prev = nullptr;

    if (!head) {
        head = newNode;
    }

    // if (element < head -> getData()) {
    //     std::cout << "Head: " << head -> getData() << "; Element: " << element << std::endl;
    //     newNode -> setNext(head);
    //     head = newNode;
    // }

    while (temp && temp -> getData() < element) {
        std::cout << "Temp: " << temp -> getData() << "; Element: " << element << std::endl;
        prev = temp;
        temp = temp -> getNext();
    }

    if (temp == head) {
        std::cout << "Head: " << head -> getData() << "; Element: " << element << std::endl;
        newNode -> setNext(head);
        head = newNode;
        return;
    }

    newNode -> setNext(prev -> getNext());
    prev -> setNext(newNode);
    std::cout << "Swapped the nodes! Inserted " << element << " in the right place!" << std::endl;
}

// Deletes a node from a linked list by index.                               Time Complexity: O(n), Space Complexity: O(1).
template <class T>
void deleteByIndex(ListNode<T> *&head, int index) {
    if (index <= 0 || index > countNodes(head)) {
        std::cout << "[ERROR] Invalid Index!" << std::endl;
        return;
    }

    if (index == 1) {
        ListNode<T> *temp = head;
        head = head -> getNext();
        std::cout << "Deleted " << temp -> getData() << std::endl;
        delete temp;
        return;
    }

    ListNode<T> *temp = head, *prev = nullptr;
    for (int i = 0; i < index - 1; i++) {
        prev = temp;
        temp = temp -> getNext();
    }

    prev -> setNext(temp -> getNext());
    std::cout << "Deleted " << temp -> getData() << std::endl;
    delete temp;
}

// Deletes a node from a linked list by value.                               Time Complexity: O(n), Space Complexity: O(1).
template <class T>
void deleteByValue(ListNode<T> *&head, T element) {
    ListNode<T> *temp = head, *prev = nullptr;

    while (temp && temp -> getData() != element) {
        prev = temp;
        temp = temp -> getNext();
    }

    if (!temp) {
        std::cout << "[WARNING] Element not found!" << std::endl;
        return;
    }

    if (temp == head) {
        prev = temp -> getNext();
        head = prev;
        delete temp;
        return;
    }

    prev -> setNext(temp -> getNext());
    std::cout << "Deleted " << temp -> getData() << std::endl;
    delete temp;
}

// Checks if linked list is sorted.                                          Time Complexity O(n), Space Complexity: O(1).
template <class T>
bool isLinkedListSorted(ListNode<T> *head) {
    ListNode<T> *temp = head -> getNext(), *prev = head;

    while (temp) {
        if (prev -> getData() > temp -> getData()) {
            return false;
        }
        prev = temp;
        temp = temp -> getNext();
    }

    return true;
}

// Deletes duplicate nodes in a sorted linked list.                          Time Complexity O(n), Space Complexity: O(1).
template <class T>
void deleteDuplicateElementsInSortedLL(ListNode<T> *head) {
    ListNode<T>* temp = head -> getNext(), *prev = head;

    int index = 0;
    while (temp) {
        if (temp -> getData() != prev -> getData()) {
            prev = temp;
            temp = temp -> getNext();
        } else {
            prev -> setNext(temp -> getNext());
            std::cout << "Deleting element " << temp -> getData() << " at index " << index << std::endl;
            delete temp;
            temp = prev -> getNext();
        }
        index++;
    }
}

// Reverses a linked list by swapping the values.                           Time Complexity: O(2n) ~ O(n), Space Complexity: O(n).
// ? This method is not preferred as copying data can take varying amounts of memory, sometimes less, sometimes a lot.
// ? Swapping links is preferred because pointers take a constant amount of memory for every data type.
template <class T>
void reverseLinkedListByValue(ListNode<T> *head) {
    int numOfNodes = countNodes<T>(head);
    T *auxillaryArray = new T[numOfNodes];

    ListNode<T> *temp = head;
    int index = 0;
    while (temp) {
        auxillaryArray[index++] = temp -> getData();
        temp = temp -> getNext();
    }
    index--;

    temp = head;

    while (temp) {
        temp -> setData(auxillaryArray[index--]);
        temp = temp -> getNext();
    }
}

// Reverses a linked list by swapping links with sliding pointers.           Time Complexity: O(n), Space Complexity: O(1).
template <class T>
void reverseLinkedListByLinks(ListNode<T> *&head) {
    ListNode<T> *prev = nullptr, *current = nullptr, *next = head;

    while (next) {
        prev = current;
        current = next;
        next = next -> getNext();

        current -> setNext(prev);
    }

    // * line 477 is vv important!!!!
    head = current;
}

// Concatenates two linked lists into a single linked list.                 Time Complexity: O(n), Space Complexity: O(1).
template <class T>
ListNode<T>* concatenateLinkedLists(ListNode<T> *first, ListNode<T> *second) {
    ListNode<T> *temp = first;

    while (temp -> getNext()) {
        temp = temp -> getNext();
    }

    temp -> setNext(second);
    return first;
}

// Merges two sorted linked lists into one sorted linked list. Returns address of head of merged linked list. Time Complexity: O(m + n), Space Complexity: O(1).
// !FIX NOT WORKING IDK WHY
template <class T>
ListNode<T>* sortedMerge(ListNode<T> *first, ListNode<T> *second) {
    ListNode<T> *head = nullptr, *last = nullptr;
    ListNode<T> *temp1 = first, *temp2 = second;

    if (temp1 -> getData() < second -> getData()) {
        head = last = temp1;
        temp1 = temp1 -> getNext();
        last -> setNext(nullptr);
    } else {
        head = last = temp2;
        temp2 = temp2 -> getNext();
        last -> setNext(nullptr);
    }

    while (temp1 && temp2) {
        if (first -> getData() < second -> getData()) {
            last -> setNext(temp1);
            last = temp1;
            temp1 = temp1 -> getNext();
            last -> setNext(nullptr);
        } else {
            last -> setNext(temp2);
            last = temp2;
            temp2 = temp2 -> getNext();
            last -> setNext(nullptr);
        }
    }

    if (temp1) {
        last -> setNext(temp1);
    } else if (temp2) {
        last -> setNext(temp2);
    }

    return head;
}

// Checks if the linked list has a loop. Time complexity: O(), Space Complexity: O().
template <class T>
bool doesLoopExist(ListNode<T> *head) {
    ListNode<T> *pointer1 = head, *pointer2 = head;
}