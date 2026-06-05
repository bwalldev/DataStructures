//////////////////////////////////////////////////////////////////////////////
//
//                      DOUBLY LINKED LIST DATA STRUCTURE
//   ----------------------------------------------------------------------       
//   Description: A linked list where each node stores a pointers to
//                both the next and previous nodes. This allows the
//                doubly linked list to traverse both forward and
//                backward. Doubly linked lists simplify adding/deleting 
//                elements and reversing the list.
//  
//   Trade-offs: Requires each node to store extra memory for a
//               pointer to its previous node.  
//
//////////////////////////////////////////////////////////////////////////////

#include "Node.h"
#include <iostream>

template <typename T>
class DoublyLinkedList 
{
    private:
        size_t size;
        Node<T> *head;
        Node<T> *tail;
    public:
        DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}
        ~DoublyLinkedList() { clear(); };
        size_t getSize() const;
        void clear();
        void printForward() const;
        void printBackward() const;
        void pushBack(T value);
        void pushFront(T value);
        bool exists(T value) const;
};

// Returns the number of elements currently in the doubly linked list
template <typename T>
size_t DoublyLinkedList<T>::getSize() const 
{
    return size;
}

// Removes all of the elements from the doubly linked list
template <typename T>
void DoublyLinkedList<T>::clear() 
{
    Node<T> *curr = head;

    while (curr) 
    {
        Node<T> *tmp = curr->next;
        delete curr;
        curr = tmp;
    }

    // bookkeeping
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Outputs the doubly linked list's elements 
template <typename T>
void DoublyLinkedList<T>::printForward() const 
{
    std::cout << "Doubly linked list:\n";

    if (size == 0) 
    {
        std::cout << "List is empty.\n\n";
        return;
    }

    Node<T> *curr = head;

    while (curr->next) 
    {
        std::cout << curr->val << " -> ";

        curr = curr->next;
    }

    std::cout << curr->val << "\n\n";
}

// Outouts the doubly linked list's elements in reverse order
template <typename T>
void DoublyLinkedList<T>::printBackward() const
{
    std::cout << "Doubly linked list reversed:\n";

    if (size == 0)
    {
        std::cout << "List is empty.";
        
        return; 
    }

    Node<T> *curr = tail;

    while (curr->prev)
    {
        std::cout << curr->val << " -> ";

        curr = curr->prev;
    }

    std::cout << curr->val << "\n";
}

// Inserts an element at the end of the doubly linked list
template <typename T>
void DoublyLinkedList<T>::pushBack(T value)
{
    if (size == 0) 
    {
        pushFront(value);
        
        return;
    }

    Node<T> *newNode = new Node<T>(value);

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    size++;
}

// Inserts an element at the front of the doubly linked list
template <typename T>
void DoublyLinkedList<T>::pushFront(T value) 
{
    if (size == 0) 
    {
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
bool DoublyLinkedList<T>::exists(T value) const 
{
    if (size == 0)
        return false;

    Node<T> *curr = head;

    while (curr) 
    {
        if (curr->val == value)
            return true;

        curr = curr->next;
    }

    return false;
}