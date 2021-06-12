#include <iostream>
using namespace std;

void print();
void insert_at_front(int data);
void insert_at_end(int data);
void insert_after_target(int target, int data);
void delete_at_front();
void delete_at_end();


struct Node {
    int data;
    Node* next;
};

Node* head = new Node;
int main() {
    head->next = NULL;

    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);
    
    insert_at_front(50);
    insert_at_front(60);
    insert_after_target(40, 45);

    delete_at_front();
    print();

    return 1;
}


void print() {
    Node* temp = new Node;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}


void insert_at_front(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = head->next;
    head->next = node;
}


void insert_at_end(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    Node* temp = head;
    while (temp->next != NULL) {   
        temp = temp->next;
    }
    temp->next = node;
}


void insert_after_target(int target, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    Node* temp = head;
    while (temp->next != NULL) {   
        temp = temp->next;
        if (temp->data == target)
            break;
    }
    node->next = temp->next;
    temp->next = node;
}


void delete_at_front() {
    Node* current = head;
    head->next = head->next->next;
    current->next = NULL;
    delete current;
}


void delete_at_end() {
    cout << "todo" << endl;
}