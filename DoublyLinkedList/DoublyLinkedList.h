// Doubly Linked List implementation

#include "Node.h"

template <typename T>
class DoublyLinkedList {
    private:
        int length;
        Node<T>* head;
        Node<T>* tail;
    public:
        DoublyLinkedList() : length(0), head(nullptr), tail(nullptr) {}
        //~DoublyLinkedList();
        int size();
        void clear();
};

// Size: Returns the number of elements currently in the doubly linked list
template <typename T>
int DoublyLinkedList<T>::size() {
    return length;
}

// Clear: Removing all the elements from the doubly linked list
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