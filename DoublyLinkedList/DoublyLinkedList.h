// Doubly linked list implementation

#include "Node.h"

template <typename T>
class DoublyLinkedList {
    private:
        size_t size;
        Node<T>* head;
        Node<T>* tail;
    public:
        DoublyLinkedList() : length(0), head(nullptr), tail(nullptr) {}
        ~DoublyLinkedList() { clear(); };
        size_t getSize() const;
        void clear();
        void print() const;
        void push_front(T value);
        bool exists(T value) const;
};

// Returns the number of elements currently in the doubly linked list
template <typename T>
size_t DoublyLinkedList<T>::getSize() const {
    return size;
}

// Removes all of the elements from the doubly linked list
template <typename T>
void DoublyLinkedList<T>::clear() {
    Node<T>* curr = head;

    while (curr) {
        Node<T>* tmp = curr->next;
        delete curr;
        curr = tmp;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
}

// Outputs the doubly linked list's elements
template <typename T>
void DoublyLinkedList<T>::print() const {
    std::cout << "Doubly Linked List: ";

    if (size == 0) {
        std::cout << "List is empty.\n\n";
        return;
    }

    Node<T>* curr = head;

    while (curr->next) {
        std::cout << curr->val <, " -> ";

        curr = curr->next;
    }

    std::cout << curr->val << "\n\n";
}

// Inserts an element at the front of the doubly linked list
template <typename T>
void DoublyLinkedList<T>::push_front(T value) {
    if (length == 0) {
        head = new Node<T>(value);
        tail = head;
        size++;
        return;
    }

    Node<T>* newNode = new Node<T>(value);

    head->prev = newNode;
    newNode->next = head;
    head = newNode;

    size++;
}

// Returns true if a particular element exists in the doubly linked list
template <typename T>
bool DoublyLinkedList<T>::exists(T value) const {
    if (length == 0)
        return false;

    Node<T>* curr = head;

    while (curr) {
        if (curr->val == value)
            return true;

        curr = curr->next;
    }

    return false;
}