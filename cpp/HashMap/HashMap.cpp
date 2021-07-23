#include "HashMap.h"
using namespace std;

int HashMap::hashFunction(int key) {
    return (key % size);
}

HashMap::HashMap(int size) {
    this->size = size;
    table = new list<KeyValuePair>[size];
}

void HashMap::insertItem(int key, string value) {
    int index = hashFunction(key);
    list<KeyValuePair>::iterator it;

    for (it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->key == key) {
            it->value = value;
            return;
        }
    }
    KeyValuePair item(key, value);
    table[index].push_back(item);
}

string HashMap::get(int key) {
    int index = hashFunction(key);
    list<KeyValuePair>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->key == key) {
            return it->value;
        }
    }
    return "null";
}

void HashMap::deleteItem(int key) {
    int index = hashFunction(key);
    if (table[index].empty()) throw invalid_argument("empty");;

    list <KeyValuePair> ::iterator it;
    for (it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->key == key) {
            table[index].erase(it);
            break;
        }
    }
    throw invalid_argument("key not found!");
}

void HashMap::printHashMap() {
    list<KeyValuePair>::iterator it;
    for (int i = 0; i < size; i++) {
        cout << i;
        for (it = table[i].begin(); it != table[i].end(); ++it) {
            cout << " --> " << it->key << ": " << it->value;
        }
        cout << endl;
    }
    cout << endl;
}

