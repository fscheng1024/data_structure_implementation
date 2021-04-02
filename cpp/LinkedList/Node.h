#include <iostream>

class Node {
private:
    int value;
    Node* next;
public:
    Node() : value(0), next(nullptr) {};
    Node(int a) : value(a), next(nullptr) {};

    friend class LinkedList;
};