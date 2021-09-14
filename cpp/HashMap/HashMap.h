#include <iostream>
#include <string>

// handle collision with linked list
#include <list>

using namespace std;


class KeyValuePair {

public:
    int key;
    string value;
    KeyValuePair() {};
    KeyValuePair(int key, string value) : key(key), value(value) {};

    friend class HashMap;
};


class HashMap {
private:
    int size;
    list<KeyValuePair>* table;
    int hashFunction(int x);

public:
    HashMap(int size); 
    void printHashMap();

    void put(int key, string value);
    void remove(int key);
    string get(int key);

};


class HashTable {
private:
    KeyValuePair* table;
    int size;
    int hashFunction(int x);
    int getIndex(int key);

    
public:
    HashTable(int size); 
    void printHashMap();

    void put(int key, string value);
    void remove(int key);
    string get(int key);
    int getSize();
};