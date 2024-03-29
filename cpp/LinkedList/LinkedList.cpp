#include <iostream>
#include "LinkedList.h"
using namespace std;

int LinkedList::getSize() {
    return _size;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

Node* LinkedList::getPrevious(Node* node) {
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next == node)
            return current;
        current = current->next;
    }
    return nullptr;
}

int LinkedList::indexOf(int value) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value)
            return count;
        current = current->next;
    }
    return -1;
}

bool LinkedList::contains(int value) {
    return indexOf(value) > 0;
}

bool LinkedList::isSingle() {
    return head->next == nullptr;
}

void LinkedList::print() {
    if (isEmpty()) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::addFirst(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    _size++;
}

void LinkedList::addLast(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    _size++;
}

void LinkedList::addAt(int idx, int val) {
    idx -= 1;
    Node* node = new Node(val);
    Node* current = head;
    while(idx--) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    _size++;
}

void LinkedList::deleteFirst() {
    if (isEmpty()) {
        cout << "List is empty.\n";
        return;
    }
    if (isSingle()) {
        head = nullptr;
    }

    Node* second = head->next;
    head->next = nullptr;
    head = second;
    _size--;
}

void LinkedList::deleteLast() {
    if (isEmpty()) {
        cout << "List is empty.\n";
        return;
    }
    if (isSingle()) {
        head = nullptr;
    }
    Node* current = head;
    while (current != nullptr) {
        if (current->next == nullptr) {
            Node* previous = getPrevious(current);
            previous->next = nullptr;
        }
        current = current->next;
    }
    _size--;
}

void LinkedList::deleteAt(int index) {
    if (index >= _size || index < 0) {
        return;
    }
    Node* current = head;
    index -= 1;
    while(index--) {
        current = current ->next;
    }
    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
    _size--;
}

void LinkedList::deleteValue(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            Node* previous = getPrevious(current);
            previous->next = current->next;
            delete current;
            _size--;
        }
        current = current->next;
    }
    cout << "There is no " << value << " in list!" << endl;
}

void LinkedList::clear() {
    while (!isEmpty()) {
        Node* current = head;
        head = head->next;
        delete current;
        _size--;
    }
}

void LinkedList::reverse() {
    if (isEmpty() || isSingle())
        return;

    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int LinkedList::getKthFromEnd(int k) {
    Node* slow = head;
    Node* current = head;
    if (isEmpty())
        return -1;
    for (int i = 0; i < k - 1; i++) {
        current = current->next;
        if (current == nullptr)
            return -1;
    }

    Node* fast = current;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->value;
}

Node* LinkedList::swapPairs(Node* head) {
    if(!head) return NULL;
    Node* tmp = new Node(0);
    tmp->next = head;
    Node* pre = tmp, *cur = head;
    while(cur && cur->next) {
        pre->next = cur->next;
        pre = pre->next;
        cur->next = pre->next;
        pre->next = cur;
        pre = cur;
        cur = cur->next;
    }
    return tmp->next;
}


int main() {

    LinkedList list;
    list.print();
    list.addLast(5);
    list.addLast(3);
    list.addFirst(9);
    list.print();
    list.addLast(4);
    list.print();

    cout << "From last 2: " << list.getKthFromEnd(2) << endl;
    list.deleteAt(2);
    list.print();

    list.addAt(2, 7);
    list.print();

    list.deleteFirst();
    list.print();

    list.deleteLast();
    list.print();

    list.addFirst(8);
    list.print();
    list.reverse();
    list.print();

    list.deleteValue(10);
    list.print();

    list.clear();
    list.print(); // print: List is empty.

    return 0;
}
