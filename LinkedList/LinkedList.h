// Single Linked List Implementation
// Stack implementation - FILO (First In Last Out)

#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void append(T value);
        void print() const;
        void pop();
        void clear();
        bool exists(T value) const;
        int length() const;
};

//--------------------------------------------------------------
// LinkedList Method Definitions
//--------------------------------------------------------------

// Constructor: Initializes an empty linked list
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

// Deconstructor: Cleans up the linked list
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// Append: Adds a new node with the given value to the end of the list
template <typename T>
void LinkedList<T>::append(T value) {
    if (size == 0) {
        head = new Node<T>(value);
        size++;
    }
    else {
        Node<T>* currNode = head;

        while (currNode->next) {
            currNode = currNode->next;
        }

        currNode->next = new Node<T>(value);
        size++;
    }
}

// Print: Outputs the linked list's valuess if it's not empty
template <typename T>
void LinkedList<T>::print() const {
    Node<T>* curr = head;

    std::cout << "Linked List: "; 

    if (curr) {
        while (curr->next) {
            std::cout << curr->val << " -> ";

            curr = curr->next;
        }

        std::cout << curr->val << " -> nullptr\n\n";
    }
    else
        std::cout << "List is currently empty\n\n";
}

// Pop: Removes and returns the last element from the linked list
template <typename T>
void LinkedList<T>::pop() {
    // When there's no elements in the list
    if (size == 0) {
        std::cout << "*** Pop Error: The linked list is currently empty ***\n\n";
        return;
    }
    
    // When there's only one element in the list
    if (size == 1) {
        delete head;
        head = nullptr;
        size--;
        return;
    }

    // When there's more than one element in the list
    Node<T>* curr = head;

    while (curr->next->next) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    size--;
}

template <typename T>
void LinkedList<T>::clear() {
    Node<T>* curr = head;

    while (curr) {
        Node<T>* tmp = curr->next;
        delete curr;
        curr = tmp;
    }

    size = 0;
    head = nullptr;
}

template <typename T>
int LinkedList<T>::length() const {
    return size;
}

// Exists: Checks if a value exists in the linked list
template <typename T>
bool LinkedList<T>::exists(T value) const {
    Node<T>* curr = head;

    while (curr) {
        if (curr->val == value)
            return true;

        curr = curr->next;
    }
    
    return false;
}