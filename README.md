# Data Structures and Algorithms
My implementation of widely used data structures and their algorithms.

## Linked List:
The file `data_structures/LinkedList/listNode.h` contains the class blueprint and its implementation, plus common operations performed on a linked list. These include:

1.  `template <class T> void displaySingleLinkedList(ListNode<T>*)`: This function takes the first node of a linked list as a parameter and prints the entire linked list.
    * Time Complexity: O(n).
    * Space Complexity: O(1).

2. `template <class T> void recursiveDisplayLL(ListNode<T>*)`: This function prints entire linked list recursively.
    * Time complexity: O(n).
    * Space Complexity: O(1 * n).

3. `template <class T> void recursiveReverseDisplayLL(ListNode<T>*)`: Same as above, but recursively prints the reverse of a linked list.

4. `template <class T> ListNode<T>* createLinkedListFromArray(T arr[], int)`: This function creates a linked list from an array of elements.
    * Time complexity: O(n).
    * Space Complexity: O(n).

5. `template <class T> int countNodes(ListNode<T>*)`: This function returns the number of elements in a linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

6. `template <class T> T sumOfData(ListNode<T>*)`: This function returns the sum of all elements in a linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

7. `template <class T> T maxElement(ListNode<T>*)`: This function returns the maximum element of a linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

8. `template <class T> ListNode<T>* searchLinkedListFor(T, ListNode<T>*)`: This function searches for a node in a linked list by value. If found, it returns the address of the node, else returns nullptr.
    * Time complexity: O(n).
    * Space Complexity: O(1).

9. `template <class T> ListNode<T>* optimisedSearch(T, ListNode<T>*)`: This function optimizes the search algorithm such that, if the previously searched element is to be searched again, it is accessed in constant time. The algorithm places the most recently searched element as the head of the linked list.
    * Time complexity: O(n) && O(1).
    * Space Complexity: O(1).

10. `void insert(ListNode<T>*&, T, int index = -1)`: This function inserts a new node in the linked list with the value in the parameter at the index specified by the user. Index 0 = head of the linked list, Index -1 = last position in the linked list.
    * Inserting new node before head: Time Complexity: O(1), Space Complexity: O(1).
    * Inserting new node in between head and last node: Time Complexity: O(n), Space Complexity: O(1).
    * Inserting new node after last node: Time Complexity: O(1), Space Complexity: O(1).

11. `template <class T> void sort(ListNode<T>*)`: A very slow bubble sort algorithm to sort the linked list by value. **Going to be changed in the future**.
    * Time complexity: O(n).
    * Space Complexity: O(1).

12. `template <class T> void insertInSortedLinkedList(T, ListNode<T>*&)`: This function inserts an element at its right place in a sorted linked list.
    * Time complexity: O(n) && O(1).
    * Space Complexity: O(1).

13. `template <class T> void deleteByIndex(ListNode<T>*&, int)`: This function deletes the element at the specified index from the linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

14. `template <class T> void deleteByValue(ListNode<T>*&, T)`: This function deletes the element with the value passed in the parameters from the linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

15. `template <class T> bool isLinkedListSorted(ListNode<T>*)`: This function returns true if the linked list is sorted, false if it isn't.
    * Time complexity: O(n).
    * Space Complexity: O(1).

16. `template <class T> void deleteDuplicateElementsInSortedLL(ListNode<T>*)`: This function deletes duplicate elements in a sorted linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

17. `template <class T> void reverseLinkedListByValue(ListNode<T>*)`: This function reverses the linked list by swapping values. **NOT PREFERRED.**
    * Time complexity: O(n).
    * Space Complexity: O(1).

18. `template <class T> void reverseLinkedListByLinks(ListNode<T>*&)`: This function reverses the linked list by swapping the links between nodes.
    * Time complexity: O(n).
    * Space Complexity: O(1).

