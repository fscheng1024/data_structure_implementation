#include <iostream>
#include <string>
#include <map>
#include <set>

#include "HashMap.h"

using namespace std;

char findFirstNonRepeatedChar(string str);
char findFirstRepeatedChar(string str);


int main() {
    string str = "aa ss d";

    char ch = findFirstNonRepeatedChar(str);
    cout << "non-repeated char: " << ch << endl;

    char ch2 = findFirstRepeatedChar(str);
    cout << "first-repeated char: " << ch2 << endl;


    HashMap h(5);
    h.insertItem(1, "aa");
    h.insertItem(2, "bb");
    h.insertItem(6, "cc");
    h.insertItem(8, "dd");
    h.insertItem(20, "ee");
    h.insertItem(199, "ff");
    h.printHashMap();

    cout << h.get(10) << endl;
    return 0;
}


char findFirstNonRepeatedChar(string str) {
    map<char, int> result;

    for (int i = 0; i < str.length(); ++i) {
        int count = result.count(str[i]);
        result[str[i]] = count > 0 ? count + 1 : 1;
    }

    map<char, int>::iterator it;
    for (it = result.begin(); it != result.end(); ++it) {
        if (it->second == 1)
            return it->first;
    }

    return (char)0;
}


char findFirstRepeatedChar(string str) {
    std::set<char> result;

    for (int i = 0; i < str.length(); i++) {
        const bool is_in = result.find(str[i]) != result.end();
        if (is_in)
            return str[i];
        result.insert(str[i]);
    }
    return (char)0;
}