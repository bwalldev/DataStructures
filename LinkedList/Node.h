// Simple Node structure for a singly linked list

template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node(T value) : val(value), next(nullptr) {}
};