19. `template <class T> ListNode<T>* concatenateLinkedLists(ListNode<T> *first, ListNode<T> *second)`: This function concatenates two linked lists together, where the first node of the second linked list is pointed to by the next pointer of the last node of the first linked list.
    * Time complexity: O(n), where n is the size of the first linked list.
    * Space Complexity: O(1).

20. `template <class T> ListNode<T>* sortedMerge(ListNode<T> *first, ListNode<T> *second)`: This function merges two linked lists and returns the address of the new first node, such that the resulting linked list is sorted.
    * Time complexity: O(m + n), where m and n are sizes of the two linked lists.
    * Space Complexity: O(1).

21. `template <class T> bool doesLoopExist(ListNode<T>*)`: This function returns true if a loop exists in the linked list.
    * Time complexity: ~O(n).
    * Space Complexity: O(1).

22. `template <class T> ListNode<T>* makeCircularLinkedList(T arr[], int size)`: This function creates a linked list and returns the address of the current head node.
    * Time complexity: O(n).
    * Space Complexity: O(1).

23. `template <class T> ListNode<T>* middleNode(ListNode<T> *head)`: This function returns the middle element of a linked list. If odd, it returns the address of the node at ⌊n/2⌋th index, if even, it returns the address of the node at the ⌈n/2⌉th index.
    * Time complexity: O(n/2).
    * Space Complexity: O(1).

## Doubly Linked List:
The file `data_structures/LinkedList/doubleListNode.h` contains the class blueprint and its implementation, plus common operations performed on a doubly linked list. I KNOW I could've used inheritance for this data structure, but i was lazy ^^. These include:

1. `template <class T> void displayDoublyLinkedList(DoubleListNode<T>*)`: This function prints all elements of the doubly linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

2. `template <class T> DoubleListNode<T>* createDoublyLinkedListFromArray(T arr[], int)`: This function creates a doubly linked list from an array and returns the address of the first node.
    * Time complexity: O(n).
    * Space Complexity: O(1).

3. `template <class T> int countNodes(DoubleListNode<T>*)`: This function returns the number of elements in a doubly linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

1. `template <class T> void insert(DoubleListNode<T>*&, T, int index = -1)`: This function inserts a new node in the linked list with the value in the parameter at the index specified by the user. Index 0 = head of the doubly linked list, Index -1 = last position in the doubly linked list.
    * Inserting new node before head: Time Complexity: O(1), Space Complexity: O(1).
    * Inserting new node in between head and last node: Time Complexity: O(n), Space Complexity: O(1).
    * Inserting new node after last node: Time Complexity: O(1), Space Complexity: O(1).

1. `template <class T> void deleteByIndex(DoubleListNode<T>*&, int)`: This function deletes the element at the specified index from the linked list.
    * Time complexity: O(n).
    * Space Complexity: O(1).

1. `template <class T> void reverse(DoubleListNode<T>*&)`: This function reverses the doubly linked list by swapping the links between nodes.
    * Time complexity: O(n).
    * Space Complexity: O(1).

1. `template <class T> DoubleListNode<T>* makeCircularDoublyLinkedList(T arr[], int)`: This function creates a new circular doubly linked list and returns the address of the current head node.
    * Time complexity: O(n).
    * Space Complexity: O(1).

1. `template <class T> void makeDoublyLinkedListCircular(DoubleListNode<T>*)`: This function makes an existing doubly linked list circular by setting the next pointer of the last node to point to the head node, and the prev pointer of the head node to point to the last node.
    * Time complexity: O(n).
    * Space Complexity: O(1).

1. `template <class T> DoubleListNode<T>* middleNode(DoubleListNode<T> *head)`: This function returns the middle element of a doubly linked list. If odd, it returns the address of the node at ⌊n/2⌋th index, if even, it returns the address of the node at the ⌈n/2⌉th index.
    * Time complexity: O(n/2).
    * Space Complexity: O(1).