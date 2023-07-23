#include <iostream>

class StackIsEmptyException : std::exception {
public:
    char* what() {
        return "[ERROR] The stack is empty!";
    }
};

class InvalidIndexException : std::exception {
public:
    char* what() {
        return "[ERROR] The index is either out of range or of invalid value!";
    }
};

