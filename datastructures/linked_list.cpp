#include <iostream>
#include <cassert>

template<typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    size_t count = 0;

public:
    void push_back(T val) {
        Node* n = new Node(val);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        ++count;
    }

    size_t size() const { return count; }
};

int main() {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    assert(list.size() == 2);
    std::cout << "DoublyLinkedList verified." << std::endl;
    return 0;
}

// Updated: 2017-11-20 - feat(datastructures): singly and doubly linked list primitives
