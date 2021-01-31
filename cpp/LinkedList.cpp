#include <iostream>
using namespace std;
                     

class Node {
private:
    int value;
    Node *next;
public:
    Node(): value(0), next(nullptr) {};
    Node(int a): value(a), next(nullptr) {};

    friend class LinkedList;
};


class LinkedList {
private:
    int length;                
    Node *first;
    int size();
    bool isEmpty();
    bool isSingle();
    bool contains(int value);            
    Node* getPrevious(Node* node);   

public:
    LinkedList(): first(nullptr) {};
    void print();
    int indexOf(int value);
    void addFirst(int value);      
    void addLast(int value);       
    void deleteFirst();
    void deleteLast(); 
    void deleteAt(int index); 
    void deleteValue(int value);      
    void clear();                
    void reverse();  
    int getKthFromEnd(int k);           
};


int LinkedList::size() {
    return length;
}


bool LinkedList::isEmpty() {
    return first == nullptr;
}


Node* LinkedList::getPrevious(Node* node) {
    Node* current = first;
    while (current->next != nullptr) {
        if (current->next == node)
            return current;
        current = current->next;
    }
    return nullptr;
}


int LinkedList::indexOf(int value) {
    int count = 0;
    Node* current = first;
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
    return first->next == nullptr;
}


void LinkedList::print(){
    if (isEmpty()) {                     
        cout << "List is empty.\n";
        return;
    }

    Node *current = first;             
    while (current != nullptr) {             
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}


void LinkedList::addFirst(int value){
    Node *newNode = new Node(value);   
    newNode->next = first;               
    first = newNode;            
}


void LinkedList::addLast(int value){
    Node *newNode = new Node(value);   
    if (isEmpty()) {                     
        first = newNode;
        return;
    }

    Node *current = first;
    while (current->next != nullptr) {         
        current = current->next;
    }
    current->next = newNode;
}


void LinkedList::deleteFirst() {
    if (isEmpty()) {                     
        cout << "List is empty.\n";
        return;
    }
    if (isSingle()) {
        first = nullptr;
    }

    Node* second = first->next;
    first->next = nullptr;
    first = second;
    length--;
}


void LinkedList::deleteLast() {
    if (isEmpty()) {                     
        cout << "List is empty.\n";
        return;
    }
    if (isSingle()) {
        first = nullptr;
    }
    Node* current = first;
    while (current != nullptr) {
        if (current->next == nullptr) {
            Node* previous = getPrevious(current);
            previous->next = nullptr;
        }
        current = current->next;
    }
    length--;
}


void LinkedList::deleteAt(int index) {
    if (index < 0 || index > length)
        cout << "Illegal index value!\n";

    int count = 0;
    Node* current = first;
    while (current != nullptr) {
        if (count == index) {
            Node* previous = getPrevious(current);
            previous->next = current->next;
            delete current;
            length--;
        }
        current = current->next;
        count++;
    }
}


void LinkedList::deleteValue(int value) {
    Node* current = first;
    while (current != nullptr) {
        if (current->value == value) {
            Node* previous = getPrevious(current);
            previous->next = current->next;
            delete current;
            length--;
        }
        current = current->next;
    }
    cout << "There is no " << value << " in list!" << endl;
}


void LinkedList::clear(){
    while (!isEmpty()) {            
        Node *current = first;
        first = first->next;
        delete current;
        length--;
    }
}


void LinkedList::reverse(){
    if (isEmpty() || isSingle()) return;
    
    Node *previous = 0;
    Node *current = first;
    Node *preceding = first->next;

    while (preceding != 0) {
        current->next = previous;      
        previous = current;            
        current = preceding;           
        preceding = preceding->next;   
    }                                  

    current->next = previous;          
    first = current;                   
}


int LinkedList::getKthFromEnd(int k) {
    Node* slow = first;
    Node* current = first;
    if (isEmpty()) return -1;
    for(int i = 0; i < k-1; i++){
        current = current->next;
        if(current == nullptr)
            return -1;
        }

        Node* fast = current;
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        } 
        return slow->value;
}


int main() {

    LinkedList list;     
    list.print();       // print: empty
    list.addLast(5);    
    list.addLast(3);    
    list.addFirst(9);   
    list.print();       // print: 9 5 3
    list.addLast(4);    
    list.print();       // print: 9 5 3 4
    
    cout << "From last 2: " << list.getKthFromEnd(2) << endl;
    list.deleteAt(2);
    list.print();

    list.deleteFirst();
    list.print();       // print: 5 4

    list.deleteLast();
    list.print();       // print: 5
     
    list.print();       // print: no 9
    list.addFirst(8);   
    list.print();       // print: 8 5  
    list.reverse();     // 
    list.print();       // print: 5 8

    list.deleteValue(10);
    list.print();

    list.clear();       
    list.print();       // print: List is empty.

    return 0;
}
