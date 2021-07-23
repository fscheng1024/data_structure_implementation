#include <iostream>
#include <string>

// handle collision with linked list
#include <list>

using namespace std;


class KeyValuePair {
private:
    int key;
    string value;

public:
    KeyValuePair(int key, string value) : key(key), value(value) {};

    friend class HashMap;
};


class HashMap {
private:
    int size;

    list<KeyValuePair>* table;

public:
    HashMap(int size); 
    void printHashMap();

    void insertItem(int key, string value);
    void deleteItem(int key);
    string get(int key);
    int hashFunction(int x);

};
